#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top;
    stack(int s){
        this->size=s;
        top=-1;
        arr=new int[s];
    }
    void push(int element){
    if(size-top>1){
        top++;
        arr[top]=element;
    }
    else{
        cout<<"No more element can be inserted";
    }
}

void pop(){
    if(top<0){
        cout<<"stack underflow";
    }
    else{
        top--;
    }
}

int peek(){
     if(top<0){
        cout<<"stack is empty";
    }
  return arr[top];
}

};




int main(){
stack s(4);
s.push(2);
s.push(5);
s.push(7);
s.pop();
cout<<s.peek();

return 0;
}