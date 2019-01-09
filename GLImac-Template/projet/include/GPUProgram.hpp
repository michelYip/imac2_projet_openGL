#ifndef _GPUPROGRAM_
#define _GPUPROGRAM_

#include <glimac/Program.hpp>
#include <string>

/// \class GPUProgram
/// \brief associated with shaders 
class GPUProgram{
	public:
		glimac::Program _program;

		GPUProgram(){}
		GPUProgram(const glimac::FilePath &applicationPath, const std::string &vsName, const std::string &fsName):_program(glimac::loadProgram(applicationPath.dirPath() + "shaders/" + vsName, applicationPath.dirPath() + "shaders/" + fsName)){}
};

#endif