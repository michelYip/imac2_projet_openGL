#include "Collider.hpp"

//Default constructor
Collider::Collider()
:_lower(glm::vec3(0.f)), _upper(glm::vec3(0.f))
{}

//Reference constructor
Collider::Collider(const Collider & other)
:_lower(other._lower), _upper(other._upper)
{}

//Parameters constructor
Collider::Collider(const glm::vec3 & lower, const glm::vec3 &upper)
: _lower(lower), _upper(upper)
{}

//Output stream
std::ostream& operator<<(std::ostream &os, const Collider &c){
	os << "Lower : (" << c._lower[0] << ", " << c._lower[1] << ", " << c._lower[2] << ")   "
	   << "Upper : (" << c._upper[0] << ", " << c._upper[1] << ", " << c._upper[2] << ")" << std::endl;
	return os;
}

//Comparison operator
bool Collider::operator==(const Collider & other){
	return (_lower == other._lower) 
		&& (_upper == other._upper);
}

//Equal operator
Collider & Collider::operator=(const Collider & other){
	_lower = other.lower();
	_upper = other.upper();
	return *this;
}

//Addition operator
Collider Collider::operator+(const glm::vec3 & v){
	return Collider(_lower+v, _upper+v);
}

//Compute the center of the bounding box
inline glm::vec3 Collider::getCenter() const {
	return 0.5f * (_lower + _upper);
}

//Return the intersection between two bounding boxes
Collider Collider::intersect(const Collider & other) const{
	return Collider(glm::max(_lower, other._lower), glm::min(_upper, other._upper));
}

//Check if a bounding box is empty
bool Collider::empty() const {
	for (auto i = 0u; i < DIM; i++) 
		if (_lower[i] > _upper[i]) return true; 
	return false; 
}

//Return the size of a bounding box
glm::vec3 Collider::size() const{
	return _upper - _lower;
}

//Check the collision between two bounding boxes
bool Collider::isColliding(const Collider & other) const{
	Collider colision = intersect(other);
	return !colision.empty();
}

//Move a bounding box
void Collider::moveCollider(const glm::vec3 & direction){
	_lower += direction;
	_upper += direction;
}