#include "Canvas.h"

Canvas::Canvas(int _rowcount, int _columncount)
{
	rowcount = _rowcount;
	columncount = _columncount;

	for (int colindex = 0; colindex < columncount; colindex++)
	{
		pixelmap.push_back(std::vector<Pixel>());

		for (int rowindex = 0; rowindex < rowcount; rowindex++)
		{
			pixelmap[colindex].push_back(Pixel(rowindex + 1, colindex + 1, Pixel::Strength::Blank));
		}
	}
}

Canvas::~Canvas()
{
}

void Canvas::Render()
{
	for (int colindex = 0; colindex < columncount; colindex++)
	{
		for (int rowindex = 0; rowindex < rowcount; rowindex++)
		{
			std::cout << pixelmap[colindex][rowindex].pixelchar;
		}

		std::cout << "\n";
	}
}

void Canvas::fillBounds(Pixel::Strength _str)
{
	for (int rowindex = 0; rowindex < rowcount; rowindex++)
	{
		pixelmap[0][rowindex].changePixelStrength(_str);
		pixelmap[rowcount - 1][rowindex].changePixelStrength(_str);
	}

	for (int columnindex = 0; columnindex < columncount; columnindex++)
	{
		pixelmap[columnindex][0].changePixelStrength(_str);
		pixelmap[columnindex][rowcount - 1].changePixelStrength(_str);
	}
}

void Canvas::fillBounds(char _char)
{
	for (int rowindex = 0; rowindex < rowcount; rowindex++)
	{
		pixelmap[0][rowindex].changePixelChar(_char);
		pixelmap[rowcount - 1][rowindex].changePixelChar(_char);
	}

	for (int columnindex = 0; columnindex < columncount; columnindex++)
	{
		pixelmap[columnindex][0].changePixelChar(_char);
		pixelmap[columnindex][rowcount - 1].changePixelChar(_char);
	}
}
