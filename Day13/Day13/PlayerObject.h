#pragma once

namespace playerobject {
	struct S_PlayerObject {
		COORD m_Position;
		int m_nKeyCount;
	};

	void Init(S_PlayerObject*, int, int);
	void move(S_PlayerObject*, CHAR_INFO*, int, int);
	int use(S_PlayerObject*, CHAR_INFO*, int, int);
	void get(S_PlayerObject*, CHAR_INFO*, int, int);
	void DrawObject(S_PlayerObject*, CHAR_INFO*);
}