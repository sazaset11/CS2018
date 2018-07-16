#pragma once
namespace cs2018prj {
	namespace playerObject {
		struct S_GAMEOBJECT {
			double m_dbSpeed;
			double m_posx, m_posy;
			int m_nFSM;
			bool m_bActive;
			void *m_pFire;
			//CHAR_INFO m_Spr;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_translation;
		};

		void Init(S_GAMEOBJECT*, double, double, double, tge_sprite::S_SPRITE_OBJECT*);
		void Apply(S_GAMEOBJECT*, double);
		void Render(S_GAMEOBJECT*, CHAR_INFO*);
	}
	namespace ailenObject {
		struct S_GAMEOBJECT {
			double m_dbSpeed;
			double m_posx, m_posy;
			double m_dbWorkTick;
			int m_nFSM;
			bool m_bActive;
			//CHAR_INFO m_Spr;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_translation;
			irr::core::vector2df m_vDir;
			cs2018prj::playerObject::S_GAMEOBJECT *m_pTargetObj;
			void *m_pAttack;
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}
	namespace clawObject {
		struct S_GAMEOBJECT {
			double m_dbSpeed;
			double m_posx, m_posy;
			double m_dbWorkTick;
			int m_nFSM;
			bool m_bActive;
			//CHAR_INFO m_Spr;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_translation;
			irr::core::vector2df m_vDir;
			cs2018prj::playerObject::S_GAMEOBJECT *m_pTargetObj;
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}
	namespace fireObject {
		struct S_GAMEOBJECT {
			double m_dbSpeed;
			double m_posx, m_posy;
			double m_dbWorkTick;
			int m_nFSM;
			bool m_bActive;
			//CHAR_INFO m_Spr;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_translation;
			irr::core::vector2df m_vDir;
			cs2018prj::ailenObject::S_GAMEOBJECT *m_pTargetObj;
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}
}