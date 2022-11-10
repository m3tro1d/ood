#pragma once

#include "ShapeTypes.h"
#include <optional>

class IStyle
{
public:
	virtual std::optional<bool> IsEnabled() const = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;

	virtual std::optional<RgbaColor> GetColor() const = 0;
	virtual void SetColor(RgbaColor color) = 0;

	virtual ~IStyle() = default;
};
