#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include "ProjectileComponent.h"


namespace Skylla
{
class CPlasmaComponent
	: public CProjectileComponent
{
public:
	CPlasmaComponent() {}
	virtual ~CPlasmaComponent() {}

	static void ReflectType(Schematyc::CTypeDesc<CPlasmaComponent>& desc);

	static CryGUID& IID()
	{
		static CryGUID id = "{7F72A045-2CEE-4DB6-8DB6-A16A3B3DE17F}"_cry_guid;
		return id;
	}


	bool IsLocked() const { return m_isLocked; }
	void SetLocked(bool val) { m_isLocked = val; }

	virtual void OnResetState();

private:
	bool m_isLocked { true };
};
}