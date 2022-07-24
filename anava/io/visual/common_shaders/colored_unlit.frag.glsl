#version 330

in vec3 colorOut;

out vec4 frag_color;

void main() {
    frag_color = vec4(colorOut.xyz,1.0);//vec4(1,0,1,1);//vec4(colorOut.xyz,1);
}