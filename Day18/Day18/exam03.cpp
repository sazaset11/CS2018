#include "stdafx.h"

namespace exam3 {
	void OnGdiPlusSetup() {

	}
	void OnGdiPlusApply(double fDelta) {

	}
	void OnGdiPlusRender(double fDelta, Graphics *pGrp) {
		pGrp->Clear(Color(200, 200, 200));
		Pen penBlack(Color(0, 0, 0));
		Pen penRed(Color(255, 0, 0));
		Matrix _mat1(1, 0, 0, -1, 160, 120);

		pGrp->DrawLine(&penBlack, 160, 0, 160, 240);
		pGrp->DrawLine(&penBlack, 0, 120, 320, 120);
		pGrp->SetTransform(&_mat1);

		{
			Matrix _mat2(1, 0, 0, 1, -32, -32);
			Matrix *_mat3 = _mat1.Clone();
			_mat3->Multiply(&_mat2);
			pGrp->SetTransform(_mat3);
			delete _mat3;
			//pGrp->TranslateTransform(-32, -32);
			irr::core::vector2df rectPos(0, 0);

			pGrp->DrawRectangle(&penBlack, irr::core::round32(rectPos.X), irr::core::round32(rectPos.Y), 64, 64);
			plusEngine::printf(pGrp, rectPos.X, rectPos.Y, L"(%.1lf, %.1lf)", rectPos.X, rectPos.Y);

			pGrp->SetTransform(&Matrix(1, 0, 0, -1, 160, 120));
		}
		{
			irr::core::vector2df rectPos(0, 0);
			pGrp->DrawRectangle(&penRed, irr::core::round32(rectPos.X), irr::core::round32(rectPos.Y), 64, 64);
			plusEngine::printf(pGrp, rectPos.X, rectPos.Y, L"(%.1lf, %.1lf)", rectPos.X, rectPos.Y);
		}

		pGrp->SetTransform(&Matrix(1, 0, 0, 1, 0, 0));
		//pGrp->ResetTransform();
	}
	void OnGdiPlusFinish() {

	}
}