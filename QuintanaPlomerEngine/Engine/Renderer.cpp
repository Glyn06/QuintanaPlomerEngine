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
unsigned int VBO;
unsigned int EBO;
unsigned int VAO;

Renderer::Renderer()
{
	glewInit;
	float* aux = shape->GetVertexBufferData();
	int* aux2 = shape->GetIndexBufferData();
	Bind(aux, aux2, sizeof(aux));
	
}


Renderer::~Renderer()
{
}

void Renderer::Bind(float _vertex[],int _index[], int _arraySize)
{
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex), _vertex, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_index), _index, GL_STATIC_DRAW);


	LoadShaders(_vertex);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(posAttrib);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "triangleColor");
	glVertexAttribPointer(colAttrib, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(colAttrib);

	GLint texAttrib = glGetAttribLocation(shaderProgram, "textCoord");
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(texAttrib);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

}

void Renderer::LoadShaders(float _vertex[])
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);								//linkean el "programa"
	glUseProgram(shaderProgram);
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
