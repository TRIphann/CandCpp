#include <iostream>

bool is_prime(int n)
{
    // H�y ho�n th�nh h�m 
    // theo y�u c?u d? b�i nh�
	int sodem=0,a=0,b=1;
    for (int i=2; i<n; i++){
    	if (n%i==0){
    		sodem++;
		}
	}
	if (sodem==0) return b;
	else return a;
}

int main()
{
    int n;

    std::cin >> n;

    std::cout << is_prime(n);

    return 0;
}

