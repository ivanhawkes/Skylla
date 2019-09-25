#include <StdAfx.h>

#include "MissileComponent.h"
#include <CryCore/StaticInstanceList.h>
#include "CrySchematyc/Env/Elements/EnvComponent.h"
#include "CrySchematyc/Env/IEnvRegistrar.h"


namespace Skylla
{
static void RegisterMissileComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CMissileComponent));
		// Functions
		{
		}
	}
}


void CMissileComponent::ReflectType(Schematyc::CTypeDesc<CMissileComponent>& desc)
{
	desc.SetGUID(CMissileComponent::IID());
	desc.SetEditorCategory("Projectiles");
	desc.SetLabel("Missile");
	desc.SetDescription("A missle.");
	desc.SetIcon("icons:ObjectTypes/light.ico");
	desc.SetComponentFlags({ IEntityComponent::EFlags::None });
	desc.AddBase<CProjectileComponent>();
}


void CMissileComponent::OnResetState()
{
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterMissileComponent)
}