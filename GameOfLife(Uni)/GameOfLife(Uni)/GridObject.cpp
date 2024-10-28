#include "GridObject.h"
#include "GridHandler.h"

void GridObject::TranslateObject(int xTranslate, int yTranslate)
{
	if (!GridHandler::IsInbounds(x + xTranslate, y + yTranslate)) return;


	GridHandler::singleton().gridObjects[x][y] = -1;
	x += xTranslate;
	y += yTranslate;
	GridHandler::singleton().gridObjects[x][y] = id;
}
