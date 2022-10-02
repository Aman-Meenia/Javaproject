#include <iostream>
using namespace std;


class node{
    public:
    int data ;
    node * next;

    node (int data){
        this->data= data;
    }

};

void printlist(node *&head){
  node * temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }cout<<endl;
}

void Insertion_in_Ordered_List(node * & head , int element){
  if(head ==NULL){
      node * n = new node(element);
    head=n;
    return;
  }
// if element is first smaller elemet
if(element<head->data){
  node * n = new node(element);
  n->next=head;
  head = n;
  return;
}

  //  if element is in middle or last

node * temp = head;
node * n = head->next;

while(n!=NULL && n->data<=element){
  temp=temp->next;
  n=n->next;
}
node * N = new node(element);
if(temp==NULL){
  temp->next=N;
  N->next=NULL;
}else{
  temp->next=N;
  N->next=n;

}

}


int main()
{
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt", "r", stdin);
    // for writing output
    freopen("output1.txt", "w", stdout);
#endif
    node * head = NULL;
Insertion_in_Ordered_List(head,10);
Insertion_in_Ordered_List(head,1);
Insertion_in_Ordered_List(head,20);
Insertion_in_Ordered_List(head,11);
Insertion_in_Ordered_List(head,23);
Insertion_in_Ordered_List(head,18);
cout<<"List after Insertion "<<endl;
printlist(head);
    return 0;
}
