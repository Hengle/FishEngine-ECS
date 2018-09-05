#pragma once

#include "Engine.hpp"
#include "Object.hpp"
#include "Math.hpp"

#include <vector>
#include <bgfx/bgfx.h>

struct PUNTVertex
{
	Vector3 position;
	Vector2 uv;
	Vector3 normal;
	Vector3 tangent;

	static void init();;

	static bgfx::VertexDecl ms_decl;
};

#include <FishEngine/Math/IntVector.hpp>


class Mesh : public Object
{
	friend class MeshUtil;
public:
	bgfx::IndexBufferHandle m_IndexBuffer;
	bgfx::VertexBufferHandle m_VertexBuffer;
	
	// for cpu skinning
	bgfx::DynamicVertexBufferHandle m_DynamicVertexBuffer = BGFX_INVALID_HANDLE;
	std::vector<PUNTVertex> m_DynamicVertices;

	std::vector<FishEngine::Int4> joints;
	std::vector<Vector4> weights;
	
	Bounds bounds;


	inline static Mesh* Cube = nullptr;
	inline static Mesh* Sphere = nullptr;
	inline static Mesh* Bunny = nullptr;

	static void StaticInit();

	void Bind();

	bool IsSkinned() const { return joints.size() > 0; }

//private:
public:
	uint32_t m_vertexCount = 0;
	uint32_t m_triangleCount = 0;
	int						m_subMeshCount = 1;
	//std::vector<Vector3>    m_vertices;
	//std::vector<Vector3>    m_normals;
	//std::vector<Vector2>    m_uv;
	//std::vector<Vector3>    m_tangents;
	//std::vector<uint32_t>   m_triangles;
	//std::vector<uint32_t>	m_subMeshIndexOffset;	// index start

	std::vector<PUNTVertex> vertices;
	std::vector<uint16_t> indices;
};

namespace ECS
{
	class GameObject;
	class Scene;
}


class MeshUtil : public Static
{
public:
	static Mesh* FromTextFile(const String & str);
	
};
