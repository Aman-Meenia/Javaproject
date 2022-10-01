#include<iostream> 
#include<stack> 
using namespace std;


   int evaluatePostfix(string s)
    {
       stack<int> st;
       for(auto a:s){
           if(a=='+' || a=='-' || a=='/' || a=='*'){
               int b1 = st.top();
               st.pop();
               int a1 = st.top();
               st.pop();
               
               if(a=='+'){
                   st.push(a1+b1);
                
               }else if(a=='-'){
                   st.push(a1-b1);
                
               }else if(a=='/'){
                   st.push(a1/b1);
                
               }else{
                   st.push(a1*b1);

               }
           }else{
           st.push(a-'0');
           }
       }
       return st.top();
    }





int main(){
 #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif

string s;
cin>>s;


cout<<evaluatePostfix(s)<<endl;


	return 0;
}
