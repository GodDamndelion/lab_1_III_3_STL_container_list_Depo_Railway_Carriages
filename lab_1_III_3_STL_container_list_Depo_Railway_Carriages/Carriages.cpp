/*III - 3. ����������� ������������ ����� �����, � ������� ������ ������� ���������� �� �����������
�������� ���� �����. ���������, ���� �� � ���� ������������ ������ ���� ���� � �����������
���� ����� 36? ���� ����, �� ����������� ���������� � ������ � ���������� �������.
������������ STL ��������� list*/
#include "Carriages.h"

void Carriage::print()
{
	cout << "����� ����� " << number << '\n' << release_year << " ���� �������";
}

int Carriage::compare(Carriage obj)
{
	int result = 1;
	if (number < obj.get_number())
		result = -1;
	return result;
}

Passenger_Carriage::Passenger_Carriage(ifstream& file)
{
	file >> number;
	file >> release_year;
	file.ignore();
	string tmp;
	getline(file, tmp);
	type = NoType;
	if (tmp == "WithSeats")
		type = WithSeats;
	else
		if (tmp == "Coupe")
			type = Coupe;
		else
			if (tmp == "SecondClass")
				type = SecondClass;
	file >> number_of_seats;
	file.ignore();
	getline(file, tmp);
	presence_of_a_shower_module = false;
	if (tmp == "������������")
		presence_of_a_shower_module = true;
	getline(file, tmp);
}

void Passenger_Carriage::print()
{
	cout << "������������ ";
	Carriage::print();
	cout << '\n';
	cout << "���: ";
	switch (type)
	{
	case WithSeats:
		cout << "�������";
		break;

	case Coupe:
		cout << "����";
		break;
		
	case SecondClass:
		cout << "�����������";
		break;

	default:
		cout << "������";
		break;
	}
	cout << '\n';
	cout << "���������� ����: " << number_of_seats << '\n';
	cout << "������� ������ " << (presence_of_a_shower_module ? "������������" : "�����������");
	cout << "\n==================================";
}

Freight_Carriage::Freight_Carriage(ifstream& file)
{
	file >> number;
	file >> release_year;
	file.ignore();
	string tmp;
	getline(file, tmp);
	type = NoType;
	if (tmp == "tank")
		type = tank;
	else
		if (tmp == "platform")
			type = platform;
		else
			if (tmp == "gondola")
				type = gondola;
			else
				if (tmp == "refrigerator")
					type = refrigerator;
	file >> tonnage;
	file.ignore();
	getline(file, tmp);
}

void Freight_Carriage::print()
{
	cout << "�������� ";
	Carriage::print();
	cout << '\n';
	cout << "���: ";
	switch (type)
	{
	case tank:
		cout << "��������";
		break;

	case platform:
		cout << "���������";
		break;

	case gondola:
		cout << "���������";
		break;

	case refrigerator:
		cout << "������������";
		break;

	default:
		cout << "������";
		break;
	}
	cout << '\n';
	cout << "������: " << tonnage;
	cout << "\n==================================";
}