#include "ShaderManager.h"
using namespace Managers;
using namespace std;

std::map<std::string, GLuint> ShaderManager::programs;

ShaderManager::ShaderManager(void) {}

ShaderManager::~ShaderManager(void)
{
	std::map<std::string, GLuint>::iterator it;
	for (it = programs.begin(); it != programs.end(); ++it)
	{
		GLuint pr = it->second;
		glDeleteProgram(pr);
	}
	programs.clear();
}

string ShaderManager::ReadShader(const std::string& filename)
{
	string shaderCode;
	ifstream file(filename.c_str(), std::ios::in);

	if (!file.good()) {
		cout << "Can't read file " << filename.c_str() << endl;
		std::terminate();
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();

	return shaderCode;
}

GLuint ShaderManager::CreateShader(GLenum shaderType, 
	const std::string& source, const 
	std::string& shaderName)
{
	int compile_result = 0;

	GLuint shader = glCreateShader(shaderType);
	const char *shader_code_ptr = source.c_str();
	const int shader_code_size = source.size();

	glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
	glCompileShader(shader);

	// Check for errors
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);
	if (compile_result == GL_FALSE)
	{
		int info_log_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
		vector<char> shader_log(info_log_length);
		glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
		cout << "ERROR compiling shader: " << shaderName.c_str() << std::endl << &shader_log[0] << std::endl;
		return 0;
	}
	return shader;
}

void ShaderManager::CreateProgram(const std::string& shaderName,
	const std::string& vertexShaderFilename,
	const std::string& fragmentShaderFilename)
{
	// Read the shader files and save the code
	string vertex_shader_code = ReadShader(vertexShaderFilename);
	string fragment_shader_code = ReadShader(fragmentShaderFilename);

	GLuint vertex_shader = CreateShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
	GLuint fragment_shader = CreateShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

	int link_result = 0;
	
	// Create the program handle, attatch the shaders and link it
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_result);
	
	// Check for link errors
	if (link_result == GL_FALSE)
	{
		int info_log_length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
		vector<char> program_log(info_log_length);
		glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
		cout << "Shader Loader : LINK ERROR" << endl << &program_log[0] << endl;
	}

	programs[shaderName] = program;
}

const GLuint ShaderManager::GetShader(const std::string& shaderName)
{
	const GLuint shader = programs.at(shaderName);
	if (shader)
	{
		return shader;
	}
	else
	{
		return 0;
	}
}

void Managers::ShaderManager::DeleteShader(const std::string & name)
{
	if (programs.at(name) != 0)
	{
		programs.erase(name);
	}
}
