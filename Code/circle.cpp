#include <cmath>
#include <iostream>
#include "circle.h"
#include "line.h"
#include "picture.h"

Circle::Circle(Point2D p, int r, Color c, int op):Primitive("Circle"), center(p), radius(r), color(c), opc(op) {
}

//Usando o algoritmo de Bresenham
void Circle::draw(Screen &screen) const {
    // Definição e Inicialização de Variáveis locais      
	//Coniderando a circunferência ao redor da origem, mas renderizada transladada
	
	if(opc == 1){
		int x = 0;          // x inicial
    	int y = radius;		// y inicial
    	int d = 1 - radius;   // d de teste inicial

    	// Desenha os pontos inicias de cada quadrante
		drawCirclePoints(x, y, screen);


    	// Gera os novos pontos e os renderiza
    	while (x < y) {         
        	if (d < 0)   // Direção E
            	d = d + 2 * x + 3;
        	else {       // Direção SE
            	d = d + 2 * (x - y) + 5;
            	y = y - 1;
    		}
		
			x = x + 1;
		
        	drawCirclePoints(x, y, screen);
		}
	}
	if(opc == 2){
		int x = 0;          // x inicial
    	int y = radius;		// y inicial
    	int d = 1 - radius;   // d de teste inicial

    	// Desenha os pontos inicias de cada quadrante
		drawCircleFull(x, y, screen);

    	// Gera os novos pontos e os renderiza
    	while (x < y) {         
        	if (d < 0)   // Direção E
            	d = d + 2 * x + 3;
        	else {       // Direção SE
            	d = d + 2 * (x - y) + 5;
            	y = y - 1;
    		}
		
			x = x + 1;
		
        	drawCircleFull(x, y, screen);
		}
	}
	if(opc == 3){
		for(int i = 0; i < radius; i++){
			int x = 0;          // x inicial
    		int y = i;		// y inicial
    		int d = 1 - i;   // d de teste inicial

    		// Desenha os pontos inicias de cada quadrante
			drawCirclePoints(x, y, screen);


    		// Gera os novos pontos e os renderiza
    		while (x < y) {         
        		if (d < 0)   // Direção E
            		d = d + 2 * x + 3;
        		else {       // Direção SE
            		d = d + 2 * (x - y) + 5;
            		y = y - 1;
    			}
		
				x = x + 1;
		
        		drawCirclePoints(x, y, screen);
			}
		}
	}
	if(opc == 4){

		int x = 0;          // x inicial
    	int y = radius;		// y inicial
    	int d = 1 - radius;   // d de teste inicial

    	// Desenha os pontos inicias de cada quadrante
		drawCircleStriped(x, y, screen);


    	// Gera os novos pontos e os renderiza
    	while (x < y) {         
        	if (d < 0)   // Direção E
            	d = d + 2 * x + 3;
        	else {       // Direção SE
            	d = d + 2 * (x - y) + 5;
            	y = y - 1;
    		}
		
			x = x + 1;
		
        	drawCircleStriped(x, y, screen);
		}
	}
	if(opc == 5){
		int x = 0;          // x inicial
    	int y = radius;		// y inicial
    	int d = 1 - radius;   // d de teste inicial

    	// Desenha os pontos inicias de cada quadrante
		drawCircleQuadrante(x, y, screen);


    	// Gera os novos pontos e os renderiza
    	while (x < y) {         
        	if (d < 0)   // Direção E
            	d = d + 2 * x + 3;
        	else {       // Direção SE
            	d = d + 2 * (x - y) + 5;
            	y = y - 1;
    		}
		
			x = x + 1;
		
        	drawCircleQuadrante(x, y, screen);
		}
	}

	
	
	
}
void Circle::drawCirclePoints(int x, int y, Screen &screen) const {
    int xCenter = center.getX();
    int yCenter = center.getY();
    
    screen.setPixel(xCenter + x, yCenter + y, color);
    screen.setPixel(xCenter + y, yCenter + x, color);
    screen.setPixel(xCenter + y, yCenter - x, color);
    screen.setPixel(xCenter + x, yCenter - y, color);
    screen.setPixel(xCenter - x, yCenter - y, color);
    screen.setPixel(xCenter - y, yCenter - x, color);
    screen.setPixel(xCenter - y, yCenter + x, color);
    screen.setPixel(xCenter - x, yCenter + y, color);	
}

