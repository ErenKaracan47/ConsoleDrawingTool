//#pragma comment(lib, "uuid.lib")
#include <iostream>
#include "Canvas.h"
#include "Windows.h"

void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void disableConsoleInput()
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD handle;
	GetConsoleMode(hInput, &handle);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS);

}

void get_console_size(int* rows, int* cols) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		*cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		*rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
}

void setConsoleToUTF8()
{
	// Set input and output code pages to UTF-8 (code page 65001)
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
}


int main() {
	
	setConsoleToUTF8();
	showConsoleCursor(false);
	int rows, cols;
	get_console_size(&rows, &cols);
	//printf("Rows: %d, Columns: %d\n", rows, cols);
	rows = 50;
	cols = 200;
	int lineheight = (int)(rows / 2);
	Canvas canv(rows, cols);
	canv.fillBounds("E");
	Shape line = Shape();

	while(true)
	{
		//for (int i = 1; i < (cols - 1); i++)
		//{
		//	{
		//		line.createLine(1, (rand() % lineheight), "N401M", i);
		//		//canv.placeShapeonCanvas(line, fmod(i, 48), 1);
		//		canv.placeShapeonCanvas(line, (int)(rows/2), i, VAnchor::Middle, HAnchor::Left);
		//	}
		//}
		//canv.render();
		//Sleep(20);
		//canv.clear(false);

	}

	
}