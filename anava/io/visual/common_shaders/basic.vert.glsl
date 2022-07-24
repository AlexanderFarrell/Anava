#version 330
in vec3 vp;

uniform mat4 mvp;

void main() {
    gl_Position = mvp * vec4(vp.xyz, 1.0);
}