/*III - 3. Разработать контейнерный класс «Депо», в котором список вагонов упорядочен по возрастанию
значений поля Номер. Проверить, есть ли в депо пассажирские вагоны типа купе с количеством
мест менее 36? Если есть, то распечатать информацию о вагоне с наименьшим номером.
Использовать STL контейнер list*/
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