#include<iostream>
#include <bits/stdc++.h>
using namespace std;




void dijkstras(vector<pair<int,int> > adj[] , int n, int source){

// distance , vertex
    priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> >> pq;


    vector<int> distance(n,INT_MAX);
 distance[source]=0;

 pq.push({0,source});
 while(!pq.empty()){
    int dist=pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for(auto it:adj[node]){
    if(distance[it.first]>dist+it.second){
        distance[it.first]=distance[node]+it.second;
        pq.push({  distance[it.first],it.first});
    }
    }
 }

 for(auto a:distance){
    cout<<a<<" ";
 }cout<<endl;


}






void prims(vector<pair<int,int> > adj[] , int n){

    int key[n];
    bool mst[n];
    int parent[n];
    for(int i=0; i<n; i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    for(int i=0; i<n-1; i++){
        int index;
        int minimumvalue=INT_MAX;
for(int j=0; j<n; j++){
    if(mst[j]==false && key[j]<minimumvalue){
        minimumvalue=key[j];
        index=j;
    }
    }
mst[index]=true;
    for(auto it:adj[index]){
if(mst[it.first]==false && key[it.first]>it.second){
key[it.first]=it.second;
parent[it.first]=index;
    }
}


}
int ans = 0;
for(int i=0; i<n; i++){
    ans+=key[i];
}
cout<<"ANS "<<ans<<endl;


for(int i=1; i<n; i++){
    cout<<i<<" <-> "<<parent[i]<<endl;
}



}


int main(){
     #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
int n = 5;

vector<pair<int,int> > adj[n];

for(int i=0; i<6; i++){
    //  (a=>vertex v , b=> vertex u , c=> cost)
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

dijkstras(adj,n,0);
 // prims(adj,5);
    return 0;
}



// 0 1 2
// 0 3 1 
// 1 2 4
// 1 4 5
// 2 3 3
// 2 4 1
