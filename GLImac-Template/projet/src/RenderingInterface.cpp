#include "RenderingInterface.hpp"

RenderingInterface::RenderingInterface(const char &type){
	switch(type){
		case 's':
			_elements.push_back(Button("title"));
			break;
		default:
			break;
	}
}

void RenderingInterface::initialize(){
	// glGenBuffers(1, &this->_vbo);
	// glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	// Vertex2DColor vertices[] = {
	// 	Vertex2DColor(glm::vec2(-0.5, -0.5), glm::vec3(1, 0, 0)),
 //        Vertex2DColor(glm::vec2(0.5, -0.5), glm::vec3(0, 1, 0)), 
 //        Vertex2DColor(glm::vec2(0.5, 0.5), glm::vec3(0, 0, 1)), 
 //        Vertex2DColor(glm::vec2(-0.5, 0.5), glm::vec3(1, 1, 1)) 
 //    };
 //    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);
 //    glBindBuffer(GL_ARRAY_BUFFER, 0);

 //    glGenBuffers(1, &this->_ibo);
 //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ibo);
 //    uint32_t indexes[] = { 0, 1, 2, 0, 2, 3};
 //    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indexes, GL_STATIC_DRAW);
 //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

 //    glGenVertexArrays(1, &this->_vao);
 //    glBindVertexArray(this->_vao);
 //    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ibo);

 //    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
 //    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
 //    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
 // 	glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 
 //        sizeof(Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, _position));
 // 	glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 
 //        sizeof(Vertex2DColor), (const GLvoid*) offsetof(Vertex2DColor, _color));
 //    glBindBuffer(GL_ARRAY_BUFFER, 0);

 //    glBindVertexArray(0);
}

void RenderingInterface::show(){
	glBindVertexArray(this->_vao);
	// for(int i = 0; i < _elements.size(); i++){
	// glBindTexture(GL_TEXTURE_2D, _elements[i].getTexture());
	// }
	// glUniform1i(uTex, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void RenderingInterface::end(){
	glDeleteBuffers(1, &this->_vbo);
	glDeleteVertexArrays(1, &this->_vao);
}