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
typedef shared_ptr<ProductInfo> ProductInfo_p;

class ProductNode {
public:
	int Amount;
	ProductNode();
	shared_ptr<ProductInfo> Info;
	shared_ptr<ProductNode> Next;
};

typedef shared_ptr<ProductNode> ProductNode_p;


class Cart {
private:
	shared_ptr<ProductNode> Front;
public:
	Cart();
	ProductNode_p& getFront();
	void addtoClientCart(string,int);
	void addtoMallproducts(string, string, int);
	shared_ptr<ProductNode>& addInfo(string, string = "unKnown!");
	shared_ptr<ProductNode>& popFront();
};