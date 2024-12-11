#pragma once

#include <vector>
#include <string>
#include "Pixel.h"

class Shape {
	enum class ShapeType {
		Line,
		Rectangle,
		Triangle,
		Circle
	};




	int rowCount;
	int columnCount;
	char shapeChar;
	std::string shapeString;

public:

	std::vector<std::vector<Pixel>> shapemap;

	void createLine(int _width, int _height, char _char);
	void createLine(int _width, int _height, std::string _string, int _stroffset = 0);

	void createTriangle(int _base, char _char, bool _fill, bool _doublespace);

	int getRowCount();
	int getColumnCount();
	char getShapeChar();

};