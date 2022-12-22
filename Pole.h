#pragma once
#include "Form_for_drawing.h"
ref class Pole :
    public Form_for_drawing
{
private:
    Point p;
    int width, height;
public:
    Pole(Point point);
    Point getPole();
    void setPole(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Form_for_drawing^ find(int x, int y) override;
};
