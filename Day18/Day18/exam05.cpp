﻿#include "stdafx.h"

namespace exam5 {
	Image *g_imgBoomber;
	double fAngle = 0;
	irr::core::vector2df vTarget = irr::core::vector2df(64, 64);
	irr::core::vector2df vPos = irr::core::vector2df(0, 0);

	void OnGdiPlusSetup() {
		g_imgBoomber = new Image(L"../../res/ww2/Bombers/A-20g.png");
	}


	void OnGdiPlusApply(double fDelta) {
		//fAngle += fDelta * 45;
		irr::core::vector2df _vDir = irr::core::vector2df(1, 0);
		irr::core::vector2df vDir = vTarget - vPos;

		vDir.normalize();
		fAngle = 0 - vDir.getAngle();
		/*double _tAngle = 0 - vDir.getAngle();
		if (fAngle > _tAngle) {
			fAngle -= fDelta * 45;
		}
		else {
			fAngle += fDelta * 45;
		}*/
		if (fDelta > 0.01) {
			fDelta = 0.01;
		}
		_vDir.rotateBy(fAngle);
		vPos += _vDir * 10.0*fDelta;
	}
	
	void OnKeyDown(WORD keycode) {
		switch (keycode)
		{
		case VK_LEFT:
			vTarget += irr::core::vector2df(-1, 0);
			break;
		case VK_RIGHT:
			vTarget += irr::core::vector2df(1, 0);
			break;
		case VK_UP:
			vTarget += irr::core::vector2df(0, -1);
			break;
		case VK_DOWN:
			vTarget += irr::core::vector2df(0, 1);
			break;
		default:
			break;
		}
	}

	void OnGdiPlusRender(double fDelta, Graphics *pGrp) {
		pGrp->Clear(Color(200, 200, 200));
		Pen penBlack(Color(0, 0, 0));

		pGrp->DrawLine(&penBlack, 160, 0, 160, 240);
		pGrp->DrawLine(&penBlack, 0, 120, 320, 120);
		plusEngine::printf(pGrp, 0, 0, L"%lf %lf %lf", fAngle, vPos.X, vPos.Y);
		pGrp->TranslateTransform(160, 120);
		{
			Matrix _tmpMat;
			pGrp->GetTransform(&_tmpMat);
			pGrp->TranslateTransform(vPos.X, vPos.Y);
			pGrp->RotateTransform(90);
			pGrp->RotateTransform(fAngle);
			pGrp->TranslateTransform(0 - g_imgBoomber->GetWidth() / 2.0, 0 - g_imgBoomber->GetHeight() / 2.0);
			pGrp->DrawImage(g_imgBoomber, Rect(0, 0, g_imgBoomber->GetWidth(), g_imgBoomber->GetHeight()),
				0, 0, g_imgBoomber->GetWidth(), g_imgBoomber->GetHeight(), UnitPixel);
			pGrp->DrawRectangle(&penBlack, 0, 0, g_imgBoomber->GetWidth(), g_imgBoomber->GetHeight());
			pGrp->SetTransform(&_tmpMat);
		}
		{
			Matrix _tmpMat;
			pGrp->GetTransform(&_tmpMat);
			pGrp->TranslateTransform(vTarget.X, vTarget.Y);
			pGrp->DrawEllipse(&penBlack, -8, -8, 16, 16);

			pGrp->SetTransform(&_tmpMat);
		}
		//pGrp->DrawImage(g_imgBoomber, 0, 0);

		pGrp->ResetTransform();
	}
	
	void OnGdiPlusFinish() {
		delete g_imgBoomber;
	}
}