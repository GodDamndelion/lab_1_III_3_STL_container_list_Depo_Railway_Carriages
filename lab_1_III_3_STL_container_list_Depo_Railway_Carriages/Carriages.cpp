/*III - 3. Разработать контейнерный класс «Депо», в котором список вагонов упорядочен по возрастанию
значений поля Номер. Проверить, есть ли в депо пассажирские вагоны типа купе с количеством
мест менее 36? Если есть, то распечатать информацию о вагоне с наименьшим номером.
Использовать STL контейнер list*/
#include "Carriages.h"

void Carriage::print()
{
	cout << "вагон номер " << number << '\n' << release_year << " года выпуска";
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
	if (tmp == "присутствует")
		presence_of_a_shower_module = true;
	getline(file, tmp);
}

void Passenger_Carriage::print()
{
	cout << "Пассажирский ";
	Carriage::print();
	cout << '\n';
	cout << "Тип: ";
	switch (type)
	{
	case WithSeats:
		cout << "Сидячий";
		break;

	case Coupe:
		cout << "Купе";
		break;
		
	case SecondClass:
		cout << "Плацкартный";
		break;

	default:
		cout << "Ошибка";
		break;
	}
	cout << '\n';
	cout << "Количество мест: " << number_of_seats << '\n';
	cout << "Душевой модуль " << (presence_of_a_shower_module ? "присутствует" : "отсутствует");
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
	cout << "Грузовой ";
	Carriage::print();
	cout << '\n';
	cout << "Тип: ";
	switch (type)
	{
	case tank:
		cout << "Цистерна";
		break;

	case platform:
		cout << "Платформа";
		break;

	case gondola:
		cout << "Полувагон";
		break;

	case refrigerator:
		cout << "Рефрижератор";
		break;

	default:
		cout << "Ошибка";
		break;
	}
	cout << '\n';
	cout << "Тоннаж: " << tonnage;
	cout << "\n==================================";
}