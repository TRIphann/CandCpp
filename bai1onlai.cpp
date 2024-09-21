#include<iostream>

using namespace std;

void nhap(int *arr, int size){
	for (int i=0; i<size; i++){
		cin >> arr[i];
	}
}

void them(int* &arr, int &size, int new_element){
	int new_size=size+1;
	int *new_arr = new int[new_size];
	
	for (int i=0; i< size; i++){
		new_arr[i]=arr[i];
	}
	
	new_arr[size]= new_element;
	
	delete[] arr;
	arr=new_arr;
	size=new_size;
}

void xuat(int *arr, int n){
	for (int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int n,n1;
	
	cout << "n= ";
	cin>> n;
	int *arr=new int[n];
	cout << "nhap mang: ";
	nhap(arr,n);
	cout << "nhap phan tu moi: ";
	cin >>n1;
	them(arr,n,n1);
	xuat(arr,n);
}
