#include <iostream>

bool is_prime(int n)
{
    // Hãy hoàn thành hàm 
    // theo yêu c?u d? bài nhé
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

