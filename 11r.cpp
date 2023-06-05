#include <iostream>
#include <fstream>
using namespace std;

class stud
{
  public:
	string name;
	string address;
	int rollno;
	char div;
	stud()
	{
		name = "";
		address = "";
		rollno = -1;
		div = ' ';
	}
};

string filename = "info.txt";

void getinfo(string name, string address, int rollno, char div)
{
	ofstream rec(filename, ios::app);
	stud student;
	
	student.name = name;
	student.address = address;
	student.rollno = rollno;
	student.div = div;
	
	if (rec.write((char *)&student, sizeof(student)))
		cout << "successfully written into file\n";
	else
		cout << "failed to write\n";

	cout << endl;
	rec.close();
}

void displayAllRec()
{
	ifstream rec(filename);

	stud student;
	bool recordsFound = false;

	while (rec.read((char *)&student, sizeof(student)))
	{
		cout << "Name: " << student.name << endl;
		cout << "Address: " << student.address << endl;
		cout << "Roll number: " << student.rollno << endl;
		cout << "Division: " << student.div << endl;
		cout << endl;
		recordsFound = true;
	}
	rec.close();

	if (!recordsFound)
	{
		cout << "No records found!" << endl;
	}
}

void del(int rollno)
{
	ifstream rec(filename);

	stud student;
	bool recordsFound = false;
	string tempfile = "temp.txt";
	ofstream temp(tempfile);

	while (rec.read((char *)&student, sizeof(student)))
	{
		if (student.rollno != rollno)
		{
			temp.write((char *)&student, sizeof(student));
		}
		else
		{
			recordsFound = true;
		}
	}
	
	temp.close();
	rec.close();
	
	if(!recordsFound) {
		cout<<"No such record found!";
		return;
	}
	

	if (!remove(filename.c_str()) && !rename(tempfile.c_str(), filename.c_str()))
	{
		cout << "Record succesfully deleted!";
	}
	else
	{
		cout << "Record couldn't delete!";
	}
}

void find(int rollno) {
	stud student;
	bool recordsFound = false;
	ifstream rec(filename);
	
	while(rec.read((char*)&student,sizeof(student))) {
		if(student.rollno==rollno) {
			cout << "Name: " << student.name << endl;
			cout << "Address: " << student.address << endl;
			cout << "Roll number: " << student.rollno << endl;
			cout << "Division: " << student.div << endl;
			cout << endl;
			recordsFound = true;
		}
	}
	rec.close();
	
	if(!recordsFound) {
		cout<<"No such record found!";
		return;
	}
}

int main()
{
	int choice;
	string name, address;
	int rollno; char div;
	
	do
	{
		cout << "Menu" << endl;
		cout << "1. Enter student record" << endl;
		cout << "2. Display student record" << endl;
		cout << "3. Delete student record" << endl;
		cout << "4. Find student record" <<endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		
		switch (choice)
		{
		case 1:
			cout << "Enter name: ";
			getline(cin, name);

			cout << "Enter address: ";
			getline(cin,address);
		
			cout << "Enter roll number: ";
			cin >> rollno;
		
			cout << "Enter division: ";
			cin >> div;
	
			getinfo(name, address, rollno, div);
			break;
			
			
		case 2:
			displayAllRec();
			break;
			
			
		case 3:
			cout << "Enter roll no which is to be deleted: ";
			cin >> rollno;
			del(rollno);
			break;
			
			
		case 4:
			cout<<"Enter roll no which is to be displayed: ";
			cin>>rollno;
			find(rollno);
			break;
			
			
		case 5:
			cout << "Exiting the program..." << endl;
			break;
			
			
		default:
			cout << "Invalid choice. Please try again." << endl;
		}

	} while (choice != 5);

	return 0;
}