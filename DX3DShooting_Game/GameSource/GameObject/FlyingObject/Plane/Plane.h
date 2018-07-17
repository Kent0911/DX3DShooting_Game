#pragma once

#include <d3d11.h>
#include <string>

#include "CKitBehaviour.h"
#include "CModel.h"
#include "CVertexTypes.h"
#include "../FlyingObject.h"


class Plane : public FlyingObject {
public:
	Plane();
	~Plane();
	void(Plane::*mfunc_control)(kit::vec3);
	void Control(kit::vec3 _target);
	void AutoControl(kit::vec3 _target);

	virtual void Update(kit::vec3 _target);
	virtual void Render(ID3D11DeviceContext* _pd3dImmidiateContext);
private:

};