#include "BulletCheckSystem.h"

#include "RectangleComponent.h"

#include "GameObject.h"
#include "PlayerComponent.h"
#include "EnemyComponent.h"
CBulletCheckSystem::CBulletCheckSystem()
{
}


CBulletCheckSystem::~CBulletCheckSystem()
{
}



void CBulletCheckSystem::CheckPlayerHit()
{
	for (auto player = m_pPlayerList.begin();player != m_pPlayerList.end();player++)	//�÷��̾� �˻�
	{
		for (auto bullet = m_pEnemyBulletList.begin(); bullet != m_pEnemyBulletList.end(); bullet++)	//���Ѿ� �˻�
		{
			if ((*player)->getComponent<CRectangleComponent>()->CheckCollision(*bullet))	//�¾Ҵٸ�
			{

				//(*player)->getComponent<CPlayerComponent>()->Hit();	//�÷��̾� ������Ʈ�� �÷��̾� ������Ʈ�� �¾Ҵٴ� ��ȣ����
				(*bullet)->SetDead();
			}


		}
	}
}

void CBulletCheckSystem::CheckEnemyHit()
{
	for (auto enemy = m_pEnemyList.begin(); enemy != m_pEnemyList.end();enemy++)	//�� �˻�
	{
		for (auto bullet = m_pPlayrBulletList.begin(); bullet != m_pPlayrBulletList.end();bullet++)	//�Ʊ��Ѿ� �˻�
		{
			if ((*enemy)->getComponent<CRectangleComponent>()->CheckCollision(*bullet))	//�¾Ҵٸ�
			{
				(*enemy)->SetDead();
				//(*enemy)->getComponent<CEnemyComponent>()->Hit();	//�� ������Ʈ�� �� ������Ʈ�� �¾Ҵٴ� ��ȣ����
				(*bullet)->SetDead();
			}
		}
	}
}

void CBulletCheckSystem::Update(float deltaTime)
{
	CheckPlayerHit();
	CheckEnemyHit();

	m_pPlayerList.clear();
	m_pEnemyBulletList.clear();
	m_pEnemyList.clear();
	m_pPlayrBulletList.clear();

}

void CBulletCheckSystem::addPlayer(CGameObject* pPlayer)
{
	if(pPlayer->getComponent<CRectangleComponent>())
		m_pPlayerList.push_back(pPlayer);
}


void CBulletCheckSystem::addEnemyBullet(CGameObject* pEnemyBullet)
{
	if (pEnemyBullet->getComponent<CRectangleComponent>())
		m_pEnemyBulletList.push_back(pEnemyBullet);
}


void CBulletCheckSystem::addEnemy(CGameObject* pEnemy)
{
	if (pEnemy->getComponent<CRectangleComponent>())
		m_pEnemyList.push_back(pEnemy);
}



void CBulletCheckSystem::addPlayerBullet(CGameObject* pPlayerBullet)
{
	if (pPlayerBullet->getComponent<CRectangleComponent>())
		m_pPlayrBulletList.push_back(pPlayerBullet);
}
