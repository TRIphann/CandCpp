#include <iostream>

int main() {
    char c = 'A'; // Ví d? v?i k? t? 'A'
    int ascii_value = static_cast<int>(c); // Chuy?n k? t? thành m? ASCII

    std::cout << "M? ASCII c?a '" << c << "' là: " << ascii_value << std::endl;

    return 0;
}

