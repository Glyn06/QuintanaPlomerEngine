#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;
class Shape
{
private:
	
	int width, height, nrChannels;
public:

	//we need the code i have, that works, but we also need animation
	Shape();
	float* GetVertexBufferData();
	int* GetIndexBufferData();
	int GetBufferSize(int i);
	
	//unsigned char* GetSprite();
	int GetWidth();
	int GetHeight();
	~Shape();
};
#endif // !SHAPE_H
