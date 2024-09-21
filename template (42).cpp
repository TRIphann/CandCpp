/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
#define MAX 2000
#define NULLDATA -1
using namespace std;

struct Stack1
{
    char arr[MAX];
    int n; // so luong phan tu cua stack
};

struct node
{
    char info;
    node *next;
};
struct Stack2
{
    node *pHead; // pTail khong co cung duoc
	node *pTail;
};

//###INSERT CODE HERE -
void InitStack(Stack1 &S){
	int n=0;
}

void reverseWords(const string &std){
	Stack1 S;
	InitStack(S);
	for (int i=0; i<std.length(); i++){
		S.arr[i]=std[i];
	}
	int a=0;
	int b=0;
	while (a<=std.length()-1){
		if (b==0&&S.arr[a]==' ') a++;
		if (b==0&&S.arr[a]!=' '){
			int c=a;
			while (S.arr[c]!=' ' && c<(std.length()-1)) c++;
			for (int i=c; i>=a; i--){
				cout << S.arr[i];
			}
			b=1;
			a++;
		}
		if (b==1) {
			a++;
			b=0;
		}
	}
	
	
	
	
	cout << "\n";
	for (int i=std.length()-1; i>=0; i--){
		cout << S.arr[i];
	}
}

int main()
{
	string str;
	getline(cin, str);
	reverseWords(str);
	return 0;
}

