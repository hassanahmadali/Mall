#include "Product.h"

ProductInfo::ProductInfo(int p, string N) :Parcode(p), Name(N) {
	;
}

bool ProductInfo::operator==(ProductInfo& rhs) const {
	return (Parcode == rhs.Parcode ? true : false);
}

bool ProductInfo::operator==(int i)const {
	return (Parcode == i ? true : false);
}


ostream& operator<<(ostream& output, ProductInfo_p& rhs) {
	return output << '#' << setfill('0') << setw(12) << rhs->Parcode << "\t " << rhs->Name;
}

ostream& operator<<(ostream& output, ProductInfo& rhs) {
	return output << '#' << setfill('0') << setw(12) << rhs.Parcode << "\t " << rhs.Name;
}

ProductNode::ProductNode() :Info(NULL), Next(NULL), Amount(0) {
	;
}

Cart::Cart() : Front(NULL) { ; }

ProductNode_p& Cart::addInfo(int i, string N) {
	for (ProductNode_p temp = Front; temp; temp = temp->Next)
		if (temp->Info->Parcode == i) return temp;
	ProductInfo_p PI_temp(new ProductInfo(i, N));
	ProductNode_p PN_temp(new ProductNode());
	PN_temp->Info = PI_temp;
	PN_temp->Amount = 0;
	PN_temp->Next = Front;
	Front = PN_temp;
}