/*III - 3. Разработать контейнерный класс «Депо», в котором список вагонов упорядочен по возрастанию
значений поля Номер. Проверить, есть ли в депо пассажирские вагоны типа купе с количеством
мест менее 36? Если есть, то распечатать информацию о вагоне с наименьшим номером.
Использовать STL контейнер list*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::ifstream;
using std::string;

class Carriage
{
protected:
	int number;
	int release_year;
public:
	Carriage(int number = 0, int release_year = 0) :
		number(number), release_year(release_year) {}
	void set_number(int input) { number = input; }
	void set_release_year(int input) { release_year = input; }
	int get_number() { return number; }
	int get_release_year() { return release_year; }
	virtual void print(); ////////
	int compare(Carriage obj);
};

class Passenger_Carriage : public Carriage
{
public:
	enum passenger_carriage_type { NoType, WithSeats, Coupe, SecondClass };
private:
	passenger_carriage_type type;
	int number_of_seats;
	bool presence_of_a_shower_module;
public:
	Passenger_Carriage(int number_of_seats, bool presence_of_a_shower_module, passenger_carriage_type type = NoType, int number = 0, int release_year = 0) :
		type(type), number_of_seats(number_of_seats), presence_of_a_shower_module(presence_of_a_shower_module), Carriage(number, release_year) {}
	Passenger_Carriage(ifstream& file);
	void set_type(passenger_carriage_type input) { type = input; }
	void set_number_of_seats(int input) { number_of_seats = input; }
	void set_presence_of_a_shower_module(bool input) { presence_of_a_shower_module = input; }
	passenger_carriage_type get_type() { return type; }
	int get_number_of_seats() { return number_of_seats; }
	bool get_presence_of_a_shower_module() { return presence_of_a_shower_module; }
	void print(); /////
};

class Freight_Carriage : public Carriage
{
public:
	enum freight_carriage_type { NoType, tank, platform, gondola, refrigerator };//gondola - полувагон
private:
	freight_carriage_type type;
	int tonnage;
public:
	Freight_Carriage(int tonnage, freight_carriage_type type = NoType, int number = 0, int release_year = 0) :
		type(type), tonnage(tonnage), Carriage(number, release_year) {}
	Freight_Carriage(ifstream& file);
	void set_type(freight_carriage_type input) { type = input; }
	void set_tonnage(int input) { tonnage = input; }
	freight_carriage_type get_type() { return type; }
	int get_tonnage() { return tonnage; }
	void print(); ///////
};