#include <iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
struct employee
{
	string name, address;
	string contact;
	int id, salary;
};
employee e[100];
fstream dataFile;
int total = 0;
int z = 0;

void employeeData();
void showData();
void searchData();
void updateData();
void delData();
bool checkId(int userId, int i);
void write();
void read();
void login(string& userName, string& password);

int main() 
{
	string userName, password;

	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
	cout << endl << endl;

	cout << "\t \t \t \t \t \t \t \t \t \t SIGNUP PAGE";
	cout << endl << endl << endl << endl;


	cout << "\t \t \t \t \t Enter username: ";
	getline(cin >> ws, userName);
	cout << endl;

	cout << "\t \t \t \t \t Enter Password: ";
	getline(cin >> ws, password);
	cout << endl << endl;

	cout << "\t \t \t \t \t \t \t \t \t SIGNING YOU IN";
	for (int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(800);
	}
	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t SIGNUP SUCCESSFULL!";
	Sleep(1000);
	system("CLS");
	login(userName, password);


	int choice;
	while (true)
	{
		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 1 to enter data.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 2 to show data.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 3 to search data.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 4 to update data.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 5 to delete data.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 6 to Write your Data.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 7 to Read your Data.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 8 to Logout.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Press 9 to Exit.";
		cout << endl << endl;
		cout << "\t \t \t \t \t Enter your choice: ";
		cin >> choice;
		cout << endl;
		cout << endl;

		switch (choice)
		{
		case 1:
			employeeData();
			break;
		case 2:
			showData();
			break;
		case 3:
			searchData();
			break;
		case 4:
			updateData();
			break;
		case 5:
			delData();
			break;
		case 6:
			write();
			break;
		case 7:
			read();
			break;
		case 8:
			login(userName, password);
			break;
		case 9:
			goto adios;
			break;
		default:
			cout << "\t \t \t \t \t \a Invalid choice!!";
		}
	}

adios:;//exit*
}

//Function for login

void login(string& userName, string& password)
{
	system("CLS");
	string confUserName, confPassword;

again:
	system("CLS");
	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
	cout << endl << endl; 
	cout << "\t \t \t \t \t \t \t \t \t \t LOGIN PAGE";
	cout << endl << endl << endl << endl;
	cout << "\t \t \t \t \t Confirm username: ";
	getline(cin >> ws, confUserName);
	cout << endl;
	cout << "\t \t \t \t \t Confirm Password: ";
	getline(cin >> ws, confPassword);
	cout << endl;

	if (confUserName == userName && confPassword == password)
	{
		cout << "\t \t \t \t \t \t \t \t \t LOGGING YOU IN";
		for (int i = 0; i < 5; i++)
		{
			cout << ".";
			Sleep(800);
		}
		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t LOGGED IN SUCCESSFULLY.";
		cout << endl;
		Sleep(2000);
		system("CLS");

	}

	else if (confUserName != userName && confPassword != password)
	{
		cout << "\t \t \t \t \t Both Username and password are incorrect!";
		Sleep(3000);
		goto again;
	}

	else if (confUserName != userName)
	{
		cout << "\t \t \t \t \t Entered username is incorrect!";
		Sleep(3000);
		system("CLS");
		goto again;
	}

	else if (confPassword != password)
	{
		cout << "\t \t \t \t \t Entered password is incorrect";
		Sleep(3000);
		system("CLS");
		goto again;
	}
}

//function to input employee data

void employeeData()
{
	system("CLS");

	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
	cout << endl << endl;
	int userId;
	int choice;
	cout << "\t \t \t \t \t How many employee's data do you want to enter?  ";
	cin >> choice;
	cout << endl;

	for (int i = total; i < total+choice; i++)
	{
		int userInput;
		system("CLS");
		
		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;

		cout << "\t \t \t \t \t \t \t Enter data of employee " << i + 1;
		cout << endl << endl;
		cout << "\t \t \t \t \t Enter Name of employee: ";
		getline(cin >> ws, e[i].name);
		cout << endl;
		back:
			cout << "\t \t \t \t \t Enter ID of employee: ";
			cin >> userId;
			cout << endl;
			bool check = checkId(userId, i);
			if (check == false) 
			{
				cout << "\t \t \t \t \t ID's should be unique!!" ;
				cout << endl << endl;
				goto back;
			}
			else
			{
				e[i].id = userId;
			}
		cout << "\t \t \t \t \t Enter Contact of employee: ";
		cin >> e[i].contact;
		cout << endl;
		cout << "\t \t \t \t \t Enter Address of employee: ";
		getline(cin >> ws, e[i].address);
		cout << endl;
		cout << "\t \t \t \t \t Enter Salary of Employee: ";
		cin >> e[i].salary;
		cout << endl << endl;
	}
	total = total + choice;
}

