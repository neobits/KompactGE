#include "Triangle.h"
using namespace Rendering;
using namespace Models;

Triangle::Triangle() {}
Triangle::~Triangle() {}

void Triangle::Create()
{
	unsigned int vao; // Vertex Array Object handler
	unsigned int vbo; // Vertex Buffer Object handler

	glGenVertexArrays(1, &vao); // Create VAO contaier and get its ID
	glBindVertexArray(vao); // Bind to OpenGL context

	std::vector<VertexFormat> vertices; // vertex positions
	vertices.push_back(VertexFormat(glm::vec3(0.25f, -0.25f, 0.0f),
		glm::vec4(1, 0, 0, 1))); //red
	vertices.push_back(VertexFormat(glm::vec3(-0.25f, -0.25f, 0.0f),
		glm::vec4(0, 1, 0, 1))); //green
	vertices.push_back(VertexFormat(glm::vec3(0.25f, 0.25f, 0.0f),
		glm::vec4(0, 0, 1, 1))); //blue

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 3, &vertices[0], GL_STATIC_DRAW);
	// Buffer is binded to context, set pipes ;)
	// 0 : POSITION
	glEnableVertexAttribArray(0);
	// Tells OpenGL about our data format
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	// 1 : COLOUR
	glEnableVertexAttribArray(1);
	// Tells OpenGL about our data format
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 
						  (void*)(offsetof(VertexFormat, VertexFormat::color)));

	// Here we assign the values
	this->VAO = vao;
	this->VBOs.push_back(vbo);
}

void Triangle::Update(){}

void Triangle::Draw()
{
	glUseProgram(program);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}