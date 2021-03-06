#include "Coin.hpp"
 
Coin::Coin(const int & x, const int & y, const int & altitude)
:StaticObject(  glm::vec3(x     ,altitude   ,y),
                glm::vec3(x-0.5 ,altitude   ,y-0.5),
                glm::vec3(x+0.5 ,altitude+1 ,y+0.5))
{loadMesh();}

Coin::Coin(const Coin &coin): StaticObject(coin)
{} 