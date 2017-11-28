#pragma once
#include "stdafx.h"
#include "Cards.h"


class Opencv: public Cards
{
private:
	std::string cor;

public:
	std::string getCor();
	void setCor(std::string cor);
	void pegaCor(int r, int g, int b, int p, int w, int y);
	int verifica();

	Opencv();
	~Opencv();

};

