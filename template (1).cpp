#include <iostream>

int main() {
    char c = 'A'; // V� d? v?i k? t? 'A'
    int ascii_value = static_cast<int>(c); // Chuy?n k? t? th�nh m? ASCII

    std::cout << "M? ASCII c?a '" << c << "' l�: " << ascii_value << std::endl;

    return 0;
}

