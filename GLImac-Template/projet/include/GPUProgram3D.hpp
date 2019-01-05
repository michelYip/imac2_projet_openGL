#ifndef _GPUPROGRAM3D_
#define _GPUPROGRAM3D_

#include <glimac/Program.hpp>


/// \class GPUProgram3D
/// \bried Contain the uniform var location needed by the Rendering3D
class GPUProgram3D{
	public:
		glimac::Program _program;

		GLint _uMVPMatrix;
		GLint _uMVMatrix;
		GLint _uNormalMatrix;
		GLint _uTexture;

	GPUProgram3D(){};
	GPUProgram3D(const glimac::FilePath &applicationPath, const std::string &vsName, const std::string &fsName):_program(glimac::loadProgram(applicationPath.dirPath() + "shaders/" + vsName, applicationPath.dirPath() + "shaders/" + fsName)){
            _uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
            _uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
            _uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
            _uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
	};

};

#endif