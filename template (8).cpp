/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/
#include <iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -

void transformString(char s1[], char s2[]){
	int length = strlen(s1);
    for (int i = 0; i < length; i++) {
        char c = s1[i];
	    if (c>='A' && c<='Z'){
	    	s2[i] = c + 32;
		}
		else if (c >= 'a' && c <= 'z') {
            s2[i] = c - 32;
        }
        else if (c >= '0' && c <= '9') {
            s2[i] = c;
        } 
        else if (c == ' ') {
            s2[i] = c;
        }
        else {
            s2[i] = '*';
        }
        s2[length] = '\0';
	}
}

int main()
{
    char s1[200], s2[200];
    cout<<"Nhap chuoi = ";
    cin.getline(s1, 199);
    transformString(s1, s2); //khong dung duoc ham toupper, tolower
    cout<<"\ns1="<<s1<<endl;
    cout<<"s2="<<s2;

    return 0;
}

