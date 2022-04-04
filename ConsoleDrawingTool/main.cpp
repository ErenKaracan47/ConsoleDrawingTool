#include <iostream>
#include "Canvas.h"

int main() {


	/*std::cout <<"\n"
		<< "	NNNN       NNN           444           00000000           1111          MMMM      MMMM\n"
		<< "	NNNNN      NNN          4444          0000  0000         11111          MMMMM    MMMMM\n"
		<< "	NNNNNN     NNN         44444         0000    0000       111111          MMMMMM  MMMMMM\n"
		<< "	NNN NNN    NNN        444444        0000      0000     111 111          MMM MMMMMM MMM\n"
		<< "	NNN  NNN   NNN       444 444        000        000         111          MMM  MMMM  MMM\n"
		<< "	NNN   NNN  NNN      444  444        000        000         111          MMM   MM   MMM\n"
		<< "	NNN    NNN NNN     444   444        0000      0000         111          MMM        MMM\n"
		<< "	NNN     NNNNNN    44444444444444     0000    0000          111          MMM        MMM\n"
		<< "	NNN      NNNNN    44444444444444      0000  0000           111          MMM        MMM\n"
		<< "	NNN       NNNN           444           00000000       11111111111111    MMM        MMM\n"
		<< "\n";*/

	Canvas canv(20, 20);
	canv.fillBounds(Pixel::Strength::Strong);
	canv.Render();
}