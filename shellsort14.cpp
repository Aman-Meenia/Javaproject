#include <iostream>
using namespace std;




void shellsort(int *v , int n){
	for(int gap=n/2; gap>0; gap/=2){
		for(int j=gap; j<n; j++){
			for(int i=j-gap; i>=0; i-=gap){
				if(v[i+gap]>v[i]){
					break;
				}else{
					swap(v[i+gap],v[i]);
				}
			}
		}
	}
}





int main(){
 
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

shellsort(array,n);
cout<<"Array After Sort "<<endl;
for(int i=0; i<n; i++){
	cout<<array[i]<<" ";
}cout<<endl;


	return 0;
}
