#include <iostream>

int main()
{
    float tong_tien, luong_co_ban;

    std::cin >> tong_tien >> luong_co_ban;
    
    // Viết code ở đây
    if (tong_tien <= luong_co_ban) {
        std::cout << "thuc linh: "<< tong_tien;
    }
    else { std::cout << "thuc linh: " << tong_tien-((tong_tien-luong_co_ban)*0.1);}

    return 0;
}
