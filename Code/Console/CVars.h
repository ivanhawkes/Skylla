#pragma once

namespace Skylla
{
class CCVars final
{
public:
	CCVars() = default;
	CCVars(CCVars const&) = delete;
	CCVars(CCVars&&) = delete;
	CCVars& operator=(CCVars const&) = delete;
	CCVars& operator=(CCVars&&) = delete;

	void RegisterVariables();
	void UnregisterVariables();

	// Game - misc
	int m_rayCastQuota{ 64 };
	int m_ladder_logVerbosity{ 0 };
	int m_cl_invertPitch{ 0 };
	float m_cl_mouseSensitivity{ 1.0f };
	int m_watch_enabled{ true };
	float m_watch_text_render_start_pos_x{ 35.0f };
	float m_watch_text_render_start_pos_y{ 180.0f };
	float m_watch_text_render_size{ 1.75f };
	float m_watch_text_render_lineSpacing{ 9.3f };
	float m_watch_text_render_fxscale{ 13.0f };
};

extern CCVars g_cvars;
}