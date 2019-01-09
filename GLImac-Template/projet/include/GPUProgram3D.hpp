#ifndef _GPUPROGRAM3D_
#define _GPUPROGRAM3D_

#include "GPUProgram.hpp"

/// \class GPUProgram3D
/// \bried Contain the uniform var location needed by the Rendering3D
class GPUProgram3D: public GPUProgram{
	public:
		GLint _uMVPMatrix;
		GLint _uMVMatrix;
		GLint _uNormalMatrix;
		GLint _uTexture;

		GPUProgram3D(){}
		GPUProgram3D(const glimac::FilePath &applicationPath, const std::string &vsName, const std::string &fsName):GPUProgram(applicationPath, vsName, fsName){
	            _uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
	            _uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
	            _uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
	            _uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
		}
};

#endif