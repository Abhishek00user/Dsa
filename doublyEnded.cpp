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

    void enqueueFront(int element){
        if((rear+1)%size==front){
            cout<<"Queue is fulll"<<endl;
        }
        else if(front==-1 && rear==-1){
            front=rear=0;
            arr[front]=element;
        }
        else if(front==0){ //if front is pointing to the first element and we have to insert in the front again then it will be inserted in the last as it is the circular type
            front==size-1;
            arr[front]=element;
        }
        else{
            front--;
            arr[front]=element;
        }
    }

    void enqueueRear(int element){
        if((rear+1)%size==front){
                cout<<"Queue is full "<<endl;
        }
        else if(front==-1 && rear==-1){
            front=rear=0;
            arr[rear]=element;
        }
        else if(rear==size-1){
            rear=0;
            arr[rear]=element;
        }
        else{
            rear++;
            arr[rear]=element;
        }
    }

    void display(){
        int i=front;
        while(i!=rear){
            cout<<arr[i];
            i=(i+1)%size;
        }
        cout<<arr[rear];
    }

    void dequeueFront(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty";
        }
        else if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }
     
    void dequeueRear(){
     if(front==-1 && rear==-1){
      cout<<"Queue is empty";
        }
         else if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
    }
};
int main(){

return 0;
}