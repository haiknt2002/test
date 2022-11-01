// neu lop A la ban cua lop B thi trong lop A duoc phep
// truy xuat den cac thanh phan private cua lop B

// quan he bao gom: 1 lop co thuoc tinh la doi tuong cua lop khac


/*
Xây dung lop laptop thuoc tính gom: model, hãng san xuat, 
giá, thoi gian bao hành. Các phuong thuc cua lop: 
hàm tao, phuong thuc toán tu nhap, xuat và các phuong thuc khác. 
Viet chuong trình nhap thông tin cho n laptop.
In danh sách theo thu tu tang dan cua giá. 
Tìm laptop duoi giá nhap vào tu bàn phím cua mot hãng san xuat cho truoc
*/
#include<bits/stdc++.h>
using namespace std;
class laptop{
    string model, hsx;
    long gia;
    int tgbh; //thoi gian bao hanh
    friend istream & operator>>(istream&, laptop&);
    friend ostream & operator<<(ostream&, const laptop&); 
    public:
        // laptop();
        laptop(string model = "none" , string hsx = "none", long gia = 0, int tgbh = 0 );
        long getgia(){
            return gia;
        }
        string gethsx(){
            return hsx;
        }
};
// laptop::laptop(){
//     this->model = "none" ;
//     this->hsx = "none"; 
//     this->gia = 0;
//     this->tgbh = 0 ;
// }
laptop::laptop(string model = "none" , string hsx = "none", long gia = 0, int tgbh = 0 ){
    this->model = model;
    this->hsx = hsx; 
    this->gia = gia;
    this->tgbh = tgbh ;
}
istream & operator>>(istream& Cin, laptop&lap){
    cout<<"Nhap model "; Cin>>lap.model;
    cout<<"Nhap hang san xuat "; Cin.ignore(1); getline(Cin,lap.hsx);
    cout<<"Nhap gia "; Cin>>lap.gia;
    cout<<"Nhap thoi gian bao hanh "; Cin>>lap.tgbh;
    return Cin;
}

ostream & operator<<(ostream&Cout, const laptop&lap){
    Cout<<lap.model<<lap.hsx<<" "<<lap.gia<<" "<<lap.tgbh;
    return Cout;
}
class ungdung{
    int n;
    laptop *ds;
    friend istream & operator>>(istream&, ungdung&);
    friend ostream & operator<<(ostream&, const ungdung&);
    public:
    friend void sapxep(ungdung &);
    friend void timkiem(ungdung &,const long&, const string&);
};
istream & operator>>(istream& Cin, ungdung&lap){
    cout<<"Nhap so laptop "; Cin>>lap.n;
    lap.ds= new laptop[lap.n];
    for(int i=0;i<lap.n;i++){
        cout<<"Nhap laptop thu "<<i+1<<endl;
        Cin>>lap.ds[i];
    }
    return Cin;
}

ostream &operator<<(ostream&Cout, const ungdung&lap){
    Cout<<endl;
    cout<<"\toan tu xuat của lop ung dung";
    for(int i=0;i<lap.n;i++)
    Cout<<lap.ds[i]<<endl;
    return Cout;
}
void sapxep(ungdung &x){
    cout<<"\nham sap xep";
    for(int i=0;i<x.n-1;i++)
        for(int j=i+1;j<x.n;j++)
            if(x.ds[i].getgia()>x.ds[j].getgia()){
            laptop tem=x.ds[i];
            x.ds[i]=x.ds[j];
            x.ds[j]=tem;
    }
}
void timkiem(ungdung &x,const long &gia, const string &hang){
    bool kq=false;
    cout<<"\nham tim kiem";
    for(int i=0;i<x.n;i++)
        if(x.ds[i].getgia()<=gia && x.ds[i].gethsx()==hang){
            kq=true;
            cout<<x.ds[i];
        }
    if(!kq) cout<<"\n Ko tim thay.\n"; 
}
int main(){
    ungdung x;
    cin>>x;
    sapxep(x);
    // x.sapxep();
    cout<<x;
    long giatim; string hangtim;
    cout<<"Nhap hang san xuat can tim: "; cin.ignore(1); getline(cin, hangtim); 
    cout<<"Nhap gia can tim: "; cin>>giatim;
    timkiem(x,giatim,hangtim);//x.timkiem(giatim,hangtim);
    return 0;
}