#include "Vectors.hpp"
#include "SDLWrapper.hpp"
#include <vector>
#include <cstdlib>

#define edges 8
const double pi = 3.14159265;

class Asteroid
{
	private:
		Vector centre;
		Vector velocity;
		double angVelocity;
		int radius;
		std::vector<Vector> corners;
	public:
		Asteroid(int x, int y, int r)
		{
			centre = Vector(x,y);
			radius = r;
			for(double i=0;i<2*pi;i+=2*pi/edges)
				corners.push_back(Vector(
				centre.x + (radius + rand()%(radius/2))*std::cos(i), 
				centre.y + (radius + rand()%(radius/2))*std::sin(i)));
		}
		void draw(Window& scr)
		{
			for(int i=1;i<edges;++i)
				scr.drawLine(
					corners[i-1].x, corners[i-1].y,
					corners[i].x, corners[i].y, 
					255, 255, 255);
			scr.drawLine(corners.front().x, corners.front().y,
						 corners.back().x, corners.back().y,
						 255, 255, 255);
		}
};
