#include <iostream>
#include "Canvas.h"
#include "Windows.h"

int main() {



	Canvas canv(50, 50);
	canv.fillBounds('E');
	Shape line = Shape();
	line.createLine(50, 2, '#');

	for (int i = 0; i < 48; i++)
	{
		printf("\x1b[0;0H");
		canv.placeShapeonCanvas(line, i, 0);
		canv.Render();
		Sleep(16);
	}

	
}