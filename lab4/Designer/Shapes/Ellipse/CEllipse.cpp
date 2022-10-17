#include "CEllipse.h"

CEllipse::CEllipse(Color color, Point const& center, double horizontalRadius, double verticalRadius)
	: CShape(color)
	, m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

Point CEllipse::GetCenter() const
{
	return m_center;
}

double CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

double CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
}
