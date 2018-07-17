#pragma once

#include <d3d11.h>
#include <string>

#include "CKitBehaviour.h"
#include "CModel.h"
#include "CVertexTypes.h"
#include "../Library/KitLib/include/ObjFile.h"

class Plane : public kit::Engine::KitBehaviour {
public:
	Plane();
	~Plane();

	virtual void Update();
	virtual void Render(ID3D11DeviceContext* _pd3dImmidiateContext);
private:
	kit::Engine::Model< kit::Engine::VertexPosNorTex > m_model;
};