#version 300 es

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexTex;

out vec2 vTex;

uniform mat3 uModelMatrix;

void main() {
    vTex = aVertexTex;
    vec2 transformed = (vec3(aVertexPosition, 1) * uModelMatrix).xy;
    gl_Position = vec4(transformed , 0, 1);
}