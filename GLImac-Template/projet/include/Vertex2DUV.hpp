#include <glimac/glm.hpp>

class Vertex2DUV{
    public:
        glm::vec2 _pos;
        glm::vec2 _tex;
        Vertex2DUV(const glm::vec2 &pos, const glm::vec2 &tex): _pos(pos), _tex(tex){};
};