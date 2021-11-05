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
	void pop();
};

typedef shared_ptr<Client> Client_p;
class ClientNode {
	ClientNode();
public:
	Client_p Data;
	shared_ptr<ClientNode> Next;
	shared_ptr<Client> Previuse;
};
typedef shared_ptr<ClientNode> ClientNode_p;

class Queue {
	Queue();
	ClientNode_p First;
public:
	Queue(Client_p);
	Client_p get() const;
	void push(Client_p);
	void pub();
};

#endif