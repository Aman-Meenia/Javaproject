#include<iostream>
#include <bits/stdc++.h>
using namespace std;




int primsalgorithm(vector<pair<int,int> > v[] , int n ){

vector<int> key(n,INT_MAX);
vector<bool> mst(n,false);

key[0]=0;
// mst[index]=true;
for(int i=0 ; i<n-1; i++){


int mini = INT_MAX;
int index =100;
for(int j=0; j<n; j++){
    if(mst[j]==false && key[j]<mini){
        index = j;
        mini=key[j];
    }
}

mst[index]=true;

for(auto it : v[index]){
    if(mst[it.first]==false && key[it.first]>it.second){
        key[it.first]=it.second;
    }
}
 
}

int ans = 0;
for(auto a:key){
ans+=a;
}



    return ans;
}





int main(){
     #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
int n = 3;

vector<pair<int,int> > adj[n];

for(int i=0; i<n; i++){
  int a , b , c;
  cin>> a >> b >>  c;
  adj[a].push_back({b,c});
    adj[b].push_back({a,c});
   
}

for(int i=0; i<n; i++){
    for(auto  a:adj[i]){
cout<<a.first<<" "<<a.second<<endl;
    }
}

 cout<<primsalgorithm(adj,3)<<endl;
    return 0;
}
