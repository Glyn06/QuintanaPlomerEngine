#ifndef SHAPE_H
#define SHAPE_H



class Shape
{
private:
	float VertexSquare[32] = {	//vertex buffer
	 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f,		// Vertex 1 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 0
	 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,		// Vertex 2 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 1
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,	// Vertex 3 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 2
	-0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,	// Vertex 4 (X, Y, COLOR RGBA, TEXTURE COORDS XY) 3
	};
	int squareIndex[6] = {	//index buffer
	0 , 1, 2,		// tirangulo derecho inferior
	2, 3, 0
	};
	int width, height, nrChannels;
public:
	Shape();
	float GetVertexBufferData();
	int GetIndexBufferData();
	//unsigned char* GetSprite();
	int GetWidth();
	int GetHeight();
	~Shape();
};
#endif // !SHAPE_H
