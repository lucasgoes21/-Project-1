#ifndef POINT2D_H
#define POINT2D_H

#include "primitive.h"
#include "color.h"

class Point2D: public Primitive {
	private:
		double x;
		double y;
		Color color;
		
	public:
		Point2D(double = 0, double = 0, Color=WHITE);
		virtual void draw(Screen &) const;
		void setX(double xx) { x = xx; };
		void setY(double yy) { y = yy; };
		double getX() const { return x; };
		double getY() const { return y; };
		void setColor(const Color c) {color = c; }
		Color getColor() const { return color; }
};

#endif