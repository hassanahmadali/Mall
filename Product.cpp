#include "Product.h"
#include"Mall.h"
#include <string>
ProductInfo::ProductInfo(string p, string N) :Parcode(p), Name(N) {
	;
}


bool ProductInfo::operator==(ProductInfo& rhs) const {
	return (Parcode == rhs.Parcode ? true : false);
}

bool ProductInfo::operator==(string i)const {
	return (Parcode == i ? true : false);
}

ostream& operator<<(ostream& output, ProductInfo& rhs) {
	return output << '#' << setfill('0') << setw(12) << rhs.Parcode << "\t " << rhs.Name;
}

ostream& operator<<(ostream& output, ProductInfo* rhs) {
	return output << '#' << setfill('0') << setw(12) << rhs->Parcode << "\t " << rhs->Name;
}


ProductNode::ProductNode() :Info(NULL), Next(NULL), Amount(0) {
	;
}

Cart::Cart() {
	ProductNode* f(new ProductNode());
	f->Amount = 0;
	f->Info = NULL;
	f->Next = NULL;
	Front = f;
}

ProductNode* Cart::getFront()
{
	return Front;
}

ProductNode* Cart::addInfo(string i, string N) {

	for (ProductNode* temp = Front; temp; temp = temp->Next)
		if (temp->Info->Parcode == i) {
			if (temp->Info->Name == "unKnown!") temp->Info->Name = N;
			return temp;
		}
	ProductInfo* PI_temp = new ProductInfo(i, N);
	ProductNode* PN_temp = new ProductNode();
	PN_temp->Info = PI_temp;
	PN_temp->Amount = 0;
	PN_temp->Next = Front;
	Front = PN_temp;
	return PN_temp;
}

ProductNode* Cart::popFront()
{
	if (Front) {
		ProductNode* dump = Front;
		Front = Front->Next;
		return dump;
	}
	return Front;
}


void Cart::addtoClientCart(string Parcode, int Amount)
{
	int& MallAmount = Mall::Products->addInfo(Parcode)->Amount;
	int& ClientAmount = addInfo(Parcode)->Amount;
	if (Mall::Test(Parcode, Amount))
	{
		ClientAmount += Amount;
		MallAmount -= Amount;
	}
	else {
		ClientAmount += MallAmount;
		MallAmount = 0;
		cout << "Sorry,your amount isn't available" << endl
			<< "You must ask for less amount." << endl
			<< "returned all Amount in Mall.";
	}
}
void Cart::addtoMall(string name, string parcode, int amount) {
	ProductNode* temp = Mall::Products->getFront();
	while (temp) {
		if (temp->Info->Parcode == parcode) {
			temp->Amount += amount;
			return;
		}
		else {
			if (temp->Next) { temp = temp->Next; }
			else {
				ProductInfo* I = new ProductInfo(parcode, name);
				ProductNode* N = new ProductNode();
				N->Info = I;
				N->Amount = amount;
				N->Next = Front;
				Front = N;
				temp->Next = N;
			}
			;
		}

	};
}

	ostream& operator<< (ostream & output, Cart & C) {
		for (ProductNode* temp = C.getFront(); temp; temp = temp->Next) {
			output << temp->Info << " Amount " << temp->Amount;
		}
		return output;
	}