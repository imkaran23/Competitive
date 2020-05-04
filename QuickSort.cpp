#include<iostream>
using namespace std;

void swap ( int &a , int &b )
{
    int t = a ; 
    a = b ;
    b = t ;
}

int partition ( int a[] , int low , int high )
{
    int pivot = a[high];
    int i = low - 1 ;

    for( int j = low; j<high ;j++ )
    {
        if ( a[j] < pivot )
        {
            i++;
            swap ( a[i] , a[j] );
        }
    }

    swap ( a[i+1] , a[high] );
    return ( i + 1 );
}

void quicksort ( int a [] , int low , int high )
{
    if( low < high )
    {
        int pi = partition ( a , low , high);
        quicksort ( a, low , pi - 1 );
        quicksort ( a , pi + 1 ,high );
    }
}

void print(int a[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << a[i] << " ";  
    cout << endl;  
}  

main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5 , 2 , 2};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quicksort (arr, 0, n - 1) ;  
    cout << "Sorted array: \n";  
    print(arr, n);  
}