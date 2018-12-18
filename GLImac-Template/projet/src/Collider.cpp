#include "Collider.hpp"

Collider::Collider()
:_lower(glm::vec3(0.f)), _upper(glm::vec3(0.f))
{}

Collider::Collider(const Collider & other)
:_upper(other._upper), _lower(other._upper)
{}

Collider::Collider(const glm::vec3 & lower, const glm::vec3 &upper)
: _lower(lower), _upper(upper)
{}

std::ostream& operator<<(std::ostream &os, const Collider &c){
	os << "Lower : (" << c._lower[0] << ", " << c._lower[1] << ", " << c._lower[2] << ")" << std::endl
	   << "Upper : (" << c._upper[0] << ", " << c._upper[1] << ", " << c._upper[2] << ")" << std::endl;
	return os;
}

inline glm::vec3 Collider::getCenter() const {
	return 0.5f * (_lower + _upper);
}

Collider Collider::intersect(const Collider & other){
	return Collider(glm::max(_lower, other._lower), glm::min(_upper, other._upper));
}

bool Collider::empty() const {
	for (auto i = 0u; i < DIM; i++) 
		if (_lower[i] > _upper[i]) return true; 
	return false; 
}

glm::vec3 Collider::size() const{
	return _upper - _lower;
}

bool Collider::isColliding(const Collider & other){
	Collider colision = intersect(other);
	return colision.empty();
}

void Collider::moveCollider(const glm::vec3 & direction){
	_lower += direction;
	_upper += direction;
}

bool Collider::operator==(const Collider & other){
	return (_lower == other._lower) 
		&& (_upper == other._upper);
}