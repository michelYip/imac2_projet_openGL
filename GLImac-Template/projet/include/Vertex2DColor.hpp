#include <glimac/glm.hpp>

class Vertex2DColor{
    public:
        glm::vec2 _position;
        glm::vec3 _color;

        Vertex2DColor(const glm::vec2 &position, const glm::vec3 &color): _position(position), _color(color){};
};