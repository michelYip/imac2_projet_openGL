#ifndef _CAMERA_
#define _CAMERA_

#include <string>
#include "TrackballCamera.hpp"
#include "FreeflyCamera.hpp"

class Camera
{
    private:
        std::string _cameraType;
        TrackballCamera _thirdCamera;
        FreeflyCamera _firstCamera;
    public:
        //CONSTRUCTORS & DESTRUCTORS
        //Default constructor
        Camera()
        :_cameraType("first"),
        _thirdCamera(),
        _firstCamera()
        {}

        //Default destructor
        ~Camera() = default;

		void firstPersonCameraMotion();
		void thirdPersonCameraMotion();
};

#endif