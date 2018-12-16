#include "EnemyComponent.h"
#include "CharacterComponent.h"


D3DXVECTOR3 CEnemyComponent::m_vecPlayerPos;

std::list<D3DXVECTOR3> CEnemyComponent::m_bulletPosList;

CEnemyComponent::CEnemyComponent()
{

}


CEnemyComponent::~CEnemyComponent()
{
}

void CEnemyComponent::Update(float deltaTime)
{
	if (m_pCharacterComponent)
	{
		m_fCurrentMoveRate += deltaTime;

		m_pCharacterComponent->Move((eWay)m_currentWay, 300 *deltaTime);


		m_pCharacterComponent->SetWay((eWay)m_currentWay);
		m_pCharacterComponent->SetAngle(m_currentWay * 45);

		if (m_fCurrentMoveRate >= m_fMoveRate)
		{
			m_currentWay=rand() % WAY_END;
			m_fCurrentMoveRate = 0;
		}
	}
	else
	{
		m_pCharacterComponent = m_pOwner->getComponent<CCharacterComponent>();
	}





	IComponent::Update(deltaTime);
}

void CEnemyComponent::Render()
{
	
}

void CEnemyComponent::GetPlayerPos(D3DXVECTOR3 vecPlayerPos)
{
	m_vecPlayerPos = vecPlayerPos;
}

void CEnemyComponent::GetPlayerBulletPosList(std::list<D3DXVECTOR3> bulletPosList)
{
	m_bulletPosList = bulletPosList;
}
