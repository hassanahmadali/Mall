#pragma once
#include "Product.h"
#ifndef CLIENT_H

class Client {
	int id;
	Cart ClientCart;
	Client();
public:
	Client(int);
	int getId()const;
	Cart getCart();
	void push(ProductNode*);
	ProductNode* pop();
};
class ClientNode {
public:
	ClientNode();
	Client* Data;
	ClientNode* Next;
};

class Queue {
	ClientNode* Front;
public:
	Queue();
	Queue(Client*);
	void push(Client&);
	ClientNode* getFront();
	ClientNode* pop();
	void ServeClient();
};

#endif