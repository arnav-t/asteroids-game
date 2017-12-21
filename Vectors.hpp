#include <cmath>

class Vector
{
	private:
		double x,y;
	public:
		Vector(double X = 0, double Y = 0)
		{
			x = X;
			y = Y;
		}
		double magnitude()
		{
			return std::sqrt(x*x + y*y);
		}
		Vector operator+(const Vector& v)
		{
			return Vector(this->x + v.x, this->y + v.y);
		}
		Vector operator-(const Vector& v)
		{
			return Vector(this->x - v.x, this->y - v.y);
		}
		double operator*(const Vector& v)
		{
			return (this->x)*(v.x) + (this->y)*(v.y);
		}
};
