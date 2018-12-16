#include "Intro.h"
#include "MainGame.h"
#include "Text.h"
#include "Stage.h"


CIntro::CIntro()
{
	pMainText = new CText();
	pMainText->SetColor(D3DCOLOR_ARGB(0,255,255,255));
	pMainText->SetTextRange(0,0, 1200, 900);
	pMainText->SetFontSize(10);

	m_IntroTextQueue.push(L"1940�� 5�� 10��, ���ϱ��� ������ ħ������ ���������� ��ħ�� ��ȭ�� �۽ο���.");
	m_IntroTextQueue.push(L"���׷轺 3���� ����, ���� ���ձ��� �������� ���п� ������ �ŵ�������,");
	m_IntroTextQueue.push(L"���ϱ��� �Ƹ��� �긲���븦 �����ϰ� ���� ���� ������  ");
	m_IntroTextQueue.push(L"���ձ��� ����ġ ���� ��Ը� ��ȸ�����⵿���� �ַºδ밡 ������ ��������� ���⿡ ������.");
	m_IntroTextQueue.push(L"���ձ��� �ƶ󽺿��� �ݰ��� ���������� �����߰�, �ᱹ ���ϱ��� ������ �����ǰ� ����.");
	m_IntroTextQueue.push(L"������ ���������� �Ⱙ�δ밡 ��ΰ� ���� ���ձ��� ����� ���� ���� �ӵ��� �����ϰ� �־���.");
	
	pBlinkingText = new CText();
	pBlinkingText->SetColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	pBlinkingText->SetTextRange(1000, 800, 1200, 900);
	pBlinkingText->SetFontSize(20);
	pBlinkingText->SetText(L"��");


	m_strCurrentText = m_IntroTextQueue.front();
	m_IntroTextQueue.pop();




}


CIntro::~CIntro()
{
	if (pMainText)
	{
		pMainText->Release();
		delete pMainText;
		pMainText = nullptr;
	}
}

void CIntro::Update(float fDeltaTime)
{
	UpdateText(fDeltaTime);
	UpdateNext(fDeltaTime);
	UpdateBlink(fDeltaTime);
	

}

void CIntro::Render()
{
	pMainText->Render();

	if (bNextTextAvailable == true)
	{
		if (bButtonBlink)
			pBlinkingText->Render();
	}
}

void CIntro::UpdateText(float fDeltaTime)
{
	if (bFadeIn)
	{
		fCurrentFadeTime += fDeltaTime;

		fFadeColor = 255 * fCurrentFadeTime / fFadeTime;

		if (fFadeColor > 255)
		{
			bFadeIn = false;
			bNextTextAvailable = true;
			fFadeColor = 255;
			fCurrentFadeTime = 0;
		}

	}
	if (bFadeOut)
	{
		fCurrentFadeTime += fDeltaTime;
		fFadeColor = 255 - (255 * fCurrentFadeTime / fFadeTime);
		if (fFadeColor < 0)
		{
			fCurrentFadeTime = 0;
			bFadeOut = false;
			fFadeColor = 0;

			if (!m_IntroTextQueue.empty())
			{
				bFadeIn = true;
				m_strCurrentText = m_IntroTextQueue.front();
				m_IntroTextQueue.pop();
			}

			else
			{
				CMainGame::GetInstance()->ChangeScene<CStage>();
			}
		}
	}
	pMainText->SetText(m_strCurrentText);
	pMainText->SetColor(D3DCOLOR_ARGB((int)fFadeColor, 255, 255, 255));
}

void CIntro::UpdateNext(float deltaTime)
{
	if (bNextTextAvailable == true)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			bFadeOut = true;
			bNextTextAvailable = false;
		}
		
	}


}

void CIntro::UpdateBlink(float deltaTime)
{
	fCurrentBlinkTime += deltaTime;

	if (fCurrentBlinkTime >= fButtonBlinkTime)
	{
		bButtonBlink = !bButtonBlink;
		fCurrentBlinkTime = 0;
	}
}