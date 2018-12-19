#version 300 es
#undef lowp
#undef mediump
#undef highp

precision mediump float;

in vec2 vTextCoord;

out vec3 fFragColor;

uniform sampler2D uText;

void main() {
	fFragColor = texture(uText, vTextCoord).xyz;
}
