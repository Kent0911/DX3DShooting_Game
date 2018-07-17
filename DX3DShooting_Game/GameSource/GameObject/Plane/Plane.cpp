#include "Plane.h"

Plane::Plane() {
	
}

Plane::~Plane() {

}

void Plane::Update() {

}

void Plane::Render(ID3D11DeviceContext* _pd3dImmidiateContext) {
	m_model.Render(_pd3dImmidiateContext);
}