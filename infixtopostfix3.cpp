#include <iostream>
#include<stack>
#include<unordered_map>
using namespace std;



   string infixToPostfix(string &s) {
      
      stack<char> st;
      string ans; 
      unordered_map<char,int> mp;
      mp['+']=1;
      mp['-']=1;
      mp['*']=2;
      mp['/']=2;
      mp['^']=3;
      for(auto a: s){
          
          if(a=='('){
              st.push('(');
              
          }else if(a==')'){
              while(st.top()!='('){
                  ans.push_back(st.top());
                  st.pop();
                  
              }
              st.pop();
          }else if(a=='+' || a=='-' || a=='/' || a=='*' || a=='^'){
              
              while(!st.empty() && mp[st.top()]>=mp[a]){
                  ans.push_back(st.top());
                  st.pop();
              }
              st.push(a);
              
              
          }else{
              ans.push_back(a);
              
          }
        
          
          
          
          
      }
      while(!st.empty()){
          ans.push_back(st.top());
          st.pop();
      }
      
      return ans;
      
    }

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input1.txt", "r", stdin);
	// for writing output
	freopen("output1.txt", "w", stdout);
#endif

string s;
cin>>s;
cout<<infixToPostfix(s)<<endl;
	return 0;
}
