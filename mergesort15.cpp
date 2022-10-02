#include<iostream>
using namespace std;


void merge(int * v , int low , int mid , int high ){

	int i =low;
	int j =mid+1;
int array[high+1];
int k = low;
	while(i<=mid && j<=high){
		if(v[i]<=v[j]){
array[k]=v[i];
i++;
k++;
		}else{
			array[k]=v[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		array[k]=v[i];
i++;
k++;
	}
	while(j<=high){
		array[k]=v[j];
			k++;
			j++;
	}
	for(int i=low; i<=high; i++){
v[i]=array[i];
	}

}





void mergesort(int *array , int low , int high ){
	if(low<high){
		int mid = low + (high-low)/2;
		mergesort(array,low,mid);
		mergesort(array,mid+1,high);
		merge(array,low,mid,high);
	}
}

int main(){
 
 #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
int n ;
cin>> n;

int array[n];
for(int i=0; i<n; i++){
cin>>array[i];;
}
cout<<"Array Before Sort "<<endl;
for(int i=0; i<n; i++){
	cout<<array[i]<<" ";
}cout<<endl;

mergesort(array,0,n-1);
cout<<"Array After Sort "<<endl;
for(int i=0; i<n; i++){
	cout<<array[i]<<" ";
}cout<<endl;
	return 0;
}
