#version 400

layout (location = 0) in vec3 vPos;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;

out vec4 color;
out vec2 uv;

void main()
{
   color = uColor;
   uv = vPos.xy;

   mat4 trans_matrix = mat4 (1.0f, 0.0f, 0.0f, 0.0f, 
							 0.0f, 1.0f, 0.0f, 0.0f,
							 0.0f, 0.0f, 1.0f, 0.0f, 
							 uOffset.x, uOffset.y, uOffset.z, 1.0f);
 
   mat4 scale_matrix = mat4 (uSize, 0.0f, 0.0f, 0.0f,
							 0.0f, uSize, 0.0f, 0.0f,
							 0.0f, 0.0f, uSize, 0.0f,
							 0.0f, 0.0f, 0.0f, 1.0f);

   mat4 transformation = scale_matrix * trans_matrix;
   gl_Position = uVP * transformation * vec4(vPos, 1.0);
}
