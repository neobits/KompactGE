#pragma once

#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

namespace Managers
{
	class ShaderManager
	{
	public:
		ShaderManager(void);
		~ShaderManager(void);

		/* Extracts the shader contents by creating both shaders,
		loading them into the program. */
		void CreateProgram(const std::string& shaderName,
			const std::string& VertexShaderFilename,
			const std::string& FragmentShaderFilename);
	
		static const GLuint GetShader(const std::string& name);
		void DeleteShader(const std::string& name);

	private:
		/* Reads and returns the contents of a file. */
		std::string ReadShader(const std::string& filename);
		/* Creates and copiles a shader. */
		GLuint CreateShader(GLenum shaderType,
			const std::string& source,
			const std::string& shaderName);

		static std::map<std::string, GLuint> programs;
	};
}