#include "operation.h"


Operation::Operation()
	: cmBack(false)
	, speed(0)
	, chgMapStateOld(0)
	, chgMapState(0)
	, inputByKey(false)
	, clickState(Operation::ClickState::None)
	, clickCoord(pt2i(-1, -1))
	, VREysDst(0.0)
{
	cmLoc = pt3(0, 0, 0);
	cmRot = pt3(0, 0, 0);
	VRLoc = pt3(0, 0, 0);
	VRStd[0] = pt3(0, 0, 0);
	VRStd[1] = pt3(0, 0, 0);
}

int Operation::updRotationParam(double x, double y, int opt)
{
	cmRot.x = x;
	cmRot.y = y;

	return 1;
}


int Operation::updLocationParam(double x, double y, int opt)
{
	cmLoc.y = x;
	cmLoc.z = y;

	return 1;
}

void Operation::ClearLocRotParam()
{
	cmLoc = pt3(0, 0, 0);
	cmRot = pt3(0, 0, 0);
}
