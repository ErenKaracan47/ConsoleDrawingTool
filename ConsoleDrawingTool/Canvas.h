#pragma once

#include <iostream>
#include <vector>
#include "Pixel.h"

class Canvas
{
public:
	Canvas(int _rowcount, int _columncount);
	~Canvas();

	void Render();

	void fillBounds(Pixel::Strength _str);
	void fillBounds(char _char);

private:

	int rowcount, columncount;

	std::vector<std::vector<Pixel>> pixelmap;

};

