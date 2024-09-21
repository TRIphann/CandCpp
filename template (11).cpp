/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
string
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//###INSERT CODE HERE -

int trade(char c){
	if ((c>='A' && c<='Z')) return c-65;
	else if ((c >= 'a' && c <= 'z')) return c-97;
}



void MaHoaMatThu(char s[]){
	int length = strlen(s);
	if ((s[0]>='A' && s[0]<='Z')||(s[0] >= 'a' && s[0] <= 'z')) cout << trade(s[0]);
	else cout << s[0];
	for (int i=1; i<length; i++){
		if ((s[i]>='A' && s[i]<='Z')||(s[i] >= 'a' && s[i] <= 'z')){
			if (s[i-1]!=' '){
				cout << '.' << trade(s[i]);
			}
			else cout << trade(s[i]);
		}
		else if (s[i]==' ') cout << "-";
		else cout << s[i];
	}
}

int main()
{
    char s[100];
    cin.getline(s,99);
    cout<<"Chuoi vua nhap: "<<s;
    cout<<"\nChuoi sau khi duoc ma hoa: ";
    MaHoaMatThu(s);

    return 0;
}
