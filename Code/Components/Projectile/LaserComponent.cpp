#include <StdAfx.h>

#include "LaserComponent.h"
#include <CryCore/StaticInstanceList.h>
#include "CrySchematyc/Env/Elements/EnvComponent.h"
#include "CrySchematyc/Env/IEnvRegistrar.h"


namespace Skylla
{
static void RegisterLaserComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CLaserComponent));
		// Functions
		{
		}
	}
}


void CLaserComponent::ReflectType(Schematyc::CTypeDesc<CLaserComponent>& desc)
{
	desc.SetGUID(CLaserComponent::IID());
	desc.SetEditorCategory("Projectiles");
	desc.SetLabel("Laser");
	desc.SetDescription("A laser beam.");
	desc.SetIcon("icons:ObjectTypes/light.ico");
	desc.SetComponentFlags({ IEntityComponent::EFlags::None });
	desc.AddBase<CProjectileComponent>();
}


void CLaserComponent::OnResetState()
{
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterLaserComponent)
}