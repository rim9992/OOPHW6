/* Homework 6
 * Robbie Robot Shop
 * 
 * Michael Currie
 * Anna Cox
 * Rabab Antria
 * Ricardo Morales
 */
#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "Shop.h"

int main() {

   Shop shop;
   //shop.load(); 
   //shop.cli();
	
	Fl_Window *win = new Fl_Window{640,300,"Robbie Robot Shop"};

	win->position(400,200);
	win->color(FL_WHITE); 
	win->resizable(*win);
	win->end();
	win->show();
	return(Fl::run()); 


}

