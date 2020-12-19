#include <iostream>
#include <conio.h>
using namespace std;
class node
{
	friend class list;
	int data;
	node* next;
	node* previous;
};
//**************************
class list
{
	node* first;
	node* last;
public:
	list();
	void print();
	void insert();          // insert to last
	void insert_first();   // insert to first
};
//***********************
list::list()
{
	first = NULL;
}
//*************************
void list::print()
{
	if (first == NULL)
		cout << "list is empty!!!!!!";
	else
	{
		node* ptr = first;
		while (ptr != last)
		{
			cout << ptr->data << "\t";
			ptr = ptr->next;
		}
	}
}
//***********************
void list::insert() {
	node* newptr;
	newptr = new node;
	cout << "Enter one number: \n";
	cin >> newptr->data;
	if (first == NULL)
	{
		first = last = newptr;
	}
	else
	{
		last->next = newptr;
		newptr->previous = last;
		last = last->next;
	}
}
//********************************
void list::insert_first() {
	node* newptr;
	newptr = new node;
	cout << "Enter one number: \n";
	cin >> newptr->data;
	if (first == NULL) {
		first = last = newptr;
	}
	else {
		newptr->next = first;
		newptr->previous = NULL;
		first->previous = newptr;
		first = newptr;
	}
}
//********************************
int menu()
{
	int c;
	cout << "1. Print list.\n";
	cout << "2. insert to last of list.\n";
	cout << "3. insert to  first of list.\n";
	cout << "4. Exit.\n";
	cout << "Enter your select (1-4).\n";
	cin >> c;
	return c;
}
//*************************************
int main(int argc, char** argv) {
	list L1;
	while (1)
	{
		system("CLS");
		switch (menu())
		{
		case 1:
			L1.print();
			break;
		case 2:
			L1.insert();
			break;
		case 3:
			L1.insert_first();
			break;
		case 4:
			exit(0);
		}
		_getch();
	}
	return 0;
}

