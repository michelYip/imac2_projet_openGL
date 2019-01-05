#ifndef _CAMERA_
#define _CAMERA_

#include <string>
#include <glimac/glm.hpp>

const float FIRST_ROTATE_SPEED = 400.f;
const float THIRD_ROTATE_SPEED = 40.f;
const float ZOOM_SPEED = 0.5f;


using namespace glm;

/// \class Camera
/// \bried Camera of the View
class Camera{
    public:
        Camera(){}
        ~Camera() = default;
        virtual glm::mat4 getViewMatrix() const = 0;
};

#endif