//Nguyen Quoc Trung. MSV:20T1080053//

#include<bits/stdc++.h>
using namespace std;

class Phone
{
	private:
		string _NamePhone;
		string _Manufacturer;
		float _OriginalCost;
		int _YearOfAppearance;
	
	public:
		Phone()
		{
			_NamePhone = "";
			_Manufacturer = "";
			_OriginalCost = 0  ;
			_YearOfAppearance = 0;
		}
		
		Phone (string NamePhone, string Manufacturer, float OriginalCost, int YearOfAppearance)
		{
			_NamePhone = NamePhone;
			_Manufacturer = Manufacturer;
			_OriginalCost = OriginalCost;
			_YearOfAppearance = YearOfAppearance;
		}
		
		Phone (Phone  & p)
		{
			_NamePhone = p._NamePhone;
			_Manufacturer = p._Manufacturer;
			_OriginalCost = p._OriginalCost;
			_YearOfAppearance = p._YearOfAppearance;
		}
		
		void SetNamePhone (string NamePhone)
		{
			_NamePhone = NamePhone;
		}
		
		void SetManufacturer (string Manufacturer)
		{
			_Manufacturer = Manufacturer;
		}
		
		void SetOriginalCost (int OriginalCost)
		{
			_OriginalCost = OriginalCost;
		}
		void SetYearOfAppearance (int YearOfAppearance)
		{
			_YearOfAppearance = YearOfAppearance;
		}
		
		void SetPhone ( string NamePhone, string Manufacturer, float OriginalCost, int YearOfAppearance)
		{
			_NamePhone = NamePhone;
			_Manufacturer = Manufacturer;
			_OriginalCost = OriginalCost;
			_YearOfAppearance = YearOfAppearance;
		}
		
		string GetNamePhone ()
		{
			return _NamePhone;
		}
		
		string GetManufacturer ()
		{
			return _Manufacturer;
		}
		
		float GetOriginalCost ()
		{
			return _OriginalCost;
		}
		int GetYearOfAppearance ()
		{
			return _YearOfAppearance;
		}
		
		void Input()
		{
			cout<<"Enter Name Phone : ";
			fflush(stdin);
			getline(cin, _NamePhone);
			cout<<"Enter Manufacturer : ";
			fflush(stdin);
			getline(cin, _Manufacturer);
			cout<<"Enter Original Cost : ";
			cin>>_OriginalCost;
			cout<<"Enter Year Of Appearance : ";
			cin>>_YearOfAppearance;
		}
		
		void Output()
		{
			cout<<"Name Phone: "<<_NamePhone <<endl;
			cout<<"Manufacturer: "<<_Manufacturer <<endl;
			cout << setprecision(2) << fixed <<" Original Cost: "<<_OriginalCost <<endl;
			cout<<"Year Of Appearance: "<<_YearOfAppearance <<endl;
		}
		
		bool operator > (const Phone &p) const {
			return (_NamePhone.compare(p._NamePhone) > 0);
		}
};

class SmartPhone : public Phone
{
	private:
		double _Speed;
		double _Size;
		int _Camera;
	
	public:
		SmartPhone() : Phone()
		{
			_Speed = 0;
			_Size = 0;
			_Camera = 0;
		}
		
	SmartPhone(string _NamePhone, string _Manufacturer, float _OriginalCost, int _YearOfAppearance, double _Speed, double _Size, int _Camera) 
			: Phone(_NamePhone, _Manufacturer, _OriginalCost, _YearOfAppearance)
		{
			_Speed = _Speed;
			_Size = _Size;
			_Camera  = _Camera ;
		}
		
		SmartPhone(SmartPhone &p) :Phone(p)
		{
			_Speed  = p._Speed ;
			_Size = p._Size ;
			_Camera = p._Camera;
		}
		
		void SetNamePhone (string NamePhone)
		{
			Phone::SetNamePhone (NamePhone);
		}
		
		void SetManufacturer (string Manufacturer)
		{
			Phone::SetManufacturer (Manufacturer);
		}
		
		void SetOriginalCost (float OriginalCost)
		{
			Phone::SetOriginalCost (OriginalCost);
		}
		
		void SetSpeed (double Speed)
		{
			_Speed = Speed;
		}
		
		void SetSize (double Size)
		{
			_Size = Size;
		}
		
		void SetCamera(int Camera)
		{
			_Camera = Camera;
		}
		

		
		string GetNamePhone ()
		{
			return Phone::GetNamePhone ();
		}
		
		string GetManufacturer ()
		{
			return Phone::GetManufacturer ();
		}
	
		
		double GetSpeed ()
		{
			return _Speed;
		}
		
		double GetSize ()
		{
			return _Size;
		}
		
		int GetCamera()
		{
			return _Camera;
		}
		
		int NumberYearOfAppearance ()
		{
			time_t date = time(0);
			tm *ltm = localtime(&date);
			int nam_hien_tai = 1900 + ltm->tm_year;
			
			return (nam_hien_tai - GetYearOfAppearance ());
		}
		
		
		float CurrentPrices ()
		{

			float _CurrentPrices = GetOriginalCost () - NumberYearOfAppearance()*0.02*GetOriginalCost ();
			if(_CurrentPrices < 0)
				return 0;
			return _CurrentPrices;
		}
		
		void Input()
		{
			Phone::Input();
			cout<<"Enter Speed: ";
			fflush(stdin);
			cin >> _Speed;
			cout<<"Enter Size: ";
			cin>>_Size;
			cout<<"Enter Camera: ";
			cin >> _Camera;
		}
		
		void Output()
		{
			Phone::Output();
			cout<<"Speed: "<<_Speed <<endl;
			cout<<"Size: "<<_Size <<endl;
			cout<<"Camera: "<<_Camera<<endl;
			cout<<"Number Year Of Appearance: "<< NumberYearOfAppearance()<<endl;
			cout << setprecision(2) << fixed <<"Current Prices : "<<CurrentPrices ()<<endl;
			cout<<"----------------------------------------------------" << endl;
		}
		
};

int main()
{
	int n;
	do{
		cout<<"Enter Number Of SmartPhone: ";
		cin>>n;
		if(n>50)
			cout<<"Enter Again!"<<endl;
		cout << "----------------------------------------------------" << endl;
	}while(n>50);
	
	SmartPhone *smartphone = new SmartPhone[n];
	for(int i=0; i<n; i++){
		smartphone[i].Input();
		cout << "----------------------------------------------------" << endl;
	}
	
	cout<<"Arrange "<<endl;
	cout << "------------------------" << endl;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(smartphone[i] > smartphone[j]){
				SmartPhone temp = smartphone[i];
				smartphone[i] = smartphone[j];
				smartphone[j] = temp;
			}
		}
	}

	for(int i=0; i<n; i++){
		smartphone[i].Output();
	}
	
	cout<<"Phone with the highest residual value"<<endl;
	cout << "------------------------" << endl;
	float _MaxCurrentPrices = 0;
	for(int i=0; i<n; i++){
		float CurrentPrices = smartphone[i].CurrentPrices ();
		if(CurrentPrices > _MaxCurrentPrices){
			_MaxCurrentPrices = smartphone[i].CurrentPrices ();
		}
	} 	
	
	for(int i=0; i<n; i++){
		float CurrentPrices = smartphone[i].CurrentPrices ();
		if(CurrentPrices == _MaxCurrentPrices){
			smartphone[i].Output();
		}
	}
}

