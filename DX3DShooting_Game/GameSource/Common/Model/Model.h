#pragma once

#include <d3d11.h>
#include <wrl.h>
#include <vector>

template<typename Vertex>
class Model {
public:
	bool Create(ID3D11Device* _pd3dDevice, std::vector<Vertex> const& _vertices, std::vector<uint16_t> const& _indices) {
		mu_indexCount = static_cast<unsigned>(_indices.size());

		// Create vertex buffer
		D3D11_BUFFER_DESC bufferDesc;
		ZeroMemory(&bufferDesc, sizeof( D3D11_BUFFER_DESC ));
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof( Vertex ) * static_cast< unsigned >( _vertices.size() );
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA initData;
		initData.pSysMem = _vertices.data();

		HRESULT hr = _pd3dDevice->CreateBuffer(&bufferDesc, &initData, mcptr_vertexBuffer.GetAddressOf());
		if ( FAILED ( hr )) { return false; }

		// Create index buffer
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof( uint16_t ) * static_cast< unsigned >( _indices.size() );
		bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		initData.pSysMem = _indices.data();

		hr = _pd3dDevice->CreateBuffer(&bufferDesc, &initData, mcptr_indexBuffer.GetAddressOf());
		if ( FAILED ( hr )) { return false; }

		return true;
	}

	void Draw(ID3D11DeviceContext* _pd3dImmdiateContext) {
		// Set index buffer
		_pd3dImmdiateContext->IASetIndexBuffer( mcptr_indexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0 );

		// Set primitive topology
		_pd3dImmdiateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );

		// Set vertex buffer
		UINT stride = sizeof(Vertex);
		UINT offset = 0;
		_pd3dImmdiateContext->IAGetVertexBuffers( 0, 1, mcptr_vertexBuffer.GetAddressOf(), &stride, &offset );

		// Draw the mesh
		_pd3dImmdiateContext->DrawIndexed( mu_indexCount, 0, 0 );
	}

	void Destory() {
		mcptr_vertexBuffer.Reset();
		mcptr_indexBuffer.Reset();
	}
private:
	Microsoft::WRL::ComPtr< ID3D11Buffer > mcptr_vertexBuffer;
	Microsoft::WRL::ComPtr< ID3D11Buffer > mcptr_indexBuffer;
	unsigned mu_indexCount;
};