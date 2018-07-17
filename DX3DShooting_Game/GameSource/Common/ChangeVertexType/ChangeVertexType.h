#pragma once

#include <d3d11.h>
#include <vector>

#include "CVertexTypes.h"
#include "../Library/KitLib/include/ObjFile.h"

std::vector< kit::Engine::VertexPosNorTex > ChangeVertexType( kit::VertexInfo const& _vertexInfo );
std::vector< uint16_t > ChangeIndex( kit::VertexInfo const& _vertexInfo );