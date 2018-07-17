#include "Player.h"

Player::Player() {
	md_gamepadNumber = muptr_devices->GetGamepad().AssignNumber();
}

void Player::GameMainKeyboardControl() {
	DirectX::Keyboard::State keyboard = muptr_devices->GetKeyboard();
	DirectX::Mouse::State mouse = muptr_devices->GetMouse();

	if ( keyboard.IsKeyDown ( DirectX::Keyboard::D )) {
		
	}
}

void Player::GameMainGamepadControl() {
	XINPUT_GAMEPAD gamepad = muptr_devices->GetGamepad().GetState(md_gamepadNumber);
}