#include "Client.h"
#include"Product.h"
Client::Client(int i) :id(i)
{}
int Client::getId() const
{
	return id;
}
Cart Client::getCart()
{
	return ClientCart;
}
void Client::push(ProductNode_p& Node)
{
	ClientCart.addInfo(Node.get()->Info.get()->Parcode, Node.get()->Info.get()->Name);
}
ProductNode_p& Client::pop()
{
	return ClientCart.popFront();
}



Queue::Queue():Front(NULL)
{
	;
}

Queue::Queue(Client_p& C)
{
	ClientNode_p  CNtemp(new ClientNode());
	CNtemp->Data = C;
	Front = CNtemp;

}


void Queue::push(Client& p) {
	Client_p Cp(& p);
	for (ClientNode_p temp = Front; temp; temp = temp->Next) {
		if (temp->Next) continue;
		else {
			ClientNode_p  CNtemp(new ClientNode());
			CNtemp->Data = Cp;
			temp->Next = CNtemp;
		}
	}
}



ClientNode_p& Queue::pop() {
	ClientNode_p* CNtemp = &Front;
	Front = Front->Next;
	return *CNtemp;
}

ClientNode::ClientNode() :Data(NULL), Next(NULL)
{}
ClientNode_p& Queue::getFront()
{
	return Front;
}
void Queue::ServeClient()
{
	ClientNode_p dump = getFront();
	while (dump)
	{
		pop();
	}
}



ostream& operator<< (ostream& output, Client& C) {
	output << "Client ID " << C.getId();
	for (ProductNode_p temp = C.getCart().getFront(); temp; temp = temp->Next) {
		output << temp->Info << " Amount " << temp->Amount;
	}
	return output;
}

ostream& operator<< (ostream& output, ClientNode& C) {
	return output << C.Data;
}
