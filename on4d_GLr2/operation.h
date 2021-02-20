// ユーザによる入力(キー, ジョイパッドetc)を保持する
#pragma once

#include "point.h"


class Operation
{
public:

	pt3 cmLoc;
	pt3 cmRot;
	bool cmBack;
	int speed;
	pt3 VRLoc;	// locからの相対位置 (VR)
	pt3 VRStd[2];	// stdに対する相対std (VR)
	double VREysDst;

	int chgMapStateOld;
	int chgMapState;
	bool inputByKey;	// キーによる入力

	enum class ClickState
	{
		None,
		Right,
		Left
	} clickState;
	pt2i clickCoord;

	int updLocationParam(double x, double y, int opt);
	int updRotationParam(double x, double y, int opt);
	void ClearLocRotParam();

	Operation();
};

