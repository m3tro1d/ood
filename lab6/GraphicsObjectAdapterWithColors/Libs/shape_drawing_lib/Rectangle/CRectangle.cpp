#include "CRectangle.h"

shape_drawing_lib::CRectangle::CRectangle(Point const& leftTop, int width, int height, graphics_lib::RgbColor color)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_color(color)
{
}

void shape_drawing_lib::CRectangle::Draw(graphics_lib::ICanvas& canvas) const
{
	canvas.SetColor(m_color);
	canvas.MoveTo(m_leftTop.x, m_leftTop.y);
	canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
	canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y + m_height);
	canvas.LineTo(m_leftTop.x, m_leftTop.y + m_height);
	canvas.LineTo(m_leftTop.x, m_leftTop.y);
}
