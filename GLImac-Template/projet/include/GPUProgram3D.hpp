#ifndef _GPUPROGRAM3D_
#define _GPUPROGRAM3D_

#include <glimac/Program.hpp>

class GPUProgram3D{
	public:
		glimac::Program _program;
		GLint _uMVPMatrix;
		GLint _uMVMatrix;
		GLint _uNormalMatrix;
		GLint _uTexture;
	GPUProgram3D(const glimac::FilePath &applicationPath):_program(glimac::loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/tex3D.fs.glsl")){
            _uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
            _uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
            _uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
            _uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
	};
};

#endif