#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Car
{
public:
	string brand;
	string model;
	int year;
	int speed;
	int price;
	int serviceTime;

	Car()
	{
		cout << "Введите марку авто: ";
		cin >> brand;

		cout << "Введите модель авто: ";
		cin >> model;

		cout << "Введите год выпуска авто: ";
		cin >> year;

		cout << "Введите скорость (км/ч) авто: ";
		cin >> speed;

		cout << "Введите цену (р) авто: ";
		cin >> price;

		cout << "Введите длительность эксплуатации (год) авто: ";
		cin >> serviceTime;
	}

	void increaseSpeed(int additional_speed)
	{
		speed += additional_speed;
		cout << "Текущая скорость: " << speed;
	}

	void decreaseSpeed(int reduced_speed)
	{
		speed -= reduced_speed;
		cout << "Текущая скорость: " << speed;
	}

	void getBrand()
	{
		cout << "Марка авто: " << brand;
	}

	void getModel()
	{
		cout << "Модель авто: " << model;
	}

	void getYear()
	{
		cout << "Год выпуска авто: " << year;
	}

	void getSpeed()
	{
		cout << "Скорость авто: " << speed;
	}

	void Payback()
	{
		int annual_income;
		cout << "Введите ваш годовой доход: ";
		cin >> annual_income;

		if (price / annual_income > serviceTime)
		{
			cout << "Поздравляем ваш автомобиль окупится быстрее, чем сломается! То есть, через " << price / annual_income << " лет!";
		}
	}

	void Workability()
	{
		if (2023 - year > serviceTime)
		{
			cout << "Советуем сменить автомобиль или, как минимум, провести полное ТО.";
		}

		else if (2023 - year == serviceTime)
		{
			cout << "Советуем провести ТО.";
		}

		else
		{
			cout << "Советуем провести ТО. Однако, автомобиль скорее всего в приемлемом состоянии.";
		}
	}
};

class Truck : public Car
{
public:
	int payloadCapacity;
	int fuelAmount;
	int fuelConsumption;

	Truck() : Car()
	{
		cout << "Введите грузоподъёмность грузовика: ";
		cin >> payloadCapacity;

		cout << "Введите кол-во топлива грузовика: ";
		cin >> fuelAmount;

		cout << "Введите потребление топлива (в переходах): ";
		cin >> fuelConsumption;
	};

	void getPayloadCapacity()
	{
		cout << "Грузоподъёмность грузовика: " << payloadCapacity;
	}

	void FuelCheck()
	{
		if (fuelAmount / fuelConsumption <= 2)
		{
			cout << "Аккуратно! У тебя может не хватить топлива на дорогу. Стоит заправиться по пути.";
		}
		else
		{
			cout << "Не беспокойся! У тебя хватит топлива!";
		}
	}

	void Refill()
	{
		int refill;
		cout << "Введи кол-во топлива на которое заправился: ";
		cin >> refill;

		fuelAmount += refill;

		cout << "Теперь тебе хватит топлива на " << fuelAmount / fuelConsumption << " перехода.";
	}
};

void Task1();
void Task2();
void Comparator(list<Car>& cars, list<Truck>& trucks, bool asc, string parameter);
void Search(list<Car>& cars, list<Truck>& trucks);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	do
	{
		cout << "Выберите задачу:\n 1 - Создание и сортировка коллекции\n 2 - Работа с классами Автомобиль и Грузовик\n";
		cin >> choice;

		if (choice == 1)
		{
			Task1();
		}

		else if (choice == 2)
		{
			Task2();
		}

		else
		{
			break;
		}

	} while (true);
}

void Task1()
{
	bool exit = false;
	int choice;
	int n;
	list<int> numbers;

	do
	{
		cout << " 1 - Создать список (list)\n 2 - Сортировка по возрастанию\n 3 - Сортировка по убыванию\n";
		cin >> choice;

		if (choice == 1)
		{
			numbers.clear();
			cout << "Введите размер массива: ";
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				numbers.push_back(rand());
				cout << numbers.back() << "\n";
			}
		}

		else if (choice == 2)
		{
			numbers.sort();

			for (int n : numbers)
			{
				cout << n << "\n";
			}
		}

		else if (choice == 3)
		{
			numbers.sort(greater<>());

			for (int n : numbers)
			{
				cout << n << "\n";
			}
		}

		else
		{
			exit = true;
		}

	} while (!exit);
}

