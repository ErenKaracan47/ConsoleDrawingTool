#pragma once

#include <iostream>
#include <vector>
#include "Pixel.h"
#include "Shape.h"

class Canvas
{
public:
	Canvas(int _rowcount, int _columncount);
	~Canvas();

	void Render();

	void fillBounds(Pixel::Strength _str);
	void fillBounds(char _char);

	void placeShapeonCanvas(Shape _shape, int _rowoffset, int _coloffset);

private:

	int rowcount, columncount;

	std::vector<std::vector<Pixel>> pixelmap;

};

