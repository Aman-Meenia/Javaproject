#include <iostream>
using namespace std;

int partition(int *v , int low , int high){

	int i = low;
	int j = high;
	while(i<j){

		while(v[i]<=v[low] && i<high){
i++;
		}
			while(v[j]>v[low] && j>low){
j--;
		}
		if(i<j){
			swap(v[i],v[j]);
		}

	}
	swap(v[low],v[j]);
	return j;
}

void quicksort(int *array, int low , int high){
	if(low<high){
		int partitionindex=partition(array,low,high);
		quicksort(array,low,partitionindex-1);
		quicksort(array,partitionindex+1,high);
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

quicksort(array,0,n-1);
cout<<"Array After Sort "<<endl;
for(int i=0; i<n; i++){
	cout<<array[i]<<" ";
}cout<<endl;


	return 0;
}
