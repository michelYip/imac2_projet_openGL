#version 300 es
#undef lowp
#undef mediump
#undef highp

precision mediump float;

in vec3 vColor;

out vec3 fFragColor;

void main() {
    fFragColor = vColor;
}
