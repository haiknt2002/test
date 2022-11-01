#include<iostream>

using namespace std;

class Shoe
{
    private:
        int id;
        int style;
        string origin;
        float cost;
    public:
        
        Shoe(int id = 0, int style = 0,string origin ="" , float cost = 0.0){
            this->id = id;
            this->style= style;
            this->origin=origin;
            this->cost=cost;
        }
        friend istream& operator>> (istream& , Shoe&);
        friend ostream& operator<< (ostream&, Shoe);

        //set
        void setID(int id);
        void setStyle(int style);
        void setOrigin(string origin);
        void setCost(float cost);
        //get
        int getId();
        int getStyle();
        string getOrigin();
        float getCost();


};
istream& operator>> (istream& in, Shoe& a){
    cout<< "Input information:" << endl;
    cout << "ID: "; in >> a.id;
    cout << "Style: "; in >> a.style;
    cout << "Origin: ";getline(in,a.origin);
    cout << "Cost: "; in >> a.cost;
    return in;
}
ostream& operator<< (ostream& out, Shoe a){
    out << "Information: " << endl;
    out << a.id << " " << a.style << " " << a.origin << " " << a.cost << endl;
    return out;
}
void Shoe :: setID(int id){
    this->id = id;
}
void Shoe :: setStyle(int style){
    this->style=style;
}
void Shoe :: setOrigin(string origin){
    this->origin=origin;
}
void Shoe :: setCost(float cost){
    this->cost=cost;
}
int Shoe :: getId(){
    return id;
}
int Shoe :: getStyle(){
    return style;
}
string Shoe :: getOrigin(){
    return origin;
}
float Shoe :: getCost(){
    return cost;
}


class Application{
    private:
        int n;
        Shoe *list;
    public:
        Application(){
            n = 0;
            list = NULL;
        }
        Application(int n){
            this->n=n;
            list = new Shoe[n];
        }
        friend istream & operator>>(istream&, Application&);
        friend ostream & operator<<(ostream&, const Application);
        friend void statistical(Application&);
};
istream & operator>>(istream& Cin, Application& x){
    cout<< " Input number of Shoe: " ; Cin >> x.n;
    x.list = new Shoe[x.n];
    for(int i = 0; i < x.n ; ++i){
        cout << "Input information the Shoe number " << i << " :" << endl;
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

void statistical(Application &x){
    int countType[] = {0,0,0,0};
    for(int j = 0 ; j < 4 ; ++j){
			for(int i = 0 ; i < x.n; ++i){
                if(x.list[i].getStyle() == j+1){
                	++countType[j];
                }
		    }
		cout<<"The numbers of StyleShoe "<< j+1 <<": "<<countType[j]<<endl;
		}
}
int main(){
    Application a;
    cin >> a;
    cout << a;
    statistical(a);
    return 0;
}