#include "Player.hpp"

std::ostream& operator<<(std::ostream &os, const Player &p){
	os << "[name:" << p._name << ", money:" << p._money << ", savingFile:" << p._savingFile << "]";
	return os;
}