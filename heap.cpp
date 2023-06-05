/*
#include<iostream>
using namespace std;
void heapify(int arr[], int n, int ri)
{
    int l=ri; //assume that rootindex is largest
    int lc=2*ri+1;
    int rc=2*ri+2;

    if(lc<n && arr[lc]>arr[l])
    {
        l=lc;
    }
     if(rc<n && arr[rc]>arr[l])
    {
        l=rc;
    }
    if(l!=ri)
    {
        swap(arr[ri], arr[l]);
        heapify(arr, n, l);
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
    cout<<"Enter the element you want to sort using heap sort : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    heapSort(arr,n);
    cout<<"Sorted arry : ";
    for(int i=0;i<n;i++) cout<<arr[i];
    return 0;
}
*/


/*#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at 'rootIndex'
// n is the size of the heap
void heapify(int arr[], int n, int rootIndex) {
    int largest = rootIndex; // Assume the root is the largest
    int leftChild = 2 * rootIndex + 1; // Index of the left child
    int rightChild = 2 * rootIndex + 2; // Index of the right child

    // If the left child is larger than the root
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // If the right child is larger than the largest so far
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If the largest is not the root, swap and heapify the affected subtree
    if (largest != rootIndex) {
        swap(arr[rootIndex], arr[largest]);
        heapify(arr, n, largest);
    }
}

// The main function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Build a max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root (largest element) to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
*/

#include<iostream>
using namespace std;

void heapify(int arr[],int n,int ri)
{
    int l=ri;
    int lc=2*ri+1;
    int rc=2*ri+2;

    if(lc<n && arr[lc]>arr[l])
    {
        l=lc;
    }
     if(rc<n && arr[rc]>arr[l])
    {
        l=rc;
    }
    if(l!=ri)
    {
        swap(arr[l],arr[ri]);
        heapify(arr,n,l);
    }
}

void heapSort(int arr[],int n)
{
    for(int i=n/2-i;i>=0;i--)
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
    cout<<"Enter the number of element you want to sort : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element "<<(i+1)<<":";
        cin>>arr[i];
    }
    heapSort(arr,n);

    cout<<"Sorted element is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

    return 0;
}