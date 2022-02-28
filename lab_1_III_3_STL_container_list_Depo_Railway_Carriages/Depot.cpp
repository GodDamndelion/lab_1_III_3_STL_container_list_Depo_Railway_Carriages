/*III - 3. –азработать контейнерный класс Ђƒепої, в котором список вагонов упор€дочен по возрастанию
значений пол€ Ќомер. ѕроверить, есть ли в депо пассажирские вагоны типа купе с количеством
мест менее 36? ≈сли есть, то распечатать информацию о вагоне с наименьшим номером.
»спользовать STL контейнер list*/
#include "Depot.h"

Depot::Depot(ifstream& file)
{
	getline(file, name);
	string tmp;
	getline(file, tmp);
	char ch;
	while (!file.eof())
	{
		file >> ch;
		file.ignore();
		if (ch == 'P')
			list_of_carriages.push_back(new Passenger_Carriage(file));
		else
			list_of_carriages.push_back(new Freight_Carriage(file));
	}
	sort();
}

void Depot::print()
{
	cout << name << '\n';
	cout << "==================================\n";
	list<Carriage*>::iterator iter = list_of_carriages.begin();
	while (iter != list_of_carriages.end())
	{
		(**iter).print();
		cout << '\n';
		++iter;
	}
}

void Depot::sort()
{
	auto compare = [](Carriage* c1, Carriage* c2)
	{
		bool result = false;
		if ((*c1).compare(*c2) < 0) //True, если первый меньше второго (по возрастанию)
			result = true;
		return result;
	};
	list_of_carriages.sort(compare);
}

Depot::~Depot()
{
	list<Carriage*>::iterator iter = list_of_carriages.begin();
	while (iter != list_of_carriages.end())
	{
		delete (*iter);
		(*iter) = nullptr;
		iter++;
	}
	/*list_of_carriages.clear();*/
}