#include <iostream>

int main()
{
    int n;
    char characters[10];

    std::cin >> n;

    // Vi?t code ? ðây
    for (int i=0; i<n; i++) {
    	std::cout << "nhap characters["<<i<<"] "; 
        std::cin >> characters[i];
    }

    for (int a=n-1; a>0; a--) {
        for (int b=0; b<a; b++) {
        	int c=static_cast<int>(characters[b]);
        	int d=static_cast<int>(characters[b+1]);
            if (c>d) {
                char doi=characters[b];
                characters[b]=characters[b+1];
                characters[b+1]=doi;
            }
        }
    }
    for (int i=0; i<n; i++) {
    	std::cout << characters[i]<<" ";
	}

    return 0;
}

