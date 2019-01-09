#ifndef _CAMERA_
#define _CAMERA_

#include <string>
#include <glimac/glm.hpp>

const float ZOOM_SPEED = 0.5f;

using namespace glm;

/// \class Camera
/// \bried Camera of the View
class Camera{
	protected:
		bool _locked;
    public:
        Camera():_locked(true){}
        ~Camera() = default;

        void changeLock(){
        	_locked =( _locked != true) ? true : false;
        }

        virtual glm::mat4 getViewMatrix() const = 0;
        virtual void motion(const float &xrel, const float &yrel) = 0;
        virtual void updatePos(const glm::vec3 &position){};
};

#endif