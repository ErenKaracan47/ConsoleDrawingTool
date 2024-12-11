#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Windows.h"
#include "Pixel.h"
#include "Shape.h"

enum VAnchor
{
	Top,
	Middle,
	Bottom
};

enum HAnchor
{
	Left,
	Center,
	Right
};

class Canvas
{
public:
	Canvas(int _rowcount, int _columncount);
	~Canvas();

	void render();
	void clear(bool _clearbounds = false);

	void fillBounds(Pixel::Strength _str);
	void fillBounds(std::string _string);

	void placeShapeonCanvas(Shape& _shape, int _rowoffset, int _coloffset, VAnchor _vanchor = VAnchor::Middle, HAnchor _hanchor = HAnchor::Center);
	void checkAlignment(Shape& _shape, VAnchor _vanchor, HAnchor _hanchor);
private:

	std::vector<std::vector<char>> currentScreen;

	bool consoleCleared = false;
	int rowCount, columnCount;

	std::vector<std::vector<Pixel>> pixelmap;

};

