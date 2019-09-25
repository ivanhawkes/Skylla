#pragma once

#include <CryEntitySystem/IEntitySystem.h>


namespace Skylla
{
class CProjectileComponent
	: public IEntityComponent
{
public:
	CProjectileComponent() {}
	virtual ~CProjectileComponent() {}

	static void ReflectType(Schematyc::CTypeDesc<CProjectileComponent>& desc);

	static CryGUID& IID()
	{
		static CryGUID id = "{A3844E30-A24A-4338-AAE2-7B28FEF4D011}"_cry_guid;
		return id;
	}


	bool IsLocked() const { return m_isLocked; }
	void SetLocked(bool val) { m_isLocked = val; }

	virtual void OnResetState();

private:
	bool m_isLocked { true };
};
}