#include <iostream> 

using namespace std;

void input_arr(int *arr, int size){
	for (int i=0; i<size; i++){
		cin >> arr[i];
	}
}

void delete_element (int* &arr, int &size, int local){
	int new_size = size-1;
	int *new_arr = new int[new_size];
	int j=0;
	for (int i=0; i<new_size; i++){
		if (local!=j) {
			new_arr[i]=arr[j];
		}
		else {
			j++;
			new_arr[i]=arr[j];
		}
		j++;
	}
	
	delete[] arr;
	arr=new_arr;
	size=new_size;
}

void output_arr (int *arr, int size) {
	for (int i=0; i<size; i++){
		cout<< arr[i] << " ";
	}
}

void input_mid (int* &arr, int &size, int local, int new_element){
	int new_size=size+1;
	int *new_arr=new int(new_size);
	int j=0;
	for (int i=0; i<new_size; i++){
		if(i!=local) {
		new_arr[i]=arr[j];
		j++;}
		else {
			new_arr[i]=new_element;
		}
	}
	delete[] arr;
	arr=new_arr;
	size=new_size;
} 

int main(){
	int n,local,local1,n1;
	cout <<"nhap n: "; cin >> n;
	cout <<"nhap mang: ";
	int *arr = new int[n];
	input_arr(arr,n);
	cout <<"nhap vi tri xoa: "; cin >> local;
	delete_element (arr,n,local);
	output_arr(arr,n);
	cout << "nhap vi tri them: "; cin >> local1;
	cout << "gia tri moi: "; cin>>n1;
	input_mid(arr,n,local1,n1);
	output_arr(arr,n);
}
