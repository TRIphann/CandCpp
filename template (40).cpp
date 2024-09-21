#include <iostream>
#include <stack>

void DecimalToBinary(int n, std::stack<int>& S) {
    while (n > 0) {
        S.push(n % 2);
        n /= 2;
    }
}

void printStack(std::stack<int> S) {
    while (!S.empty()) {
        std::cout << S.top();
        S.pop();
    }
    std::cout << std::endl;
}

int main() {
    int n=-1;
    std::cin >> n;

    if (n < 0) {
        std::cout << std::endl;
    }

    std::stack<int> S;
    DecimalToBinary(n, S);
    
    printStack(S);

    return 0;
}

