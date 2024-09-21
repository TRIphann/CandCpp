/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
string
###End banned keyword*/

#include <iostream>
#include<cstring>

using namespace std;

//###INSERT CODE HERE -

bool check(char c){
	if (c >= 'a' && c <= 'z') return 1;
	return 0;
}

int main()
{
    char s[256];
    cin.getline(s,256);
    int length = strlen(s);
    int stat=0,count=0;
    while (s[stat]==' '){
    	stat++;
	}
	bool ctn=false;
	for (int i=stat; i<length; i++){
		if (!ctn && !check(s[i])) ctn=true;
		if (s[i]==' ') ctn=false;
		if (!ctn&&check(s[i])&&s[i+1]==' ') count++;
	}
	
	bool check1 = true;
	if (s[length-1]==' ') check1= false;
	
    while (length > 1 && s[length - 1] != ' ') {
        if (!check(s[length-1])){
			check1=false;
			break;
		}
        length--;
    }

    if (check1&&length>0) {
        count++;
    }
	cout << count;
    return 0;
}
