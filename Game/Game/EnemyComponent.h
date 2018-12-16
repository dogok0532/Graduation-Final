#pragma once
#include "IComponent.h"
#include <list>
class CCharacterComponent;
class CEnemyComponent :
	public IComponent
{
private:
	CCharacterComponent* m_pCharacterComponent;


	int		m_currentWay=0;
	float	m_fBulletCycle=0.1;
	float	m_fFireRate = 5;

	float	m_fMoveRate=5;
	float	m_fCurrentMoveRate=0;
	

	//AI를 받을 플레이어 정보
	
	static D3DXVECTOR3 m_vecPlayerPos;
	static std::list<D3DXVECTOR3> m_bulletPosList;
public:
	CEnemyComponent();
	virtual ~CEnemyComponent();

	virtual void Update(float deltaTime) override;


	virtual void Render() override;



	static void GetPlayerPos(D3DXVECTOR3 vecPlayerPos);
	static void GetPlayerBulletPosList(std::list<D3DXVECTOR3> bulletPosList);
};

