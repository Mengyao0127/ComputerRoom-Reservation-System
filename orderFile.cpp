#include "orderFile.h"

//Constructor
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //date
	string interval;  //interval
	string stuId;     //student id 
	string stuName;   //student name 
	string roomId;    //room id 
	string status;    //status


	this->m_Size = 0; //Number of appointment records

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//test code
		/*
		cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		*/

		string key;
		string value;
		map<string, string> m;

		//Truncation interval
		int pos = date.find(":");  //4
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//Truncate name
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//Intercept computer room information
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		//Intercept state
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//Put a small map container into a large map container
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	//test code
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end();it++)
	//{
	//	cout << "key = " << it->first << " value = " << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << mit->first << " " << mit->second << " ";
	//	}
	//	cout << endl;
	//}

	ifs.close();

}

//Update appointment record
void OrderFile::updateOrder() {
	if (this->m_Size == 0)
	{
		return; //The reservation record is 0, return
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();

}