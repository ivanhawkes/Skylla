#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include "ProjectileComponent.h"


namespace Skylla
{
class CMissileComponent
	: public CProjectileComponent
{
public:
	CMissileComponent() {}
	virtual ~CMissileComponent() {}

	static void ReflectType(Schematyc::CTypeDesc<CMissileComponent>& desc);

	static CryGUID& IID()
	{
		static CryGUID id = "{B68AD71F-54DE-495A-AE92-E86CA06119D0}"_cry_guid;
		return id;
	}


	bool IsLocked() const { return m_isLocked; }
	void SetLocked(bool val) { m_isLocked = val; }

	virtual void OnResetState();

private:
	bool m_isLocked { true };
};
}