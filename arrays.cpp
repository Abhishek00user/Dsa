#include<iostream>
using namespace std;


// program to split an array based on the index
void splitting(int arr[],int size,int index){
    int subArray1[index];
    int subArray2[size-index];
    int i=0;

    for(i=0;i<index;i++){
        subArray1[i]=arr[i];
    }
    for(int j=0;j<size-index;j++){
        subArray2[j]=arr[i];
        i++;
    }
    for(int i=0;i<index;i++){
        cout<<subArray1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<size-index;i++){
        cout<<subArray2[i]<<" ";
    }
}

void merging(int sub1[],int size1,int sub2[],int size2){
    int arr[size1+size2];
    for(int i=0;i<size1;i++){
        arr[i]=sub1[i];
    }
    int j=0;
    for(int i=size1;i<size1+size2;i++){
        arr[i]=sub2[j];
        j++;
    }

    for(int i=0;i<size1+size2;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
int arr[]={1,2,3,4,5,6};
int s1[]={2,3,4};
int s2[]={5,6,7,8};
// splitting(arr,6,3);
merging(s1,3,s2,4);
return 0;
}