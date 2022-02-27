/*III - 3. ����������� ������������ ����� �����, � ������� ������ ������� ���������� �� �����������
�������� ���� �����. ���������, ���� �� � ���� ������������ ������ ���� ���� � �����������
���� ����� 36? ���� ����, �� ����������� ���������� � ������ � ���������� �������.
������������ STL ��������� list*/
#pragma once
#include "Carriages.h"
#include <list>
#include <iterator>

using std::list;

class Depot
{
	string name;
	list<Carriage*> list_of_carriages;
public:
	Depot(ifstream& file);
	void set_name(string input) { name = input; }
	string get_name() { return name; }
	void print();
	void sort();
	list<Carriage*>::iterator begin() { return list_of_carriages.begin(); }
	list<Carriage*>::iterator end() { return list_of_carriages.end(); }
	~Depot();
};