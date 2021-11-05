#include "Mall.h"
Cart* Mall::Products = new Cart();



bool Mall::Test(string Parcode,int Amount )
{
	ProductNode_p dump = Products->getFront();
	while (dump)
	{
		if (dump->Amount >= Amount && dump->Info->Parcode == Parcode)
		{
			return true;
		}
	}
	return false;
}
