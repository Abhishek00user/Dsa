#include<iostream>
#include<vector>
using namespace std;
void print_sub(int index,vector<int> &ds,int arr[],int n){
    if(index == n){
        for(auto it:ds){
            cout<<it<<" ";
        }
        // for printing the empty set as it also conclude the subsequence
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return ;
    }
    ds.push_back(arr[index]);
    print_sub(index+1,ds,arr,n);
    // when the above recursion gets executed then we do the not pick thing and call it 
    // again without including the element
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
    // if during left recursion we found our answer then there is no need to go to right recursion
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
    // include will give us the no of subsequences that we got while picking the elements
    int include=countSubsequence(index+1,arr,sum,k,n);

    sum-=arr[index];
    int exclude=countSubsequence(index+1,arr,sum,k,n);

    return include+exclude;
}

// We have to find all the subset’s sum and print them
void subsetSum1(int index,int arr[],int n,int sum,vector<int> &ans){
    
    if(index == n){
        ans.push_back(sum);
        return;
    }

    // picking element
    subsetSum1(index+1,arr,n,sum+arr[index],ans);
    // not picking the element
    subsetSum1(index+1,arr,n,sum,ans);
}

// printing permutations with extra space
void printPermutation(int arr[],int n,int freq[],vector<int>&ds,vector<vector<int>> & ans){
    // base case
    if(ds.size()==n){
        ans.push_back(ds);
    }
    for(int i=0;i<n;i++){
        if(!freq[i]){
            ds.push_back(arr[i]);
            freq[i]=1;
            // calling recursion
            printPermutation(arr,n,freq,ds,ans);
            // while coming back
            freq[i]=0;
            ds.pop_back();
        }
    }
}
// printing premutations without extra space
void swap(vector<int> &arr,int first,int second){
    int temp=arr[first];
    arr[first]=arr[second];
    arr[second]=temp;
}
void printPermutationWospace(int index,vector<int> &nums,int n,vector<vector<int>> &ans){
    if(index == n){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<n;i++){
        swap(nums,i,index);
        printPermutationWospace(index+1,nums,n,ans);
        swap(nums,i,index);
    }
}
int main(){
    // int arr[]={3,1,2};
    vector<int> arr={3,1,2};
    vector<int> ds;
    vector<vector<int>> ans;
    int freq[3]={0};
    // subsetSum1(0,arr,3,0,ds);
    // printPermutation(arr,3,freq,ds,ans);
    printPermutationWospace(0,arr,3,ans);
    for (const auto& row : ans) {
        for (int num : row) {
           cout << num << " ";
        }
        cout << endl;
    }
    // print_sub(0,ds,arr,5);
//    print_OnlyOnesubseq_equalsK(0,ds,arr,0,3,3);
// cout<<countSubsequence(0,arr,0,4,5  );
   
return 0;
}