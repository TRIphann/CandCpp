/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
using namespace std;



//###INSERT CODE HERE -

int main()
{
    int na, a[100],nb, b[100];
    cin>>na;
    inputArray(a,na);
    cout<<"Mang a:"<<endl;
    outputArray(a,na);
    cout<<endl;
    int m;cin>>m;
    filterPrimes(a,na,b,nb,m); //tao ra mang b bang cach tach m so nguyen to tu a
    cout<<"Mang b:"<<endl;
    outputArray(b,nb);

    return 0;
}
