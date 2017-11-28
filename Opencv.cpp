#include "stdafx.h"
#include "Opencv.h"

string Opencv::getCor()
{
	return cor;
}

void Opencv::setCor(std::string cor)
{
	this->cor = cor;
}

void Opencv::pegaCor(int r, int g, int b, int p, int w, int y)
{
	if (r > g && r > b && r > p && r > w && r > y) {
		this->setCor("RED");
	}
	if (g > r && g > b && g > p && g > w && g > y) {
		this->setCor("GREEN");
	}
	if (b > r && b > g && b > p && b > w && b > y) {
		this->setCor("BLUE");
	}
	if (p > r && p > g && p > b && p > w && p > y) {
		this->setCor("BLACK");
	}
	if (w > r && w > g && w > b && w > p && w > y) {
		this->setCor("WHITE");
	}
	if (y > r && y > g && y > b && y > w && y > p) {
		this->setCor("YELLOW");
	}
}

int Opencv::verifica()
{
	if (this->getColor() == this->getCor()) {
		return 1;
	}
	else {
		return 0;
	}
}

Opencv::Opencv()
{
}

Opencv::~Opencv()
{
}
