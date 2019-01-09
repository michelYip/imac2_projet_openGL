#version 300 es
#undef lowp
#undef mediump
#undef highp

precision mediump float;

in vec3 vPosition;
in vec3 vNormal;

out vec3 fFragColor;

void main() {
    fFragColor = normalize(vNormal);
}
