#pragma once
#include<iostream>
using namespace std;
#include <map>
#include "globalFile.h"
#include <map>
#include<string>

class OrderFile
{
public:

	//Constructor
	OrderFile();

	//Update appointment record
	void updateOrder();

	//record container  key --- number of records   value --- Key-value pair information for specific records
	map<int, map<string, string>> m_orderData;

	//Number of appointment records
	int m_Size;
};
