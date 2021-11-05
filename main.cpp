#include <iostream>
#include "Mall.h"
#include<string>
using namespace std;
int main() {
	Mall m;
	int x;
	cout << "HELLO" << endl
		<< "How many time you want to use program?" << endl;
	cin >> x;
	//m.Products->addtoMallproducts("milk", "12", 3);
	//cout << Mall::Products->getFront()->Info;
	while (x > 0)
	{
		cout << "Choose Number:" << endl
			<< "1.Add Product to mall" << endl
			<< "2.Add client to queue" << endl
			<< "3.Add product to cart of client" << endl
			<< "4.Serve client" << endl;
		switch (x)
		{
		case(1):
		{
			string name, parcode;
			int amount;
			cout << "Enter Name,Code,amount of product" << endl;
			cin >> name >> parcode >> amount;
			m.Products->addtoMallproducts(name, parcode, amount);
			break;
		}
		case(2):
		{
			int y; int id;
			cout << "How many client you need?" << endl;
			cin >> y;
			while (y > 0)
			{
				cout << "Enter client id" << endl;
				cin >> id;
				y--;
			}
		}
		}
				
		x-- ;
	}
	
	return 0;
}