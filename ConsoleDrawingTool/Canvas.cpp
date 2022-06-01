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
			pixelmap[colindex].push_back(Pixel(rowindex, colindex, Pixel::Strength::Blank));
		}
	}
}

Canvas::~Canvas()
{
}

void Canvas::Render()
{

	printf("\x1b[0;0H");

	for (int rowindex = 0; rowindex < rowcount; rowindex++)
	{
		for (int colindex = 0; colindex < columncount; colindex++)
		{
			putchar(pixelmap[rowindex][colindex].pixelchar);
		}

		printf("\x1B[1B\x1B[0G"); //TODO: renderdan önce setup kýsmýnda canvas kadar whitespace olsun. var olmayan space'de cursor down yapamýyoruz.

		//putchar('\n');

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

void Canvas::placeShapeonCanvas(Shape _shape, int _rowoffset, int _coloffset)
{
	for (int rowindex = 0; rowindex < _shape.getRowCount(); rowindex++)
	{
		for (int colindex = 0; colindex < _shape.getColumnCount(); colindex++)
		{
			pixelmap[rowindex + _rowoffset][colindex + _coloffset].changePixelChar(_shape.shapemap[rowindex][colindex].pixelchar);
		}
	}
}
