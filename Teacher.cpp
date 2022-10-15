#include "Teacher.h"


	//default construction
Teacher::Teacher() {

}
	//parameterized construction parameter:employer ID¡¢name¡¢password
Teacher::Teacher(int empId, string name, string pwd) {
	//Initialize properties
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}
	//teacher Menu
 
	 //Teacher menu interface
	 void Teacher::operMenu()
	 {
		 cout << "Welcome teachers£º" << this->m_Name << "Log in£¡" << endl;
		 cout << "\t\t ----------------------------------\n";
		 cout << "\t\t|                                  |\n";
		 cout << "\t\t|          1.View all appointments |\n";
		 cout << "\t\t|                                  |\n";
		 cout << "\t\t|          2.Review appointment    |\n";
		 cout << "\t\t|                                  |\n";
		 cout << "\t\t|          0.logout                |\n";
		 cout << "\t\t|                                  |\n";
		 cout << "\t\t ----------------------------------\n";
		 cout << "Please select your action£º " << endl;
	 }



	//View all appointment
void Teacher::showAllOrder() {
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
		cout << "Interval£º" << (of.m_orderData[i]["interval"] == "1" ? "morning" : "afternoon");
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



	//Check  appointment
void Teacher::validOrder() {

	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "No appointment record" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "The appointment records to be reviewed are as follows£º" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "¡¢ ";
			cout << "Appointment Date: Week" << of.m_orderData[i]["date"];
			cout << " Interval£º" << (of.m_orderData[i]["interval"] == "1" ? "ÉÏÎç" : "ÏÂÎç");
			cout << " Computer room£º" << of.m_orderData[i]["roomId"];
			string status = " Status£º ";  // 0Cancelled appointment   1 under review   2 reserved  -1 Appointment failed
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "under review";
			}
			cout << status << endl;
		}
	}
	cout << "Please enter the audited appointment record, 0 means return" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "Please enter the audit result" << endl;
				cout << "1¡¢Pass" << endl;
				cout << "2¡¢Fail" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "Review completed£¡" << endl;
				break;
			}
		}
		cout << "Incorrect input, please try again" << endl;
	}

	system("pause");
	system("cls");
}

	