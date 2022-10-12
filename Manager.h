#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
class Manager : public Identity
{
public:

	//default construction
	Manager();
		//parameterized construction parameter:administrator's name¡¢password
		Manager(string name, string pwd);

	//Choose Menu
	virtual void operMenu();

	//Add account
	void addPerson();

	//View account
	void showPerson();

	//View computer room information
	void showComputer();

	//Clear appointment record
	void cleanFile();

	//Initialize the container
	void initVector();

	//Detect duplicates  Parameter 1 Detect student number and employee number;Parameter 2 Detection Type
	bool checkRepeat(int id , int type );
	
	//student container
	vector<Student> vStu;

	//teacher container
	vector<Teacher> vTea;

};