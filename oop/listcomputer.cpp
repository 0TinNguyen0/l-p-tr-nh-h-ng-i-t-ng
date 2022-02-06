#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

using namespace std;

class Document
{
	private:
		string identity;
		string name;
        int page;
	public:
		Document();
		Document(string id, string na, int pa);
		Document(const Document &dc);
		
		void SetId(string id);
		void SetName(string na);
		void SetPage(int pa);
        void SetDocument(string id, string na, int pa);
		
		string GetId();
		string GetName();
        int GetPage();
		
		void Input();
		void Output();

        bool operator > (const Document &dc) const;
		bool operator < (const Document &dc) const;
};

Document::Document()
{
	identity = "";
	name = "";
    page = 0;
}

Document::Document(string id, string na, int pa)
{
	identity = id;
	name = na;
}

Document::Document(const Document &dc)
{
	identity = dc.identity;
	name = dc.name;
    page = dc.page;
}

void Document::SetId(string id)
{
	identity = id;
}
void Document::SetName(string na)
{
	name = na;
}

void Document::SetPage(int pa)
{
    page = pa;
}

void Document::SetDocument(string id, string na, int pa)
{
	identity = id;
	name = na;
    page = pa;
}

string Document::GetId()
{
	return identity;
}

string Document::GetName()
{
	return name;
}

int Document::GetPage()
{
    return page;
}

void Document::Input()
{
	cout << "Enter Document Code: ";
	cin >> identity; 
	cout << "Emter Document Name: ";
	cin >> name;
    cout << "Enter Document number of Pages: ";
    cin >> page;
}

void Document::Output()
{
	cout << "Document Code: " << identity << endl;
	cout << "Document Name: " << name << endl;
    cout << "Document number of Pages" << page << endl;
}

bool Document::operator > (const Document &dc) const
{
	return name > dc.name;
}

bool Document::operator < (const Document &dc) const
{
	return name < dc.name;
}

class Book : public Document
{
	private:
		string writer;
        double price; 
		int year;
	public:
		int circulated_year;
        double remain_price;
		Book() : Document()
		{
			writer = "";
            price = 0;
			year = 0;
		}
		
		Book(string id, string na, int pa, string wt, double pr, int ye) : Document(id, na, pa)
		{
			writer = wt;
            price = pr;
			year = ye;
		}
		
		Book(const Book &b) : Document(b)
		{
            writer = b.writer;
            price = b.price;
			year = b.year;
		}
		
		void SetId(string id);
		void SetName(string na);
		void SetPage(int pa);
        void SetWriter(string wt);
        void SetPrice(double pr);
		void SetYear(int ye);
		void SetBook(string id, string na, int pa, string wt, double pr, int ye);
			
		string GetId();
		string GetName();
		int GetPage();
        string GetWtitter();
        float GetPrice();
		float GetYear();
		
		void Input();
		void Output();

};

void Book::SetId(string id)
{
	Document::SetId(id);
}

void Book::SetName(string na)
{
	Document::SetName(na);
}

void Book::SetPage(int pa)
{
    Document::SetPage(pa);
}

void Book::SetWriter(string wt)
{
    writer = wt;
}

void Book::SetPrice(double pr)
{
	price = pr;
}
void Book::SetYear(int ye)
{
	year = ye;
}
void Book::SetBook(string id, string na, int pa, string wt, double pr, int ye)
{
	SetDocument(id, na, pa);
	price = pr;
	year = ye;
}
	
string Book::GetId()
{
	return Document::GetId();
}

string Book::GetName()
{
	return Document::GetName();
}

int Book::GetPage()
{
    return Document::GetPage();
}

float Book::GetPrice()
{
	return price;
}

float Book::GetYear()
{
	return year;
}

void Book::Input()
{
	Document::Input();
	cout << "Enter name of writer: ";
    cin >> writer;
    cout << "Enter price of book: ";
	cin >> price;
	cout << "Enter year of book: ";
	cin >> year;
    circulated_year = 2021 - year;
    remain_price = price - circulated_year*(5/100)*price;
}

void Book::Output()
{
    cout << "----------------------------------------------------" << endl;
	Document::Output();
	cout << "Name of writer: " << writer << endl;
    cout << "Price of book: " << price << endl;
	cout << "Year of book: " << year << endl;
    cout << "Circulation of book: " << circulated_year << endl;
    cout << "Remain price: " << remain_price << endl;
	cout << "----------------------------------------------------" << endl;
}



int main()
{
	int n;
	cout << "Enter Number of Book: ";
	cin >> n;
	Book *b = new Book[n];
	for (int i = 0; i < n; i++)
		b[i].Input();
	
	//Sap xep theo ten
	cout << "\nTruoc Khi sap xep: " << endl;
	for (int i = 0; i < n; i++)
		b[i].Output();
	sort(b, b + n);
	cout << "\nSap xep theo ten tu a - z: " << endl;
	for (int i = 0; i < n; i++)
		b[i].Output();

	//tim sach co gia tri su dung cao nhat
	double max = b[0].remain_price;
	for (int i = 1; i < n; i++) 
	{
		if (b[n].remain_price > max)
			max = b[n].remain_price;
	}
	cout << "Nhung sach co gia tri con lai lon nhat la: " << endl;
	for (int i = 0; i < n; i++) 
	{
		if (b[i].remain_price == max)
			b[i].Output();
	}
}
