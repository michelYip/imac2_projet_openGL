#ifndef _VERTEX3DUV_ 
#define _VERTEX3DUV_


#include <glimac/glm.hpp>

class Vertex3DUV{
    public:
        glm::vec3 _pos;
        glm::vec3 _tex;
        Vertex3DUV(const glm::vec3 &pos, const glm::vec3 &tex): _pos(pos), _tex(tex){};
};

#endif