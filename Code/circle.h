#ifndef CIRCLE_H
#define CIRCLE_H

#include "primitive.h"
#include "color.h"
#include "point2D.h"

class Circle: public Primitive {
	private:
		Point2D center;
		int radius;
		Color color;
		int opc;
		void drawCirclePoints(int, int, Screen &) const;
		void drawCircleFull(int, int, Screen &) const;
		void drawCircleStriped(int, int, Screen &) const;
		void drawCircleQuadrante(int, int, Screen &) const;
	public:
		Circle(Point2D, int, Color=WHITE, int = 0);
		virtual void draw(Screen &) const;
		void setCenterPoint(const Point2D p) { center = p; };
		Point2D getCenter() const { return center; };
		void setRadius (int r) { radius = r; };
		int getRadius() const { return radius; };
		void setColor(const Color c) {color = c; };
		Color getColor() const { return color; };
		void setopc (int op) { opc = op; };
		int getopc() const { return opc; };
};

#endif
