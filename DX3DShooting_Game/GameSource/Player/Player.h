#pragma once

#include <d3d11.h>

#include "../Library/KitLib/include/Kitlib.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "../GameObject/FlyingObject/Plane/Plane.h"

class Scene;

class Devices {
public:
	inline DirectX::Keyboard::State GetKeyboard() const {
		return m_keyboard.GetState();
	}
	inline DirectX::Mouse::State GetMouse() const {
		return m_mouse.GetState();
	}
	inline kit::GamePad GetGamepad() const {
		return m_gamepad;
	}
private:
	DirectX::Keyboard	m_keyboard;
	DirectX::Mouse		m_mouse;
	kit::GamePad		m_gamepad;
};

class Player : public kit::Singleton<Player> {
public:
	inline Devices* GetDevices() {
		return muptr_devices.get();
	}
	void(Player::*mfunc_control)();
	void Update();
private:
	friend class Singleton<Player>;
	Player();

	void GameMainKeyboardControl();
	void GameMainGamepadControl();

	std::unique_ptr<Devices>	muptr_devices;
	DWORD						md_gamepadNumber;
	std::weak_ptr<Scene>		mwptr_currentScene;
	std::unique_ptr<Plane>		muptr_plane;
};