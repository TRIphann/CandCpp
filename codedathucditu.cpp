#include <iostream>
#include <cstring>
#include <string>
#include<cmath>
using namespace std;

struct node{
	int heSo, soMu;
	node*pNext;
};
struct List{
	node* pHead, *pTail;
};
void Init(List &L){
    L.pHead=L.pTail=NULL;
}
node* getNode(int heSo, int soMu){//tao 1 node la bien dong
	node *p= new node;//bien da tao
	p->heSo=heSo;
    p->soMu=soMu;
	p->pNext=NULL;
	return p;
}
void addTail(List &L, int heSo, int soMu){
 	node* p=getNode(heSo, soMu);
 	//B2:Kiem tra thwur co rong khong
 	if(L.pHead==NULL){
 	L.pHead=L.pTail=p;
    }else
 {
 	L.pTail->pNext=p;
 	L.pTail=p;
 }
}
class DaThuc{
    private:
    List L;
    public:
    DaThuc(){
    Init(L);
    }

 void Nhap( int n){
   cout<<"Nhap vao n: ";//n la so mu lon nhat
   cin>>n;
   for(int i=0; i<n; i++){
    int heSo, soMu;
    cout<<"Nhap he so va so mu cua hang tu"<<" "<<i+1<<": ";
    cin>>heSo>>soMu;
    addTail(L,heSo, soMu);
   }
 }
   void Xuat(){
 if(L.pHead==NULL){
        cout<<"Da thuc rong";
        return;
    }
    node* p=L.pHead;
    while(p!=NULL){
        cout<<p->heSo<<"x"<<"^"<<p->soMu;
        p=p->pNext;
        if(p!=NULL && p->heSo>=0){
            cout<<"+";
        }
    }
    cout<<endl;
}
int Giatri(List L,float x){
	float giatri=0.0;
	node* p=L.pHead;
	while(p!=NULL){
		giatri+=p->heSo*pow(x,p->soMu);
		p=p->pNext;
	}
}
   };
int main()
{
    DaThuc DT;
    int n;
    DT.Nhap(n);
    cout<<"Da Thuc vua nhap la: "<<endl;
    DT.Xuat();
    float x;
    cout<<"Nhap vao gia tri x: ";
    cin>>x;
    float giatri=DT.Giatri(,x);
    cout<<"Gia tri cua da thu tai x= "<<x<<" "<<"la: "<<giatri<<endl;
    
    return 0;
}
