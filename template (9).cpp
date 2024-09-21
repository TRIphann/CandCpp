/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -

void  ThayTheKyTuChuCai(char s[], char x){
	int length = strlen(s);
    for (int i = 0; i < length; i++) {
		if ((s[i]>='A' && s[i]<='Z')||(s[i] >= 'a' && s[i] <= 'z')) s[i]=x;
	}
}

int main()
{
    char s[256];
    cin.getline(s,256);
    char x;
    cin>>x;
    ThayTheKyTuChuCai(s,x); // Ham thay the cac ky tu chu cai co trong chuoi s thanh ky tu x
    cout<<s;
    return 0;
}
