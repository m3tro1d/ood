#pragma once

#include "../ICanvas.h"

namespace graphics_lib
{

class CCanvas : public ICanvas
{
public:
	void SetColor(RgbColor color) override;
	void MoveTo(int x, int y) override;
	void LineTo(int x, int y) override;
};

} // namespace graphics_lib
