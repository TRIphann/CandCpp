#include <iostream>

int main()
{
    int year, month;

    std::cin >> year >> month;

    // Viết code ở đây
    if ( (year%400==0) || (year%4==0)&&(year%100!=0)){
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
           std::cout <<"Thang "<<month<<" nam "<<year<<" co 31 ngay ";
           break;
        case 4:
        case 6:
        case 9:
        case 11:
           std::cout <<"Thang "<<month<<" nam "<<year<<" co 30 ngay ";
           break;
        case 2:
           std::cout <<"Thang "<<month<<" nam "<<year<<" co 28 ngay ";
           break;
        default: std::cout << "Thang khong hop le";
        
    }
    }
    else {
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
           std::cout <<"Thang "<<month<<" nam "<<year<<" co 31 ngay ";
           break;
        case 4:
        case 6:
        case 9:
        case 11:
           std::cout <<"Thang "<<month<<" nam "<<year<<" co 30 ngay ";
           break;
        case 2:
           std::cout <<"Thang "<<month<<" nam "<<year<<" co 29 ngay ";
           break;
        default: std::cout << "Thang khong hop le";
        
    }
    
    }

    return 0;
}
