#pragma once

#include <CryEntitySystem/IEntitySystem.h>


namespace Skylla
{
class CPlayAreaComponent final : public IEntityComponent
{
public:
	CPlayAreaComponent() = default;
	virtual ~CPlayAreaComponent() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CPlayAreaComponent>& desc)
	{
		desc.SetGUID("{83335924-A86B-4978-BB2A-0E9701AF0F0A}"_cry_guid);
		desc.SetEditorCategory("Area");
		desc.SetLabel("PlayArea");
		desc.SetDescription("Provides a guide frame for where gameplay should be restricted.");
		desc.SetComponentFlags({ IEntityComponent::EFlags::Transform, IEntityComponent::EFlags::Socket, IEntityComponent::EFlags::Attach });
	}
};
}