#include<iostream>
#include<stack>

using namespace std;

int main(){
	int count=0;
	string s;
	stack<char> st;
	getline(cin,s);
	for(int i=0; i<s.length(); i++){
		st.push(s[i]);
	}
	for (int i=0; i<s.length(); i++){
		if(s[i]==s[i+1]){
			count++;
			break;
		}
		cout << s[i];
		if (count!=0) cout << count;
	}
}
