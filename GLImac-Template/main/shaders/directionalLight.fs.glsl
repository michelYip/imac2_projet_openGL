#version 300 es
#undef lowp
#undef mediump
#undef highp

precision mediump float;

in vec2 vTextCoord;
in vec3 vPosition;
in vec3 vNormal;

out vec3 fFragColor;

uniform sampler2D uText;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;

vec3 blinnPhong(){
	vec3 wi = normalize(uLightPos_vs);
	vec3 Li = normalize(uLightIntensity);
	vec3 w0 = normalize(-vPosition);
	vec3 halfVector = w0 + wi;
	halfVector *= 0.5;
	vec3 Kd = normalize(uKd);
	vec3 Ks = normalize(uKs);
	vec3 N = normalize(vNormal);

	return Li * (Kd * dot(wi, N) + Ks * pow(dot(halfVector, N), uShininess));
}

void main() {
	fFragColor = (vec3(0.5, 0.5, 0.5) + blinnPhong()) * texture(uText, vTextCoord).xyz;
}
