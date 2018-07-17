#include "ChangeVertexType.h"

std::vector<kit::Engine::VertexPosNorTex> ChangeVertexType(kit::VertexInfo const& _vertexInfo) {
	std::vector<kit::Engine::VertexPosNorTex> vertices = {};
	
	for ( int i = 0; i < _vertexInfo.vertices.size(); ++i ) {
		kit::Engine::VertexPosNorTex vertex = {};
		DirectX::XMFLOAT3 v = {};
		DirectX::XMFLOAT3 n = {};
		DirectX::XMFLOAT2 t = {};

		v.x = _vertexInfo.vertices[i].x;
		v.y = _vertexInfo.vertices[i].y;
		v.z = _vertexInfo.vertices[i].z;

		n.x = _vertexInfo.normals[i].x;
		n.y = _vertexInfo.normals[i].y;
		n.z = _vertexInfo.normals[i].z;

		t.x = _vertexInfo.texcoords[i].x;
		t.y = _vertexInfo.texcoords[i].y;

		vertex = { v,n,t };

		vertices.push_back(vertex);
	}
	return vertices;
}