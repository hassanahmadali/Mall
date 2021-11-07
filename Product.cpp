#include "Product.h"
#include"Mall.h"


ProductInfo::ProductInfo(string p, string N) :Parcode(p), Name(N) {
	;
}

bool ProductInfo::operator==(ProductInfo& rhs) const {
	return (Parcode == rhs.Parcode);
}

bool ProductInfo::operator==(string N)const {
	return (Parcode == N);
}

ostream& operator<<(ostream& output, ProductInfo& rhs) {
	return output << '#' << setfill('0') << setw(12) << rhs.Parcode << "\t " << rhs.Name;
}



ProductNode::ProductNode(string P, string N, int A) : Next(NULL), Amount(A) {
	Info = new ProductInfo(P, N);
}



ProductList::ProductList(string P, string N, int A)
{
	Front = new ProductNode(P, N, A);
}

ProductNode* ProductList::getFront()
{
	return Front;
}

ProductNode* ProductList::addInfo(string P, string N) {
	if (Front)
		for (ProductNode* _temp_ProductNode = Front; _temp_ProductNode; _temp_ProductNode = _temp_ProductNode->Next)
			if (_temp_ProductNode->Info->Parcode == P) {
				if (_temp_ProductNode->Info->Name == "unKnown!") _temp_ProductNode->Info->Name = N;
				return _temp_ProductNode;
			}
	ProductNode* _new_ProductNode = new ProductNode(P, N, 0);
	_new_ProductNode->Next = Front;
	Front = _new_ProductNode;
	return _new_ProductNode;
}

void ProductList::popFront()
{
	if (Front)
		Front = Front->Next;
}


void ProductList::addtoList(string P, int A)
{
	int& MallAmount = Mall::Products->addInfo(P)->Amount;
	int& ClientAmount = addInfo(P)->Amount;
	if (Mall::Test(P, A))
	{
		ClientAmount += A;
		MallAmount -= A;
	}
	else {
		ClientAmount += MallAmount;
		MallAmount = 0;
		cout << "Sorry,your amount isn't available" << endl
			<< "You must ask for less amount." << endl
			<< "returned " << MallAmount << "which is all Amount in Mall.";
	}
}

ostream& operator<< (ostream& output, ProductList& C)
{
	for (ProductNode* temp = C.getFront(); temp; temp = temp->Next) {
		output << temp->Info << " Amount " << temp->Amount;
	}
	return output;
}

Cart::Cart(string P, string N, int A)
{
	Data = new ProductList(P, N, A);
}
//
//void ProductList::addtoMall(string P, string N, int A) {
//	if (Mall::Products) {
//		Mall::Products->addInfo(P, N)->Amount += A;
//	}
//	else {
//		Mall::Products = new ProductList(P, N, A);
//	}
}