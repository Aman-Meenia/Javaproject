#include<iostream>
#include<vector>
#include<stack> 
using namespace std;

class node{
    public:
    int data ;
    node * left ;
    node * right ;
    node (int data){
        this->data= data;
    }




};

node * fun(){
    int temp ;
    cin>> temp;
    if(temp==-1) return NULL;
    node * n = new node(temp);
cout<<"Enter the left for "<<temp<<endl;
    n->left=fun();
    cout<<"Enter the right for "<<temp<<endl;
    n->right=fun();
    return n ;
}

//  LEVEL ORDER TRAVERSAL 

void Level_Order_Traversal(node * root){
	if(root==NULL){
	return ;
	}
	queue<node *> q;
	q.push(root);

while(!q.empty()){
node * n = q.front();
q.pop();
cout<<n->data<<" ";
if(n->left){
	q.push(n->left);
}
if(n->right){
	q.push(n->right);
}

}cout<<endl;


}

//  INORDER TRAVERSAL
void Inorder(node * root){
    if(root==NULL) return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}


//  INORDER TREAVERSAL USING STACK 
void Iterative_Inorder(node *root){
    if(root==NULL){
        return ;
    }

    stack<node *> st;
node * n = root;
while(true){
if(n!=NULL){
    st.push(n);
    n=n->left;
}else{
    if(st.empty()) return;
    n=st.top();
    cout<<st.top()->data<<" ";
    st.pop();
    n=n->right;

}

} 

cout<<endl;

}


//  PRORDER TRAVERSAL 

void Preorder(node * root){
    if(root==NULL) return ;
        cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}

void Iterative_Preorder(node *root){
    if(root==NULL){
        return ;
    }

    stack<node *> st;
st.push(root);

while(!st.empty()){
    node * n = st.top();
    st.pop();
    cout<<n->data<<" ";
    if(n->right){
        st.push(n->right);
    }
    if(n->left){
        st.push(n->left);
    }

} cout<<endl;



}


// POSTORDER TRAVERSAL 

void Postorder(node * root){
if(root==NULL) return;
Postorder(root->left);
Postorder(root->right);
cout<<root->data<<" ";
}



void Iterative_Postorder(node * root){
if(root==NULL) return;
vector<int> v;

stack<node *> st;
st.push(root);
while(!st.empty()){
    node * n = st.top();
v.push_back(n->data);
st.pop();
if(n->left){
    st.push(n->left);
}
if(n->right){
    st.push(n->right);
}
}
reverse(v.begin(),v.end());
for(auto a:v){
cout<<a<<" ";
}cout<<endl;

}






int main(){

node * n = fun();


Preorder(n);
cout<<endl;
Iterative_Preorder(n);


Inorder(n);
cout<<endl;
Iterative_Inorder(n);

Postorder(n);
cout<<endl;
Iterative_Postorder(n);




    return 0;
}

