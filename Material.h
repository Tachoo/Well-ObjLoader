#pragma once
#include <string>

namespace objl
{
	struct Material
	{
		// Nombre del Material
		std::string name;
		// Color Ambiente
		Vector3 Ka;
		// Color Diffuso
		Vector3 Kd;
		// Color Specular
		Vector3 Ks;
		// Specular Exponent
		float Ns;
		// Optical Density
		float Ni;
		// Desvanecimiento
		float d;
		// Iluminacion
		int illum;
		// Textura de ambiente
		std::string map_Ka;
		// Textura diffusa
		std::string map_Kd;
		// Textura specular
		std::string map_Ks;
		// Realce Especular
		std::string map_Ns;
		// Textura Alpha
		std::string map_d;
		// Bump map
		std::string map_bump;
		// Constructor
		Material() :name(""), Ns(0.0f), Ni(0.0f), d(0.0f), illum(0) {/*Optimizado*/ };
	};
}