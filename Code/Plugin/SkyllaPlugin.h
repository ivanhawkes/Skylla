#pragma once

#include <CrySystem/ICryPlugin.h>
#include <CryGame/IGameFramework.h>
#include <CryEntitySystem/IEntityClass.h>
#include <CryNetwork/INetwork.h>


namespace Skylla
{
class CPlayerComponent;

// The entry-point of the application
// An instance of CSkyllaPlugin is automatically created when the library is loaded
// We then construct the local player entity and CPlayerComponent instance when OnClientConnectionReceived is first called.
class CSkyllaPlugin
	: public Cry::IEnginePlugin
	, public ISystemEventListener
	, public INetworkedClientListener
{
public:
	CRYINTERFACE_SIMPLE(Cry::IEnginePlugin)
		CRYGENERATE_SINGLETONCLASS_GUID(CSkyllaPlugin, "Skylla", "{71787276-F410-4870-A7C5-133DE7392D38}"_cry_guid)

		virtual ~CSkyllaPlugin();

	// Cry::IEnginePlugin
	virtual const char* GetCategory() const override { return "Game"; }
	virtual bool Initialize(SSystemGlobalEnvironment& env, const SSystemInitParams& initParams) override;
	// ~Cry::IEnginePlugin

	// ISystemEventListener
	virtual void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;
	// ~ISystemEventListener

	// INetworkedClientListener
	// Sent to the local client on disconnect
	virtual void OnLocalClientDisconnected(EDisconnectionCause cause, const char* description) override {}

	// Sent to the server when a new client has started connecting
	// Return false to disallow the connection
	virtual bool OnClientConnectionReceived(int channelId, bool bIsReset) override;

	// Sent to the server when a new client has finished connecting and is ready for gameplay
	// Return false to disallow the connection and kick the player
	virtual bool OnClientReadyForGameplay(int channelId, bool bIsReset) override;

	// Sent to the server when a client is disconnected
	virtual void OnClientDisconnected(int channelId, EDisconnectionCause cause, const char* description, bool bKeepClient) override;

	// Sent to the server when a client is timing out (no packets for X seconds)
	// Return true to allow disconnection, otherwise false to keep client.
	virtual bool OnClientTimingOut(int channelId, EDisconnectionCause cause, const char* description) override { return true; }
	// ~INetworkedClientListener

	// Helper function to call the specified callback for every player in the game
	void IterateOverPlayers(std::function<void(CPlayerComponent& player)> func) const;

	// Helper function to get the CSkyllaPlugin instance
	// Note that CSkyllaPlugin is declared as a singleton, so the CreateClassInstance will always return the same pointer
	static CSkyllaPlugin* GetInstance()
	{
		return cryinterface_cast<CSkyllaPlugin>(CSkyllaPlugin::s_factory.CreateClassInstance().get());
	}

protected:
	// Map containing player components, key is the channel id received in OnClientConnectionReceived
	std::unordered_map<int, EntityId> m_players;
};
}