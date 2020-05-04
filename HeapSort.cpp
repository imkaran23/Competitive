#include<iostream>
using namespace std;

void print(int a[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << a[i] << " ";  
    cout << endl;  
} 

void heapify(int a[],int n,int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[l]>a[largest])
        largest = l;
    
    if(r<n && a[r]>a[largest])
        largest = r;

    if(largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void heapsort(int a[], int n)
{
    for(int i = n/2-1 ; i>=0 ; i--)
        heapify(a,n,i);

    for(int i=n-1 ; i>=0 ; i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

main()
{
    int arr[] = {10, 7, 8, 9, 1, 5 , 2 , 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    cout << "Sorted array is \n"; 
    print(arr,n);
}