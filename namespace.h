#pragma once
#include"Mesh.h"
// Namespace: Math
//
// Descripcion: contiene algunas propiedades de los vecotres utiles
namespace math
{
	// Vector3 Producto Cruz
	objl::Vector3 CrossV3(const objl::Vector3 a, const objl::Vector3 b)
	{
		return objl::Vector3(a.Y * b.Z - a.Z * b.Y,
			a.Z * b.X - a.X * b.Z,
			a.X * b.Y - a.Y * b.X);
	}

	// Vector3 Maginitud del vector
	float MagnitudeV3(const objl::Vector3 in)
	{
		return (sqrtf(powf(in.X, 2) + powf(in.Y, 2) + powf(in.Z, 2)));
	}

	// Vector3 Producto Punto
	float DotV3(const objl::Vector3 a, const objl::Vector3 b)
	{
		return (a.X * b.X) + (a.Y * b.Y) + (a.Z * b.Z);
	}

	// Angulo entre dos vectores
	float AngleBetweenV3(const objl::Vector3 a, const objl::Vector3 b)
	{
		float angle = DotV3(a, b);
		angle /= (MagnitudeV3(a) * MagnitudeV3(b));
		return angle = acosf(angle);
	}
}

// Namespace: Algorithm
//
// Descripcion: contiene algunos algoritmos utiles
namespace algorithm
{
	// Vector3 Operator Multiplicacion  Overload
	objl::Vector3 operator*(const float& left, const objl::Vector3& right)
	{
		return objl::Vector3(right.X * left, right.Y * left, right.Z * left);
	}

	// Vector3 Es un triangulo?
	bool inTriangle(objl::Vector3 point, objl::Vector3 tri1, objl::Vector3 tri2, objl::Vector3 tri3)
	{
		
		objl::Vector3 u = tri2 - tri1;
		objl::Vector3 v = tri3 - tri1;
		objl::Vector3 w = point - tri1;
		objl::Vector3 n = math::CrossV3(u, v);

		float y = (math::DotV3(math::CrossV3(u, w), n) / math::DotV3(n, n));
		float b = (math::DotV3(math::CrossV3(u, w), n) / math::DotV3(n, n));
		float a = 1 - y - b;

		// Projecion de los puntos
		objl::Vector3  p = (a * tri1) + (b * tri2) + (y * tri3);

		if (a >= 0 && a <= 1
			&& b >= 0 && b <= 1
			&& y >= 0 && y <= 1)
		{
			return true;
		}
		else
			return false;
	}

	// Organizar el string y darles un ID
	inline void split(const std::string &in,
		std::vector<std::string> &out,
		std::string token)
	{
		out.clear();

		std::string temp;

		for (int i = 0; i < int(in.size()); i++)
		{
			std::string test = in.substr(i, token.size());

			if (test == token)
			{
				if (!temp.empty())
				{
					out.push_back(temp);
					temp.clear();
					i += (int)token.size() - 1;
				}
				else
				{
					out.push_back("");
				}
			}
			else if (i + token.size() >= in.size())
			{
				temp += in.substr(i, token.size());
				out.push_back(temp);
				break;
			}
			else
			{
				temp += in[i];
			}
		}
	}

	// Asignamos los id
	inline std::string tail(const std::string &in)
	{
		size_t token_start = in.find_first_not_of(" \t");
		size_t space_start = in.find_first_of(" \t", token_start);
		size_t tail_start = in.find_first_not_of(" \t", space_start);
		size_t tail_end = in.find_last_not_of(" \t");
		if (tail_start != std::string::npos && tail_end != std::string::npos)
		{
			return in.substr(tail_start, tail_end - tail_start + 1);
		}
		else if (tail_start != std::string::npos)
		{
			return in.substr(tail_start);
		}
		return "";
	}

	// Obtener el primer ID
	inline std::string firstToken(const std::string &in)
	{
		if (!in.empty())
		{
			size_t token_start = in.find_first_not_of(" \t");
			size_t token_end = in.find_first_of(" \t", token_start);
			if (token_start != std::string::npos && token_end != std::string::npos)
			{
				return in.substr(token_start, token_end - token_start);
			}
			else if (token_start != std::string::npos)
			{
				return in.substr(token_start);
			}
		}
		return "";
	}

	// Obtener el elemento en el index dado
	template <class T>
	inline const T & getElement(const std::vector<T> &elements, std::string &index)
	{
		int idx = std::stoi(index);
		if (idx < 0)
			idx = int(elements.size()) + idx;
		else
			idx--;
		return elements[idx];
	}
}
