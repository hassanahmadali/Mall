#pragma once

#include <string>
#include <iostream>
#include <iomanip>


using namespace std;


class ProductInfo {
public:
	ProductInfo(int, string);
	const string Name;
	const int Parcode;
	bool operator==(ProductInfo&)const;
	bool operator==(int)const;
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
	shared_ptr<ProductNode>& addInfo(int, string = "unKnown!");
	shared_ptr<ProductNode>& popFront();
};