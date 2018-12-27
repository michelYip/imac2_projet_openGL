#include <glimac/glm.hpp>

using namespace glm;

class TrackballCamera{

	private:
		float _fDistance;	// distance par rapport au centre de la scène
		float _fAngleX;		// angle de la caméra autour de l'axe x
		float _fAngleY;		// de l'axe Y

	public:
		// constructeur(s)
		TrackballCamera():_fDistance(-5.f), _fAngleY(0.f),_fAngleX(0.f){}; 

		// getters
		inline const float getDistance() const{
			return _fDistance;
		};
		inline const float getAngleX() const{
			return _fAngleX;
		};
		inline const float getAngleY() const{
			return _fAngleY;
		};

		// méthodes
		void moveFront(float delta){
			this->_fDistance += delta;
		};
		void rotateLeft(float degrees){
			this->_fAngleY += degrees * 0.005;
		};
		void rotateUp(float degrees){
			this->_fAngleX += degrees * 0.005;
		};
		mat4 getViewMatrix() const{
			mat4 MVMatrix = translate(mat4(1.f), vec3(0, 0, _fDistance));
			MVMatrix = rotate(MVMatrix, -radians(_fAngleY), vec3(0, 1, 0));
			MVMatrix = rotate(MVMatrix, -radians(_fAngleX), vec3(1, 0, 0));
			return MVMatrix;
		};
};