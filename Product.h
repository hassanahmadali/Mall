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
	ProductNode();
public:
	int Amount;
	ProductNode(string, string, int = 0);
	ProductInfo* Info;
	ProductNode* Next;
};

class ProductList {
private:
	ProductNode* Front;
	ProductList();
public:
	ProductList(string, string, int = 0);
	void addtoList(string, int);
	ProductNode* addInfo(string, string = "unKnown!");
	ProductNode* getFront();
	void popFront();
	static ProductList* MallProducts;
};

class Cart {
	Cart();
public:
	ProductList* Data;
	Cart(string, string, int = 0);
};
