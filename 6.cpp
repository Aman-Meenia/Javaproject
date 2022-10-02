#include<iostream> 
using namespace std;

class node{

public:
	int data;
	node * next;
	// Empty constructor
	node(){}

	//  Assign value 
	node(int data){
		this->data=data;
	}

	//  how to print link list 
	void printLinkedlist(node * ptr){
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
      

      //  how to insert at start of linked list 

	void insertatstart(node * &head , int element){

node * n = new node(element);
n->next = head;
head = n;

	}

//  how to insert at end of linked list

	void insertatend(node * & head , int element){
		node * n = new node(element);
		node * temp = head ;
while(temp->next!=NULL){
	temp = temp->next;
}
temp->next=n;

	}

};

void Delete_All_Occurance(node * & head, int value){
while(head!=NULL && head->data==value){
	       node *deletenode=head;
 	head=head->next;
            delete(deletenode);

}
 node * previous=NULL;
        node * temp=head;
        while(temp!=NULL){
            if(temp->data==value){
                node *deletenode=temp;
                temp=temp->next;
               previous->next=temp;
                delete(deletenode);
            }else{
                previous=temp;
                temp=temp->next;
            }
        }
      


}




int main(){
	 #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

node * head = new node(10);
head->next=NULL;
node *num=new node();
num->insertatstart(head,10);
num->insertatend(head,10);
num->insertatstart(head,100);
num->insertatend(head,10);
num->insertatend(head,5);
cout<<"LinkList before deletion "<<endl;
num->printLinkedlist(head);

Delete_All_Occurance(head,10);
cout<<"LinkList After  deletion "<<endl;
num->printLinkedlist(head);


    return 0;
}
