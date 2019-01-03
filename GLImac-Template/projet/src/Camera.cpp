#include "Camera.hpp"

void Camera::changeCameraType(){
	if(_cameraType == "first") _cameraType = "third";
	else _cameraType = "first";
}

void Camera::cameraMotion(const glm::vec2 &lastPos, const glm::vec2 &pos){
	if(_cameraType == "first"){
		_first.rotateLeft(pos.x - lastPos.x);
		_first.rotateUp(pos.y - lastPos.y);
	}
	else{
		_third.rotateLeft(pos.x - lastPos.x);
		_third.rotateUp(pos.y - lastPos.y);
	}
}