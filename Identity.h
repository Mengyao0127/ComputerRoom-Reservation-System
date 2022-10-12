#pragma once //  Prevent header files from being repeatedly included
#include<iostream>
using namespace std;

class Identity //Identity abstract base class
{
public:

	virtual void operMenu() = 0; //Action menu    pure virtual function
	string m_Name; //username
	string m_Pwd;  //password    


};