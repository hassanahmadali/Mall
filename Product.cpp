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
ostream& operator<<(ostream& output, ProductInfo* rhs) {
	if (rhs)
		output << '#' << setfill('0') << setw(12) << rhs->Parcode << "\t " << rhs->Name;
	return output;
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

ProductNode* ProductList::addInfo(string P, int A, string N) {
	for (ProductNode* _temp_ProductNode = Front; _temp_ProductNode; _temp_ProductNode = _temp_ProductNode->Next)
		if (_temp_ProductNode->Info->Parcode == P) {
			if (_temp_ProductNode->Info->Name == uKn) _temp_ProductNode->Info->Name = N;
			_temp_ProductNode->Amount += A;
			return _temp_ProductNode;
		}
	ProductNode* _new_ProductNode = new ProductNode(P, N, A);
	_new_ProductNode->Next = Front;
	Front = _new_ProductNode;
	return _new_ProductNode;
}

void ProductList::popFront()
{
	if (Front)
		Front = Front->Next;
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
	ProductNode* _Mall_Node = ProductList::MallProducts->addInfo(P);
	if (_Mall_Node->Info->Name == uKn) {
		_Mall_Node->Info->Name = N;
	}
	if (_Mall_Node->Amount >= A)
	{
		Data = new ProductList(P, N, A);
		_Mall_Node->Amount -= A;
	}
	else {
		Data = new ProductList(P, N, _Mall_Node->Amount);
		cout << "there is not enough prouducts in the mall returned all amount in the mall which is " << _Mall_Node->Amount;
		_Mall_Node->Amount = 0;
	}
}
//
//void ProductList::addtoMall(string P, string N, int A) {
//	if (Mall::Products) {
//		Mall::Products->addInfo(P, N)->Amount += A;
//	}
//	else {
//		Mall::Products = new ProductList(P, N, A);
//	}
//}