#include<iostream>
using namespace std;
int main (){
	int nb=5,count=10;
	int* pNb = &nb;     
	int* pCount = &count;
	*pNb = *pCount;
	cout << nb << count;
}
