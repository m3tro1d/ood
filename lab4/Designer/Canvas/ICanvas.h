#pragma once

#include "../Shapes/ShapeTypes.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(Point const& from, Point const& to) = 0;
	virtual void DrawEllipse(Point const& center, int width, int height) = 0;
};
