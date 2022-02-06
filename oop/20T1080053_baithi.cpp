#include <bits/stdc++.h>
using namespace std;

class Computer {
	private:
		string computerid;
		string manufacturer;
		int yearofmanufacture;
		float price;
	
	public:
		Computer();
		Computer(string _computerid, string _manufacturer, string _yearofmanufacture, float price);
		Computer(Computer &c);
		
		void SetComputerid(string _computerid);
		void SetManufacturer(string _manufacturer);
		void SetYearofmanufacture(int _yearofmanufacture);
		void SetPrice(float _price);
		void SetComputer(string _computerid, string _manufacturer, int _yearofmanufacture, float _price);
		
		string GetComputerid();
		string GetManufacturer();
		int GetYearofmanufacture();
		float GetPrice();
		
		void Input();
		void Output();
		
};

Computer::Computer() {
	computerid = "";
	manufacturer = "";
	yearofmanufacture = 0; 
	price = 0;
}

Computer::Computer(string _computerid, string _manufacturer, int _yearofmanufacture, float _price) {
	computerid = _computerid;
	manufacturer = _manufacturer;
	yearofmanufacture = _yearofmanufacture;
	price = _price;
}

Computer::Computer(Computer &c) {
	computerid = c.computerid;
	manufacturer = c.manufacturer;
	yearofmanufacture = c.yearofmanufacture;
	price = c.price;
}

void Computer::SetComputerid(string _computerid) {
	computerid = _computerid;
}

void Computer::SetManufacturer(string _manufacturer) {
	manufacturer = _manufacturer;
}

void Computer::SetYearofmanufacture(int _yearofmanufacture) {
	yearofmanufacture = _yearofmanufacture;
}

void Computer::SetPrice (float _price ) {
	price  = _price;
}

void Computer::SetComputer(string _computerid, string _manufacturer, int _yearofmanufacture, float _price) {
	computerid = _computerid;
	manufacturer = _manufacturer;
	yearofmanufacture = _yearofmanufacture;
	price = _price
}

string Computer::GetComputerid() {
	return computerid();
}

string Computer::GetManufacturer() {
	return manufacturer;
}

int Computer::GetYearofmanufacture() {
	return yearofmanufacture;
}

float Computer::GetPrice() {
	return price;
}

void Computer:Input() {
	cout<<"Enter ComputerID: ";
	fflush(stdin);
	getline(cin, computerid);
	cout<<"Enter Manufacturer: ";
	fflush(stdin);
	getline(cin, manufacturer);
	cout<<"Enter Year Of Manufacture: ";
	cin>>yearofmanufacture;
	cout<<"Enter Price: ";
	cin>>price;
}

void Compter::Output() {
	cout<<"ComputerID: "<<computerid<<endl;
	cout<<"Manufacturer: "<<manufacturer<<endl;
	cout<<"Year Of Manufacture:" <<yearofmanufacture<<endl;
	cout<<"Price" <<price<<endl;
};


class Laptop: public Computer {
	private:
		float weight;
		float thickness;
		float screensize;
		
	public:
		Laptop() : Computer() {
			weight = 0;
			thickness = 0;
			screensize = 0;
		}
		Laptop(string _computerid, string _manufacturer, int _yearofmanufacture, float _price, float _weight, float _thickness, float _screensize) : Canbo( _computerid, _manufacturer, _yearofmanufacture, _price) {
			weight = _weight;
			thicknessc = _thickness;
			screensize = _screensize;
		}
		Laptop(Laptop &l) : Laptop(l) {
			weight = l.weight;
			thicknessc = l.thicknessc;
			screensize = l.screensize;	
		}
		
		void SetWeight(float _weight);
		void SetThicknessc(float _thicknessc);
		void SetScreensize(string _screensize);
		void SetLaptop(string _computerid, string _manufacturer, int _yearofmanufacture, float _price, float _weight, float _thickness, float _screensize);
			
		int GetWeight();
		int GetThicknessc();
		string GetScreensize();
		
		string operatingsystem();
		int numberofyearsofuse();
		int residualvalue();
		
		void Input();
		void Output();
		
		bool operator > (const Laptop &c) const;
		
};

void Laptop::SetWeight(float _weight) {
	weight = _weight;
}

void Laptop::SetThicknessc(float _thicknessc) {
	thicknessc = _thicknessc;
}

void Laptop::SetScreensize(string _screensize) {
	screensize = _screensize;
}

void Laptop::SetLaptop(string _computerid, string _manufacturer, int _yearofmanufacture, float _price, float _weight, float _thicknessc,float _screensize) {
	SetComputer(_computerid,_manufacturer,_yearofmanufacture,_price);
	weight = _weight;
	thicknessc = _thicknessc;
	screensize = _screensize;
}

float Laptop::GetWeight() {
	return weight;
}

float Laptop::GetThicknessc() {
	return thicknessc;
}

float Laptop::GetScreensize() {
	return screensize;
}

float Laptop::operatingsystem() {
	return operatingsystem;
}

int Laptop::numberofyearsofuse() {
	return numberofyearsofuse;
}

