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

ostream& operator<<(ostream& output, ProductInfo_p& rhs) {
	return output << '#' << setfill('0') << setw(12) << rhs->Parcode << "\t " << rhs->Name;
}


ProductNode::ProductNode() :Info(NULL), Next(NULL), Amount(0) {
	;
}

Cart::Cart() {
	ProductNode_p f(new ProductNode());
	f->Amount = 0;
	f->Info = NULL;
	f->Next = NULL;
	Front = f;
}

ProductNode_p& Cart::getFront()
{
	return Front;
}

ProductNode_p& Cart::addInfo(string i, string N) {

	for (ProductNode_p temp = Front; temp; temp = temp->Next)
		if (temp->Info->Parcode == i) return temp;
	ProductInfo_p* PI_temp = new ProductInfo_p(new ProductInfo(i, N));
	ProductNode_p* PN_temp = new ProductNode_p(new ProductNode());
	(*PN_temp)->Info = *PI_temp;
	(*PN_temp)->Amount = 0;
	(*PN_temp)->Next = Front;
	Front = *PN_temp;
	return *PN_temp;
}

ProductNode_p& Cart::popFront()
{
	if (Front) {
		ProductNode_p dump = Front;
		Front = Front->Next;
		return dump;
	}
	return Front;
}
bool Cart::Test(string Parcode, int Amount)
{
	return Mall::Test(Parcode, Amount);
}

void Cart::ServeClient(string Parcode,int Amount)
{
	if (Mall::Test(Parcode,Amount))
	{
		addInfo(Parcode)->Amount +=Amount;
		Mall::Products->addInfo(Parcode)->Amount -=Amount;
	}
}