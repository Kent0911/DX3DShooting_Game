#include "Plane.h"

Plane::Plane( ID3D11Device* _pd3dDevice, bool _flag ) {
	std::vector< kit::Engine::VertexPosNorTex > vertices = ChangeVertexType( *kit::LoadObjFile("Resources/Plane.obj") );
	std::vector< uint16_t > indices = ChangeIndex( *kit::LoadObjFile("Resources/Plane.obj") );
	m_model.Create( _pd3dDevice, vertices, indices );
	WhoisControl( _flag );
	if ( !mb_isComControl ) { mfunc_control = &Plane::Control; }
	else if ( mb_isComControl ) { mfunc_control = &Plane::AutoControl; }
}

Plane::~Plane() {
	m_model.Destroy();
}

void Plane::Control(kit::vec3 _target) {

}

void Plane::AutoControl(kit::vec3 _target) {

}

void Plane::Update(kit::vec3 _target) {
	(this->*mfunc_control)(_target);
}

void Plane::Render(ID3D11DeviceContext* _pd3dImmidiateContext) {
	m_model.Render(_pd3dImmidiateContext);
}