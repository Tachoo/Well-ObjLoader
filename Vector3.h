#pragma once
namespace objl
{
	// Estructura: Vector3
	//
	// Descripcion: un vector en el espacio dimencional R3 que contiene datos de posicion 
	struct Vector3
	{
		//Variables publicas
		float X = NULL;
		float Y = NULL;
		float Z = NULL;
		//Constructor
		Vector3() :X(0.0f), Y(0.0f), Z(0.0f) {/*Optimizado*/ };
		//Set Constructor
		Vector3(float X_, float Y_, float Z_) :X(X_), Y(Y_), Z(Z_) {/*Optimizado*/ };
		// Bool Igualacion Overload
		bool operator==(const Vector3& other) const
		{
			return (this->X == other.X && this->Y == other.Y && this->Z == other.Z);
		}
		// Bool Diferencia  Overload
		bool operator!=(const Vector3& other) const
		{
			return !(this->X == other.X && this->Y == other.Y && this->Z == other.Z);
		}
		// Adicion  Overload
		Vector3 operator+(const Vector3& right) const
		{
			return Vector3(this->X + right.X, this->Y + right.Y, this->Z + right.Z);
		}
		// Substraer Overload
		Vector3 operator-(const Vector3& right) const
		{
			return Vector3(this->X - right.X, this->Y - right.Y, this->Z - right.Z);
		}
		// Float Multiplicacion  Overload
		Vector3 operator*(const float& other) const
		{
			return Vector3(this->X *other, this->Y * other, this->Z - other);
		}
	};
};