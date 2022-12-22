#pragma once
#include <cliext/list>
#include "Form_for_drawing.h"

ref class DrawingField
{
private:
	cliext::list<Form_for_drawing^> forms;

public:
	void addForm_for_drawing(Form_for_drawing^ form);
	void drawForm_for_drawing(Graphics^ g);
	Form_for_drawing^ findForm_for_drawing(int x, int y);
	void deleteForm_for_drawing(Form_for_drawing^ form);
	void clear();
};
