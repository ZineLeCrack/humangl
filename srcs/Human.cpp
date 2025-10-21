#include "Human.hpp"

void	Human::draw_legs() {
	draw_rect(-0.25,  0.0, -0.1, -0.25, -0.8,  0.1, _legs_color);
	draw_rect(-0.05,  0.0, -0.1, -0.05, -0.8,  0.1, _legs_color);
	draw_rect( 0.05,  0.0, -0.1,  0.05, -0.8,  0.1, _legs_color);
	draw_rect( 0.25,  0.0, -0.1,  0.25, -0.8,  0.1, _legs_color);
	draw_rect(-0.25,  0.0,  0.1, -0.05, -0.8,  0.1, _legs_color);
	draw_rect( 0.25,  0.0,  0.1,  0.05, -0.8,  0.1, _legs_color);
	draw_rect(-0.25,  0.0, -0.1, -0.05, -0.8, -0.1, _legs_color);
	draw_rect( 0.25,  0.0, -0.1,  0.05, -0.8, -0.1, _legs_color);

	draw_rect(-0.25, -1.0, -0.1, -0.05, -1.0,  0.1, _foots_color);
	draw_rect( 0.25, -1.0, -0.1,  0.05, -1.0,  0.1, _foots_color);
	draw_rect(-0.25, -1.0, -0.1, -0.25, -0.8,  0.1, _foots_color);
	draw_rect(-0.05, -1.0, -0.1, -0.05, -0.8,  0.1, _foots_color);
	draw_rect( 0.05, -1.0, -0.1,  0.05, -0.8,  0.1, _foots_color);
	draw_rect( 0.25, -1.0, -0.1,  0.25, -0.8,  0.1, _foots_color);
	draw_rect(-0.25, -1.0,  0.1, -0.05, -0.8,  0.1, _foots_color);
	draw_rect( 0.25, -1.0,  0.1,  0.05, -0.8,  0.1, _foots_color);
	draw_rect(-0.25, -1.0, -0.1, -0.05, -0.8, -0.1, _foots_color);
	draw_rect( 0.25, -1.0, -0.1,  0.05, -0.8, -0.1, _foots_color);
}
