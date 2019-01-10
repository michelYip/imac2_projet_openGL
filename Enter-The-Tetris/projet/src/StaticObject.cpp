#include "StaticObject.hpp"

StaticObject::StaticObject( const glm::vec3 & position, 
                            const glm::vec3 & _lower, 
                            const glm::vec3 & _upper)
:Object(position, _lower, _upper)
{}

StaticObject::StaticObject(const StaticObject &staticObject): Object(staticObject)
{}