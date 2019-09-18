#include <StdAfx.h>

#include "CVars.h"
#include <CrySystem/ISystem.h>
#include <CrySystem/ConsoleRegistration.h>
#include <Plugin/SkyllaPlugin.h>


namespace Skylla
{
CCVars g_cvars;

void CCVars::RegisterVariables()
{
	// ***
	// *** VARIABLES
	// ***

	// Game - misc
	REGISTER_CVAR2("game_rayCastQuota", &m_rayCastQuota, 64, VF_CHEAT, "Number of allowed deferred raycasts.");
	REGISTER_CVAR2("cl_invertPitch", &m_cl_invertPitch, false, VF_CHEAT, "Should we invert the Y axis for camera movements? This is preferred by some players, particularly those using a flight yoke.");
	REGISTER_CVAR2("cl_mouseSensitivity", &m_cl_mouseSensitivity, 1.0f, VF_CHEAT, "Overall mouse sensitivity. This should be factored into any movements involving the mouse.");
	REGISTER_CVAR2("watch_enabled", &m_watch_enabled, true, VF_CHEAT, "Is watch debug enabled?");
	REGISTER_CVAR2("watch_text_render_start_pos_x", &m_watch_text_render_start_pos_x, 35.0f, VF_CHEAT, "The watch text render start position x coordinate.");
	REGISTER_CVAR2("watch_text_render_start_pos_y", &m_watch_text_render_start_pos_y, 18.0f, VF_CHEAT, " The watch text render start position y coordinate.");
	REGISTER_CVAR2("watch_text_render_size", &m_watch_text_render_size, 1.75f, VF_CHEAT, "Size at which the watch text will render.");
	REGISTER_CVAR2("watch_text_render_lineSpacing", &m_watch_text_render_lineSpacing, 9.3f, VF_CHEAT, "Line spacing for watch text.");
	REGISTER_CVAR2("watch_text_render_fxscale", &m_watch_text_render_fxscale, 13.0f, VF_CHEAT, "The watch text render fxscale.");

	// ***
	// *** COMMANDS
	// ***

}


void CCVars::UnregisterVariables()
{
	// ***
	// *** VARIABLES
	// ***


	// ***
	// *** COMMANDS
	// ***

}
}