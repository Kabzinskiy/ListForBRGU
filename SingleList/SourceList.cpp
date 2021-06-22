#include <iostream>              

using namespace std;                  
unsigned int counter;                 

class SingleList                      
{
public:                               
	SingleList();
	SingleList(int value);
	void PrintEven();
	SingleList* createList(int value);
	void PrintEvery();
	void dellList();
	

private:                               
	int value;
	SingleList* next;
};

SingleList::SingleList()              
{
	this->value = 0;
	this->next = nullptr;
}

SingleList::SingleList(int value)     
{
	this->value = value;
	this->next = nullptr;
}

void SingleList::PrintEven() {            
	if (this->value%2 == 0)
	{
		cout << value << " ";
	}
	if (this->next != nullptr)
	{
		this->next->PrintEven();
	}
}

SingleList* SingleList::createList(int value) {         
	SingleList* listPtr = new SingleList;
	listPtr->next = this;
	listPtr->value = value;
	++counter;
	return listPtr;
}

void SingleList::PrintEvery() {            
	cout << value << " ";
	if (this->next != nullptr)
	{
		this->next->PrintEvery();
	}
}

void SingleList::dellList()                   
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
	unsigned int quant = 0;     
	int choice = 0;             
	SingleList* list = nullptr;  

	for (;;)                      
	{
		cout << endl << endl;                    
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
		cin >> choice;                          

		switch (choice)                          
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