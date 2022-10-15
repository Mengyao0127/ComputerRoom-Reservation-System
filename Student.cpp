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
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "No appointment record" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		//string converse to int
		//string use .c_str() converse to const char *  
		//use atoi (const char*) converse to int
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)//Find your own appointment
		{
			cout << "Appointment Date: Week" << of.m_orderData[i]["date"];
			cout << " Interval£º" << (of.m_orderData[i]["interval"] == "1" ? "morning" : "afternoon");
			cout << "Computer room£º" << of.m_orderData[i]["roomId"];
			string status = " Status£º ";  // 0 Cancelled appointment   1 under review   2 reserved -1 Appointment failed
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "under review";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "Appointment successful";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "Approval failed, booking failed";
			}
			else
			{
				status += "Appointment cancelled";
			}
			cout << status << endl;

		}
	}

	system("pause");
	system("cls");


}
//View all appointment
void Student::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "No appointment record" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "¡¢ ";

		cout << "Appointment Date: Week" << of.m_orderData[i]["date"];
		cout << " Interval£º" << (of.m_orderData[i]["interval"] == "1" ? "morning" : "afternoon");
		cout << " Student id£º" << of.m_orderData[i]["stuId"];
		cout << " Name£º" << of.m_orderData[i]["stuName"];
		cout << " Computer room£º" << of.m_orderData[i]["roomId"];
		string status = " Status£º ";  // 0 Cancelled appointment   1 under review   2 reserved -1 Appointment failed
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "under review";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "Appointment successful";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "Approval failed, booking failed";
		}
		else
		{
			status += "Appointment cancelled";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");


}
//Cancel your appointment
void Student::cancelOrder() {

	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "No appointment record" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Records under review or reservations can be cancelled, please enter the cancelled record" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)  //First judge that it is your own student number
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")  //Rescreen status Under review or appointment is successful
			{
				v.push_back(i);
				cout << index++ << "¡¢ ";
				cout << "Appointment Date: Week" << of.m_orderData[i]["date"];
				cout << " Interval£º" << (of.m_orderData[i]["interval"] == "1" ? "ÉÏÎç" : "ÏÂÎç");
				cout << " Computer room£º" << of.m_orderData[i]["roomId"];
				string status = "Status£º ";  // 0 Cancelled appointment   1 under review   2 reserved  -1 Appointment failed
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "under review";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "Appointment successful";
				}
				cout << status << endl;

			}
		}
	}

	cout << "Please enter the canceled record, 0 means return" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//	cout << "record location£º " << v[select - 1] << endl;
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "Appointment cancelled" << endl;
				break;
			}

		}
		cout << "Incorrect input, please try again" << endl;
	}

	system("pause");
	system("cls");

}

