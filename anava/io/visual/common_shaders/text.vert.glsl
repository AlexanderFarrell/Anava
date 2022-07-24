#version 330
in vec3 vp;
in vec2 uv;

//out vec3 colorOut;
out vec2 uvOut;

uniform mat4 mvp;

void main() {
    uvOut = uv;
    //    colorOut = texture(texture1, uv).rgb;//vec3(uv.xy, 1.0);//texture(texture1, uv).rgb;
    gl_Position = mvp * vec4(vp.xyz, 1.0);
}