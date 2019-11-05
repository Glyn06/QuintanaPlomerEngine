#include "Shape.h"



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
