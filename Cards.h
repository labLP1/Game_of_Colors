#pragma once
class Cards
{
private:
	string color;

public:
	std::string getColor();
	void setColor();
	virtual int verifica() = 0;
	virtual void pegaCor(int r, int g, int b, int p, int w, int y) = 0;
	Cards();
	~Cards();
};

