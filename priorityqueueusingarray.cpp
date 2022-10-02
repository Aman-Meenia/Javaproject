#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Priority_queue{
public:
    int *array;
    int n;
    int cnt;
    //  it will store the number of elements present in priority queue at any time 


    Priority_queue(int n ){
        this->n=n;
        array = new int[n];
        cnt=0;
    }


    //  To check priority_queue is empty()
bool isempty(){
    if(cnt==0){
return true;
    }else{
        return false;
    }
}

// To check priority_queue is full

bool isfull(){
    if(cnt==n){
        return true;
    }else{
        return false;
    }
}


//  Hot to push elemnt in queue

void pushelement(int element){
if(isfull()){
    cout<<"priority_queue is full"<<endl;
}else{

int i = cnt-1;
while(i>=0 && array[i]>element){
    swap(array[i],array[i+1]);
    i--;
}
array[i+1]=element;
cnt++;
}

}


//  How to pop element 
void popelement(){

    if(cnt>=0){
        int i = 0;
        while(i+1 <cnt){
            swap(array[i],array[i+1]);
            i++;
        }
        cnt--;

    }else{
        cout<<"Priority_queue is empty"<<endl;
    }
}

//  Top element 
int topelement(){
    if(isempty()){
               cout<<"Priority_queue is empty"<<endl;
               return INT_MAX;
           }else{
return array[0];
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


Priority_queue pq(5);
pq.pushelement(10);
pq.pushelement(100);
pq.pushelement(1);
pq.pushelement(8);
cout<<"Top element "<<pq.topelement()<<endl;
for(int i=0; i<pq.cnt; i++){
    cout<<pq.array[i]<<" ";
}cout<<endl;
pq.popelement();
cout<<"Top element "<<pq.topelement()<<endl;
for(int i=0; i<pq.cnt; i++){
    cout<<pq.array[i]<<" ";
}cout<<endl;





}
