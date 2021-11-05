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
	void push(ProductNode_p);
	ProductNode_p& pop();
};
typedef shared_ptr<Client> Client_p;

class ClientNode {
public:
	ClientNode();
	Client_p Data;
	shared_ptr<ClientNode> Next;
};
typedef shared_ptr<ClientNode> ClientNode_p;

class Queue {
	Queue();
	ClientNode_p Front;
public:
	Queue(Client_p&);
	void push(Client_p&);
	ClientNode_p& pub();

};

#endif