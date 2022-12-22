#include "DrawingField.h"

void DrawingField::addForm_for_drawing(Form_for_drawing^ form)
{
    forms.push_front(form);
}

void DrawingField::drawForm_for_drawing(Graphics^ g)
{
    if (!forms.empty()) {
        for each (Form_for_drawing ^ form in forms) {
            form->draw(g);
        }
    }
}

Form_for_drawing^ DrawingField::findForm_for_drawing(int x, int y)
{
    Form_for_drawing^ result = nullptr;
    for each (Form_for_drawing ^ form in forms)
        if (form->find(x, y) != nullptr)
        {
            result = form;
            forms.remove(form);
            break;
        }

    return result;
}

void DrawingField::clear() {
    forms.clear();
}


void DrawingField::deleteForm_for_drawing(Form_for_drawing^ form)
{
    forms.remove(form);
}
