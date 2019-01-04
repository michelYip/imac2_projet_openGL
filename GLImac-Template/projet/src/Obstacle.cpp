#include "Obstacle.hpp"
 

//Parameter constructor
Obstacle::Obstacle(const int & x, const int & y, const float & altitude, const float & height)
:StaticObject(  glm::vec3(x,altitude,y),
                glm::vec3(x,altitude,y),
                glm::vec3(x+1,altitude+height,y+1))
{loadMesh();}
