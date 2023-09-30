#include <iostream>

int main()
{
    int m, n, numbers[10][10];

    std::cin >> m >> n;

    // Vi?t code ? ðây
 
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            std::cin >>numbers[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            std::cout << numbers[i][j] <<" ";
        }
        std::cout << "\n";
    }
    

    return 0;
}

