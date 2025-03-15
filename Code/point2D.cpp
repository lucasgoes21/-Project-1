#include "point2D.h"

Point2D::Point2D(double xx , double yy, Color c):Primitive("Point2D"), x(xx), y(yy), color(c) {
}

void Point2D::draw(Screen &screen) const{
	screen.setPixel(x, y, color);
}