#pragma once

#include "../CanvasPainter/ICanvasDrawable.h"

namespace shape_drawing_lib
{

class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(Point const& p1, Point const& p2, Point const& p3, graphics_lib::RgbColor color = 0);

	void Draw(graphics_lib::ICanvas& canvas) const override;

private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
	graphics_lib::RgbColor m_color;
};

} // namespace shape_drawing_lib
