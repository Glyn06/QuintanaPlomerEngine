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
//uniform sampler2D ourTexture;
void main()
{
//outColor = texture(ourTexture, textureCoords);
outColor = ourColor;
}
)glsl";
//------------------------------ Shaders ------------------------------
unsigned int VBO;
unsigned int EBO;
unsigned int VAO;
unsigned int ourTexture;
Renderer::Renderer()
{
	
	if(glewInit() != GLEW_OK)
	{
		printf("glew error");
	}

	float* vertex = shape->GetVertexBufferData();
	int* index = shape->GetIndexBufferData();
	int vertexSize = shape->GetBufferSize(0);
	int indexSize = shape->GetBufferSize(1);
	
	Bind(vertex, index, vertexSize, indexSize);
	
	
}


Renderer::~Renderer()
{
}

void Renderer::Bind(GLfloat _vertex[],GLint _index[], int _vertexSize, int _indexSize)
{
	
	//printf("_vertex: %f" + _vertex[0]);
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, _vertexSize, _vertex, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indexSize, _index, GL_STATIC_DRAW);


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
/*
void Renderer::LoadTexture()
{
	glGenTextures(1, &ourTexture);
	glBindTexture(GL_TEXTURE_2D, ourTexture);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);		//LINEAR
	unsigned char *data = shape->GetSprite();
	int width = entity->GetWidth();
	int height = entity->GetHeight();
	if (data)
	{
		printf("loaded texture correctly\n");
		printf("Width: %i \n", width);
		printf("Height: %i \n", height);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf("Failed to load texture \n");
	}

}*/
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
