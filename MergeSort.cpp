#include<iostream>
#include<stdlib.h> 

using namespace std;

void print(int a[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << a[i] << " ";  
    cout << endl;  
} 

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	print(L,n1);
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
	print(R,n2);

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 


void mergesort ( int arr[], int l, int r )
{
    if( l < r )
    {
        int m = l + ( r - l )/2 ;
        mergesort ( arr , l , m );
        mergesort ( arr , m +1 , r );
        merge ( arr , l ,m ,r );
    }
} 

main ()
{
    int arr[] = {10, 7, 8, 9, 1, 5 , 2 , 2};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    mergesort (arr, 0, n - 1) ;  
    cout << "Sorted array: \n";  
    print(arr, n);  
}
