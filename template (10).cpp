
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include<iostream>
#include<cstring>
using namespace std;



int countWords(char s[]){
	int count=0,i=0;
	bool chu=false;
	while (s[i]!='\0'){
		if ((s[i]>='A' && s[i]<='Z')||(s[i] >= 'a' && s[i] <= 'z')) {
			chu=true;
		}
		else if (s[i]==' '){
			if (chu) count ++;
			chu=false;
		}
		i++;
	}
	if (chu) count ++;
	return count;
} 

int main()
{

   char s[256];
   cin.getline(s, 256);

   cout << countWords(s) << endl;
    return 0;
}
