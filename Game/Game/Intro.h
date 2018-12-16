#pragma once
#include "Scene.h"
#include <queue>

class CText;
class CIntro :
	public CScene
{
private:
	CText* pMainText=nullptr;
	CText* pBlinkingText;




	std::queue<wstring> m_IntroTextQueue;
	wstring m_strCurrentText;
	

	float fFadeColor = 0;
	float fFadeTime = 0.1;
	float fCurrentFadeTime=0;

	bool bFadeIn=true;
	bool bFadeOut=false;

	bool bNextTextAvailable=false;

	bool bButtonBlink=false;
	float fButtonBlinkTime=0.1;
	float fCurrentBlinkTime=0;


	void UpdateText(float deltaTime);	//�ؽ�Ʈ ��� ���̵�ȿ��
	void UpdateNext(float deltaTime);	//�����ؽ�Ʈ ��� ����
	void UpdateBlink(float deltaTime);	//��� ��¿Ϸ�� �����Ÿ�

public:
	CIntro();
	virtual ~CIntro();

	virtual void Update(float fDeltaTime);


	virtual void Render() override;

};

