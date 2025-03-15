#include <iostream>
#include <SDL2/SDL.h>
#include "screen.h"
#include "point2D.h"
#include "color.h"
#include "line.h"
#include "picture.h"
#include "circle.h"

int main(int argc, char *argv[])
{
    Screen screen("Virtual Screen", BLACK, 725, 700);

    Point2D p1(73, 500);
    Point2D p2(217, 500);
    Point2D p3(361, 500);
    Point2D p4(505, 500);
    Point2D p5(649, 500);

    Picture p;
    
	/* Nao consegui passar vetor como parametro no projeto entao fiz algumas opcoes que podem ser vistas no line.cpp
	op1: {1,1,1,0,0,1,1,1}
	op2: {1,0,1,0,0,1,0,1}
	op3: {1,1,1,1,0,1,1,1}
	op4: {0,0,1,0,0,1,1,0}
	op5: {1,1,1,0,0,1,0,1}
	op6: {1,1,1,0,0,1,0,0}
	op7: {1,1,1,1,1,1,1,1}
	*/
	
	    
    Line l1(Point2D(3, 80), Point2D(722, 80), GREEN,1);
    Line ld1(Point2D(3, 80), Point2D(722, 160), WHITE,2);
    
    Line l2(Point2D(3, 160), Point2D(722, 160), BLUE,3);
    Line ld2(Point2D(3, 160), Point2D(722, 240), RED,4);
    
    Line l3(Point2D(3, 240), Point2D(722, 240), ROXO,5);
    Line ld3(Point2D(3, 240), Point2D(722, 320), ROSA,6);
    
    Line l4(Point2D(3, 320), Point2D(722, 320), AMARELO,7);
    
    
    int a = 1;
    
    /* Nao consegui passar vetor como parametro no projeto entao os vetores de config dos circulos estam em circle.cpp
	op 1: Circulo nao vazio
	op 2: Circulo cheio
	op 3: 1ª padrao cheio (Circulos dentro de Circulos)
	op 4: 2ª padrao cheio (Circulo listrado)
	op 5: 3ª padrao cheio (Circulo preenchido por quadrante)
	*/
    Circle circ1(p1, 70, BLUE, 1);
    Circle circ2(p2, 70, RED, 2);
    Circle circ3(p3, 70, WHITE, 3);
    Circle circ4(p4, 70, GREEN, 4);
    Circle circ5(p5, 70, ROXO, 5);
        
    // Insere primitivas na lista
    p.add(&l1);
    p.add(&l2);
    p.add(&l3);
    p.add(&l4);
    
    p.add(&ld1);
    p.add(&ld2);
    p.add(&ld3);
   
    p.add(&circ1);
    p.add(&circ2);
    p.add(&circ3);
    p.add(&circ4);
    p.add(&circ5);
        
    screen.run(p);

    return 0;
}
