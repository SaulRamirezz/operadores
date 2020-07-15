#include <iostream>
#include <sstream>
#include <string>
#include <memory>
using namespace std;

class Date
{

public:

	Date(int inDay, int inMont, int inYear) :
		month(inMont), day(inDay), year(inYear) {

	}
	Date& operator --() {
		--day;
		return *this;
	}
	Date& operator ++() {
		++day;
		return *this;
	}
	Date operator ++(int) {

		Date copy(day, month, year);
		++day;
		return *this;
	}
	Date operator --(int) {

		Date copy(day, month, year);
		--day;
		return copy;
	}
	void masDias(int _dias) { //Aqui comienza la implementación de los operadores += y -=
		day += _dias;
	}
	void menosDias(int _dias) {
		day -= _dias;
	}
	operator const char* ()
	{
		ostringstream formattedDate;
		formattedDate << day << "/" << month << "/" << year;
		dateInString = formattedDate.str();
		return dateInString.c_str();
	}
	~Date() {}
	void displayDate() {
		cout << year << "/" << month << "/" << day;
	}

private:
	int day, month, year;
	string dateInString;
};

int main()
{
	Date f(13, 2, 1995);
	f.masDias(10);
	f.displayDate();
	cout<<endl;
	f.menosDias(3);
	f.displayDate();
}

