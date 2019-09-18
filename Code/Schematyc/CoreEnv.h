#pragma once

namespace Skylla
{
static constexpr CryGUID g_coreEnvPackageGuid = "{D16A61F7-8C57-4FC7-B69A-F4816E5FDB6D}"_cry_guid;
static constexpr CryGUID g_SkyllaModuleGUID = "{FDAA6E9D-5042-42D4-9DFD-8CB7A9901449}"_cry_guid;
static constexpr CryGUID g_generalModuleGUID = "{D906B99B-6EC3-40F6-B218-B60C5D8CCBC4}"_cry_guid;

struct ::Schematyc::IEnvRegistrar;

void RegisterCoreEnvPackage(::Schematyc::IEnvRegistrar& registrar);

} // ~Schematyc
