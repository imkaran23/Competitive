#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512 
#define NUM_OF_ELEMS 4096 

#define funcCheck(stmt) {                                            \
    cudaError_t err = stmt;                                          \
    if (err != cudaSuccess)                                          \
    {                                                                \
        printf( "Failed to run stmt %d ", __LINE__);                 \
        printf( "Got CUDA error ...  %s ", cudaGetErrorString(err)); \
        return -1;                                                   \
    }                                                                \
}

__global__  void total(float * input, float * output, int len) 
{
    // Load a segment of the input vector into shared memory
    __shared__ float partialSum[2*BLOCK_SIZE];
    int globalThreadId = blockIdx.x*blockDim.x + threadIdx.x;
    unsigned int t = threadIdx.x;
    unsigned int start = 2*blockIdx.x*blockDim.x;

    if ((start + t) < len)
    {
        partialSum[t] = input[start + t];      
    }
    else
    {       
        partialSum[t] = 0.0;
    }
    if ((start + blockDim.x + t) < len)
    {   
        partialSum[blockDim.x + t] = input[start + blockDim.x + t];
    }
    else
    {
        partialSum[blockDim.x + t] = 0.0;
    }

    // Traverse reduction tree
    for (unsigned int stride = blockDim.x; stride > 0; stride /= 2)
    {
      __syncthreads();
        if (t < stride)
            partialSum[t] += partialSum[t + stride];
    }
    __syncthreads();

    // Write the computed sum of the block to the output vector at correct index
    if (t == 0 && (globalThreadId*2) < len)
    {
        output[blockIdx.x] = partialSum[t];
    }
}

int main(int argc, char ** argv) 
{
    int ii;

    float * hostInput; // The input 1D vector
    float * hostOutput; // The output vector
    float * deviceInput;
    float * deviceOutput;

    int numInputElements = NUM_OF_ELEMS; // number of elements in the input list
    int numOutputElements; // number of elements in the output list
    hostInput = (float *) malloc(sizeof(float) * numInputElements);

    for (int i=0; i < NUM_OF_ELEMS; i++)
    {
        hostInput[i] = 1.0;     // Add your input values
    }

    numOutputElements = numInputElements / (BLOCK_SIZE<<1);
    if (numInputElements % (BLOCK_SIZE<<1)) 
    {
        numOutputElements++;
    }
    hostOutput = (float*) malloc(numOutputElements * sizeof(float));

    funcCheck(cudaMalloc((void **)&deviceInput, numInputElements * sizeof(float)));
    funcCheck(cudaMalloc((void **)&deviceOutput, numOutputElements * sizeof(float)));

    cudaMemcpy(deviceInput, hostInput, numInputElements * sizeof(float), cudaMemcpyHostToDevice);

    dim3 DimGrid( numOutputElements, 1, 1);
    dim3 DimBlock(BLOCK_SIZE, 1, 1);

    total<<<DimGrid, DimBlock>>>(deviceInput, deviceOutput, numInputElements);
    cudaMemcpy(hostOutput, deviceOutput, numOutputElements * sizeof(float), cudaMemcpyDeviceToHost);

    // Reduce output vector on the host
    for (ii = 1; ii < numOutputElements; ii++) 
    {
        hostOutput[0] += hostOutput[ii];
    }

    printf("Reduced Sum from GPU = %f\n", hostOutput[0]);   

    cudaFree(deviceInput);
    cudaFree(deviceOutput); 
    free(hostInput);
    free(hostOutput);

    return 0;
}