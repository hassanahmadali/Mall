#include <iostream>
#include "Mall.h"
#include<string>
using namespace std;
int main() {
	Mall m;
	string name, parcode;
	int x, id, amount;
	cout << "HELLO" << endl;

	do {
		cout << "Choose Number:" << endl
			<< "1. Add Product to mall" << endl
			<< "2. Add client to queue" << endl
			<< "3. Add product to cart of client" << endl
			<< "4. Serve client" << endl
			<< "5. show all Clients" << endl
			<< "0. exit" << endl;
		cin >> x;
		switch (x)
		{
		case(1):
		{
			cout << "Enter Name,Parcode,Amount of product" << endl;
			cin >> name >> parcode >> amount;
			Mall::Products->addtoMall(name, parcode, amount);
			break;
		}
		case(2):
		{
			cout << "Enter client id" << endl;
			cin >> id;
			Client c(id);
			m.Q.push(c);
			break;
		}

		case(3):
		{
			cout << "enter Client id" << endl;
			cin >> id;
			cout << "Enter Parcode,needed amount of product" << endl;
			cin >> parcode >> amount;
			//ProductNode_p* dump = new ProductNode_p(new ProductNode());
			for (ClientNode_p temp = m.Q.getFront(); temp; temp = temp->Next) {
				if (temp->Data->getId() == id)
				{
					temp->Data->getCart().addtoClientCart(parcode, amount);
					break;
				}
			}
			break;
		}
		case(4):
		{
			m.Q.ServeClient();
			break;
		}
		case(5):
		{
			for (ClientNode_p temp = m.Q.getFront(); temp; temp = temp->Next) {
				cout << temp->Data;
			}
			break;
		}
		case(0):
			cout << "Good bye." << endl;
			break;
		}
	} while (x != 0);

	return 0;
}