#include <iostream>
#include "Mall.h"
using namespace std;
int main() {
	Mall m;
	cout << "HELLO" << endl;
	m.Products->addtoMallproducts("milk", "12", 3);
	cout << Mall::Products->getFront()->Info;
	return 0;
}