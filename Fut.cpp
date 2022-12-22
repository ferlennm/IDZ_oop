#include "Fut.h"

using namespace System::Drawing;

Fut::Fut(Point point) {
	this->p = point;
	type = 3;
}
Point Fut::getFut() {
	return p;
}
void Fut::setFut(Point point) {
	this->p = point;
}
void Fut::draw(Graphics^ g) {
	Image^ img = Image::FromFile("���������.png");
	width = img->Width;
	height = img->Height;
	g->DrawImage(img, p);
}
Form_for_drawing^ Fut::find(int x, int y)
{

	if (x >= p.X && x <= p.X + width) {
		if (y >= p.Y && y <= p.Y + height)
			return this;
	}
	return nullptr;
}
