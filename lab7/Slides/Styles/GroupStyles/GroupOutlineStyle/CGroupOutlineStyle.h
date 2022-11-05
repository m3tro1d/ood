#pragma once

#include "../../../Shapes/IOutlineStyle.h"
#include "../CGroupStyleImpl.h"
#include <functional>

using IOutlineStyleCallback = std::function<void(IOutlineStyle&)>;
using IOutlineStyleEnumerator = std::function<void(IOutlineStyleCallback const&)>;

class CGroupOutlineStyle : public CGroupStyleImpl<IOutlineStyle, IOutlineStyleEnumerator>
{
public:
	explicit CGroupOutlineStyle(IOutlineStyleEnumerator const& enumerator);

	std::optional<double> GetThickness() const override;
	void SetThickness(double thickness) override;
};