//function to display employee data

void showData()
{
	system("CLS");

	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
	cout << endl << endl;

	if (total != 0)
	{
		for (int i = 0; i < total; i++)
		{
			cout << "\t \t \t \t \t \t \t Data of employee " << i + 1;
			cout << endl << endl;
			cout << "\t \t \t \t \t Employee Name: " << e[i].name;
			cout << endl;
			cout << "\t \t \t \t \t Employee ID: " << e[i].id;
			cout << endl;
			cout << "\t \t \t \t \t Employee Contact: " << e[i].contact;
			cout << endl;
			cout << "\t \t \t \t \t Employee Address: " << e[i].address;
			cout << endl;
			cout << "\t \t \t \t \t Employee Salary: " << e[i].salary;
			cout << endl;
			cout << endl;
		}
	}

	else
	{
		system("CLS");

		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;

		cout << "\t \t \t \t \t The record is empty!!";
		Sleep(800);
	}
}

//function to search employee's data

void searchData()
{
	int id;
	bool found = false;
	system("CLS");

	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
	cout << endl << endl;

	if (total != 0)
	{
		cout << "\t \t \t \t \t Enter ID of the employee of which you want to search data: ";
		cin >> id;
		cout << endl;
		for (int i = 0; i < total; i++)
		{
			if (id==e[i].id)
			{
				system("CLS");
				found = true;
				cout << endl << endl;
				cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
				cout << endl << endl;

				cout << "\t \t \t \t \t \t \t Data of employee " << i + 1;
				cout << endl << endl;
				cout << "\t \t \t \t \t Employee Name: " << e[i].name;
				cout << endl;
				cout << "\t \t \t \t \t Employee ID: " << e[i].id;
				cout << endl;
				cout << "\t \t \t \t \t Employee Contact: " << e[i].contact;
				cout << endl;
				cout << "\t \t \t \t \t Employee Address: " << e[i].address;
				cout << endl;
				cout << "\t \t \t \t \t Employee Salary: " << e[i].salary;
				cout << endl;
				cout << endl;
				Sleep(5000);

				break;
			}
		}

		if (found = false)
		{
			system("CLS");

			cout << endl << endl;
			cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			cout << endl << endl;

			cout << "\t \t \t \t \t No such record found!!";

			Sleep(5000);
		}
	}

	else
	{
		system("CLS");

		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;

		cout << "\t \t \t \t \t The record is empty!!";
		Sleep(2000);
	}
}

//function to update data

