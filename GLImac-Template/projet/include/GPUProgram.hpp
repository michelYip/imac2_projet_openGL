#ifndef _GPUPROGRAM_
#define _GPUPROGRAM_

#include <glimac/Program.hpp>
#include <string>

/// \class GPUProgram
/// \brief Program with uniform var locations and shaders to render correctly
class GPUProgram{
	public:
		glimac::Program _program; ///< program with the two shaders

		GPUProgram(){}
		/// \param: applicationPath : filePath of the game
		/// \param: vsName, fsName : names of the used shaders
		GPUProgram(const glimac::FilePath &applicationPath, const std::string &vsName, const std::string &fsName):_program(glimac::loadProgram(applicationPath.dirPath() + "shaders/" + vsName, applicationPath.dirPath() + "shaders/" + fsName)){}
};

#endif