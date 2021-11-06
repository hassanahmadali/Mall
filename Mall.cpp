#include "Mall.h"

Cart* Mall::Products = new Cart();

bool Mall::Test(string Parcode, int Amount)
{
	ProductNode* temp = Products->getFront();
	while (temp)
	{
		if (temp->Info->Parcode == Parcode) {
			if (temp->Amount >= Amount)
				return true;
		}
	}
	return false;
}

Mall::Mall() {

	;
}

