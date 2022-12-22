#pragma once
#include "Form_for_drawing.h"
ref class Fut :
    public Form_for_drawing
{
private:
    Point p;
    int width, height;
public:
    Fut(Point point);
    Point getFut();
    void setFut(Point point);

    virtual void draw(Graphics^ g) override;
    virtual Form_for_drawing^ find(int x, int y) override;
};
