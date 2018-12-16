#pragma once
#include "IComponent.h"
#include "directheader.h"
#include <string>
#include "CTexture.h"

using namespace std;



class C2DSpriteComponent :
	public IComponent
{
private:
	RenderInfo m_RenderInfo;


	CTexture* m_pTexture;
	CSprite* m_pSprite;

	wstring m_strTextureName;
	wstring m_strSpriteName;
	int m_iFrame = 0;

	int m_iDrawState = 0;

	void SetSizeAsFrame();

	
public:	//�׸� �׸� ����
	void SetTexture(wstring texture);
	void SetSprite(wstring sprite);   
	void SetFrame(int frame);


public: //�׸���  Auto K �׸��� ����
	void SetAngle(float fAngle);
	void SetPos(D3DXVECTOR3 vecPos);
	void SetPos(float x, float y, float z = 0);
	void SetRatio(float XRatio, float YRatio);
	void SetSize(float width, float height);



private:
	void DrawFrame();
	void DrawSprite();
	void DrawTexture();

 	
public:
	virtual void Update(float deltaTime);
	virtual void Render();
	void SetDrawNothing() { m_iDrawState = 0; }
	void SetDrawFrame() { m_iDrawState = 1; }
	void SetDrawSprite() { m_iDrawState = 2; }
	void SetDrawTexture() { m_iDrawState = 3; }

	D3DXVECTOR3 GetTextureSize();

public:
	C2DSpriteComponent();
	virtual ~C2DSpriteComponent();
};

