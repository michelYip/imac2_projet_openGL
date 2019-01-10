#ifndef _CAMERA_
#define _CAMERA_

#include <string>
#include <glimac/glm.hpp>

const float ZOOM_SPEED = 0.5f;

/// \class Camera
/// \brief Camera of the View
class Camera{
	protected:
		bool _locked; ///< returns if the camera is locked or not
    public:
        Camera():_locked(true){}
        ~Camera() = default;
        /// \brief change locked state
        void changeLock(){
        	_locked =( _locked != true) ? true : false;
        }
        /// \brief returns view matrix of camera view
        virtual glm::mat4 getViewMatrix() const = 0;
        /// \brief makes the camera move 
        virtual void motion(const float &xrel, const float &yrel) = 0;
        /// \brief update Camera position
        virtual void updatePos(const glm::vec3 &position){};
};
#endif