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
        if(rear==size-1){
            cout<<"stack is full "<<endl;
        }
        else if(front==-1 && rear==-1){  //first element to be inserted
            front=rear=0;
            arr[rear]=element;
        }
        else{
                rear++;
                arr[rear]=element;
        }
    }

    void dequeue(){
        if(front==-1 && rear==-1){
            cout<<"queue is empty"<<endl;
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }

    void display(){
        for(int i=front;i<rear+1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int peek(){
         if(front==-1 && rear==-1){
            cout<<"queue is empty"<<endl;
        }
        else{
            return arr[front];
        }
    }
};

int main(){
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    // cout<<q.peek()<<endl;  mistake in peek function
    q.display();

    return 0;
}