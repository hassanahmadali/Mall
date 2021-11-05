#include "Client.h"
#include"Product.h"
Client::Client(int i) :id(i)
{}
int Client::getId() const
{
	return id;
}
void Client::push(ProductNode_p Node)
{
	ClientCart.addInfo(Node.get()->Info.get()->Parcode, Node.get()->Info.get()->Name);
}
ProductNode_p& Client::pop()
{
	return ClientCart.pop();
}

Queue::Queue(Client_p& C)
{
	ClientNode_p  CNtemp (new ClientNode());
	CNtemp->Data = C;
	Front = CNtemp;
}

Client_p Queue::get()const {

}
void Queue::push(Client_p) {

}

void Queue::pub() {

}