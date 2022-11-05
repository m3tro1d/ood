#include "CGroupOutlineStyle.h"

CGroupOutlineStyle::CGroupOutlineStyle(IOutlineStyleEnumerator const& enumerator)
	: m_enumerator(enumerator)
{
}

bool CGroupOutlineStyle::IsEnabled() const
{
	bool enabled = true;

	m_enumerator([&enabled](IOutlineStyle& style) {
		enabled &= style.IsEnabled();
	});

	return enabled;
}

void CGroupOutlineStyle::Enable()
{
	m_enumerator([](IOutlineStyle& style) {
		style.Enable();
	});
}

void CGroupOutlineStyle::Disable()
{
	m_enumerator([](IOutlineStyle& style) {
		style.Disable();
	});
}

RgbaColor CGroupOutlineStyle::GetColor() const
{
	// TODO: implement with optional
	return 0;
}

void CGroupOutlineStyle::SetColor(RgbaColor color)
{
	m_enumerator([color](IOutlineStyle& style) {
		style.SetColor(color);
	});
}

double CGroupOutlineStyle::GetThickness() const
{
	// TODO: implement with optional
	return 0;
}

void CGroupOutlineStyle::SetThickness(double thickness)
{
	m_enumerator([thickness](IOutlineStyle& style) {
		style.SetThickness(thickness);
	});
}