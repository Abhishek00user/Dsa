#include<iostream>
#include<vector>
using namespace std;
void print_sub(int index,vector<int> &ds,int arr[],int n){
    if(index == n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return ;
    }
    ds.push_back(arr[index]);
    print_sub(index+1,ds,arr,n);
    ds.pop_back();
    print_sub(index+1,ds,arr,n);
}

void print_subseq_equalsK(int index,vector<int> &ds,int arr[],int sum,int k,int n){
    if(index == n){
        if(sum == k){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // pick condition setup
    ds.push_back(arr[index]);
    sum+=arr[index];
    print_subseq_equalsK(index+1,ds,arr,sum,k,n);

    // not pick condition setup
    sum-=arr[index];
    ds.pop_back();
    print_subseq_equalsK(index+1,ds,arr,sum,k,n);
}

bool print_OnlyOnesubseq_equalsK(int index,vector<int> &ds,int arr[],int sum,int k,int n){
    if(index == n){
        if(sum == k){
            for(auto it:ds){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        else return false;
    }
    // pick condition setup
    ds.push_back(arr[index]);
    sum+=arr[index];
    if(print_OnlyOnesubseq_equalsK(index+1,ds,arr,sum,k,n) == true) return true;

    // not pick condition setup
    sum-=arr[index];
    ds.pop_back();
    if(print_OnlyOnesubseq_equalsK(index+1,ds,arr,sum,k,n) == true) return true;
    return false;
}

int countSubsequence(int index,int arr[],int sum,int k,int n){
    if(index == n){
        if(sum == k){
            return 1;
        }
        return 0;
    }
    sum+=arr[index];
    int include=countSubsequence(index+1,arr,sum,k,n);

    sum-=arr[index];
    int exclude=countSubsequence(index+1,arr,sum,k,n);

    return include+exclude;
}
int main(){
    int arr[]={4,2,2,1,1};
    vector<int> ds;
    // print_sub(0,ds,arr,5);
//    print_OnlyOnesubseq_equalsK(0,ds,arr,0,3,3);
cout<<countSubsequence(0,arr,0,4,5);
   
return 0;
}