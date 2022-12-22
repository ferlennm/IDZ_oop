#include "Mach.h"

using namespace System::Drawing;

Mach::Mach(Point point) {
	this->p = point;
	type = 8;
}
Point Mach::getMach() {
	return p;
}
void Mach::setMach(Point point) {
	this->p = point;
}
void Mach::draw(Graphics^ g) {
	Image^ img = Image::FromFile("ìÿ÷.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}
Form_for_drawing^ Mach::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;
}
