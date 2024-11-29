#include<iostream>
#include<vector>
#include <algorithm>
#include <iomanip>
#include<fstream>
using namespace std;

class ds;
class Car{
	private:
		string ten, hang;
		int id,price;
        int count;
	public:
		friend istream &operator>>(istream &is, Car &x);
		friend ostream &operator << (ostream &os, Car &x);
		bool operator < (const Car &x){
			return this->id < x.id;
		}
		friend class ds;
	};

istream &operator >> (istream &is, Car &x){
	cout << "Nhap ten xe:";
	is.ignore();
	getline(cin, x.ten);
	cout << "Nhap hang xe:";
	getline(cin,x.hang);
	cout << "Nhap id:";
	is >> x.id;
	cout << "Nhap gia:";
	is >> x.price;
	return is;
}
ostream &operator << (ostream &os, Car x){
	os <<left<< x.ten << setw(20) << x.hang << setw(20)<< x.id<<setw(20)<< x.price <<endl; 
	return os;
}

class ds{
	private:
		vector<Car> v;
	public:
	    void nhapdsf();
	    void in1(Car);
		void inds();
		void inf();
		void xx();
		void maxPrice();
		void searchName();
		void push_back();
		void Erase();
		bool Empty();
		void changePrice();
};

void ds::nhapdsf(){
    ifstream f("GaracuaNang.txt");  
    if (!f.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    int n;
    f >> n;
    f.ignore();
    for(int i=1; i<=n; i++){
        Car x;
        getline(f, x.ten,'#');
        getline(f, x.hang, '#');
        f >> x.id;
        f.ignore();
        f >>x.price;
        f.ignore();
        v.push_back(x);
    }
    f.close();
}

void ds::in1(Car x){
	cout << "-Ten: "<< x.ten<< endl<< "-Hang: "<< x.hang<< endl<< "-ID: "<< x.id<< endl<< "-Gia: "<<x.price;  
}

void ds::inds(){
	if(v.empty()){
		cout << "Gara rong!"<<endl;
		return;
	}
	string header[]={"STT", "Ten", "Hang", "ID", "Gia"};
	cout<<left<<setw(5)<<header[0]<<setw(20) <<header[1]<<setw(20)<<header[2]<<setw(20)<< header[3]<<setw(20)<<header[4];
	cout<<endl;
	for(int i=0; i<v.size(); i++){
		cout <<left<<setw(5)<<i+1<<setw(20)<< v[i];
	}
}

void ds::inf() {
    ofstream f("GaracuaNang.txt");  
    if (!f.is_open()) {
        cout << "Khong the mo file de ghi!" << endl;
        return;
    }
    
    f << v.size() << endl;  
    for (const Car& x : v) {
        f << x.ten << "#" << x.hang << "#" << x.id << "#" << x.price << endl;
    }
    f.close();
    cout << "Da luu danh sach xe vao file!" << endl;
}

void ds::xx(){
	if(v.empty()){
		cout <<"Gara rong!"<<endl;
		return;
	}
	sort(v.begin(),v.end());
}

void ds::maxPrice(){
	if(v.empty()){
		cout << "Gara rong!"<< endl;
		return;
	}
	Car max=v[0];
	for(Car x:v){
		if(x.price > max.price) max=x;
	}
	cout << "Xe co gia cao nhat la: "<<endl;
	in1(max);
}

void ds::searchName(){
	string str;
	cout << "Nhap ten xe can xem thong tin:";
	cin.ignore();	
	getline(cin,str);
	int kt=0;
	for(Car x:v){
		if(x.ten==str) {  
		    in1(x);
		    kt++;
			}
	}
	if(kt==0) cout << "Khong tim thay xe "<< str<<endl;
} 

void ds::push_back(){
	Car x;
	cout << "Nhap du lieu xe muon them:"<< endl;
	cin >> x;
	v.push_back(x);
}

void ds::Erase(){
	cout << "Nhap ten xe muon xoa: ";
	string str;
	cin.ignore();
	getline(cin,str);
	for(auto it=v.begin();it!=v.end();it++){
		if(it->ten==str){
			v.erase(it);
			cout << "Da xoa xe "<<str;
			break;
		}
	}
}

void ds::changePrice(){
    string chN;
	cout << "Nhap ten xe muon thay doi gia: ";
	cin.ignore();
	getline(cin,chN);
	bool kt=true;
	for(auto it=v.begin(); it!=v.end(); it++){
		if(it->ten==chN){
			int nPrice;
	        cout <<"Nhap gia moi: ";
	        cin >> nPrice;
			it->price=nPrice;
			kt=false;
		}
	}
	if(kt) cout << "Khong tim thay xe!"<< endl;	
}

bool ds::Empty(){
	return v.empty(); 
}



class app{
	private:
		ds list;
	public:
		app(){
            list.nhapdsf();
        };
		void menu();
		~app(){};
};
void app::menu(){
    int choice;
	do{
	system("cls");
    list.inds();
	cout << "---Quan li xe---"<<endl;
	cout << "1. In danh sach xe theo thu tu tang dan ID" << endl;
	cout << "2. Xe co gia cao nhat"<<endl;
	cout << "3. Tim xe theo ten"<<endl;
	cout << "4. Thay doi gia xe" << endl;
	cout << "5. Them xe"<<endl;
	cout << "6. Xoa xe"<<endl;
	cout << "7. Thoat chuong trinh" << endl;
	cout <<endl<<"-----------"<< endl <<"Nhap lua chon cua ban: ";
	cin >> choice;
	switch(choice){
		case 1:{
			cout <<"Danh sach xe da duoc in theo ID tang dan";
			list.xx();
			break;
		}
		case 2:{
			list.maxPrice();
			break;
		}
		case 3:{
			list.searchName();
			break;
		}
		case 4:{
			list.changePrice();
			break;
		}
		case 5:{
			list.push_back();
			break;
		}
		case 6:{
			list.Erase();
			break;
		}
		case 7:{
			list.inf();
			cout << "Hen gap lai!";
			return;
		}
		default:{
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
	}
	cout <<endl<<"-----------" <<endl;
	cout << "Nhan phim bat ky de tiep tuc...";
    cin.ignore();
    cin.get();
    } while (true);
}
int main(){
	app a;
	a.menu();
	return 0;
}
