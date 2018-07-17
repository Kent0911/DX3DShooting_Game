#pragma once

#include <d3d11.h>

#include "CKitBehaviour.h"
#include "../Library/KitLib/include/Kitlib.h"
#include "CModel.h"
#include "CVertexTypes.h"
#include "../../Common/ChangeVertexType/ChangeVertexType.h"

class FlyingObject : public kit::Engine::KitBehaviour {
public:
	inline kit::vec3 Position() const {
		return mvec_position;
	}

	virtual void Update(kit::vec3 _target) = 0;
	virtual void Render(ID3D11DeviceContext* _pd3dImmidiateContext) = 0;
protected:
	kit::vec3 m_speed;
	kit::vec3 m_accelSpeed;
	kit::axis m_accelYaw;
	kit::Engine::Model< kit::Engine::VertexPosNorTex > m_model;

	bool LoadAndCreateModel( ID3D11Device* _pd3dDevice, std::string _path );
};