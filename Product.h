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

class ProductNode {
public:
	int Amount;
	ProductNode();
	shared_ptr<ProductInfo> Info;
	shared_ptr<ProductNode> Next;
};


class Cart {
private:
	shared_ptr<ProductNode> Front;
public:
	Cart();
	void Test();
	shared_ptr<ProductNode>& addInfo(int, string = "unKnown!");
	ProductNode_p& pop_front();
};

typedef shared_ptr<ProductInfo> ProductInfo_p;
typedef shared_ptr<ProductNode> ProductNode_p;