#include <iostream>

int main () {
	int n,mang[10],h,doi;
	std::cin >> n;
	 
	for (int i=0; i<n; i++) {
			std::cin >> mang[i];
		}
	for (int a=(n-1); a>0; a--) {
		for (int b=0; b<a; b++) {
			if (mang[b]>mang[b+1]) {
				doi=mang[b];
				mang[b]=mang[b+1];
				mang[b+1]=doi;
			} 
		}
	} 
	for (int i=0; i<n; i++) {
			std::cout << mang[i]<<" ";
		}
}


