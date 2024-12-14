#include <iostream>
#include "../COM_Essentials_One_DLL/Library.hpp"

int main()
{
	IHen* hen = CreateHen();
	hen->Cluck();

	IHen2* hen2 = static_cast<IHen2*>(hen->As("IHen2"));

	if (hen2)
	{
		hen2->Forage();
		hen2->Release();
	}

	IOfflineChicken* offlineChicken = static_cast<IOfflineChicken*>(hen->As("IOfflineChicken"));

	if (offlineChicken)
	{
		offlineChicken->Load("filename");
		offlineChicken->Save("filename");
		offlineChicken->Release();
	}

	hen->Release();
	return 0;
}