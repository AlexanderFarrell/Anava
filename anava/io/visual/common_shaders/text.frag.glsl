#version 330

in vec3 colorOut;
in vec2 uvOut;

out vec4 frag_color;
uniform sampler2D texture1;

void main() {

    frag_color = vec4(1.0, 1.0, 1.0, texture(texture1, uvOut).r);//vec4(colorOut.xyz,1.0);
}