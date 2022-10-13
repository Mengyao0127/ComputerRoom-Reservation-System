#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <vector>
#include"computerRoom.h"
#include <fstream>
#include"globalFile.h"

//Student Class
class Student : public Identity
{
public:

	//default construction
	Student();
	//parameterized construction parameter:student ID¡¢name¡¢password
	Student(int id,string name,string pwd);
	//Menu
	virtual void operMenu();
	 
	//Appointment application
	void applyOrder();
	//View your own appointment
	void showMyOrder();
	//View all appointment
	void showAllOrder();
	//Cancel your appointment
	void cancelOrder();
	
	//Student ID
	int m_Id;
	//computer room container
	vector<ComputerRoom> vCom;


};