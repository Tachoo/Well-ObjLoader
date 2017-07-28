// Example 1: Load and Print
//
// Load the data from the .obj then print it into a file
//	called e1Out.txt

// Iostream
#include <iostream>

// fStream
#include <fstream>

// OBJ_Loader
#include "OBJ_Loader.h"

// Main
int main(int argc, char* argv[])
{
	// Nombre , Extencion
	std::string Name;
	Name = "box_stack";
	std::string Extencion;
	Extencion = Name + ".obj";

	// Intancia de el cargador
	objl::Loader Loader;

	// Cargar el obj
	bool loadout = Loader.LoadFile(Extencion);
	//Si fue cargado		
	if (loadout)
	{
		// Creamos el arvhivo del Log
		std::string name = "Out_"+Name+"_Log" + ".txt";
		std::ofstream file(name);

		// Verificamos si tiene cosas adentro
		for (int i = 0; i < Loader.LoadedMeshes.size(); i++)
		{
			// Copiamos el primer elemento a un temporal
			objl::Mesh curMesh = Loader.LoadedMeshes[i];

			// tiene nombre ?
			file << "Mesh " << i << ": " << curMesh.MeshName << "\n";

			// Vertices
			file << "Vertices:\n";

			
			// ahora solo  position, normal, and texture coordinate
			for (int j = 0; j < curMesh.Vertices.size(); j++)
			{
				file << "V" << j << ": " <<
					"P(" << curMesh.Vertices[j].Position.X << ", " << curMesh.Vertices[j].Position.Y << ", " << curMesh.Vertices[j].Position.Z << ") " <<
					"N(" << curMesh.Vertices[j].Normal.X << ", " << curMesh.Vertices[j].Normal.Y << ", " << curMesh.Vertices[j].Normal.Z << ") " <<
					"TC(" << curMesh.Vertices[j].TextureCoordinate.X << ", " << curMesh.Vertices[j].TextureCoordinate.Y << ")\n";
			}

			// Indices
			file << "Indices:\n";

			// Go through every 3rd index and print the
			//	triangle that these indices represent
			for (int j = 0; j < curMesh.Indices.size(); j += 3)
			{
				file << "T" << j / 3 << ": " << curMesh.Indices[j] << ", " << curMesh.Indices[j + 1] << ", " << curMesh.Indices[j + 2] << "\n";
			}

			// Materiales
			file << "Material: " << curMesh.MeshMaterial.name << "\n";
			file << "Ambient Color: " << curMesh.MeshMaterial.Ka.X << ", " << curMesh.MeshMaterial.Ka.Y << ", " << curMesh.MeshMaterial.Ka.Z << "\n";
			file << "Diffuse Color: " << curMesh.MeshMaterial.Kd.X << ", " << curMesh.MeshMaterial.Kd.Y << ", " << curMesh.MeshMaterial.Kd.Z << "\n";
			file << "Specular Color: " << curMesh.MeshMaterial.Ks.X << ", " << curMesh.MeshMaterial.Ks.Y << ", " << curMesh.MeshMaterial.Ks.Z << "\n";
			file << "Specular Exponent: " << curMesh.MeshMaterial.Ns << "\n";
			file << "Optical Density: " << curMesh.MeshMaterial.Ni << "\n";
			file << "Dissolve: " << curMesh.MeshMaterial.d << "\n";
			file << "Illumination: " << curMesh.MeshMaterial.illum << "\n";
			file << "Ambient Texture Map: " << curMesh.MeshMaterial.map_Ka << "\n";
			file << "Diffuse Texture Map: " << curMesh.MeshMaterial.map_Kd << "\n";
			file << "Specular Texture Map: " << curMesh.MeshMaterial.map_Ks << "\n";
			file << "Alpha Texture Map: " << curMesh.MeshMaterial.map_d << "\n";
			file << "Bump Map: " << curMesh.MeshMaterial.map_bump << "\n";

			// Pequeño espacio  de mesh a mesh
			file << "\n";
		}

		// Close File
		file.close();
	}
	// If not output an error
	else
	{
		// Create/Open Out.txt
		std::string name = "Out_" + Name + "_Log" + ".txt";
		std::ofstream file(name);

		//  Error
		file << "Failed to Load File. May have failed to find it or it was not an .obj file.\n";

		//  File
		file.close();
	}

	
	// Exit the program
	return 0;
}