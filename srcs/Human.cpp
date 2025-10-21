#include "Human.hpp"

void	Human::draw_legs() {

	/* right leg */
	{
		// thigh
		draw_rect(-0.25, -0.2, -0.1, -0.25, -0.6,  0.1, _legs_color);
		draw_rect(-0.05, -0.2, -0.1, -0.05, -0.6,  0.1, _legs_color);
		draw_rect(-0.25, -0.2,  0.1, -0.05, -0.6,  0.1, _legs_color);
		draw_rect(-0.25, -0.2, -0.1, -0.05, -0.6, -0.1, _legs_color);

		// lower part
		draw_rect(-0.25, -0.6, -0.1, -0.25, -0.8,  0.1, _legs_color);
		draw_rect(-0.05, -0.6, -0.1, -0.05, -0.8,  0.1, _legs_color);
		draw_rect(-0.25, -0.6,  0.1, -0.05, -0.8,  0.1, _legs_color);
		draw_rect(-0.25, -0.6, -0.1, -0.05, -0.8, -0.1, _legs_color);

		// foot
		draw_rect(-0.25, -1.0, -0.1, -0.05, -1.0,  0.1, _foots_color);
		draw_rect(-0.25, -1.0, -0.1, -0.25, -0.8,  0.1, _foots_color);
		draw_rect(-0.05, -1.0, -0.1, -0.05, -0.8,  0.1, _foots_color);
		draw_rect(-0.25, -1.0,  0.1, -0.05, -0.8,  0.1, _foots_color);
		draw_rect(-0.25, -1.0, -0.1, -0.05, -0.8, -0.1, _foots_color);
	}
	/* left leg */
	{
		// thigh
		draw_rect( 0.05, -0.2, -0.1,  0.05, -0.6,  0.1, _legs_color);
		draw_rect( 0.25, -0.2, -0.1,  0.25, -0.6,  0.1, _legs_color);
		draw_rect( 0.25, -0.2,  0.1,  0.05, -0.6,  0.1, _legs_color);
		draw_rect( 0.25, -0.2, -0.1,  0.05, -0.6, -0.1, _legs_color);

		// lower part
		draw_rect( 0.05, -0.6, -0.1,  0.05, -0.8,  0.1, _legs_color);
		draw_rect( 0.25, -0.6, -0.1,  0.25, -0.8,  0.1, _legs_color);
		draw_rect( 0.25, -0.6,  0.1,  0.05, -0.8,  0.1, _legs_color);
		draw_rect( 0.25, -0.6, -0.1,  0.05, -0.8, -0.1, _legs_color);

		// foot
		draw_rect( 0.25, -1.0, -0.1,  0.05, -1.0,  0.1, _foots_color);
		draw_rect( 0.05, -1.0, -0.1,  0.05, -0.8,  0.1, _foots_color);
		draw_rect( 0.25, -1.0, -0.1,  0.25, -0.8,  0.1, _foots_color);
		draw_rect( 0.25, -1.0,  0.1,  0.05, -0.8,  0.1, _foots_color);
		draw_rect( 0.25, -1.0, -0.1,  0.05, -0.8, -0.1, _foots_color);
	}
}

void	Human::draw_body() {
	draw_rect(-0.25, -0.2, -0.1,  0.25, -0.2,  0.1, _body_color);
	draw_rect(-0.25,  0.6, -0.1,  0.25, -0.2, -0.1, _body_color);
	draw_rect(-0.25,  0.6,  0.1,  0.25, -0.2,  0.1, _body_color);
	draw_rect(-0.25,  0.6, -0.1, -0.25, -0.2,  0.1, _body_color);
	draw_rect( 0.25,  0.6, -0.1,  0.25, -0.2,  0.1, _body_color);
}

void	Human::draw_arms() {

	/* right arm */
	{
		// forearm
		draw_rect(-0.25, -0.2, -0.1, -0.45, -0.2,  0.1, _arms_color);
		draw_rect(-0.45, -0.2, -0.1, -0.45,  0.2,  0.1, _arms_color);
		draw_rect(-0.25, -0.2, -0.1, -0.45,  0.2, -0.1, _arms_color);
		draw_rect(-0.25, -0.2,  0.1, -0.45,  0.2,  0.1, _arms_color);

		// upper arm
		draw_rect(-0.45,  0.2, -0.1, -0.45,  0.4,  0.1, _arms_color);
		draw_rect(-0.25,  0.2, -0.1, -0.45,  0.4, -0.1, _arms_color);
		draw_rect(-0.25,  0.2,  0.1, -0.45,  0.4,  0.1, _arms_color);

		// shoulder
		draw_rect(-0.25,  0.6, -0.1, -0.45,  0.6,  0.1, _body_color);
		draw_rect(-0.45,  0.4, -0.1, -0.45,  0.6,  0.1, _body_color);
		draw_rect(-0.25,  0.4, -0.1, -0.45,  0.6, -0.1, _body_color);
		draw_rect(-0.25,  0.4,  0.1, -0.45,  0.6,  0.1, _body_color);
	}
	/* left arm */
	{
		// forearm
		draw_rect( 0.25, -0.2, -0.1,  0.45, -0.2,  0.1, _arms_color);
		draw_rect( 0.45, -0.2, -0.1,  0.45,  0.2,  0.1, _arms_color);
		draw_rect( 0.25, -0.2, -0.1,  0.45,  0.2, -0.1, _arms_color);
		draw_rect( 0.25, -0.2,  0.1,  0.45,  0.2,  0.1, _arms_color);

		// upper arm
		draw_rect( 0.45,  0.2, -0.1,  0.45,  0.4,  0.1, _arms_color);
		draw_rect( 0.25,  0.2, -0.1,  0.45,  0.4, -0.1, _arms_color);
		draw_rect( 0.25,  0.2,  0.1,  0.45,  0.4,  0.1, _arms_color);

		// shoulder
		draw_rect( 0.25,  0.6, -0.1,  0.45,  0.6,  0.1, _body_color);
		draw_rect( 0.45,  0.4, -0.1,  0.45,  0.6,  0.1, _body_color);
		draw_rect( 0.25,  0.4, -0.1,  0.45,  0.6, -0.1, _body_color);
		draw_rect( 0.25,  0.4,  0.1,  0.45,  0.6,  0.1, _body_color);
	}
}

void	Human::draw_head() {
	draw_rect(-0.25,  0.6, -0.25,  0.25,  0.6,  0.25, _head_color);
	draw_rect(-0.25,  1.1, -0.25,  0.25,  1.1,  0.25, _head_color);
	draw_rect(-0.25,  0.6, -0.25, -0.25,  1.1,  0.25, _head_color);
	draw_rect( 0.25,  0.6, -0.25,  0.25,  1.1,  0.25, _head_color);
	draw_rect(-0.25,  0.6, -0.25,  0.25,  1.1, -0.25, _head_color);
	draw_rect(-0.25,  0.6,  0.25,  0.25,  1.1,  0.25, _head_color);
}
