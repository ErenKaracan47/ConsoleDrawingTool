#include "Shape.h"



void Shape::createLine(int _width, int _height, char _char)
{
	for (int rowindex = 0; rowindex < _height; rowindex++)
	{
		if (shapemap.size() < _height)
		{
			shapemap.push_back(std::vector<Pixel>());
		}

		for (int colindex = 0; colindex < _width; colindex++)
		{
			if (shapemap[rowindex].size() < _width)
			{
				shapemap[rowindex].push_back(Pixel(_char));
			}
			shapemap[rowindex][colindex] = Pixel(_char);
		}
	}

	rowCount = _height;
	columnCount = _width;
	shapeChar = _char;
}

void Shape::createLine(int _width, int _height, std::string _string, int _stroffset)
{
	if (_height % 2 == 0)
	{
		_height++;
	}

	int strcounter = 0;
	int centerindex = ((_height - 1) / 2);
	for (int rowindex = 0; rowindex < _height; rowindex++)
	{
		if (shapemap.size() < _height)
		{
			shapemap.push_back(std::vector<Pixel>());
		}

		int distance = abs(rowindex - centerindex) % (_string.length());
		int charofstr = (distance + _stroffset) % (_string.length());

		for (int colindex = 0; colindex < _width; colindex++)
		{
			if (shapemap[rowindex].size() < _width)
			{
				//shapemap[rowindex].push_back(Pixel(_string[strcounter % (_string.length() - 1)]));
				shapemap[rowindex].push_back(Pixel(_string[charofstr]));
			}
			//shapemap[rowindex][colindex] = Pixel(_string[strcounter % (_string.length() - 1)]);
			shapemap[rowindex][colindex] = Pixel(_string[charofstr]);
			strcounter++;
		}
	}

	rowCount = _height;
	columnCount = _width;
	shapeString = _string;
}

void Shape::createTriangle(int _base, char _char, bool _fill, bool _doublespace)
{
	

}

int Shape::getRowCount()
{
	return rowCount;
}

int Shape::getColumnCount()
{
	return columnCount;
}

char Shape::getShapeChar()
{
	return shapeChar;
}
