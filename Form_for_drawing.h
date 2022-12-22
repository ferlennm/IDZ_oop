#pragma once
using namespace System::Drawing;

ref class Form_for_drawing abstract
{
public:
	int type;
	virtual void draw(Graphics^ g) = 0;
	virtual Form_for_drawing^ find(int x, int y) = 0;
};
