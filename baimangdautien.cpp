#include <iostream>

int main()
{
    int n, numbers[10];

    // Vi?t code ? d�y
    std::cin >> n;
    for (int i=0; i<n; i++) {
         std::cin >> numbers[i];
    }
    for (int i=0; i<n; i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}

