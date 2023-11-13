#include <iostream>
using namespace std;

int main() {
	int nu=-1,nam=-1,btc=-1,nhaplai=0,sodoi;
	while ((nam<0) || (nu<0) || (btc<0) || (nam>100) || (nu>100) || (nam+nu<btc)) {
		if (nhaplai>0) {
			cout << "nhap lai: ";
		}
		nhaplai++;
		cin >> nu >> nam >>btc;

}
	
	if (btc==0) {
		if (nam==0){
			cout <<"0";
		}
		else {
			int tamthoi=nu/(nam*2);
			cout << tamthoi;
		}
	}
	else {
		if (nam*2<nu){
			btc=btc-(nu%(2*nam));
		}
		else {
			if (nu%2!=0){ 
				nu=nu-1;
				btc=btc-1;
			} 
			btc=btc-(nam-nu/2);
		}
		//cout << nu<< " " << nam<<" " << btc<< " "<< btc/3;
		if (nam*2>nu) sodoi=nu/2;
		else sodoi=nam;
		
		if (btc<=0) cout << sodoi;
		else {
			if (btc%3!=0) sodoi=sodoi-(btc/3 +1);
			else sodoi=sodoi-(btc/3);

			cout << sodoi;
		}
		
	}

	
} 
