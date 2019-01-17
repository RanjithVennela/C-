#include<iostream>
#include<string>

using namespace std;

int len = 0;
class Person {
public:
	int Id;
	string firstName, lastName;

	void acceptData()
	{
		cout << "Enter Student Details" << endl;
		cout << "ID ";
		cin >> this->Id ;
		cout << "First Name ";
		cin.ignore();
		getline(cin,this->firstName);
		cout << "lastName ";
		getline(cin,this->lastName);
	}
};
class UgStudent :public Person {
public:


};
class Sports {
public:
	string sportsName;
};
class PgStudent : public UgStudent, public Sports {
public:


};

void displayDetails(PgStudent obj[], int siz)
{
	cout << "ID\tfirstname\tlastname" << endl;
	cout << siz << endl;
	for (int i = 0; i < siz; i++)
	{ 
			cout << obj[i].Id << " " << obj[i].firstName << " " << obj[i].lastName << " " << endl;
//		cout << obj[i].Id << " hello" << endl;
	}
}

void sortedData(PgStudent obj[], int siz)
{
	PgStudent temp;
	for (int i = 0; i < siz; i++)
	{
		for (int j = i + 1; j < siz; j++)
		{
			if (obj[i].Id > obj[j].Id)
			{
				temp = obj[i];
				obj[i] = obj[j];
				obj[j] = temp;
			}
		}
	}
}

void findStudent(PgStudent obj[], int id,int siz)
{
	int flag = 0;
	cout << "Required student details : " << endl;
	for (int i = 0; i < siz; i++)
	{
		if (obj[i].Id == id)
		{
			flag = 1;
			cout << obj[i].Id << " " << obj[i].firstName << " " << obj[i].lastName << " "<< endl;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "Enter Valid ID" << endl;
	}
}

void updateDetails(PgStudent obj[], int id, int siz)
{
	int flag = 0;
	string name1, name2;
	for (int i = 0; i < siz; i++)
	{
		if (obj[i].Id == id)
		{
			cout << "Enter new firstName, lastName, group : " << endl;
			cin >> name1 >> name2;
			obj[i].firstName = name1;
			obj[i].lastName = name2;
			
			cout << "Details got updated" << endl;
		}
	}
}

void deleteDetails(PgStudent obj[], int id, int siz)
{
	for (int i = 0; i < siz; i++)
	{
		if (obj[i].Id == id)
		{
			for (int j = i + 1; j < siz; j++)
			{
				PgStudent temp;
				temp = obj[i];
				obj[i] = obj[j];
				obj[j] = temp;
				i++;
			}
			len--;
			break;
		}
	}
}


int main() {
	PgStudent stdObj[20];
	int n, id;
	
	while (1)
	{
		cout << "Enter 1 to store student details" << endl;
		cout << "Enter 2 to display all student details" << endl;
		cout << "Enter 3 to get sorted student details using ID" << endl;
		cout << "Enter 4 to find a student using ID" << endl;
		cout << "Enter 5 to update student details using ID" << endl;
		cout << "Enter 6 to delete student details using ID" << endl;
		cout << "Enter 7 to exit" << endl;
		cin >> n;
		if (n == 7)
		{
			break;
		}
		else
		{
			switch (n)
			{
			case 1:	
					stdObj[len].acceptData();
					len++;
					break;
			case 2:	
					displayDetails(stdObj, len);
					break;
			case 3:	sortedData(stdObj, len);
					break;
			case 4:
					cout << "Enter student ID to get the student details : " << endl;
					cin >> id;
					findStudent(stdObj, id, len);
					break;
			case 5:	cout << "Enter Id of the student to update the details : " << endl;
					cin >> id;
					updateDetails(stdObj, id, len);
					break;
			case 6: cout << "Enter Id of the student to delete the details : " << endl;
					cin >> id;
					deleteDetails(stdObj, id, len);
					break;
			}
			
		}
	}
}
