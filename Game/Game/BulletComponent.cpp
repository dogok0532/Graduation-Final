#include "BulletComponent.h"
#include "RectangleComponent.h"
#include "2DSpriteComponent.h"
#include "GameObject.h"

CBulletComponent::CBulletComponent()
{
	m_SyncState = COMPONENT_TO_OWNER;
}


CBulletComponent::~CBulletComponent()
{

}

void CBulletComponent::Render()
{
	if(m_pSpriteComonent)
		m_pSpriteComonent->SetDrawFrame();
}

bool CBulletComponent::isEnemy()
{
	return m_isEnemy;
}

void CBulletComponent::Update(float deltaTime)
{
	D3DXMATRIX matRotate;
	D3DXVECTOR3 vecMovement = {m_fVelocity,0,1};

	D3DXMatrixRotationZ(&matRotate, m_fAngle / 180 * 3.141592);
	D3DXVec3TransformCoord(&vecMovement, &vecMovement, &matRotate);

	m_vecPos += vecMovement;
	m_fCurrentDistance +=D3DXVec3Length(&vecMovement);

	//�߻���⿡ ���� �ӵ�/���� ���� �� ��ǥ �ֽ�ȭ

	if (m_fCurrentDistance > m_fMaxDistance)		//�ִ��Ÿ��� �����Ұ��
	{
		m_pOwner->SetDead();	
	}

	if (m_pSpriteComonent)						
	{
		m_pSpriteComonent->SetPos(m_vecPos);
		m_pSpriteComonent->SetFrame(0);
	}
	else
	{
		m_pSpriteComonent = m_pOwner->getComponent<C2DSpriteComponent>();
		m_pSpriteComonent->SetTexture(L"Effect");
		m_pSpriteComonent->SetSprite(L"Effect1");
	}


	if (m_pRectangleComponent)
	{
		m_pRectangleComponent->SetHeight(10);
		m_pRectangleComponent->SetWidth(10);
	}
	else
	{
		m_pRectangleComponent = m_pOwner->getComponent<CRectangleComponent>();
		m_pRectangleComponent->SetHeight(10);
		m_pRectangleComponent->SetWidth(10);
	}


	IComponent::Update(deltaTime);
}


void CBulletComponent::SetBulletInfo(float fAngle, float fVelocity,bool isEnemy,float fMaxDistance)
{
	
	m_fAngle = fAngle;
	m_fVelocity = fVelocity;
	m_isEnemy = isEnemy;
	m_fMaxDistance = fMaxDistance;
}