void Task2()
{
	static list<Car> cars;
	static list<Truck> trucks;
	list<Car>& refCars{ cars };
	list<Truck>& refTrucks{ trucks };
	int choice;
	bool exit = false;

	do
	{
		cout << " 1 - Создать экземпляр классов Автомобиль и Грузовик\n 2 - Вывести список экземпляров классов Автомобиль и Грузовик\n 3 - Сортировка по параметрам и поиск\n";
		cin >> choice;

		if (choice == 1)
		{
			int choice1;

			cout << " 1 - Создать экземпляр класса Автомобиль\n 2 - Создать экземпляр класса Грузовик\n";
			cin >> choice1;

			if (choice1 == 1)
			{
				Car newCar;
				cars.push_back(newCar);
			}

			else if (choice1 == 2)
			{
				Truck newTruck;
				trucks.push_back(newTruck);
			}
		}

		else if (choice == 2)
		{
			for (Car car : cars)
			{
				cout << "Модель: " << car.model << "\n\tмарка: " << car.model << "\n\tцена: " << car.price << "\n\tгод выпуска: " << car.year << "\n\tвремя эксплуатации: " << car.serviceTime << "\n\tскорость: " << car.speed << "\n\n";
			}

			for (Truck truck : trucks)
			{
				cout << "Модель: " << truck.model << "\n\tмарка: " << truck.model << "\n\tцена: " << truck.price << "\n\tгод выпуска: " << truck.year << "\n\tвремя эксплуатации: " << truck.serviceTime << "\n\tскорость: " << truck.speed << "\n\t\tгрузоподъёмность: " << truck.payloadCapacity << "\n\t\tкол-во топлива: " << truck.fuelAmount << "\n\t\tрасход топлива: " << truck.fuelConsumption << "\n\n";
			}
		}

		else if (choice == 3)
		{
			bool asc = true;
			string parameter;

			int choice1;
			cout << " 1 - Сортировка по году выпуска\n 2 - Сортировка по скорости\n 3 - Поиск по марке или модели\n";
			cin >> choice1;

			if (choice1 == 1 || choice1 == 2)
			{
				if (choice1 == 1)
				{
					parameter = "year";
				}
				else if (choice1 == 2)
				{
					parameter = "speed";
				}

				int choice2;
				cout << " 1 - Возрастающая\n 2 - Убывающая\n";
				cin >> choice2;

				if (choice2 == 1)
				{
					asc = true;
				}
				else if (choice2 == 2)
				{
					asc = false;
				}

				Comparator(refCars, refTrucks, asc, parameter);

				for (Car car : cars)
				{
					cout << "Модель: " << car.model << "\n\tмарка: " << car.model << "\n\tцена: " << car.price << "\n\tгод выпуска: " << car.year << "\n\tвремя эксплуатации: " << car.serviceTime << "\n\tскорость: " << car.speed << "\n\n";
				}
				for (Truck truck : trucks)
				{
					cout << "Модель: " << truck.model << "\n\tмарка: " << truck.model << "\n\tцена: " << truck.price << "\n\tгод выпуска: " << truck.year << "\n\tвремя эксплуатации: " << truck.serviceTime << "\n\tскорость: " << truck.speed << "\n\t\tгрузоподъёмность: " << truck.payloadCapacity << "\n\t\tкол-во топлива: " << truck.fuelAmount << "\n\t\tрасход топлива: " << truck.fuelConsumption << "\n\n";
				}
			}

			else if (choice1 == 3)
			{
				Search(refCars, refTrucks);
			}
		}

		else
		{
			exit = true;
		}

	} while (!exit);
}

void Comparator(list<Car>& cars, list<Truck>& trucks, bool asc, string parameter)
{
	if (parameter == "year")
	{
		if (asc)
		{
			cars.sort([](Car car1, Car car2) { return car1.year < car2.year; });
			trucks.sort([](Truck truck1, Truck truck2) { return truck1.year < truck2.year; });
		}
		else
		{
			cars.sort([](Car car1, Car car2) { return car1.year > car2.year; });
			trucks.sort([](Truck truck1, Truck truck2) { return truck1.year > truck2.year; });
		}
	}
	else
	{
		if (asc)
		{
			cars.sort([](Car car1, Car car2) { return car1.speed < car2.speed; });
			trucks.sort([](Truck truck1, Truck truck2) { return truck1.year < truck2.year; });
		}
		else
		{
			cars.sort([](Car car1, Car car2) { return car1.speed > car2.speed; });
			trucks.sort([](Truck truck1, Truck truck2) { return truck1.speed > truck2.speed; });
		}
	}
}

void Search(list<Car>& cars, list<Truck>& trucks)
{
	string brand;
	string model;
	cout << "Введите марку авто: ";
	cin >> brand;
	cout << "Введите модель авто: ";
	cin >> model;

	for (Car car : cars)
	{
		if (brand == car.brand && model == car.model)
		{
			cout << "Модель: " << car.model << "\n\tмарка: " << car.model << "\n\tцена: " << car.price << "\n\tгод выпуска: " << car.year << "\n\tвремя эксплуатации: " << car.serviceTime << "\n\tскорость: " << car.speed << "\n\n";
		}
	}
	for (Truck truck : trucks)
	{
		if (brand == truck.brand && model == truck.model)
		{
			cout << "Модель: " << truck.model << "\n\tмарка: " << truck.model << "\n\tцена: " << truck.price << "\n\tгод выпуска: " << truck.year << "\n\tвремя эксплуатации: " << truck.serviceTime << "\n\tскорость: " << truck.speed << "\n\t\tгрузоподъёмность: " << truck.payloadCapacity << "\n\t\tкол-во топлива: " << truck.fuelAmount << "\n\t\tрасход топлива: " << truck.fuelConsumption << "\n\n";
		}
	}
}
