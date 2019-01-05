#ifndef _LIGHT_
#define _LIGHT_

#include "GPUProgram.hpp"

/// \ class Light
/// \ brief set the light of the scene or an object
class Light{
	private:
		GLuint _uKd;
		GLuint _uKs;
		GLuint _uShininess;
		GLuint _uLightPos;
		GLuint _uLightIntensity;
	public:
		Light(){}
		Light(const glimac::Program &program):
		_uKd(glGetUniformLocation(program.getGLId(), "uKd")),
		_uKs(glGetUniformLocation(program.getGLId(), "uKs")),
		_uShininess(glGetUniformLocation(program.getGLId(), "uShininess")),
		_uLightPos(glGetUniformLocation(program.getGLId(), "uLightPos_vs")),
		_uLightIntensity(glGetUniformLocation(program.getGLId(), "uLightIntensity"))
		{}
		~Light(){}

		/// \ set the materials parameters 
		void setMaterials(
			const glm::vec3 &Kd,
			const glm::vec3 &Ks,
			const float shininess)
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