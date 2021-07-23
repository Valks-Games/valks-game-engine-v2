#pragma once

namespace Valk 
{
	enum class EventType 
	{
		None,
		WindowClose, WindowResize,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
}