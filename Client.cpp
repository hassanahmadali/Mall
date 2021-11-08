#include "Client.h"

Client::Client(int I) :id(I), ClientCart(NULL)
{
	;
}

ProductNode* Client::addInfo(string P, int A, string N)
{
	ProductNode* new_ProductNode;
	if (ClientCart) {
		new_ProductNode = ClientCart->addInfo(P, 0, N);
	}
	else {
		ClientCart = new Cart(P, 0, N);
		new_ProductNode = ClientCart->addInfo(P, 0, N);
	}
	ProductNode* Mall_Node = Cart::MallProducts->addInfo(P, 0, N);
	if (Mall_Node->Amount <= A) {
		cout << "there is not enough prouducts in the mall returned all amount in the mall which is " << Mall_Node->Amount;
		new_ProductNode->Amount += Mall_Node->Amount;
		Mall_Node->Amount = 0;
		return new_ProductNode;
	}
	else {
		Mall_Node->Amount -= A;
		new_ProductNode->Amount += A;
		return new_ProductNode;
	}
}

void Client::pop()
{
	if (ClientCart) {
		ClientCart->Data->popFront();
	}
}

ProductNode* Client::getFront()
{
	if (ClientCart) {
		return ClientCart->Data->getFront();
	}
	return NULL;
}


ClientNode::ClientNode(int id)
{
	Data = new Client(id);
	Next = NULL;
}

Queue::Queue(int id) {
	Front = new ClientNode(id);
}

ClientNode* Queue::push(int id) {
	ClientNode* temp_ClientNode = Front;
	if (Front) {
		for (; temp_ClientNode; temp_ClientNode = temp_ClientNode->Next) {
			if (temp_ClientNode->Next == NULL) {
				break;
			}
			else
				if (temp_ClientNode->Data->id == id)
					return temp_ClientNode;
		}
		temp_ClientNode->Next = new ClientNode(id);
		return temp_ClientNode->Next;

	}

	else {
	Front = new ClientNode(id);
	return Front;
	}
}

void Queue::pop() {
	Front = Front->Next;
}

ClientNode* Queue::getFront()
{
	return Front;
}

void Queue::ServeClient()
{
	pop();
}

