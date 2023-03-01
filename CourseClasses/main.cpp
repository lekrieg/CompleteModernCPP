#include "BasicLanguageFacilities/BasicLanguageFacilities.h"

int main()
{
	BLF::BasicLanguageFacilities basicFacilities;

	basicFacilities.PrintBasicTypesInfo();
	basicFacilities.GetUserInput();
	basicFacilities.BasicPointerAndReferenceTest();
	basicFacilities.PrintCircleInfo(5.44f);
	basicFacilities.ForLoopPratice();
	basicFacilities.Square(5);
	basicFacilities.FunctionPointerPratice();

	return 0;
}