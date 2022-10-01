#include<iostream> 
#include<stack> 
using namespace std;


bool fun(string &s){

stack<char> st;
int n = s.size();
for(int i=0; i<n; i++){

if(s[i]=='(' || s[i]=='{' ||s[i]=='['){
	st.push(s[i]);
}else{

if(st.empty()) return false;

if(s[i]==')' && st.top()=='(' || s[i]==']' && st.top()=='[' ||s[i]=='}' && st.top()=='{'  ){
st.pop();
}else{
	return false;
}



}
}
if(st.empty()) return true;
return false;


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


if(fun(s)){
	cout<<"Expression is Correct"<<endl;
}else{
		cout<<"Expression is InCorrect "<<endl;
}


	return 0;
}
