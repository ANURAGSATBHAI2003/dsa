#include<iostream>
using namespace std;

void heapify(int arr[],int n, int i)
{
    int l=i;
    int lc=2*i+1;
    int rc=2*i+2;
    
    if(lc<n && arr[lc]>arr[l])
    {
        l=lc;
    }
    if(rc<n && arr[rc]>arr[l])
    {
        l=rc;
    }
    if(l!=i)
    {
        swap(arr[i],arr[l]);
        heapify(arr,n,l);
    }
}

void heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of element you want to sort using heap sort: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) 
    {
    cout<<"Enter the number "<<i+1<<":";
    cin>>arr[i];
    }
    heapSort(arr,n);
    cout<<"Sorted element is : ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"maximum marks is : "<<arr[n-1]<<endl;
    cout<<"minmum marks is : "<<arr[0]<<endl;
    return 0;
    
}