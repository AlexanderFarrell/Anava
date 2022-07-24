#version 330
in vec3 vp;
in vec3 color;

uniform mat4 mvp;

out vec3 colorOut;

void main() {
    colorOut = color;
    gl_Position = vec4(vp.xyz, 1.0) * mvp;
}