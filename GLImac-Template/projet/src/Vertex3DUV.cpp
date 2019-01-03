#include "Vertex3DUV.hpp"

std::ostream& operator<<(std::ostream &os, const Vertex3DUV &p){
    os << "[POS:(" << p._pos.x << "," << p._pos.y << "," << p._pos.z << ")";
    os << " - NORM:(" << p._norm.x << "," << p._norm.y << "," << p._norm.z << ")";
    os << " - TEX:(" << p._tex.x << "," << p._tex.y << ")]";
    return os;
}
