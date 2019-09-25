#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include "ProjectileComponent.h"


namespace Skylla
{
class CLaserComponent
	: public CProjectileComponent
{
public:
	CLaserComponent() {}
	virtual ~CLaserComponent() {}

	static void ReflectType(Schematyc::CTypeDesc<CLaserComponent>& desc);

	static CryGUID& IID()
	{
		static CryGUID id = "{C8F3860D-4ED6-42AB-8C14-72EF2C826032}"_cry_guid;
		return id;
	}


	bool IsLocked() const { return m_isLocked; }
	void SetLocked(bool val) { m_isLocked = val; }

	virtual void OnResetState();

private:
	bool m_isLocked { true };
};
}