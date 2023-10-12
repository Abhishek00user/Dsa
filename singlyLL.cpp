#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// inserting at the head
   void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp; //head ko set karna hai isliye head phle aur temp badd me 
}

// inserting at the end
void insertAtEnd(Node* &head,int d){
    Node* toInsert=new Node(d);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=toInsert;
    toInsert->next=NULL;
}

// Inserting in between the List
void insertBtwByPosition(Node* &head,int pos,int val){
    if(pos==1){
        insertAtHead(head,val);
    }
    Node* toInsert=new Node(val);
    int i=1;
    Node* temp=head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    toInsert->next=temp->next;
    temp->next=toInsert;

}

// deleting the first NOde
void deleteFirst(Node* &head){
Node* temp=head;
head=head->next;
delete(temp);
}

// deleting the last Node
void deleteLast(Node* &head){
    Node* temp=head;
    Node* back=head;
    while(temp->next!=NULL){
        back=temp;
        temp=temp->next;
    }
    back->next=temp->next;
    delete(temp);
}

// deleting in between when the value is given that is to be deleted
void deleteBetween(Node* &head,int value){
    Node *temp=head;
    Node *back=head;
    while(temp->data!=value){
        back=temp;
        temp=temp->next;
    }
    back->next=temp->next;
    delete(temp);
}

// reversing the linked list
void reverse(Node* &head){
    Node* pre=NULL;
    Node* next=NULL;
    Node* cur=head;
    while(cur!=NULL){
    next=cur->next;
    cur->next=pre;
    pre=cur;
    cur=next;
    }

}

// printing the list 
void printing(Node* &head){
    Node* temp =head;
    while(temp !=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){
Node* n1=new Node(1);
Node* n2=new Node(2);
n1->next=n2;
Node* first=n1;
printing(first);

insertAtHead(first,3);
printing(first);

insertAtEnd(first,5);
printing(first);

// deleteFirst(first);
// printing(first);

// deleteLast(first);
// printing(first);

insertBtwByPosition(first,3,6);
printing(first);

// deleteBetween(first,6);
// printing(first);

reverse(first);
printing(first);

return 0;
}

