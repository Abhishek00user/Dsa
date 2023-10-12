#include<iostream>
using namespace std;

class Node{
    public:
    int top;
    int size;
    Node* link;
    int val;
    Node(int val){
        this->val=val;
        top=-1;
        this->link=NULL;
    }
    void push(int element){
    Node* n=new Node(element);
    if(top==NULL){
        top=n->val;
    }
}
};



int main(){

return 0;
}