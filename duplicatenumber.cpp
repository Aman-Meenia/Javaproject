#include <iostream>
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

void Insert_BinarysearchTree(node * &root, int value,node * previous , int &cnd ){
  if(root==NULL){
    node * n = new node(value);
    if(previous==NULL){
      root=n;
      return;
    }
    if(value>previous->data){
previous->right=n;
    }else{
previous->left=n;
    }
    return ;
  } 
  if(root->data==value){
    cnd= 1;
    return;
  }
   if(root->data<value){
 Insert_BinarysearchTree(root->right,value,root,cnd);
    }else{
     Insert_BinarysearchTree(root->left,value,root,cnd);   
    }
  


}

void Inorder(node * root){
    if(root==NULL) return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}
int main()
{
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt", "r", stdin);
    // for writing output
    freopen("output1.txt", "w", stdout);
#endif
    int n ;
    cin>> n;
int array[n];
for(int i=0; i<n; i++){
  cin>>array[i];
}


node * root=NULL;
for(int i=0; i<n; i++){
int cnd = 0;
  Insert_BinarysearchTree(root,array[i],NULL,cnd);
  if(cnd==1){
    cout<<"Duplicate Number  " <<array[i]<<endl;
  }
}





    return 0;
}