void updateData()
{
	int choice;
	int id;
	bool found = false;
	system("CLS");

	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
	cout << endl << endl;


	if (total != 0)
	{
		cout << "\t \t \t \t \t Enter ID of the employee of which you want to update data: ";
		cin >> id;
		cout << endl;
		for (int i = 0; i < total; i++)
		{
			if (id == e[i].id)
			{
				found = true;
				cout << "\t \t \t \t \t \t \t Data of employee " << i + 1;
				cout << endl << endl;
				cout << "\t \t \t \t \t Employee Name: " << e[i].name;
				cout << endl;
				cout << "\t \t \t \t \t Employee ID: " << e[i].id;
				cout << endl;
				cout << "\t \t \t \t \t Employee Contact: " << e[i].contact;
				cout << endl;
				cout << "\t \t \t \t \t Employee Address: " << e[i].address;
				cout << endl;
				cout << "\t \t \t \t \t Employee Salary: " << e[i].salary;
				cout << endl;
				cout << endl;

				Sleep(2000);

				system("CLS");

				cout << endl << endl;
				cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
				cout << endl << endl;


				cout << "\t \t \t \t \t ~UPDATING DATA ";
				cout << endl;
				cout << "\t \t \t \t \t If you want to update Employee's whole data PRESS 1.";
				cout << endl;
				cout << "\t \t \t \t \t If you want to update Employee's Name PRESS 2.";
				cout << endl;
				cout << "\t \t \t \t \t If you want to update Employee's ID PRESS 3.";
				cout << endl;
				cout << "\t \t \t \t \t If you want to update Employee's Contact number PRESS 4.";
				cout << endl;
				cout << "\t \t \t \t \t If you want to update Employee's Address PRESS 5.";
				cout << endl;
				cout << "\t \t \t \t \t If you want to update Employee's Salary PRESS 6.";
				cout << endl;
				cout << "\t \t \t \t \t Enter your choice: ";
				cin >> choice;
				cout << endl;
				cout << endl;

				if (choice == 1)
				{

					system("CLS");

					cout << endl << endl;
					cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
					cout << endl << endl;


					cout << "\t \t \t \t \t Enter Employee's Name: ";
					getline(cin >> ws, e[i].name);
					cout << endl;
					cout << "\t \t \t \t \t Enter Employee's ID: ";
					cin >> e[i].id;
					cout << endl;
					cout << "\t \t \t \t \t Enter Employee's Contact  Number: ";
					cin >> e[i].contact;
					cout << endl;
					cout << "\t \t \t \t \t Enter Employee's Address: ";
					getline(cin >> ws, e[i].address);
					cout << endl;
					cout << "\t \t \t \t \t Enter Employee's Salary: ";
					cin >> e[i].salary;
					cout << endl;
				}

				else if (choice == 2)
				{

					system("CLS");

					cout << endl << endl;
					cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
					cout << endl << endl;


					cout << "\t \t \t \t \t Enter Employee's Name: ";
					getline(cin >> ws, e[i].name);
					cout << endl;
				}

				else if (choice == 3)
				{
					system("CLS");

					cout << endl << endl;
					cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
					cout << endl << endl;
					int userId;
				back:
					cout << "\t \t \t \t \t Enter ID of employee: ";
					cin >> userId;
					bool check = checkId(userId, total);
					if (check == false)
					{
						cout << "\t \t \t \t \t ID's should be unique!!";
						cout << endl;
						goto back;
					}
					else
					{
						e[i].id = userId;
						break;
					}
				}

				else if (choice == 4)
				{
					system("CLS");

					cout << endl << endl;
					cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
					cout << endl << endl;

					cout << "\t \t \t \t \t Enter Employee's Contact Number: ";
					cin >> e[i].contact;
					cout << endl;
				}

				else if (choice == 5)
				{
					system("CLS");

					cout << endl << endl;
					cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
					cout << endl << endl;

					cout << "\t \t \t \t \t Enter Employee's Address: ";
					getline(cin >> ws, e[i].address);
					cout << endl;
				}

				else if (choice == 6)
				{
					system("CLS");

					cout << endl << endl;
					cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
					cout << endl << endl;

					cout << "\t \t \t \t \t Enter Employee's Salary: ";
					cin >> e[i].salary;
					cout << endl;
				}

				else
				{
					system("CLS");

					cout << endl << endl;
					cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
					cout << endl << endl;


					cout << "\t \t \t \t \t Invalid Choice!!";
				}


				system("CLS");

				cout << endl << endl;
				cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
				cout << endl << endl;


				cout << "\t \t \t \t \t UPDATED RECORD";
				cout << endl << endl;
				cout << "\t \t \t \t \t Employee's Name: " << e[i].name;
				cout << endl;
				cout << "\t \t \t \t \t Employee's ID: " << e[i].id;
				cout << endl;
				cout << "\t \t \t \t \t Employee's Contact Number: " << e[i].contact;
				cout << endl;
				cout << "\t \t \t \t \t Employee's Address: " << e[i].address;
				cout << endl;
				cout << "\t \t \t \t \t Employee's Salary: " << e[i].salary;
				cout << endl;

				break;
			}
		}

		if (found==false)
		{
			system("CLS");

			cout << endl << endl;
			cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			cout << endl << endl;

			cout << "\t \t \t \t \t No such record found!!";
		}
	}

	else
	{
		system("CLS");

		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;

		cout << "\t \t \t \t \t Your record is empty!!";
		Sleep(800);
	}
}

//function to delete data

