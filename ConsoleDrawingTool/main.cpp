#include <iostream>
#include "Canvas.h"

int main() {



	Canvas canv(50, 50);
	canv.fillBounds('E');
	Shape line = Shape();
	line.createLine(50, 2, '#');
	canv.placeShapeonCanvas(line, 25, 0);
	canv.Render();
}