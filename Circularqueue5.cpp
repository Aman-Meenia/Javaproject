#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Queue{
public:
    // it will cnt the exact number of element present in a queue at anytime
    int cnt =0;
    int *array;
    int front;
    int rear;
    int n ;

//  constructor to intitalize the size of array 
Queue(int n ){
    array=new int[n];
    this->n=n;
    front = 0;
    rear = 0;
}


//  To check stack is empty

bool isempty(){
    if(front == rear) return true;
    else return false;
}


//  To check stack is full 

bool isfull(){
    if(n==cnt) return true;
    else return false;
}


//  Push element in stack


void pushelement(int element){
    if(isfull()){
        cout<<" Queue is full,we cannot insert"<<endl;
    }else{
array[rear%n]=element;
cnt++;
rear++;
    }
}


// Pop element 
void popelement(){
    if(isempty()){
        cout<<"queue is empty "<<endl;
    }else{
        front++;
        cnt--;
    }
}


// How to get front element;
void frontelement(){
    if(isempty()){
        cout<<"queue is empty "<<endl; 
    }else{
        cout<<array[front%n]<<endl;
    }
}



};








int main(){

     #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


Queue q1(5);
q1.pushelement(3);
q1.pushelement(13);
q1.pushelement(32);
q1.pushelement(98);
q1.pushelement(289);
if(q1.isempty()){
cout<<"Stack is empty"<<endl;
}if(q1.isfull()){
cout<<"Stack is Full "<<endl;
}













}
