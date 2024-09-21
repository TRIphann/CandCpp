
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};

//###INSERT CODE HERE -

void Init(Stack &S){
	S.n=0;
} 

bool IsEmpty(Stack S) {
	return S.n==0;
}

bool IsPull	(Stack S){
	return S.n==MAX; 
}

void Push(Stack &S, int x){
	S.arr[S.n]=x;
	S.n++;
}

void printStack(Stack S){
	if (IsEmpty(S)){
		cout << "Stack is empty";
	}
	else {
		for (int i=0; i<S.n; i++){
		cout << S.arr[i] << " ";
	}	
}
}

int Top(Stack S) {
    if (IsEmpty(S)) {
        return NULLDATA;
    }
    return S.arr[S.n-1];
}

void Pop(Stack &S) {
    if (IsEmpty(S)) {
        cout << "Stack is empty, cannot pop." << endl;
    } 
	else {
//        for (int i=0; i<S.n-1; i++){
//        	S.arr[i]=S.arr[i+1];
//		} 
		S.n--;
    }
}


int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}




