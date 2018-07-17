#include "Plane.h"

Plane::Plane() {
	
}

Plane::~Plane() {

}

void Plane::Control(kit::vec3 _target) {

}

void Plane::AutoControl(kit::vec3 _target) {

}

void Plane::Update(kit::vec3 _target) {

}

void Plane::Render(ID3D11DeviceContext* _pd3dImmidiateContext) {
	m_model.Render(_pd3dImmidiateContext);
}