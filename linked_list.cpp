#include <iostream>
#include <conio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class node
{
	friend class list;
	int data;
	node* next;
};
//**************************
class list
{
	node* first;
public:
	list();
	void insert();        // insert to the last of link 
	void insert_after();  // insert after data 
	void insert_first();  // insert at first of link
	void delete_data();   // delete a data node
	void print();        //prints all the link
};
//***********************
list::list()
{
	first = NULL;
}
//*************************
void list::insert()
{
	node* newptr;
	newptr = new node;
	newptr->next = NULL;
	cout << "Enter one number: \n";
	cin >> newptr->data;
	if (first == NULL)
		first = newptr;
	else
	{
		node* ptr = first;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newptr;
	}
}
//************************
void list::insert_after() {
	int data ;
	cout << "enter number to find \n";
	cin >> data;
	int new_node_date ;
	cout << "enter new number to add after " << data <<"\n";
	cin >> new_node_date;
	node* ptr = first;
	while (ptr != NULL)
	{
		if (ptr->data == data)
		{
			node* new_node = new node;
			new_node->data = new_node_date;
			if (ptr->next == NULL) {
				new_node->next = NULL;
				ptr->next = new_node;
				break;
			}
			else {
			new_node->next = ptr->next;
			ptr->next = new_node;
			break;
			}
		}
		ptr = ptr->next;
	}
}
//*************************
void list::insert_first() {
	cout << "enter one number \n";
	int data;
	cin >> data;
	node* new_node = new node;
	new_node->data = data;
	if (first == NULL) {
		first = new_node;
	}
	else {
		new_node->next = first;
		first = new_node;
	}
}

//************************
void list::delete_data() {
	cout << "enter one number \n";
	int data;
	cin >> data;
	node* ptr1, * ptr2;
	ptr1 = first;
	ptr2 = NULL;
	while(ptr1->data != data && ptr1->next != NULL) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
	}
	if (ptr1->data == data) {
		ptr2->next = ptr1->next;
		delete ptr1;
	}
}
//*************************
void list::print()
{
	if (first == NULL)
		cout << "list is empty!!!!!!";
	else
	{
		node* ptr = first;
		while (ptr != NULL)
		{
			cout << ptr->data << "\t";
			ptr = ptr->next;
		}
	}
}
//********************************
int menu()
{
	int c;
	cout << "1. Print list.\n";
	cout << "2. insert to list.\n";
	cout << "3. insert to after the data.\n";
	cout << "4. insert to first \n";
	cout << "5. delete from list.\n";
	cout << "6. Exit.\n";
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
			L1.insert_after();
			break;
		case 4:
			L1.insert_first();
			break;
		case 5:
			L1.delete_data();
			break;
		case 6:
			exit;
		}
		_getch();
	}
	return 0;
}