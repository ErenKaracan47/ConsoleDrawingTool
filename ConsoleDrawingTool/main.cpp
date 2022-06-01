#include <iostream>
#include "Canvas.h"
#include "Windows.h"

int main() {



	Canvas canv(50, 50);
	canv.fillBounds('E');
	Shape line = Shape();
	line.createLine(8, 1, '#');

	for (int i = 1; i < 48; i++)
	{
		
		//canv.placeShapeonCanvas(line, fmod(i, 48), 1);
		canv.placeShapeonCanvas(line, ((rand() % 40) + 2), 1);

		canv.Render();
		//Sleep(0);
	}

	
}