#pragma once
#include "Form_for_drawing.h"
ref class Mach :
    public Form_for_drawing
{
private:
    Point p;
    int width, height;
public:
    Mach(Point point);
    Point getMach();
    void setMach(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Form_for_drawing^ find(int x, int y) override;
};
