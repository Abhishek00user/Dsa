#include<bits/stdc++.h>
using namespace std;


void selectionSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){  //till last second element
        int min=i; 
        for(int j=i+1;j<=n-1;j++ ){  //till last element
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements are still left out 
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    // merging 
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void ms(vector<int> &arr,int low,int high){
    if(low>=high)
    return;

    int mid=(low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);

}
int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int start=low;
    int end=high;
    while(start<end){
        while(arr[start] <= pivot && start <= high -1){
            start++;
        }
        while(arr[end] > pivot && end > low + 1){
            end--;
        }
        if(start<end) swap(arr[start],arr[end]);
    }
    swap(arr[low],arr[end]);
    return end;
}
void qs(vector<int> &arr,int low ,int high){
    if(low<high){
        int pIndex=partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}
int main(){
    // int arr[]={8,5,2,3,1};
    vector<int> arr={8,6,5,4,7};
    int n=5;
    // selectionSort(arr,5);
    // insertionSort(arr,5);
    // bubbleSort(arr,5);
    qs(arr,0,n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
return 0;
}