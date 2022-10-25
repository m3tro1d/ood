#include "PaintUtils.h"
#include "../Libs/graphics_lib/Canvas/CCanvas.h"
#include "../Libs/shape_drawing_lib/Rectangle/CRectangle.h"
#include "../Libs/shape_drawing_lib/Triangle/CTriangle.h"

void app::PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	shape_drawing_lib::CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	shape_drawing_lib::CRectangle rectangle({ 30, 40 }, 18, 24);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void app::PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
	PaintPicture(painter);
}
