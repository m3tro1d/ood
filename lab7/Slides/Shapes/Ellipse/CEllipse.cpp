#include "CEllipse.h"

CEllipse::CEllipse(
	PointD const& center,
	double horizontalRadius,
	double verticalRadius,
	std::shared_ptr<IStyle> const& outlineStyle,
	std::shared_ptr<IStyle> const& fillStyle)
	: m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
	, CShape(outlineStyle, fillStyle)
{
}

RectD CEllipse::GetFrame() const
{
	return {
		.leftTop = { m_center.x - m_horizontalRadius, m_center.y - m_verticalRadius },
		.width = m_horizontalRadius * 2,
		.height = m_verticalRadius * 2,
	};
}

void CEllipse::SetFrame(RectD const& rect)
{
	m_center = { rect.leftTop.x + rect.width / 2, rect.leftTop.y + rect.height / 2 };
	m_horizontalRadius = rect.width / 2;
	m_verticalRadius = rect.height / 2;
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.DrawEllipse(
		m_center,
		m_horizontalRadius,
		m_verticalRadius,
		GetOutlineColor(),
		GetFillColor());
}
