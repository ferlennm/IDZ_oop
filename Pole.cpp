#include "Pole.h"

using namespace System::Drawing;

Pole::Pole(Point point) {
	this->p = point;
	type = 7;
}
Point Pole::getPole() {
	return p;
}
void Pole::setPole(Point point) {
	this->p = point;
}
void Pole::draw(Graphics^ g) {
	Image^ img = Image::FromFile("поле.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}
Form_for_drawing^ Pole::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;
}
