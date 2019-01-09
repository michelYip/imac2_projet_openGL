#ifndef _CAMERA_
#define _CAMERA_

#include <string>
#include <glimac/glm.hpp>


using namespace glm;

/// \class Camera
/// \brief Camera of the View
class Camera{
    protected:
        const float ZOOM_SPEED = 0.5f;
		bool _locked;
    public:
        Camera():_locked(true){}
        ~Camera() = default;

        void changeLock(){
        	_locked =( _locked != true) ? true : false;
        }

        virtual glm::mat4 getViewMatrix() const = 0;
        virtual void motion(const float &xrel, const float &yrel) = 0;

        virtual void zoomIn(){};
        virtual void zoomOut(){};
};

#endif