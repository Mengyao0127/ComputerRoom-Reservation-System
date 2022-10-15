#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
 
//Enter the student submenu
void studentMenu(Identity*& student)
{
	while (true)
	{
		//student menu
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //apply reservation
		{
			stu->applyOrder();
		}
		else if (select == 2) //view your order
		{
			stu->showMyOrder();
		}
		else if (select == 3) //view all order
		{
			stu->showAllOrder();
		}
		else if (select == 4) //cancel your order
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "Log out successfully!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//Teacher Menu
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//teacher menu
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//View all appointments
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//Review appointment
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "Logout succeeded!" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}










//Enter the administrator submenu
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//Invoke the admin submenu
		manager->operMenu();

		//Convert parent class pointer to child class pointer,invoke other interfaces in the subclass
		Manager* man = (Manager*)manager;

		int select = 0;
		//Accept user options
		cin >> select;

		if (select == 1) //Add account
		{
			cout << "add account" << endl;
			man->addPerson();
		}
		else if (select == 2) //View account
		{

			cout << "view account" << endl;
			man->showPerson();
		}
		else if (select == 3) //view computer room

		{
			cout << "view computer room" << endl;
			man->showComputer();
		}

		else if (select == 4)  //Clear appointment
		{

			cout << "clear appointment" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;  //destroy object
			cout << "Logout succeeded" << endl;
			system("pause");
			system("cls");
			return;
		}


	}

}
//Log in Function    parameter 1   Action file name   parameter 2  Operational Identity Type
void LoginIn(string fileName, int type)
{

	//parent class pointer,Used to point to subclass objects
	Identity* person = NULL;

	//reading file 
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//Check if the file exists
	if (!ifs.is_open())
	{
		cout << "file does not exist" << endl;
		ifs.close();
		return;

	}

	//Ready to receive user information
	{
		int id = 0;
		string name;
		string pwd;

		//Judging identity
		if (type == 1)  //Student
		{
			cout << "Please enter your student number:   " << endl;
			cin >> id;

		}

		else if (type == 2) //teacher
		{
			cout << "Please enter your employee number:   " << endl;
			cin >> id;
		}


		cout << "please enter user name:   " << endl;
		cin >> name;

		cout << "please enter password:   " << endl;
		cin >> pwd;


		if (type == 1)
		{
			//student identity verification
			int fId; //ID number read from file
			string fName;  //name read from file
			string fPwd;  //password read from file
			while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

				//Compare with the information entered by the user
				if (fId == id && fName == name && fPwd == pwd)

					cout << "Student login successfully!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//Go to the Student Status submenu
				studentMenu(person);
				return;
			}
		}
	
	else if (type == 2)
	{
			//teacher identity verification
			int fId;   //ID number read from file
			string fName;  //name read from file
			string fPwd;   //password read from file
			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (fId == id && fName == name && fPwd == pwd)
					cout << "Teacher login successfully!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//Go to Teacher Submenu
				TeacherMenu(person);
				return;
			}

	}

	else if (type == 3)
	{
			//administrator identity verification
			string fName;  //name read from file
			string fPwd;   //password read from file
			while ( ifs >> fName && ifs >> fPwd)
			{
				if (fName == name && fPwd == pwd)
					cout << "Manager login successfully!" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				//Go to Manager Submenu
				managerMenu(person);
				return;
			}

	}

		cout << "failed to login!" << endl;
		
		
		system("pause");
		system("cls");

		return;
	}


	int main();
	{
		int select = 0; //Used to receive user selections

		while (true)
		{ 


		cout << "-----Welcome to computer room reservation system--------"
			<< endl;
		cout << endl << "Please enter your identity" << endl;
		cout << "\t\t---------------------------------------\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|     1.Student                       |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|     2.Teacher                       |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|     3.Manager                       |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t|     0.Sign out                      |\n";
		cout << "\t\t|                                     |\n";
		cout << "\t\t---------------------------------------\n";
		cout << "Enter your choice: ";

		cin >> select; //Used to receive user selections

		switch (select) //Different interfaces can be linked according to user selection
		{
		case 1://Student
			
			LoginIn(STUDENT_FILE, 1);

				break;
		case 2://Teacher

			LoginIn(TEACHER_FILE, 2);

			    break;
		case 3://Manager

			LoginIn(ADMIN_FILE, 3);

			    break;
		case 0://Sign out
			cout << "Welcome to use next time" << endl;
			system("pause");
			return;
			break;
		default:
			cout << "Incorrect input, please try again!" << endl;
			system("pause");
			system("cls");
			break;
		}


	}



	return;
}