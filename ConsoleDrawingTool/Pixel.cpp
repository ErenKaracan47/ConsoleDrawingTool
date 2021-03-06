#include"Pixel.h"

Pixel::Pixel(int _row, int _col, Strength _str)
{
	pixelrow = _row;
	pixelcolumn = _col;
	pixelstrength = _str;

	matchPixelChartoStrength();
}

Pixel::Pixel(int _row, int _col, char _char)
{
	pixelrow = _row;
	pixelcolumn = _col;
	pixelstrength = Strength::Custom;
	pixelchar = _char;
}

Pixel::Pixel(char _char)
{
	pixelrow = -1;
	pixelcolumn = -1;
	pixelstrength = Strength::Custom;
	pixelchar = _char;
}

Pixel::~Pixel()
{
}

void Pixel::changePixelStrength(Strength _str)
{
	pixelstrength = _str;
	matchPixelChartoStrength();
}

void Pixel::matchPixelChartoStrength()
{
	switch (pixelstrength)
	{
	case Strength::Blank:
		pixelchar = ' ';
		break;
	case Strength::Weak:
		pixelchar = '.';
		break;
	case Strength::Medium:
		pixelchar = '+';
		break;
	case Strength::Strong:
		pixelchar = 'K';
		break;
	case Strength::Custom:
		break;
	}
}

void Pixel::changePixelChar(char _char)
{
	pixelstrength = Strength::Custom;
	pixelchar = _char;
}
