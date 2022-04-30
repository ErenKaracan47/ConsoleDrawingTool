#include "Shape.h"



void Shape::createLine(int _width, int _height, char _char)
{
	for (int rowindex = 0; rowindex < _height; rowindex++)
	{
		shapemap.push_back(std::vector<Pixel>());

		for (int colindex = 0; colindex < _width; colindex++)
		{
			shapemap[rowindex].push_back(Pixel(_char));
		}
	}

	rowcount = _height;
	columncount = _width;
}

void Shape::createTriangle(int _base, char _char, bool _fill, bool _doublespace)
{
	

}

int Shape::getRowCount()
{
	return rowcount;
}

int Shape::getColumnCount()
{
	return columncount;
}
