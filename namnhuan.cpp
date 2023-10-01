#include <iostream>

int main()
{
    int year;

    std::cin >> year;

    // Viết code ở đây
    if ((year%400==0) || ((year%4==0) && (year%100!=0))) {
        std::cout << year << " la nam nhuan";
    }
    else { std::cout << year << " khong phai la nam nhuan";}

    return 0;
}
