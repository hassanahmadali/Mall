#pragma once

#include <string>
#include <iostream>
#include <iomanip>


using namespace std;


class ProductInfo {
public:
	ProductInfo(string, string);
	string Name;
	const string Parcode;
	bool operator==(ProductInfo&)const;
	bool operator==(string)const;
};

class ProductNode {
public:
	int Amount;
	ProductNode();
	ProductInfo* Info;
	ProductNode* Next;
};

class Cart {
private:
	ProductNode* Front;
public:
	Cart();
	ProductNode* getFront();
	void addtoClientCart(string, int);
	void addtoMall(string, string, int);
	ProductNode* addInfo(string, string = "unKnown!");
	ProductNode* popFront();
};