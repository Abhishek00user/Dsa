#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> NGE(int arr[],int n){
    stack<int> st;
    vector<int> ans(n,-1);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

vector<int> PGE(int arr[],int n){
    stack<int> st;
    vector<int> ans(n,-1);

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

vector<int> NSE(int arr[],int n){
    stack<int> st;
    vector<int> ans(n,-1);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

vector<int> PSE(int arr[],int n){
    stack<int> st;
    vector<int> ans(n,-1);

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main(){
int arr[]={6,1,2,2,5};

vector<int> ans=NGE(arr,5);
cout<<"NGE: ";
for(int i:ans){
    cout<< i<< " ";
}
cout<<endl;

vector<int> ans2=PGE(arr,5);
cout<<"PGE: ";
for(int i:ans2){
    cout<< i<< " ";
}
cout<<endl;

vector<int> ans3=NSE(arr,5);
cout<<"NSE: ";
for(int i:ans3){
    cout<< i<< " ";
}
cout<<endl;

vector<int> ans4=PSE(arr,5);
cout<<"PSE: ";
for(int i:ans4){
    cout<< i<< " ";
}
cout<<endl;
return 0;
}