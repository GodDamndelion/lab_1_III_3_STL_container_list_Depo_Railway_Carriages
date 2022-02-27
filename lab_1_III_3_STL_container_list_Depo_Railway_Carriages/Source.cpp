/*III - 3. ����������� ������������ ����� �����, � ������� ������ ������� ���������� �� �����������
�������� ���� �����. ���������, ���� �� � ���� ������������ ������ ���� ���� � �����������
���� ����� 36? ���� ����, �� ����������� ���������� � ������ � ���������� �������.
������������ STL ��������� list*/
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Depot.h"

using std::cout;
using std::ifstream;

bool Coupe_Carriage_with_seats_less_than_36__is_exist(Depot& Depo);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	bool Error = false;
	ifstream input("input.txt");
	if (!input)
	{
		cout << "���� input.txt �� ��� ������!\n";
		system("pause");
		Error = true;
	}
	if (!Error)
	{
		Depot Depo(input);
		int choice;
		bool ext = false;
		while (!ext)
		{
			cout << "������� ����� ������������ ������\n";
			cout << "1. ���������� ���������.\n";
			cout << "0. ���������� ���������.\n\n";
			choice = _getwch();
			switch (choice)
			{
			case '1': //
			{
				Depo.print();
				cout << '\n';
				if (!Coupe_Carriage_with_seats_less_than_36__is_exist(Depo))
					cout << "������� ������ � " << Depo.get_name() << " �� �������.";
				cout << '\n';
				cout << '\n';
			}
			break; //

			case '0': //���������� ���������
				ext = 1;
				break; //���������� ���������

			default:
				cout << "�������� ������ �����, ���������� ��� ���\n\n";
				break;
			}
		}
	}
	input.close();
	return 0;
}
//=================================================================================
bool Coupe_Carriage_with_seats_less_than_36__is_exist(Depot& Depo)
{
	bool result = false;
	list<Carriage*>::iterator iter = Depo.begin();
	Passenger_Carriage* tmp = nullptr;
	while (iter != Depo.end() && !result)
	{
		tmp = dynamic_cast<Passenger_Carriage*>(*iter);
		if (tmp && (*tmp).get_type() == Passenger_Carriage::Coupe && (*tmp).get_number_of_seats() < 36)
		{
			result = true;
			cout << "������ �����:";
			cout << "\n==================================\n";
			(**iter).print();
		}
		++iter;
	}
	tmp = nullptr;
	return result;
}