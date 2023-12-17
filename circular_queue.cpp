#include<iostream>
using namespace std;

class queue{
    public:
    int size;
    int front;
    int rear;
    int *arr;

    queue(int size) {
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

void enqueue(int element){
   if((rear+1)%size==front){
    cout<<"stack overflow"<<endl;
   }
   else if(front==-1 && rear==-1){
    front=rear=0;
    arr[rear]=element;
   }
   else{
    rear=(rear+1)%size;
    arr[rear]=element;
   }
}

void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"queue is already empty"<<endl;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%size;
    }
}

void display(){
    if(front==-1 && rear==-1){
        cout<<"Queue is Empty"<<endl;
    } else{
        int i=front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        cout<<arr[rear];
    }
}
};
int main(){
queue q(5);
q.enqueue(6);
q.enqueue(5);
q.enqueue(4);
q.dequeue();
q.display();



return 0;
}