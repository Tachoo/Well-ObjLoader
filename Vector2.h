#pragma once
namespace objl
{
	// Estructura: Vector2
	//
	// Descripcion: un vector en el espacio dimencional R2 que contiene datos de posicion 
	struct Vector2
	{
		//Variables publicas
		float X = NULL;
		float Y = NULL;
		//Constructor
		Vector2():X(0),Y(0) {/*Optimizado*/ };
		//Set Constructor
		Vector2(float X_, float Y_) :X(X_), Y(Y_) {/*Optimizado*/ };
		// Bool Igualacion Overload
		bool operator==(const Vector2& other) const
		{
			return (this->X == other.X && this->Y == other.Y);
		}
		// Bool Diferencia  Overload
		bool operator!=(const Vector2& other) const
		{
			return !(this->X == other.X && this->Y == other.Y);
		}
		// Adicion  Overload
		Vector2 operator+(const Vector2& right) const
		{
			return Vector2(this->X + right.X, this->Y + right.Y);
		}
		// Substraer Overload
		Vector2 operator-(const Vector2& right) const
		{
			return Vector2(this->X - right.X, this->Y - right.Y);
		}
		// Float Multiplicacion  Overload
		Vector2 operator*(const float& other) const
		{
			return Vector2(this->X *other, this->Y * other);
		}
	};
}