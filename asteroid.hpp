#include "Vectors.hpp"
#include "SDLWrapper.hpp"
#include <vector>
#include <cstdlib>

#define edges 8
const double pi = 3.14159265;

const int maxVelocity = 5;
const int maxAng = 7;

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
			velocity = Vector((rand()%maxVelocity - maxVelocity/2)/10.0,
							  (rand()%maxVelocity - maxVelocity/2)/10.0);
			angVelocity = (rand()%maxAng - maxAng/2)/100.0;
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
		void update(Window& scr)
		{
			for(int i=0;i<edges;++i)
			{
				double r = (corners[i] - centre).magnitude();
				double newAngle = atan2(corners[i].y - centre.y, corners[i].x - centre.x) + angVelocity;
				corners[i].x = centre.x + r*std::cos(newAngle) + velocity.x;
				corners[i].y = centre.y + r*std::sin(newAngle) + velocity.y;
			}
			centre = centre + velocity;
			draw(scr);
		}
};
