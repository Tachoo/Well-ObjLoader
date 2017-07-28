#pragma once
#include<vector>
#include"Vertex.h"
#include"Material.h"

namespace objl
{
	// Estructura: Mesh
	//
	// Descripcion: Un mesh que almacena el nombre , sus vertices y su index
	struct Mesh
	{
		// Nombre del mesh
		std::string MeshName;
		// Vector de Vertices
		std::vector<Vertex> Vertices;
		// Vector de indices
		std::vector<unsigned int> Indices;
		// Material
		Material MeshMaterial;

		// Constructor
		Mesh() {/*Optimizado*/ };
		// Set Constructor
		Mesh(std::vector<Vertex>& _Vertices, std::vector<unsigned int>& _Indices) :Vertices(_Vertices), Indices(_Indices) {/*Optimizado*/ };
	};
}