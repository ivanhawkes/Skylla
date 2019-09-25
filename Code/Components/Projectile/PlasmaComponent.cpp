#include <StdAfx.h>

#include "PlasmaComponent.h"
#include <CryCore/StaticInstanceList.h>
#include "CrySchematyc/Env/Elements/EnvComponent.h"
#include "CrySchematyc/Env/IEnvRegistrar.h"


namespace Skylla
{
static void RegisterPlasmaComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CPlasmaComponent));
		// Functions
		{
		}
	}
}


void CPlasmaComponent::ReflectType(Schematyc::CTypeDesc<CPlasmaComponent>& desc)
{
	desc.SetGUID(CPlasmaComponent::IID());
	desc.SetEditorCategory("Projectiles");
	desc.SetLabel("Plasma");
	desc.SetDescription("A plasma projectile.");
	desc.SetIcon("icons:ObjectTypes/light.ico");
	desc.SetComponentFlags({ IEntityComponent::EFlags::None });
	desc.AddBase<CProjectileComponent>();
}


void CPlasmaComponent::OnResetState()
{
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterPlasmaComponent)
}