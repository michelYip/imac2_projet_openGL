#version 300 es

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNorm; 
layout(location = 2) in vec2 aVertexTextCoord;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

out vec3 vPosition;
out vec3 vNormal;
out vec2 vTextCoord;

void main() {
	vec4 vertexPosition = vec4(aVertexPosition, 1);
	vec4 vertexNormal = vec4(aVertexNorm, 0);

	vPosition = vec3(uMVMatrix * vertexPosition);
	vNormal = vec3(uNormalMatrix * vertexNormal);
	vTextCoord = aVertexTextCoord;

	gl_Position = uMVPMatrix * vertexPosition;
}