#include<iostream>;
#include<cstdlib>
#include<windows.h>

using namespace std;

struct Product{
	int price;
	int quantity;
	
	friend istream& operator>>(istream &is, Product &product){
		is >> product.price;
		is >> product.quantity;
		
		return is;
	}
	
	friend ostream& operator<<(ostream &os, Product product){
		os << product.price << "\n";
		os << product.quantity;
		
		return os;
	}
};

int main(){
	Product product;
	cin >> product;
	cout << product;
	
	char computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName);
	if (GetComputerName(computerName, &size)) 
	{
		printf("\nTen may tinh la: %s\n", computerName);
	}
	return 0;
}
