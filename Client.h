#pragma once
#include "Product.h"

class Client {
	Cart *ClientCart;
	Client();
public:
	Client(int);
	const int id;
	ProductNode* addInfo(string P , int A = 0 , string N = "unKnown Product Name! ");
	void pop();
	ProductNode* getFront();

};
class ClientNode {
public:
	ClientNode(int id);
	Client* Data;
	ClientNode* Next;
};

class Queue {
public:
	ClientNode* Front;
	Queue(int id );
	ClientNode* push(int id);
	void pop();
	ClientNode* getFront();
	void ServeClient();
	
};