void Circle::drawCircleQuadrante(int x, int y, Screen &screen) const {
    int xCenter = center.getX();
    int yCenter = center.getY();
	
	int v[4] = {1,0,1,0};
	
	for(int i = yCenter + x; i > yCenter - x; i--){
		if(v[0] == 1 && v[3] == 1){
			screen.setPixel(xCenter + y, i, color);
		}
		if(v[0] == 1 && v[3] == 0){
			if(yCenter >= i){
				screen.setPixel(xCenter + y, i, color);
			}
		}
		if(v[0] == 0 && v[3] == 1){
			if(yCenter <= i){
				screen.setPixel(xCenter + y, i, color);
			}
		}
	}
	for(int i = yCenter + y; i > yCenter - y; i--){
		if(v[0] == 1 && v[3] == 1){
			screen.setPixel(xCenter + x, i, color);
		}
		if(v[0] == 1 && v[3] == 0){
			if(yCenter >= i){
				screen.setPixel(xCenter + x, i, color);
			}
		}
		if(v[0] == 0 && v[3] == 1){
			if(yCenter <= i){
				screen.setPixel(xCenter + x, i, color);
			}
		}
		
	}
	for(int i = yCenter - x; i < yCenter + x; i++){
		if(v[1] == 1 && v[2] == 1){
			screen.setPixel(xCenter - y, i, color);
		}
		if(v[1] == 1 && v[2] == 0){
			if(yCenter >= i){
				screen.setPixel(xCenter - y, i, color);
			}
		}
		if(v[1] == 0 && v[2] == 1){
			if(yCenter <= i){
				screen.setPixel(xCenter - y, i, color);
			}
		}
		
	}
	for(int i = yCenter - y; i < yCenter + y; i++){
		if(v[1] == 1 && v[2] == 1){
			screen.setPixel(xCenter - x, i, color);
		}
		if(v[1] == 1 && v[2] == 0){
			if(yCenter >= i){
				screen.setPixel(xCenter - x, i, color);
			}
		}
		if(v[1] == 0 && v[2] == 1){
			if(yCenter <= i){
				screen.setPixel(xCenter - x, i, color);
			}
		}
		
	}
    
    screen.setPixel(xCenter + x, yCenter + y, color);
    screen.setPixel(xCenter + y, yCenter + x, color);
    screen.setPixel(xCenter + y, yCenter - x, color);
    screen.setPixel(xCenter + x, yCenter - y, color);
    screen.setPixel(xCenter - x, yCenter - y, color);
    screen.setPixel(xCenter - y, yCenter - x, color);
    screen.setPixel(xCenter - y, yCenter + x, color);
    screen.setPixel(xCenter - x, yCenter + y, color);	
}


void Circle::drawCircleStriped(int x, int y, Screen &screen) const {
    int xCenter = center.getX();
    int yCenter = center.getY();
	
	int v1 = 0, v2 = 0;
	int v[4] = {1,0,1,0};
	
	if(v[3] == 1){
		for(int i = yCenter + x; i > yCenter - x; i--){
			screen.setPixel(xCenter + y, i, color);
		}
	}
	
	if(v[2] == 1){
		for(int i = yCenter + y; i > yCenter - y; i--){
			screen.setPixel(xCenter + x, i, color);
		}
	}
	if(v[0] == 1){
		for(int i = yCenter - x; i < yCenter + x; i++){
			screen.setPixel(xCenter - y, i, color);
		}
	}
	
	if(v[1] == 1){
		for(int i = yCenter - y; i < yCenter + y; i++){
			screen.setPixel(xCenter - x, i, color);
		}
	}
	
    
    screen.setPixel(xCenter + x, yCenter + y, color);
    screen.setPixel(xCenter + y, yCenter + x, color);
    screen.setPixel(xCenter + y, yCenter - x, color);
    screen.setPixel(xCenter + x, yCenter - y, color);
    screen.setPixel(xCenter - x, yCenter - y, color);
    screen.setPixel(xCenter - y, yCenter - x, color);
    screen.setPixel(xCenter - y, yCenter + x, color);
    screen.setPixel(xCenter - x, yCenter + y, color);	
}
void Circle::drawCircleFull(int x, int y, Screen &screen) const {
    int xCenter = center.getX();
    int yCenter = center.getY();
	
	
	for(int i = yCenter + x; i > yCenter - x; i--){
		screen.setPixel(xCenter + y, i, color);
	}
	for(int i = yCenter + y; i > yCenter - y; i--){
		screen.setPixel(xCenter + x, i, color);
	}
	for(int i = yCenter - x; i < yCenter + x; i++){
		screen.setPixel(xCenter - y, i, color);
	}
	for(int i = yCenter - y; i < yCenter + y; i++){
		screen.setPixel(xCenter - x, i, color);
	}
    
    screen.setPixel(xCenter + x, yCenter + y, color);
    screen.setPixel(xCenter + y, yCenter + x, color);
    screen.setPixel(xCenter + y, yCenter - x, color);
    screen.setPixel(xCenter + x, yCenter - y, color);
    screen.setPixel(xCenter - x, yCenter - y, color);
    screen.setPixel(xCenter - y, yCenter - x, color);
    screen.setPixel(xCenter - y, yCenter + x, color);
    screen.setPixel(xCenter - x, yCenter + y, color);	
}
