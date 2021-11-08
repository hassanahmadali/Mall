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
ostream& operator<<(ostream& output, ProductInfo& rhs);
ostream& operator<<(ostream& output, ProductInfo* rhs);


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
	ProductList(string P, string N = "unKnown Product Name! ", int = 0);
	ProductNode* addInfo(string P, int A = 0, string N = "unKnown Product Name! ");
	ProductNode* getFront();
	void popFront();
};

ostream& operator<< (ostream& output, ProductList& C);

class Cart {
	Cart();
public:

	static ProductList* MallProducts;
	ProductList* Data;
	Cart(string P, int A =0, string N = "unKnown Product Name!");
	ProductNode* addInfo(string P, int A = 0, string N = "unKnown Product Name! ");
};

ProductList* Cart::MallProducts = new ProductList("0");