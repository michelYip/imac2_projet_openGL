#ifndef _CAMERA_
#define _CAMERA_

#include <string>

#include "FreeflyCamera.hpp"
#include "TrackballCamera.hpp"

const float FIRST_ROTATE_SPEED = 400.f;
const float THIRD_ROTATE_SPEED = 40.f;
const float ZOOM_SPEED = 0.5f;


/// \class Camera
/// \bried Camera of the View
class Camera{
    private:
        std::string _cameraType;
        FreeflyCamera _first;
        TrackballCamera _third;
    public:
        Camera():_cameraType("third"){}
        ~Camera(){}

        inline std::string cameraType() const{
            return _cameraType;
        }
        inline FreeflyCamera firstPCamera() const{
            return _first;
        }
        inline TrackballCamera thirdPCamera() const{
            return _third;
        }
        inline glm::mat4 getCurrentViewMatrix() const{
            if(_cameraType == "first") return _first.getViewMatrix();
            else return _third.getViewMatrix();
        }

        void changeCameraType();
        void cameraMotion(const float &xrel, const float &yrel);
        void zoomIn();
        void zoomOut();
};

#endif