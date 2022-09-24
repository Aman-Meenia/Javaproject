#include<iostream>
#include<queue> 
#include<stack> 
using namespace std;

class node{
public:
	int data;
	node * left;
	node * right;

node (int data){
	this->data =data;
}


};

//  CREATE A TREE 
node * fun(){

int temp;
cin>> temp;
if(temp==-1) return NULL;
node * n = new node(temp);
cout<<" Enter the left for "<<temp<<endl;
n->left=fun();
cout<<"Enter the right for "<<temp<<endl;
n->right=fun();


	return n;
}


//   SEARCH IN A BINARY SEACRH TREE 
bool Searchin_BinarysearchTree(node * root, int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(root->data<target){
return Searchin_BinarysearchTree(root->right,target);
    }else{
   return   Searchin_BinarysearchTree(root->left,target);   
    }


}

//  INSERT IN A BINARY SEARCH TREE 
void Insert_BinarysearchTree(node * &root, int value,node * previous){
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
		cout<<"Element is already present "<<endl;
		return;
	}
	 if(root->data<value){
 Insert_BinarysearchTree(root->right,value,root);
    }else{
     Insert_BinarysearchTree(root->left,value,root);   
    }
	


}

//  TRAVERSAL
void Inorder(node * root){
    if(root==NULL) return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}

//  DELETE IN A BINARY SEARCH TREE 

// THREE CASES
// 1. IF NODE IS ROOT NODE 
// 2. ONLY ONE CHILD
// 3. BOTH LEFT AND RIGHT CHILD
node * maxofleftsubtree(node * root){
	node * temp = root;
while(temp->right!=NULL){
	temp = temp->right;
}
	return temp;
}
node * delete_BinarySearchTree(node * root , int target){

	if(root==NULL){
		return NULL;
	}
	if(target>root->data){
		root->right=delete_BinarySearchTree(root->right,target);
	}else if(target<root->data){
		root->left=delete_BinarySearchTree(root->left,target);
	}else if(target==root->data){
		// case 1
if(root->left==NULL && root->right==NULL){
	return NULL;
}
//  case 2
if(root->left==NULL){
return root->right;
}else if(root->right==NULL){
return root->left;
}
// case 3
node * temp = maxofleftsubtree(root->left);
root->data= temp->data;
root->left= delete_BinarySearchTree(root->left,temp->data);
	}

return root;

}
// DELETE IN A BINARY SEARCH TREE  { Easier version }
void deleteinbinaryseachtree(node *& root , int target){
	if(root==NULL){
		return ;
	}
	if(target>root->data){
		deleteinbinaryseachtree( root->right ,target);
	}else if(target<root->data){
		deleteinbinaryseachtree( root->left ,target);
	}
	else{
		// case 1
		if(root->left==NULL && root->right==NULL) {
		  //  cout<<"Aman "<<endl;
		    root=NULL;
		    return ;
		}
        // case2
        
        if(root->left==NULL){
        	root=root->right;
        	return;
        }else if(root->right==NULL){
            root=root->left;
            return;
        }
        // case3
    
        node * temp=maxofleftsubtree(root->left);
        root->data = temp->data;
        deleteinbinaryseachtree(root->left ,temp->data);

	}
}





int main(){
//  #ifndef ONLINE_JUDGE
//     // for getting input 
//     freopen("input1.txt","r",stdin);
//     // for writing output
//     freopen("output1.txt","w",stdout);
// #endif
cout<<"Enter the parent Node "<<endl;
node * n = fun();

// if(Searchin_BinarysearchTree(n,10)){
//     cout<<"Element is present in Tree"<<endl;
// }else{
//     cout<<"Element is not present "<<endl;
// }


// Insert_BinarysearchTree(n,20,NULL);
// Insert_BinarysearchTree(n,3,NULL);
// Insert_BinarysearchTree(n,8,NULL);
Inorder(n);
cout<<endl;

deleteinbinaryseachtree(n,10);
Inorder(n);
cout<<endl;
deleteinbinaryseachtree(n,8);
Inorder(n);
cout<<endl;
deleteinbinaryseachtree(n,1);
Inorder(n);
cout<<endl;

// Level_Order_Traversal(n);
	return 0;
}
