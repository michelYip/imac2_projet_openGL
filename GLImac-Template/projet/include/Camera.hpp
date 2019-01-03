#ifndef _CAMERA_
#define _CAMERA_

#include <string>

#include "FreeflyCamera.hpp"
#include "TrackballCamera.hpp"

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
        void cameraMotion(const glm::vec2 &lastPos, const glm::vec2 &pos);
};

#endif