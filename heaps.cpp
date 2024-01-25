#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size = 0;
    }
    void insert(int value)
    {
        size = size + 1;
        int index = size;
        // inserting the element in the array
        arr[index] = value;

        // checking if it satisfy the max heap property
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        // placing the last element at the first index
        arr[1] = arr[size];
        size--;

        // now take the root node to its correct position
        int i = 1;

        // after that we can directly heapify the root node and we will get the same result as it will take 
        // the root node to its correct but we are doing it by normal way
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
                if(leftIndex < size && arr[i]<arr[leftIndex]){
                    swap(arr[i],arr[leftIndex]);
                    i=leftIndex;
                }
                else if(rightIndex< size && arr[i]<arr[rightIndex]){
                    swap(arr[i],arr[rightIndex]);
                }
                else{
                    return;
                }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[],int n,int elementIndex){
    int largest=elementIndex;
    int left=2*elementIndex;
    int right=2*elementIndex+1;

//   since,it is 1 based indexing so we write left<=n
    if(left<=n && arr[left]>arr[largest]){
        largest=left;
    }

    if(right<=n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=elementIndex){
        swap(arr[largest],arr[elementIndex]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        // swap the first element with the last ,what it will do is it will push the max element to the last
        // after that we will reduce the size and then we'll heapify the new root element to its correct position
        // in this way we'll again get the root element as the max element then we will repeat the steps
        swap(arr[size],arr[1]);
        size--;

    // now we will take the first index element to its right position
        heapify(arr,size,1);
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deleteFromHeap();
    h.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    // for going to each element in the heap for heapifying
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"After heapifying all the elements of the array : ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout<<"printing the array after heap sort : ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    return 0;
}