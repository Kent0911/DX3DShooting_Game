#pragma once

#include <d3d11.h>

#include "CKitBehaviour.h"
#include "../Library/KitLib/include/Kitlib.h"
#include "CModel.h"
#include "CVertexTypes.h"
#include "../../Common/ChangeVertexType/ChangeVertexType.h"

class MoveState {
public:
	inline void Speed(kit::vec3 _speed){
		m_speed = _speed;
	}
	inline kit::vec3 Speed() const {
		return m_speed;
	}
	inline void AccelSpeed(kit::vec3 _accelSpeed) {
		m_accelSpeed = _accelSpeed;
	}
	inline kit::vec3 AccelSpeed() const {
		return m_accelSpeed;
	}
	inline void AccelYaw(kit::axis _accelYaw) {
		m_accelYaw = _accelYaw;
	}
	inline kit::axis AccelYaw() const {
		return m_accelYaw;
	}
private:
	kit::vec3 m_speed;
	kit::vec3 m_accelSpeed;
	kit::axis m_accelYaw;
};

class FlyingObject : public kit::Engine::KitBehaviour {
public:
	inline kit::vec3 Position() const {
		return mvec_position;
	}
	inline void Yaw( kit::axis _axis ) {
		m_axis = _axis;
	}
	inline MoveState GetMoveState() const {
		return m_moveState;
	}

	virtual void Update( kit::vec3 _target ) = 0;
	virtual void Render( ID3D11DeviceContext* _pd3dImmidiateContext ) = 0;
protected:
	MoveState m_moveState;
	kit::Engine::Model< kit::Engine::VertexPosNorTex > m_model;

	bool LoadAndCreateModel( ID3D11Device* _pd3dDevice, std::string _path );
};