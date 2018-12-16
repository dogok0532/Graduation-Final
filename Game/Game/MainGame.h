#pragma once
#include <iostream>
#include <vector>
#include "Defines.h"
#include <queue>

using namespace std;


class CText;
class CScene;
class CGameObject;

class CSoundResource;
class CSpriteResource;

class CMessage;

class CMainGame
{
	



private:
	CScene * m_pCurrentScene = NULL;
	CScene * m_pNewScene=NULL;

	void UpdateChangeScene();

private: //���հ��� ����

	CSoundResource* pSoundResource;	//���� ���ҽ� ����
	CSpriteResource* pSpriteResource;	//�̹��� ���ҽ� ����
public:
	
	CSoundResource*  GetSound() { return pSoundResource; }	
	CSpriteResource*  GetSpriteResource() { return pSpriteResource;}

	template <typename T> T* ChangeScene()
	{
		m_pNewScene = new T();
		return (T*)(m_pNewScene);
	}


public:
	
	void Init();			//���� ����� �ʿ��� ��ҵ� ����
	void Update(float deltaTime);	//	Update����
	void Render();					//	Render����
	void ResetSprite();				// ��������Ʈ ���ҽ� ����


	void CreateObject(CGameObject* pGameObject);

	DECLARE_SINGLETON(CMainGame)		//�̱��� ����
};
