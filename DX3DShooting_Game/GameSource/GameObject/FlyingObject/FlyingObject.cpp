#include "FlyingObject.h"

bool FlyingObject::LoadAndCreateModel( ID3D11Device* _pd3dDevice, std::string _path ) {
	std::vector< kit::Engine::VertexPosNorTex >			m_vertices;
	std::vector< uint16_t >								m_indices;

	m_vertices = ChangeVertexType(*kit::LoadObjFile(_path));
	if ( nullptr == m_vertices.data() ) { return false; }

	m_indices = ChangeIndex(*kit::LoadObjFile(_path));
	if ( nullptr == m_indices.data() ) { return false; }

	return m_model.Create( _pd3dDevice, m_vertices, m_indices );
}