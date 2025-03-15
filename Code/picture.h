#ifndef PICTURE_H
#define PICTURE_H

#include <list>
#include <iterator>
#include "primitive.h"
#include "screen.h"

using std::list;

class Primitive;
class Screen;

class Picture {
	private:
		list<Primitive *> listOfPrimitives;
	public:
		Picture() {	};
		void add(Primitive *p);
		void draw(Screen &screen);
};
#endif