#include "Canvas.h"

Canvas::Canvas(int _rowcount, int _columncount)
	: rowCount(_rowcount), columnCount(_columncount) // Use initializer list
{
	// Reserve space for rows in advance
	pixelmap.reserve(rowCount);
	currentScreen.reserve(rowCount);

	for (int rowindex = 0; rowindex < rowCount; rowindex++)
	{
		// Add empty rows with reserved space for columns
		pixelmap.emplace_back();
		currentScreen.emplace_back();
		pixelmap[rowindex].reserve(columnCount);
		currentScreen[rowindex].reserve(columnCount);

		for (int colindex = 0; colindex < columnCount; colindex++)
		{
			// Initialize each cell
			pixelmap[rowindex].emplace_back(rowindex, colindex, Pixel::Strength::Blank);
			currentScreen[rowindex].emplace_back(' ');
		}
	}
}


Canvas::~Canvas()
{
}

void Canvas::render()
{
	if (!consoleCleared)
	{
		// Clear the entire console once
		printf("\x1b[2J");
		consoleCleared = true;
	}

	// Set up the console screen buffer (buffer to hold the output)
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { columnCount, rowCount };  // Console buffer size (width x height)
	COORD bufferCoord = { 0, 0 };  // Start at top-left corner
	SMALL_RECT writeRegion = { 0, 0, columnCount - 1, rowCount - 1 }; // Region to update

	// Create a buffer to store CHAR_INFO structures (character + attribute)
	std::vector<CHAR_INFO> consoleBuffer(rowCount * columnCount);

	// Build the console output in the buffer
	for (int rowindex = 0; rowindex < rowCount; rowindex++)
	{
		for (int colindex = 0; colindex < columnCount; colindex++)
		{
			// Get the character for this position
			char pixelChar = pixelmap[rowindex][colindex].pixelchar;

			// If it has changed, update the screen buffer
			consoleBuffer[rowindex * columnCount + colindex].Char.AsciiChar = pixelChar;
			consoleBuffer[rowindex * columnCount + colindex].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
		}
	}

	// Write the buffer to the console at once
	WriteConsoleOutput(hConsole, consoleBuffer.data(), bufferSize, bufferCoord, &writeRegion);
}


void Canvas::clear(bool _clearbounds)
{
	if (_clearbounds)
	{
		for (int rowindex = 0; rowindex < rowCount; rowindex++)
		{
			for (int colindex = 0; colindex < columnCount; colindex++)
			{
				pixelmap[rowindex][colindex] = Pixel(rowindex, colindex, Pixel::Strength::Blank);
			}
		}
	}
	else
	{
		for (int rowindex = 1; rowindex < rowCount - 1; rowindex++)
		{
			for (int colindex = 1; colindex < columnCount - 1; colindex++)
			{
				pixelmap[rowindex][colindex] = Pixel(rowindex, colindex, Pixel::Strength::Blank);
			}
		}
	}
	
}


void Canvas::fillBounds(Pixel::Strength _str)
{
	for (int rowindex = 0; rowindex < rowCount; rowindex++)
	{
		pixelmap[rowindex][0].changePixelStrength(_str);
		pixelmap[rowindex][rowCount - 1].changePixelStrength(_str);
	}
	for (int colindex = 0; colindex < columnCount; colindex++)
	{
		pixelmap[0][colindex].changePixelStrength(_str);
		pixelmap[rowCount - 1][colindex].changePixelStrength(_str);
	}
}

void Canvas::fillBounds(std::string _string)
{
	for (int rowindex = 0; rowindex < rowCount; rowindex++)
	{
		pixelmap[rowindex][0].changePixelChar(_string[rowindex % _string.length()]);
		pixelmap[rowindex][columnCount - 1].changePixelChar(_string[rowindex % _string.length()]);
	}
	for (int colindex = 0; colindex < columnCount; colindex++)
	{
		pixelmap[0][colindex].changePixelChar(_string[colindex % _string.length()]);
		pixelmap[rowCount - 1][colindex].changePixelChar(_string[colindex % _string.length()]);
	}
}

void Canvas::placeShapeonCanvas(Shape& _shape, int _rowoffset, int _coloffset, VAnchor _vanchor, HAnchor _hanchor)
{
	checkAlignment(_shape, _vanchor, _hanchor);
	int shaperowcount = _shape.getRowCount();
	int shapecolcount = _shape.getColumnCount();

	for (int rowindex = 0; rowindex < shaperowcount; rowindex++)
	{
		for (int colindex = 0; colindex < shapecolcount; colindex++)
		{
			switch (_vanchor)
			{
			case Top:
				switch (_hanchor)
				{
				case Left:
					break;
				case Center:
					break;
				case Right:
					break;
				default:
					break;
				}
				break;
			case Middle:
				switch (_hanchor)
				{
				case Left:
					pixelmap[_rowoffset - (int)(shaperowcount / 2) + rowindex][colindex + _coloffset].changePixelChar(_shape.shapemap[rowindex][colindex].pixelchar);
					break;
				case Center:
					break;
				case Right:
					break;
				default:
					break;
				}
				break;
			case Bottom:
				break;
			default:
				break;
			}
			//pixelmap[rowindex + _rowoffset][colindex + _coloffset].changePixelChar(_shape.shapemap[rowindex][colindex].pixelchar);
		}
	}
}

void Canvas::checkAlignment(Shape& _shape, VAnchor _vanchor, HAnchor _hanchor)
{
	bool resizev = false;
	bool resizeh = false;
	int rowcount = _shape.getRowCount();
	int colcount = _shape.getColumnCount();

	if (_vanchor == VAnchor::Middle)
	{
		if (rowcount % 2 == 0)
		{
			resizev = true;
		}
	}
	if (_hanchor == HAnchor::Center)
	{
		if (colcount % 2 == 0)
		{
			resizeh = true;
		}
	}

	if (resizev || resizeh)
	{
		int newColCount = resizeh ? (colcount + 1) : colcount;
		int newRowCount = resizev ? (rowcount + 1) : rowcount;
		_shape.createLine(newColCount, newRowCount, _shape.getShapeChar());
	}
}
