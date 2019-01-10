#ifndef _GPUPROGRAM2D_
#define _GPUPROGRAM2D_

#include "GPUProgram.hpp"

/// \class GPUProgram2D
/// \bried Contain the uniform var location needed by the RenderingInterface
class GPUProgram2D: public GPUProgram{
	public:	
		GLint _uModelMatrix; ///< location of the uniform var of the model matrix
		GLint _uColor; ///< location of the uniform var of the color
		GLint _uTexture; ///< location of the uniform var of the texture

		GPUProgram2D(){}
		/// \param: applicationPath : filePath of the game
		/// \param: vsName, fsName : names of the used shaders
		GPUProgram2D(const glimac::FilePath &applicationPath, const std::string &vsName, const std::string &fsName):GPUProgram(applicationPath, vsName, fsName){
			_uModelMatrix = glGetUniformLocation(_program.getGLId(), "uModelMatrix");
			_uColor = glGetUniformLocation(_program.getGLId(), "uColor");
			_uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
		}
};

#endif