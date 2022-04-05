#pragma once


class Pixel {

public:

	enum class Strength {
		Blank,
		Weak,
		Medium,
		Strong,
		Custom
	};

	Pixel(int _row, int _col, Strength _str);
	Pixel(int _row, int _col, char _char);
	Pixel(char _char);
	~Pixel();

	void changePixelStrength(Strength _str);
	void matchPixelChartoStrength();

	void changePixelChar(char _char);

	Strength pixelstrength = Strength::Blank;
	char pixelchar = ' ';

	int pixelrow, pixelcolumn;
};