#include <StdAfx.h>

#include "ProjectileComponent.h"
#include <CryCore/StaticInstanceList.h>
#include "CrySchematyc/Env/Elements/EnvComponent.h"
#include "CrySchematyc/Env/IEnvRegistrar.h"


namespace Skylla
{
static void RegisterProjectileComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CProjectileComponent));
		// Functions
		{
		}
	}
}


void CProjectileComponent::ReflectType(Schematyc::CTypeDesc<CProjectileComponent>& desc)
{
	desc.SetGUID(CProjectileComponent::IID());
	desc.SetEditorCategory("Projectiles");
	desc.SetLabel("Projectile");
	desc.SetDescription("A simple projectile.");
	desc.SetIcon("icons:ObjectTypes/light.ico");
	desc.SetComponentFlags({ IEntityComponent::EFlags::None });
}


void CProjectileComponent::OnResetState()
{
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterProjectileComponent)
}