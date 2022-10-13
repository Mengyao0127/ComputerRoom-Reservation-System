#include "Student.h"






//default construction
Student::Student()
{


}
//parameterized construction parameter:student ID¡¢name¡¢password
Student::Student(int id,string name, string pwd)
{
	//Initialize properties
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//Initialize computer room information
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{//Put the read information into the container
		vCom.push_back(com);
	}

	ifs.close();

}
//Menu
void Student::operMenu() {

	cout << "Welcome student£º" << this->m_Name << "Log in£¡" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         1.Request an Appointment|\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         2.View my appointment   |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         3.View all appointments |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         4.cancel appointment    |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|         0.Log out               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "Please select your action£º " << endl;

 }

//Appointment application
void Student::applyOrder() {

	cout << "The computer room is open Monday to Friday£¡" << endl;
	cout << "Please enter the time to apply for an appointment£º" << endl;
	cout << "1¡¢Monday" << endl;
	cout << "2¡¢Tuesday" << endl;
	cout << "3¡¢Wednesday" << endl;
	cout << "4¡¢Thursday" << endl;
	cout << "5¡¢Friday" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "Incorrect input, please try again" << endl;
	}


	cout << "Please enter the time slot for requesting an appointment£º" << endl;
	cout << "1¡¢morning" << endl;
	cout << "2¡¢afternoon" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "Incorrect input, please try again" << endl;
	}

	cout << "Please select a room£º" << endl;
	cout << "No. 1 computer room capacity£º" << vCom[0].m_MaxNum << endl;
	cout << "No. 2 computer room capacity£º" << vCom[1].m_MaxNum << endl;
	cout << "No. 3 computer room capacity£º" << vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "Incorrect input, please try again" << endl;
	}

	cout << "Appointment successful! under review" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}
//View your own appointment
void Student::showMyOrder() {



}
//View all appointment
void Student::showAllOrder() {



}
//Cancel your appointment
void Student::cancelOrder() {



}

