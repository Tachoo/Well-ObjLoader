#pragma once
#include"Vector3.h"
#include"Vector2.h"
namespace objl
{
	// Estructura: Vertex
	// Descripcion: Objeto que almacena la Posicion , la normal  y las cordenadas de la textura
	struct Vertex
	{
		Vector3 Position;//Posicion
		Vector3 Normal;//Normal
		Vector2 TextureCoordinate;//Text
	};
}