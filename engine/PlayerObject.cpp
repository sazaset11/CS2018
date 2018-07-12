#include "stdafx.h"
#include "PlayerObject.h"
#include "TGE.h"

namespace playerobject {
	void Init(S_PlayerObject *pObj, int _sx, int _sy) {
		pObj->m_nKeyCount = 0;
		pObj->m_Position.X = _sx;
		pObj->m_Position.Y = _sy;
	}

	void move(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy) {
		int _checkx = pObj->m_Position.X + _dx;
		int _checky = pObj->m_Position.Y + _dy;
		CHAR_INFO *pCi = tge::getCharacter(pMapBuf, _checkx, _checky);

		if (pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes == 0x0007) {
			pObj->m_Position.X = _checkx;
			pObj->m_Position.Y = _checky;
		}
		else if (pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes == 0x00c0) {
			printf("문이 잠겨있습니다.			");
		}
		else if (pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes == 0x00b0) {
			printf("열쇠가 떨어져있습니다.			");
		}
	}

	int use(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy) {
		int _checkx = pObj->m_Position.X + _dx;
		int _checky = pObj->m_Position.Y + _dy;
		CHAR_INFO *pCi = tge::getCharacter(pMapBuf, _checkx, _checky);

		if (pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes == 0x00c0) {
			if (!pObj->m_nKeyCount) {
				printf("열쇠가 필요합니다.");
			}
			
			pObj->m_nKeyCount--;
			pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes = 0x0007;

			printf("문이 열렸습니다..		");

			return 1;
		}
		else if (pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes == 0x00a0) {
			pObj->m_nKeyCount--;
			pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes = 0x0007;

			printf("탈출 성공~~~		\n");

			return 0;
		}
		else {
			printf("아무것도 없습니다.		");

			return 1;
		}
	}
	
	void get(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy){
		int _checkx = pObj->m_Position.X + _dx;
		int _checky = pObj->m_Position.Y + _dy;
		CHAR_INFO *pCi = tge::getCharacter(pMapBuf, _checkx, _checky);

		if (pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes == 0x00b0) {
			pObj->m_nKeyCount++;
			pMapBuf[_checky*SCREEN_WIDTH + _checkx].Attributes = 0x0007;

			printf("열쇠를 주웠습니다.		");
		}
		else {
			printf("아무것도 없습니다.		");
		}
	}

	void DrawObject(S_PlayerObject *pObj, CHAR_INFO *pMapBuf) {
		tge::setCharacter(pMapBuf, pObj->m_Position.X, pObj->m_Position.Y, 0x41, 0x000f);
	}
}
