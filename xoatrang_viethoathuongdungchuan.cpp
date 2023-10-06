#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string str;
    int i=0;

    getline(cin, str);

    // Vi?t code ? dây

    while (str[0] == ' ') {
        str.erase(0, 1);
    }
    while (str[str.length()-1] == ' ') {
    	str.erase(str[str.length()] -1,1);
	}
	
	while (i < str.length()) {
		if (str[i] == ' ' && str[i+1] == ' ') {
			str.erase(i, 1);
		}
		else { i++;
		}	
	} 
	
	for (int i=0; i<str.length() ; i++) {
		str[i]=tolower(str[i]); 
	}
	str[0]=toupper(str[0]);
	for (int i=0; i<str.length() -1 ; i++) {
		if (str[i]== ' '){
			str[i+1]=toupper(str[i+1]); 
	}
	}
	

	cout << str;
    

    return 0;
}

