#include <iostream>
#include <windows.h>
#include <string>


using namespace std;
struct date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct line_n {
	char name[20];
	char prud[15];
	unsigned short cou;
	float cost;
	struct date date;
};

void p_date(unsigned short day, unsigned short month, unsigned short year, int lien) {
	int w = 10;
	int spac = (lien - w) / 2 - 1;
	cout << left;
	cout.width(spac); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(spac); cout << " ";
}

void c_Tab(struct line_n* line_n) {
	cout << endl;	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78 + 5);  cout << left << "|Офисные пакеты"; cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Наименование ";
	cout << left << "| Производитель ";
	cout << left << "| Количество сост. частей ";
	cout << left << "| Цена($) ";
	cout << left << " |  Дата релиза ";
	cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(14); cout << left << line_n[i].name;
		cout << left << "|"; cout.width(14 + 1); cout << left << line_n[i].prud;
		cout << left << "|"; cout.width(24 + 1); cout << left << line_n[i].cou;
		std::cout.precision(2);
		cout << left << "|"; cout.width(9 + 1); cout << left << fixed << line_n[i].cost;
		cout << left << "|";
		p_date(line_n[i].date.day, line_n[i].date.month, line_n[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78 + 5);  cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
}

void reps(struct line_n* line_n) {
	int mina = 0;
	int maxa = 0;
	for (int i = 1; i < 3; i++) {
		if (line_n[maxa].date.day + line_n[maxa].date.month*30 + line_n[maxa].date.year * 365 < line_n[i].date.day + line_n[i].date.month * 30 + line_n[i].date.year * 365){
			maxa = i;
		}
	}
	for (int i = 1; i < 3; i++) {
		if (line_n[mina].date.day + line_n[mina].date.month * 30 + line_n[mina].date.year * 365 > line_n[i].date.day + line_n[i].date.month * 30 + line_n[i].date.year * 365) {
			mina = i;
		}
	}

	line_n[4] = line_n[mina];
	line_n[mina] = line_n[maxa];
	line_n[maxa] = line_n[4];

	cout << mina;
	cout << maxa;

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct line_n line_n[10];
	line_n[0] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
	line_n[1] = { "SmartSute", "Lotus", 5, 1020.99, {21,10,2012} };
	line_n[2] = { "StarOffice", "Sun", 4, 9.99, {21,10,2020} };

	c_Tab(line_n);

	reps(line_n);
	
	c_Tab(line_n);
}

