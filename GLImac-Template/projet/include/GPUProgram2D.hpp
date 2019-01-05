#ifndef _GPUPROGRAM2D_
#define _GPUPROGRAM2D_

#include <glimac/Program.hpp>

/// \class GPUProgram2D
/// \bried Contain the uniform var location needed by the RenderingInterface
class GPUProgram2D{
	public:
		glimac::Program _program;
	
		GLint _uModelMatrix;
		GLint _uColor;
		GLint _uTexture;

		GPUProgram2D(){};
		GPUProgram2D(const glimac::FilePath &applicationPath, const std::string &vsName, const std::string &fsName):_program(glimac::loadProgram(applicationPath.dirPath() + "shaders/" + vsName, applicationPath.dirPath() + "shaders/" + fsName)){
			_uModelMatrix = glGetUniformLocation(_program.getGLId(), "uModelMatrix");
			_uColor = glGetUniformLocation(_program.getGLId(), "uColor");
			_uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
		};
		// GPUProgram2D(const GPUProgram2D &program){
		// 	_program = program._program;
		// 	_uModelMatrix = program._uModelMatrix;
		// 	_uColor = program._uColor;
		// 	_uTexture = program._uTexture;
		// }

		// GPUProgram2D &operator=(const GPUProgram2D &program){
		// 	if (this != &program){
		// 		_program = program._program;
		// 		_uModelMatrix = program._uModelMatrix;
		// 		_uColor = program._uColor;
		// 		_uTexture = program._uTexture;				
		// 	}
		// };
};

#endif