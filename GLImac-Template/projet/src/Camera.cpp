#include "Camera.hpp"

void Camera::changeCameraType(){
	if(_cameraType == "first") _cameraType = "third";
	else _cameraType = "first";
}

void Camera::cameraMotion(const float &xrel, const float &yrel){
	if(_cameraType == "first"){
		_first.rotateLeft(xrel * FIRST_ROTATE_SPEED);
		_first.rotateUp(yrel * FIRST_ROTATE_SPEED);
	}
	else{
		_third.rotateLeft(xrel * THIRD_ROTATE_SPEED);
		_third.rotateUp(yrel * THIRD_ROTATE_SPEED);
	}
}

void Camera::zoomIn(){
	_third.moveFront(ZOOM_SPEED);
}
void Camera::zoomOut(){
	_third.moveFront(-ZOOM_SPEED);
}