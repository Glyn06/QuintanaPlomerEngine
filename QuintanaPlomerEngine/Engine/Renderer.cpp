#include "Renderer.h"


//------------------------------ Shaders ------------------------------
/*
const char* vertexSource = R"glsl(
    #version 330 core
out vec4 ourColor;
out vec2 textureCoords;
in vec4 triangleColor;
in vec2 textCoord;
in vec2 position;
uniform mat4 translate;
uniform mat4 rotate;
uniform mat4 scale;
uniform mat4 view;
uniform mat4 proj;
    void main()
    {
        gl_Position = proj*view* translate*rotate*scale* vec4(position, 0.0, 1.0);
		textureCoords = textCoord;		
		ourColor = triangleColor;
    }
)glsl";
const char* fragmentSource = R"glsl(
   #version 330 core
out vec4 outColor;
in vec4 ourColor;
in vec2 textureCoords;
uniform sampler2D ourTexture;
void main()
{
outColor = texture(ourTexture, textureCoords);
//outColor = ourColor;
}
)glsl";*/

const char* vertexSource = R"glsl(
    #version 330 core
out vec4 ourColor;
out vec2 textureCoords;
in vec4 triangleColor;
in vec2 textCoord;
in vec2 position;
    void main()
    {
		gl_Position =  vec4(position, 0.0, 1.0);
		textureCoords = textCoord;		
		ourColor = triangleColor;
    }
)glsl";

const char* fragmentSource = R"glsl(
   #version 330 core
out vec4 outColor;
in vec4 ourColor;
in vec2 textureCoords;
uniform sampler2D ourTexture;
void main()
{
outColor = texture(ourTexture, textureCoords);
//outColor = ourColor;
}
)glsl";
//------------------------------ Shaders ------------------------------


Renderer::Renderer()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


}


Renderer::~Renderer()
{
}





Window* Renderer::CreateWindow(int width, int height, const char *title)
{
	Window* w = new Window(width,height,title);
	return w;
}

void Renderer::SwapBuffers(Window* window)
{
	glfwSwapBuffers(window->GetWindow());
}

void Renderer::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Renderer::ClearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
}
