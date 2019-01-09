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

		GLuint _uKd;
		GLuint _uKs;
		GLuint _uShininess;
		GLuint _uLightPos;
		GLuint _uLightIntensity;

		GPUProgram3D(){}
		GPUProgram3D(const glimac::FilePath &applicationPath, const std::string &vsName, const std::string &fsName):GPUProgram(applicationPath, vsName, fsName),
			_uKd(glGetUniformLocation(_program.getGLId(), "uKd")),
			_uKs(glGetUniformLocation(_program.getGLId(), "uKs")),
			_uShininess(glGetUniformLocation(_program.getGLId(), "uShininess")),
			_uLightPos(glGetUniformLocation(_program.getGLId(), "uLightPos_vs")),
			_uLightIntensity(glGetUniformLocation(_program.getGLId(), "uLightIntensity")){
	            _uMVPMatrix = glGetUniformLocation(_program.getGLId(), "uMVPMatrix");
	            _uMVMatrix = glGetUniformLocation(_program.getGLId(), "uMVMatrix");
	            _uNormalMatrix = glGetUniformLocation(_program.getGLId(), "uNormalMatrix");
	            _uTexture = glGetUniformLocation(_program.getGLId(), "uTexture");
		}

		/// \ set the materials parameters 
		void setMaterials(
			const glm::vec3 &Kd,
			const glm::vec3 &Ks,
			const float &shininess)
		{
			glUniform3f(_uKd, Kd.x, Kd.y, Kd.z);
	        glUniform3f(_uKs, Ks.x, Ks.y, Ks.z);
	        glUniform1f(_uShininess, shininess);
		}
		/// \ set the light
		void setLight(const glm::vec4 &lightPos, const glm::vec3 &lightInt){
			glUniform3f(_uLightPos, lightPos.x, lightPos.y, lightPos.z);
			glUniform3f(_uLightIntensity, lightInt.x, lightInt.y, lightInt.z);
		}
};

#endif