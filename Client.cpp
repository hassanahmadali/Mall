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
	return ClientCart.popFront();
}

Queue::Queue(Client_p& C)
{
	ClientNode_p  CNtemp(new ClientNode());
	CNtemp->Data = C;
	Front = CNtemp;

}


void Queue::push(Client_p& Cp) {
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
	ClientNode_p *CNtemp =& Front;
	Front = Front->Next;
	return *CNtemp;
}

ClientNode::ClientNode() :Data(NULL), Next(NULL)
{

}