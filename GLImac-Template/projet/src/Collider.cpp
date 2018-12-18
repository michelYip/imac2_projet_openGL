#include "Collider.hpp"

std::ostream& operator<<(std::ostream &os, const Collider &c){
	os << "Size: " << c._size;
	return os;

}