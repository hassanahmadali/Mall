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
void Client::push(ProductNode* Node)
{
	ClientCart.addInfo(Node->Info->Parcode, Node->Info->Name);
}
ProductNode* Client::pop()
{
	return ClientCart.popFront();
}



Queue::Queue():Front(NULL)
{
	;
}

Queue::Queue(Client* C)
{
	ClientNode*  CNtemp(new ClientNode());
	CNtemp->Data = C;
	Front = CNtemp;

}


void Queue::push(Client& p) {
	Client* Cp(& p);
	for (ClientNode* temp = Front; temp; temp = temp->Next) {
		if (temp->Next) continue;
		else {
			ClientNode*  CNtemp =new ClientNode();
			CNtemp->Data = Cp;
			temp->Next = CNtemp;
		}
	}
}



ClientNode* Queue::pop() {
	ClientNode* CNtemp = Front;
	Front = Front->Next;
	return CNtemp;
}

ClientNode::ClientNode() :Data(NULL), Next(NULL)
{}
ClientNode* Queue::getFront()
{
	return Front;
}
void Queue::ServeClient()
{
	ClientNode* dump = getFront();
	while (dump)
	{
		pop();
	}
}



ostream& operator<< (ostream& output, Client& C) {
	output << "Client ID " << C.getId();
	for (ProductNode* temp = C.getCart().getFront(); temp; temp = temp->Next) {
		output << temp->Info << " Amount " << temp->Amount;
	}
	return output;
}

ostream& operator<< (ostream& output, ClientNode& C) {
	return output << C.Data;
}
