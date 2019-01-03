#ifndef _VERTEX3DUV_ 
#define _VERTEX3DUV_


#include <glimac/glm.hpp>

class Vertex3DUV{
	private:
        glm::vec3 _pos;
        glm::vec3 _norm;
        glm::vec2 _tex;

    public:
        Vertex3DUV(const glm::vec3 &pos, const glm::vec3 &norm, const glm::vec2 &tex): _pos(pos), _tex(tex), _norm(norm){};
        Vertex3DUV(const Vertex3DUV &v): _pos(v._pos), _tex(v._tex), _norm(v._norm){};

        const glm::vec3 &pos() const{return _pos;}
        const glm::vec3 &norm() const{return _norm;}
        const glm::vec2 &tex() const{return _tex;}
        glm::vec3 &pos() {return _pos;}
        glm::vec3 &norm() {return _norm;}
        glm::vec2 &tex() {return _tex;}

        static size_t offset_pos(){return offsetof(Vertex3DUV,_pos);}
        static size_t offset_norm(){return offsetof(Vertex3DUV,_norm);}
        static size_t offset_tex(){return offsetof(Vertex3DUV,_tex);}

        //OPERATORS
        friend std::ostream& operator<<(std::ostream &os, const Vertex3DUV &p);

};
#endif