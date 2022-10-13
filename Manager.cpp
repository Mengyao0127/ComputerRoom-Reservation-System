#include "Manager.h"

//default construction
Manager::Manager() {


}

//parameterized construction parameter:Manager's name¡¢password
Manager::Manager(string name, string pwd) {
	//Initialize administrator information
	this->m_Name = name;
	this->m_Pwd = pwd;

//Initialize the container  get all files students¡¢teachers information
	this->initVector();

	//Initialize computer room information
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "The number of rooms is:  "<< vCom.size() << endl;

}

//Choose Menu
void Manager::operMenu() {
	cout << "Welcome administrator£º" << this->m_Name << "Log in£¡" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.add account         |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.view account        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.view computer room  |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.clear appointment   |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.   logout           |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "Enter your choice£º " << endl;

}

//Add account
void Manager::addPerson() {
	cout << "Please enter the type of account to add" << endl;
	cout << "1¡¢Add student" << endl;
	cout << "2¡¢Add teacher" << endl;

	string fileName;  //Action file name
	string tip;   //prompt id
	string errorTip; //Repeat error message
	ofstream ofs;  //file operation object

	int select = 0;
	cin >> select;  //Accept user options

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "Please enter student id£º ";
		errorTip = "Duplicate student ID, please re-enter:   ";

	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "Please enter employee id£º";
		errorTip = "The employee number is duplicated, please re-enter :   ";
	}
	//Write file by appending
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)   //there are repetitions
		{
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}


	
	cin >> id;

	cout << "Please enter your name£º " << endl;
	cin >> name;

	cout << "Please enter your password£º " << endl;
	cin >> pwd;

	//Add data to the file
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "Add successfully!" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//Call the initialization container interface,Retrieve the data in the file
	this->initVector();
}
void printStudent(Student & s) {
	cout << "Student id:  " << s.m_Id << "Name:  " << s.m_Name << "Password:  " << s.m_Pwd << endl;
}
void printTeacher(Teacher& s) {
	cout << " Employee id:  " << s.m_EmpId << "Name:  " << s.m_Name << "Password:  " << s.m_Pwd << endl;
}

//View account
void Manager::showPerson() {
	cout << "Please select to view content:  " << endl;
	cout << "1.View all students" << endl;
	cout << "2.View all teachers" << endl;

	int select = 0; //Receive user selection
	cin >> select;

	if (select == 1) {

		 //View students
		cout << "All student information below:  " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {

		//view teachers

		cout << "All teacher information below:  " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//View computer room information
void Manager::showComputer() {
	cout << "The room information is as follows:  " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "Room number:  " << it->m_ComId << "The maximum capacity of the computer room:  " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");

}

//Clear appointment record
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "Cleared successfully!" << endl;
	system("pause");
	system("cls");

}

//Initialize the container
void Manager::initVector()
{

vStu.clear();
vTea.clear();

//Read information from student files
ifstream ifs;
ifs.open(STUDENT_FILE, ios::in);
if (!ifs.is_open())
{
	cout << "file read failed" << endl;
	return;
}

vStu.clear();
vTea.clear();

Student s;
while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
{
	vStu.push_back(s);
}
cout << "The current number of students is£º " << vStu.size() << endl;
ifs.close(); //student initialization

//Read teacher file information
ifs.open(TEACHER_FILE, ios::in);

Teacher t;
while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
{
	vTea.push_back(t);
}
cout << "The current number of teachers is£º " << vTea.size() << endl;

ifs.close();
}

//Detect duplicates  Parameter 1 Detect student number and employee number;Parameter 2 Detection Type
bool Manager::checkRepeat(int id, int type) {

	if (type == 1) {
		//test students
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id) {
				return true;

			}

		}
	}
	else {

		//test teachers
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId) {
				return true;

			}

		}



	}

	return false;

}
