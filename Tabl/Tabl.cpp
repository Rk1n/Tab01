#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>


using namespace std;
struct date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Line_n {
	char name[20];
	char prud[15];
	unsigned short cou;
	float cost;
	struct date date;
};

struct node {
	Line_n data;
	struct node* next;
};

struct node* myHead;
int countItem = 0;


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

void c_Tab(struct Line_n* line_n) {
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

void reps(struct Line_n* line_n) {
	int mina = 0;
	int maxa = 0;
	for (int i = 1; i < 3; i++) {
		if (line_n[maxa].date.day + line_n[maxa].date.month * 30 + line_n[maxa].date.year * 365 < line_n[i].date.day + line_n[i].date.month * 30 + line_n[i].date.year * 365) {
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

}

void addItem(Line_n data)
{
	struct node* newItem = new node();
	newItem->data = data;
	if (countItem == 0) 
	{
		newItem->next = NULL;
	}
	else
	{
		newItem->next = myHead;
	}
	myHead = newItem;
	countItem++;
}


void insertItem(int index, Line_n data) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) {
		addItem(data);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->data = data;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

void editItem(int index, Line_n data) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
			//cout << "+" << current->data;
		}
		current->data = data;
	}
	else {
		cout << endl << "Ошибка индекс не в диапазоне";
	}
}

void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		struct node* old;
		if (index == 0) {
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current) {
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				i++;
				current = current->next;
			}
		}
	}
}
void printMyList() {
	struct node* current = myHead;
	cout << endl;
	while (current) {
		cout << " " << current->data.name;
		current = current->next;
	}
}


void DrawWithList() {
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
	struct node* current = myHead;
	while (current) {
		cout << left << "|"; cout.width(14); cout << left << current -> data.name;
		cout << left << "|"; cout.width(14+1); cout << left << current -> data.prud;
		cout << left << "|"; cout.width(24+1); cout << left << current -> data.cou;
		std::cout.precision(2);
		cout << left << "|"; cout.width(9+1); cout << left << fixed << current -> data.cost;
		cout << left << "|";
		p_date(current->data.date.day, current->data.date.month, current -> data.date.year, 16);
		cout << "|" << endl;
		current = current->next;
	}
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78 + 5);  cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct Line_n line_n[10];
	line_n[0] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
	line_n[1] = { "SmartSute", "Lotus", 5, 1020.99, {21,10,2012} };
	line_n[2] = { "StarOffice", "Sun", 4, 9.99, {21,10,2020} };

	c_Tab(line_n);

	reps(line_n);

	c_Tab(line_n);
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;


	int n = 3; //kol-vo yach
	Line_n* a;
	a = (Line_n*)calloc(n, sizeof(Line_n));
	for (int i = 0; i < n; i++) {
		strcpy_s(a[i].name, line_n[i].name);
		strcpy_s(a[i].prud, line_n[i].prud);
		a[i].cost = line_n[i].cost;

	}
	Line_n** b;
	b = (Line_n**) new Line_n * [10];
	for (int i = 0; i < 10; i++) {
		b[i] = (Line_n*) new Line_n;
		*(b[i]) = a[i];
	}
	a = (Line_n*)realloc(a, 10 * sizeof(Line_n));
	if (a) {
		for (int i = 0; i < 3; i++) {
			cout << endl << "адрес А[i]" << &a[i] << "A[i] -> name " << a[i].name;
			cout << ", " << "адрес B[i]" << &b[i] << "B[i] -> name " << b[i]->name;
		}
		for (int i = 0; i < 3; i++) {
			cout << endl << "адрес А[i]" << &a[i] << "A[i] -> prod " << a[i].prud;
			cout << ", " << "адрес B[i]" << &b[i] << "B[i] -> prod " << b[i]->prud;
		}
		for (int i = 0; i < 3; i++) {
			cout << endl << "адрес А[i]" << &a[i] << "A[i] -> cost " << a[i].cost;
			cout << ", " << "адрес B[i]" << &b[i] << "B[i] -> cost " << b[i]->cost;
		}
		for (int i = 0; i < 10; i++) {
			delete b[i];
		}
	}
	delete[]b;
	free(a);
	cout << endl;


	// Практическая_работа_№3
	// Правка кода >_<
	cout << "Практика 3 Динамический список" << endl;
	//system("mspaint");
	addItem(line_n[0]);
	addItem(line_n[1]);
	addItem(line_n[2]);
	DrawWithList();
	struct Line_n newLine = { "LibreOffice", "StarDivi.", 4, 0.01, {25,01,2011} };
	insertItem(0, newLine);
	DrawWithList();
	deleteItem(3);
	DrawWithList();
	struct Line_n editLine = { "Яндекс360", "Yandex", 5, 0.5, {25,04,2017} };
	editItem(1, editLine);
	DrawWithList();
}

