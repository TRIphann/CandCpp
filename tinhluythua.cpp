#include <iostream>

int main()
{
    int n;
    unsigned long long result = 1;

    std::cin >> n;

    // Vi?t code ? dây
    for (int i=0; i <= n; i++) {
        result = result * i;
    }

    std::cout << result;

    return 0;
}

