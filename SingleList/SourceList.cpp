#include <iostream>              //подключение директивы препроцессора

using namespace std;                  //подключение пространства имен
unsigned int counter;                 //объявляем глобальную переменную подсчета элементов

class SingleList                      //создаем класс лист
{
public:                               //в паблик модификатор записываем все необходимые методы
	SingleList();
	SingleList(int value);
	void PrintEven();
	SingleList* createList(int value);
	void PrintEvery();
	void dellList();
	

private:                               //класс будет хранить целочисленные данные и указатель на следующий элемент
	int value;
	SingleList* next;
};

SingleList::SingleList()              //инициализируем конструктор без параметров
{
	this->value = 0;
	this->next = nullptr;
}

SingleList::SingleList(int value)     //инициализируем конструктор с параметрами
{
	this->value = value;
	this->next = nullptr;
}

void SingleList::PrintEven() {            //метод, который выводит все четные числа
	if (this->value%2 == 0)
	{
		cout << value << " ";
	}
	if (this->next != nullptr)
	{
		this->next->PrintEven();
	}
}

SingleList* SingleList::createList(int value) {         //метод создающий новый экземпляр класса
	SingleList* listPtr = new SingleList;
	listPtr->next = this;
	listPtr->value = value;
	++counter;
	return listPtr;
}

void SingleList::PrintEvery() {            //метод вывода в консоль всего списка
	cout << value << " ";
	if (this->next != nullptr)
	{
		this->next->PrintEvery();
	}
}

void SingleList::dellList()                    //метод удаления последнего элемента списка
{
	if (counter == 0)
	{
		cout << "You must create a list." << endl;
	}
	else if (counter == 1)
	{
		--counter;
		SingleList* tempPtr = this;
		delete tempPtr;
	}
	else if (this->next->next == nullptr)
	{
		--counter;
		SingleList* tempPtr = this->next;
		delete tempPtr;
		this->next = nullptr;
		
	}
	else
	{
		this->next->dellList();
	}
}

int main() {
	unsigned int quant = 0;     //переменная, куда мы задаем количество элементов
	int choice = 0;             //переменная записи выбора пользователя
	SingleList* list = nullptr;  //указатель на первый элемент списка

	for (;;)                      //бесконечный цикл
	{
		cout << endl << endl;                    //меню выбора
		cout << "What do you want?" << endl;
		cout << "1 - Create new list." << endl;
		cout << "2 - Add element." << endl;
		cout << "3 - Delete element." << endl;
		cout << "4 - Print event fields." << endl;
		cout << "5 - Print all fields." << endl;
		cout << "6 - Display the number of elements." << endl;
		cout << "7 - Delete list." << endl;
		cout << "8 - Exit." << endl;
		cout << endl;
		cin >> choice;                          //вводим переменную выбора

		switch (choice)                          //условная конструкция выбора и вызова определенных методов
		{
		case 1:
			if (counter == 0)
			{
				cout << "Enter quantity" << endl;
				cin >> quant;
				if (quant > 0)
				{
					int data = 0;
					cout << "Put number:" << endl;
					cin >> data;
					list = new SingleList(data);
					++counter;
					for (unsigned int i = counter; i < quant; ++i)
					{
						cout << "Put number:" << endl;
						cin >> data;
						list = list->createList(data);
					}

				}
				else
				{
					cout << "Error of enter." << endl;
				}
			}
			else
			{
				cout << "You have the list. Delete the previous list." << endl;
			}
			
			break;

		case 2:
			if (counter > 0)
			{
				int data = 0;
				cout << "Put number:" << endl;
				cin >> data;
				list = list->createList(data);
			}
			else
			{
				cout << "You must create a list." << endl;
			}
			break;

		case 3:
			if (counter > 0)
			{
				list->dellList();
				if (counter == 0)
				{
					list = nullptr;
				}
			}
			else
			{
				cout << "You must create a list." << endl;
			}
			break;

		case 4:
			if (counter > 0)
			{
				cout << endl << "Event fields:";
				list->PrintEven();
			}
			else
			{
				cout << "You must create a list." << endl;
			}
			break;

		case 5:
			if (list != nullptr)
			{
				cout << endl << "All fields:";
				list->PrintEvery();
			}
			else
			{
				cout << "You must create a list." << endl;
			}
			
			break;

		case 6:
			cout << "Your number of elements:" << counter << endl;
			break;

		case 7:
			for (unsigned int i = 0, c = counter; i <= c; ++i)
			{
				list->dellList();
			}
			list = nullptr;
			break;
		default:                                          //выход
			cout << "Bye!" << endl;
			exit(0);
			break;
		}
	}
	return 0;
}