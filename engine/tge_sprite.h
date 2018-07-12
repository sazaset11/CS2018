#pragma once

namespace tge_sprite {
	struct S_SPRITE_HEADER {
		char szHeader[16];
		COORD m_cdWorkSpr;
	};

	struct S_SPRITE_OBJECT {
		S_SPRITE_HEADER m_header;
		CHAR_INFO *m_pSpriteBuf;
	};
	void Init(S_SPRITE_OBJECT*);
	int save(S_SPRITE_OBJECT*, const char*);
	int load(S_SPRITE_OBJECT*, const char*);
	int put(S_SPRITE_OBJECT*, int, int);
	int put(S_SPRITE_OBJECT*, int, int, CHAR_INFO*);	
	int get(S_SPRITE_OBJECT*, int, int, int, int);
}