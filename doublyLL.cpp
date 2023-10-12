#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// inserting at head in the linked list
void insertAtHead(Node* &head,int value){
Node* toInsert=new Node(value);
toInsert->next=head;
head->prev=toInsert;
head=toInsert;
}

// inserting at the last of linkedlist
void insertAtLast(Node* &head,int data){
    Node* toInsert=new Node(data);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=toInsert;
    toInsert->prev=temp;
}

void insertAtPosition(Node* &head,int pos,int data){
    if(pos==1){
        insertAtHead(head,data);
    }
    Node* toInsert=new Node(data);
    Node* temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    toInsert->next=temp->next;
    temp->next->prev=toInsert;
    temp->next=toInsert;
    toInsert->prev=temp;
}

// reversing the linkedlist in iterative way 
void reverse(Node* &head){
    Node *curr=head,*pre=NULL,*next=NULL;

    while(curr!=NULL){        
        next=curr->next;
        curr->next=pre;
       curr->prev=next;
        pre=curr;
        curr=next;
    }
    head=pre;
}

int main(){
    Node* N1=new Node(5);
    Node* N2= new Node(6);
    N1->next=N2;
    N2->prev=N1;
    Node* first=N1;
    print(first);

    insertAtHead(first,4);
    print(first);

    insertAtLast(first,8);
    print(first);

    insertAtPosition(first,3,9);
    print(first);

    reverse(first);
    print(first);

    return 0;
}