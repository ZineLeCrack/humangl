#include "Human.hpp"

void	Human::draw_legs() {
	/* right leg */
	{
		// thigh
		draw_rect(-0.125, -0.1, -0.05, -0.125, -0.3,  0.05, _legs_color);
		draw_rect(-0.025, -0.1, -0.05, -0.025, -0.3,  0.05, _legs_color);
		draw_rect(-0.125, -0.1,  0.05, -0.025, -0.3,  0.05, _legs_color);
		draw_rect(-0.125, -0.1, -0.05, -0.025, -0.3, -0.05, _legs_color);

		// lower part
		draw_rect(-0.125, -0.3, -0.05, -0.125, -0.4,  0.05, _legs_color);
		draw_rect(-0.025, -0.3, -0.05, -0.025, -0.4,  0.05, _legs_color);
		draw_rect(-0.125, -0.3,  0.05, -0.025, -0.4,  0.05, _legs_color);
		draw_rect(-0.125, -0.3, -0.05, -0.025, -0.4, -0.05, _legs_color);

		// foot
		draw_rect(-0.125, -0.5, -0.05, -0.025, -0.5,  0.05, _foots_color);
		draw_rect(-0.125, -0.5, -0.05, -0.125, -0.4,  0.05, _foots_color);
		draw_rect(-0.025, -0.5, -0.05, -0.025, -0.4,  0.05, _foots_color);
		draw_rect(-0.125, -0.5,  0.05, -0.025, -0.4,  0.05, _foots_color);
		draw_rect(-0.125, -0.5, -0.05, -0.025, -0.4, -0.05, _foots_color);
	}
	/* left leg */
	{
		// thigh
		draw_rect( 0.025, -0.1, -0.05,  0.025, -0.3,  0.05, _legs_color);
		draw_rect( 0.125, -0.1, -0.05,  0.125, -0.3,  0.05, _legs_color);
		draw_rect( 0.125, -0.1,  0.05,  0.025, -0.3,  0.05, _legs_color);
		draw_rect( 0.125, -0.1, -0.05,  0.025, -0.3, -0.05, _legs_color);

		// lower part
		draw_rect( 0.025, -0.3, -0.05,  0.025, -0.4,  0.05, _legs_color);
		draw_rect( 0.125, -0.3, -0.05,  0.125, -0.4,  0.05, _legs_color);
		draw_rect( 0.125, -0.3,  0.05,  0.025, -0.4,  0.05, _legs_color);
		draw_rect( 0.125, -0.3, -0.05,  0.025, -0.4, -0.05, _legs_color);

		// foot
		draw_rect( 0.125, -0.5, -0.05,  0.025, -0.5,  0.05, _foots_color);
		draw_rect( 0.025, -0.5, -0.05,  0.025, -0.4,  0.05, _foots_color);
		draw_rect( 0.125, -0.5, -0.05,  0.125, -0.4,  0.05, _foots_color);
		draw_rect( 0.125, -0.5,  0.05,  0.025, -0.4,  0.05, _foots_color);
		draw_rect( 0.125, -0.5, -0.05,  0.025, -0.4, -0.05, _foots_color);
	}
}

void	Human::draw_body() {
	draw_rect(-0.125, -0.1, -0.05,  0.125, -0.1,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05,  0.125, -0.1, -0.05, _body_color);
	draw_rect(-0.125,  0.3,  0.05,  0.125, -0.1,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05, -0.125, -0.1,  0.05, _body_color);
	draw_rect( 0.125,  0.3, -0.05,  0.125, -0.1,  0.05, _body_color);
}

void	Human::draw_arms() {
	/* right arm */
	{
		// forearm
		draw_rect(-0.125, -0.1, -0.05, -0.225, -0.1,  0.05, _arms_color);
		draw_rect(-0.225, -0.1, -0.05, -0.225,  0.1,  0.05, _arms_color);
		draw_rect(-0.125, -0.1, -0.05, -0.225,  0.1, -0.05, _arms_color);
		draw_rect(-0.125, -0.1,  0.05, -0.225,  0.1,  0.05, _arms_color);

		// upper arm
		draw_rect(-0.225,  0.1, -0.05, -0.225,  0.2,  0.05, _arms_color);
		draw_rect(-0.125,  0.1, -0.05, -0.225,  0.2, -0.05, _arms_color);
		draw_rect(-0.125,  0.1,  0.05, -0.225,  0.2,  0.05, _arms_color);

		// shoulder
		draw_rect(-0.125,  0.3, -0.05, -0.225,  0.3,  0.05, _body_color);
		draw_rect(-0.225,  0.2, -0.05, -0.225,  0.3,  0.05, _body_color);
		draw_rect(-0.125,  0.2, -0.05, -0.225,  0.3, -0.05, _body_color);
		draw_rect(-0.125,  0.2,  0.05, -0.225,  0.3,  0.05, _body_color);
	}
	/* left arm */
	{
		// forearm
		draw_rect( 0.125, -0.1, -0.05,  0.225, -0.1,  0.05, _arms_color);
		draw_rect( 0.225, -0.1, -0.05,  0.225,  0.1,  0.05, _arms_color);
		draw_rect( 0.125, -0.1, -0.05,  0.225,  0.1, -0.05, _arms_color);
		draw_rect( 0.125, -0.1,  0.05,  0.225,  0.1,  0.05, _arms_color);

		// upper arm
		draw_rect( 0.225,  0.1, -0.05,  0.225,  0.2,  0.05, _arms_color);
		draw_rect( 0.125,  0.1, -0.05,  0.225,  0.2, -0.05, _arms_color);
		draw_rect( 0.125,  0.1,  0.05,  0.225,  0.2,  0.05, _arms_color);

		// shoulder
		draw_rect( 0.125,  0.3, -0.05,  0.225,  0.3,  0.05, _body_color);
		draw_rect( 0.225,  0.2, -0.05,  0.225,  0.3,  0.05, _body_color);
		draw_rect( 0.125,  0.2, -0.05,  0.225,  0.3, -0.05, _body_color);
		draw_rect( 0.125,  0.2,  0.05,  0.225,  0.3,  0.05, _body_color);
	}
}

void	Human::draw_head() {
	draw_rect(-0.1,  0.3, -0.1,  0.1,  0.3,  0.1, _head_color);
	draw_rect(-0.1,  0.5, -0.1,  0.1,  0.5,  0.1, _head_color);
	draw_rect(-0.1,  0.3, -0.1, -0.1,  0.5,  0.1, _head_color);
	draw_rect( 0.1,  0.3, -0.1,  0.1,  0.5,  0.1, _head_color);
	draw_rect(-0.1,  0.3, -0.1,  0.1,  0.5, -0.1, _head_color);
	draw_rect(-0.1,  0.3,  0.1,  0.1,  0.5,  0.1, _head_color);
}