void delData()
{
	int id;
	int choice;
	bool found = false;

	cout << endl << endl;
	cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
	cout << endl << endl;

	if (total != 0)
	{
		cout << "\t \t \t \t \t Press 1 to Delete Full Record.";
		cout << endl;
		cout << "\t \t \t \t \t Press 2 to Delete Specific Record.";
		cout << endl;
		cout << "\t \t \t \t \t Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			system("CLS");
			cout << endl << endl;
			cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			cout << endl << endl;

			total = 0;
			cout << "\t \t \t \t \t All Record is Deleted.";
            cout << endl;
		}

		else if (choice == 2)
		{
			system("CLS");

			cout << endl << endl;
			cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			cout << endl << endl;

			cout << "\t \t \t \t \t Enter the ID of the employee of which you want to delete data: ";
			cin >> id;

			for (int i = 0; i < total; i++)
			{
				if (id == e[i].id)
				{
					found = true;
					for(int j=i; j<total;j++)
					{ 
					e[j].name = e[j + 1].name;
					e[j].id = e[j + 1].id;
					e[j].contact = e[j + 1].contact;
					e[j].address = e[j + 1].address;
					e[j].salary = e[j + 1].salary;
					Sleep(800);
					}
					total--;
					break;
				}
				
			}

			if (found == true)
			{
				cout << "\t \t \t \t \t Record Deleted Successfully!";
			}

			if (found==false)
			{
				system("CLS");

				cout << endl << endl;
				cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
				cout << endl << endl;

				cout << "\t \t \t \t \t No such Record found!!";
			}
		}

		else
		{
			system("CLS");

			cout << endl << endl;
			cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			cout << endl << endl;

			cout << "\t \t \t \t \t Invalid Input!!";
			Sleep(800);
		}
	}

	else
	{
		system("CLS");

		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;

		cout << "\t \t \t \t \t Your record is empty!!";
		Sleep(800);
	}
}

//Function to check if the id is unique or not

bool checkId(int userId, int i)
{
	for (int x = 0; x < i; x++)
	{
		if (e[x].id == userId)
		{
			return false;
		}
	}
	return true;
}

//Function to write data in file

void write()
{
	if (total != 0)
	{
		dataFile.open("Employee-Data.txt", ios::out);
		if (!dataFile)
		{
			system("CLS");

			cout << endl << endl;
			cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			cout << endl << endl;

			cout << "\t \t \t \t \t File not created!!";
		}

		else
		{
			system("CLS");
			dataFile << endl << endl;
			dataFile << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			dataFile << endl << endl;

			for (z = 0; z < total; z++)
			{

				dataFile << "\t \t \t \t \t Data of Employee " << z + 1;
				dataFile << endl << endl;
				dataFile << "\t \t \t \t \t Name Of Employee: " << e[z].name;
				dataFile << endl;
				dataFile << "\t \t \t \t \t ID Of Employee: " << e[z].id;
				dataFile << endl;
				dataFile << "\t \t \t \t \t Contact Of Employee: " << e[z].contact;
				dataFile << endl;
				dataFile << "\t \t \t \t \t Address Of Employee: " << e[z].address;
				dataFile << endl;
				dataFile << "\t \t \t \t \t Salary Of Employee: " << e[z].salary;
				dataFile << endl << endl << endl;
			}

			cout << "\t \t \t \t \t TASK COMPLETED SUCCESSFULLY!!";
			Sleep(1000);
			system("CLS");
		}
	}

	else
	{
		system("CLS");

		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;

		cout << "\t \t \t \t \t Your record is empty!!";
		Sleep(800);
	}
}

//Function to read data from file

void read()
{
	if (total != 0)
	{

		ifstream dataFile;
		dataFile.open("Employee-Data.txt", ios::in);

		if (!dataFile)
		{
			system("CLS");

			cout << endl << endl;
			cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
			cout << endl << endl;

			cout << "\t \t \t \t \t File not created!!";
		}
		else
		{
			system("CLS");

			string message;
			while (getline(dataFile, message))
			{
				cout << message;
				cout << endl;
				Sleep(1000);
			}
		}
	}

	else
	{
		system("CLS");

		cout << endl << endl;
		cout << "\t \t \t \t \t \t \t \t \t EMPLOYEE MANAGEMENT SYSTEM";
		cout << endl << endl;

		cout << "\t \t \t \t \t Your record is empty!!";
		Sleep(800);
	}
}