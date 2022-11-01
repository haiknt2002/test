#include<iostream>

using namespace std;

class Laptop{
    private:
        string model,manufacturer;
        float price;
        int guarantee;
    public:
        Laptop(string model = "" , string manufacturer = "" , float price = 0.0, int guarantee = 0){
            this->model= model;
            this->manufacturer=manufacturer;
            this->price=price;
            this->guarantee=guarantee;
        }
        friend istream & operator>>(istream&, Laptop&);
        friend ostream & operator<<(ostream&, const Laptop);

        float getPrice();
        string getManufacturer();   

};

istream & operator>>(istream& Cin, Laptop&lap){
    cout<<"Nhap model "; Cin>>lap.model;
    cout<<"Nhap hang san xuat "; Cin.ignore(1); getline(Cin,lap.manufacturer);
    cout<<"Nhap gia "; Cin>>lap.price;
    cout<<"Nhap thoi gian bao hanh "; Cin>>lap.guarantee;
    return Cin;
}

ostream & operator<<(ostream&Cout, const Laptop lap){
    Cout<<lap.model << " "<<lap.manufacturer<<" "<<lap.price<<" "<<lap.guarantee<< endl;
    return Cout;
} 
float Laptop :: getPrice(){
    return price;
}
string Laptop :: getManufacturer(){
    return manufacturer;
}
class Application{
    private:
        int n;
        Laptop *list;
    public:
        Application(){
            n = 0;
            list = NULL;
        }
        Application(int n){
            this->n=n;
            list = new Laptop[n];
        }
        friend istream & operator>>(istream&, Application&);
        friend ostream & operator<<(ostream&, const Application);
        friend void Swap(Application &);
        friend void Find(Application &x,const float price);
};

istream & operator>>(istream& Cin, Application& x){
    cout<< " Input number of laptop: " ; Cin >> x.n;
    x.list = new Laptop[x.n];
    for(int i = 0; i < x.n ; ++i){
        cout << "Input information the Laptop number " << i << " :" << endl;
        Cin >> x.list[i];
    }
    return Cin;
}

ostream & operator<<(ostream&Cout, const Application x){
    for(int i = 0; i < x.n ; ++i){
        Cout << x.list[i];
    }
    return Cout;
}
void Swap(Application &x){
    for(int i = 0 ; i < x.n-1 ; ++i){
        for(int j = i+1 ; j<x.n ; ++j){
            if(x.list[i].getPrice() > x.list[j].getPrice()){
                Laptop a = x.list[i];
                x.list[i] = x.list[j];
                x.list[j] = a;
            }
        }      
    }
}
void Find(Application &x,const float price){
    bool check=false;
    for(int i = 0 ; i < x.n ; ++i)
        if(x.list[i].getPrice() <= price){
            check=true;
            cout<<x.list[i];
        }
    if(!check) cout<<"\nNot Found.\n"; 
}

int main(){
    Application x;
    cin>>x;
    Swap(x);
    cout<<x;
    long giatim;
    cout<<"Nhap gia can tim: "; cin>>giatim;
    Find(x,giatim);
    return 0;
}