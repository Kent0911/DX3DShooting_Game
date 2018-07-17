#pragma once

#include <d3d11.h>
#include <string>

#include "CKitBehaviour.h"
#include "CModel.h"
#include "CVertexTypes.h"
#include "../FlyingObject.h"

enum class ControlIs {
	Player = false,
	CPU = true
};

class Plane : public FlyingObject {
public:
	Plane( ID3D11Device* _pd3dDevice, bool _flag );
	~Plane();
	void( Plane::*mfunc_control )( kit::vec3 );

	inline void WhoisControl( bool _flag ) {
		mb_isComControl = _flag;
	}

	virtual void Update( kit::vec3 _target );
	virtual void Render( ID3D11DeviceContext* _pd3dImmidiateContext );
private:
	void Control( kit::vec3 _target );
	void AutoControl( kit::vec3 _target );

	bool mb_isComControl;
};