#pragma once
class Shape
{
private:
	float vertices[9] = { //HARCODEADO PARA TRIANGULO
	   -0.5f, -0.5f, 0.0f,  // V1 (x,y,z) 0
		0.5f, -0.5f, 0.0f,	// V2 (x,y,z) 1
		0.0f,  0.5f, 0.0f	// V2 (x,y,z) 2
	};
public:
	Shape();
	~Shape();
};

