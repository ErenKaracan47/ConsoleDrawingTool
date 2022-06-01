#pragma once

#include <vector>
#include "Pixel.h"

class Shape {
	enum class ShapeType {
		Line,
		Rectangle,
		Triangle,
		Circle
	};




	int rowcount;
	int columncount;

public:

	std::vector<std::vector<Pixel>> shapemap;

	void createLine(int _width, int _height, char _char);

	void createTriangle(int _base, char _char, bool _fill, bool _doublespace);

	int getRowCount();
	int getColumnCount();

};