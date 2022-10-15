#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include "orderFile.h"
#include <vector>
//Teacher Class
class Teacher : public Identity
{
public:

	//default construction
	Teacher();
	//parameterized construction parameter:employee ID¡¢name¡¢password
	Teacher(int empId, string name, string pwd);
	//Menu
	virtual void operMenu();

	//View all appointment
	void showAllOrder();

	//Check  appointment
	void validOrder();

	//Employee ID
	int m_EmpId;

};