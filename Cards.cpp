#include "stdafx.h"
#include "Cards.h"


std::string Cards::getColor()
{
	return this->color;
}

void Cards::setColor()
{
	srand(time(NULL));
	int x = rand()  % 6 ;

	switch (x) {
	case 0:
		this->color = "White";
		break;
	case 1:
		this->color = "Black";
		break;
	case 2:
		this->color = "Red";
		break;
	case 3:
		this->color = "Yellow";
		break;
	case 4:
		this->color = "Blue";
		break;
	case 5:
		this->color = "Green";
		break;
	default:
			break;
	}
	
}

Cards::Cards()
{
	this->setColor();
}

Cards::~Cards()
{
}
