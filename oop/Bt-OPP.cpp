#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;

class Person
{
	private:
		string _HoDem;
		string _Ten;
		int _Tuoi;
	public:
		Person();
		Person(string HoDem, string Ten, int Tuoi);
		Person(Person &p);
		
		void SetHoDem(string _HoDem);
		void SetTen(string _Ten);
		void SetTuoi(int _Tuoi);
		void SetPerson(string HoDem, string Ten, int Tuoi);
		
		string GetHoDem();
		string GetTen();
		int GetTuoi();
		
		void Input();
		void Output();
		
		bool operator > (const Person &p) const;
};

Person::Person()
{
	_HoDem = "";
	_Ten = "";
	_Tuoi = -1;
}

Person::Person(string HoDem, string Ten, int Tuoi)
{
	SetPerson(HoDem, Ten, Tuoi);
}

Person::Person(Person &p)
{
	_HoDem = p._HoDem;
	_Ten = p._Ten;
	_Tuoi = p._Tuoi;
}
		
void Person::SetHoDem(string _HoDem)
{
	_HoDem = HoDem;
}

void Person::SetTen(string _Ten)
{
	_Ten = Ten;
}

void Person::SetTuoi(int _Tuoi)
{
	if(Tuoi < 0)
		_Tuoi = -1;
	else
		_Tuoi = Tuoi;
}

void Person::SetPerson(string HoDem, string Ten, int Tuoi)
{
	_HoDem = HoDem;
	_Ten = Ten;
	SetPerson(Tuoi);
}

string Person::GetHoDem()
{
	return _HoDem;
}

string Person::GetTen()
{
	return _Ten;
}

int Person::GetTuoi()
{
	return _Tuoi;
}
		
void Person::Input()
{
	cout << "Nhap Ho Dem: ";
	fflush(std);
	getline(cin, _HoDem);
	cout << "Nhap Ten: ";
	fflush(std);
	getline(cin, _Ten);
	cout << "Nhap Tuoi: ";
	cin >> _Tuoi;
}

void Person::Output()
{
	cout << "Ho Dem: " << _HoDem << endl;
	cout << "Ten: " << _Ten << endl;
	if (_Tuoi != -1)
		cout << "Tuoi: " << _Tuoi ;
	else
		cout << "Tuoi: ######" << endl;
}
		
bool Person::operator > (const Person &p) const
{
	return (_HoDem > p._HoDem);
}

class Officer : public Person
{
	private: 
		string _MaSo;
		float _Luong;
		float _TienBaoHiem;
	public:
		Officer();
		Officer(string MaSo, float Luong, float TienBaoHiem);
		Officer(Officer &p);
		
		void SetMaSo(string _MaSo);
		void SetLuong(float _Luong);
		void SetTienBaoHiem(float _TienBaoHiem);
		void SetOfficer(string HoDem, string Ten, int Tuoi, string MaSo, float Luong, float TienBaoHiem);
		
		string GetMaSo();
		float GetLuong();
		float GetTienBaoHiem();
		
		void Input();
		void Output();
		
		bool operator > (const Officer &p) const;
};

Officer::Officer()
{
	_MaSo = "";
	_Luong = -1;
	_TienBaoHiem = -1;
}

Officer::Officer(string MaSo, float Luong, float TienBaoHiem)
{
	SetOfficer(MaSo, Luong, TienBaoHiem);
}

Officer::Officer(Officer &p)
{
	_MaSo = p._MaSo;
	_Luong = p._Luong;
	_TienBaoHiem = p._TienBaoHiem;
}
		
void Officer::SetMaSo(string _MaSo)
{
	_MaSo = MaSo;
}

void Officer::SetLuong(float _Luong)
{
	if(Luong < 0)
		_Luong = -1;
	else
		_Luong = Luong
}

void Officer::SetTienBaoHiem(float _TienBaoHiem)
{
	if(TienBaoHiem < 0)
		_TienBaoHiem = -1;
	else
		_TienBaoHiem = TienBaoHiem;
}

void Officer::SetOfficer(string HoDem, string Ten, int Tuoi, string MaSo, float Luong, float TienBaoHiem)
{
	SetPerson(HoDem, Ten, Tuoi);
	_Maso = Maso
	SetLuong(Luong);
	SetTienBaoHiem(TienBaoHiem); 
}

string Officer::GetMaSo()
{
	return _MaSo;
}

string Officer::GetLuong()
{
	return _Luong;
}

int Officer::GetTienBaoHiem()
{
	return _TienBaoHiem;
}
		
void Officer::Input()
{
	Person::Input();
	cout << "Nhap Ma So: ";
	cin >> _MaSo;
	cout << "Nhap Luong: ";
	cin >> _Luong;
	cout << "Nhap Tien Bao Hiem: ";
	cin >> _TienBaoHiem;
}

void Officer::Output()
{
	cout << "Ma So: " << _MaSo << endl;
	if (_Luong != -1)
		cout << "Luong: " << _Luong ;
	else
		cout << "Luong: ######" << endl;
		
	if (_TienBaoHiem != -1)
		cout << "Tien Bao Hiem: " << _TienBaoHiem ;
	else
		cout << "Tien Bao Hiem: ######" << endl;
}

void SapXepOfficer(Officer o[], int n)
{
	cout<<"======= Sap xep tang dan theo ten va ho dem ======="<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(o[i] > o[j]){
				Officer temp = o[i];
				o[i] = o[j];
				o[j] = temp;
			}
		}
	}
	for(int i=0; i<n; i++){
		o[i].Output();
	}
}

void TienThucNhan(Officer o[], int n)
{
	cout<<"======= Nhung can bo co so tien thuc nhan cao nhat ======="<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	long TienTN = 0;
	for(int i=0; i<n; i++){
		float tienthucnhan = o[i].TienThucNhan();
		if(tienthucnhan > MaxTienTN){
			MaxTienTN = o[i].TienThucNhan();
		}
	} 	
	for(int i=0; i<n; i++){
		float tienthucnhan = o[i].TienThucNhan();
		if(tienthucnhan == MaxTienTN){
			o[i].Output();
		}
	}
}

int main()
{
	int n;
	do{
		cout<<"Nhap so luong can bo: ";
		cin>>n;
		if(n>50)
			cout<<"Nhap qua so luong gioi han - Nhap lai !"<<endl;
		cout<<"------------------------------------------------------------"<<endl;
	}while(n>50);
	
	Officer *o = new Officer[n];
	for(int i=0; i<n; i++){
		o[i].Input();
		cout<<"------------------------------------------------------------"<<endl;
	}
	
	cout<<"======= Danh sach can bo ======="<<endl;
	cout<<"------------------------------------------------------------"<<endl;
	for(int i=0; i<n; i++){
		o[i].Output();
	}
	
	SapXepOfficer(o, n);
	MaxTienThucNhan(o, n);
	
	return 0;
}







