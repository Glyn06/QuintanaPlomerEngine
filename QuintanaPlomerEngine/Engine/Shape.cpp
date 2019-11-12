#include "Shape.h"

float VertexSquare[] = {	//vertex buffer
	 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,		// Vertex 1 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 0
	 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// Vertex 2 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 1
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,	// Vertex 3 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 2
	-0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,	// Vertex 4 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 3
};
int IndexSquare[] = {	//index buffer
0 , 1, 2,		// tirangulo derecho inferior
2, 3, 0
};

Shape::Shape()
{
	width = 16;
	height = 16;
}
float* Shape::GetVertexBufferData() 
{ 
	return VertexSquare;
}
int* Shape::GetIndexBufferData()
{
	return IndexSquare;
}
int Shape::GetBufferSize(int i)
{
	switch (i)
	{
	case 0:
		return 32;
		break;
	case 1:
		return 6;
		break;
	}
	return 0;
}
int Shape::GetWidth()
{
	return width;
}
int Shape::GetHeight()
{
	return height;
}

Shape::~Shape()
{
}
