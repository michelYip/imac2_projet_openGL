#version 300 es
#undef lowp
#undef mediump
#undef highp

precision mediump float;

in vec2 vTex;

out vec4 fFragColor;

uniform vec3 uColor;
uniform sampler2D uTexture;

void main() {
	fFragColor = texture(uTexture, vTex);
}