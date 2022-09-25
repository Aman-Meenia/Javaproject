#include<iostream>
using namespace std;


class node{

public:
	int data;
	node * next;
node(int data){
	this->data= data;
}


// PRINT LINKLIST 
void display(node * &head){
	node * temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}cout<<endl;
}

//  INSERT AT START

void Insert_At_Start(node * &head,int element){

	node * n = new node(element);
    n->next=head;
    head=n;
}

//  INSERT AT END

void Insert_At_End(node * & head , int element){
	node * n = new node(element);
	n->next=NULL;
	node * temp = head;

	if(temp==NULL){
		head=n;
		return ;
	}

while(temp->next!=NULL){
	temp = temp->next;
}
temp->next=n;


}

//  INSERT AT ANY INDEX 

void Insert_At_AnyIndex(node * & head, int element, int index){
	node * n = new node(element);
if(index==0||head==NULL){

    n->next=head;
    head=n;
    return;
}

node * temp = head;
int cnt = 0;
while(temp->next!=NULL && cnt!=index-1){
temp=temp->next;
cnt++;
}

n->next=temp->next;
temp->next=n;

}



//  DELETION LINKLIST 


// DELETION AT START
void Delete_At_Start(node * &head ){
	//  IF LIST IS ALREADY EMPTY
	if(head==NULL) return;

	node * temp = head;
	head=head->next;
	delete(temp);
}


//  DELETION AT END 
void Delete_At_End(node * &head ){
	//  IF LIST IS EMPTY
	if(head==NULL) return;


	node * temp = head;
// IF ONLY ONE ELEMENT 
if(temp->next==NULL){
head = NULL;
return;
}
// MORE THAN ONE ELEMENT

while(temp->next->next!=NULL){
	temp = temp->next;
}
node * n = temp->next;
temp->next=NULL;
delete(n);

	
}


//  DELETION OF ANY ELEMENT


void Delete_OF_AnyElement(node *& head , int element){

if(head==NULL) return;

if(head->data==element){
	head = head->next;
	return;
}
node * temp = head;
while(temp->next!=NULL && temp->next->data!=element){
	temp = temp->next;
}

if(temp->next!=NULL){
	node * n = temp->next;
temp->next=temp->next->next;
delete(n);
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

node * head = NULL;

node * n1;
n1->Insert_At_End(head,100);
n1->Insert_At_Start(head,10);
n1->Insert_At_Start(head,1);
n1->Insert_At_AnyIndex(head,200,3);
n1->display(head);

// n1->Delete_At_Start(head);
// n1->Delete_At_Start(head);
// n1->Delete_At_Start(head);
// n1->Delete_At_Start(head);
// n1->Delete_At_Start(head);
// n1->Delete_At_End(head);
// n1->Delete_At_End(head);
// n1->Delete_At_End(head);

n1->Delete_OF_AnyElement(head,100);
n1->display(head);
n1->Delete_OF_AnyElement(head,10);
n1->Delete_OF_AnyElement(head,1);
n1->Delete_OF_AnyElement(head,10);
n1->Delete_OF_AnyElement(head,200);
n1->display(head);








}
