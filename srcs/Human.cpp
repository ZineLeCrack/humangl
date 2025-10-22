#include "Human.hpp"

void	Human::draw_legs() {
	float angle = sin((glfwGetTime() - _animation_frame) * 5.0f) * 30.0f;

	/* right leg */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK) {
			glTranslatef(0.0f, -0.1f, 0.0f);
			glRotatef(angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.1f, 0.0f);
		}

		// thigh
		draw_rect(-0.125, -0.1, -0.05, -0.025, -0.1,  0.05, _legs_color);
		draw_rect(-0.125, -0.1, -0.05, -0.125, -0.3,  0.05, _legs_color);
		draw_rect(-0.025, -0.1, -0.05, -0.025, -0.3,  0.05, _legs_color);
		draw_rect(-0.125, -0.1,  0.05, -0.025, -0.3,  0.05, _legs_color);
		draw_rect(-0.125, -0.1, -0.05, -0.025, -0.3, -0.05, _legs_color);

		if (_animation == WALK) {
			glTranslatef(0.0f, -0.3f, 0.0f);
			glRotatef(angle < 0 ? -angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.3f, 0.0f);
		}

		// lower part
		draw_rect(-0.125, -0.29, -0.05, -0.125, -0.45,  0.05, _legs_color);
		draw_rect(-0.025, -0.29, -0.05, -0.025, -0.45,  0.05, _legs_color);
		draw_rect(-0.125, -0.29,  0.05, -0.025, -0.45,  0.05, _legs_color);
		draw_rect(-0.125, -0.29, -0.05, -0.025, -0.45, -0.05, _legs_color);

		// foot
		draw_rect(-0.125, -0.50, -0.05, -0.025, -0.50,  0.05, _foots_color);
		draw_rect(-0.125, -0.50, -0.05, -0.125, -0.45,  0.05, _foots_color);
		draw_rect(-0.025, -0.50, -0.05, -0.025, -0.45,  0.05, _foots_color);
		draw_rect(-0.125, -0.50,  0.05, -0.025, -0.45,  0.05, _foots_color);
		draw_rect(-0.125, -0.50, -0.05, -0.025, -0.45, -0.05, _foots_color);

		if (_animation) glPopMatrix();
	}
	/* left leg */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK) {
			glTranslatef(0.0f, -0.1f, 0.0f);
			glRotatef(-angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.1f, 0.0f);
		}

		// thigh
		draw_rect( 0.125, -0.1, -0.05,  0.025, -0.1,  0.05, _legs_color);
		draw_rect( 0.025, -0.1, -0.05,  0.025, -0.3,  0.05, _legs_color);
		draw_rect( 0.125, -0.1, -0.05,  0.125, -0.3,  0.05, _legs_color);
		draw_rect( 0.125, -0.1,  0.05,  0.025, -0.3,  0.05, _legs_color);
		draw_rect( 0.125, -0.1, -0.05,  0.025, -0.3, -0.05, _legs_color);

		if (_animation == WALK) {
			glTranslatef(0.0f, -0.3f, 0.0f);
			glRotatef(-angle < 0 ? angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.3f, 0.0f);
		}

		// lower part
		draw_rect( 0.025, -0.29, -0.05,  0.025, -0.45,  0.05, _legs_color);
		draw_rect( 0.125, -0.29, -0.05,  0.125, -0.45,  0.05, _legs_color);
		draw_rect( 0.125, -0.29,  0.05,  0.025, -0.45,  0.05, _legs_color);
		draw_rect( 0.125, -0.29, -0.05,  0.025, -0.45, -0.05, _legs_color);

		// foot
		draw_rect( 0.125, -0.50, -0.05,  0.025, -0.50,  0.05, _foots_color);
		draw_rect( 0.025, -0.50, -0.05,  0.025, -0.45,  0.05, _foots_color);
		draw_rect( 0.125, -0.50, -0.05,  0.125, -0.45,  0.05, _foots_color);
		draw_rect( 0.125, -0.50,  0.05,  0.025, -0.45,  0.05, _foots_color);
		draw_rect( 0.125, -0.50, -0.05,  0.025, -0.45, -0.05, _foots_color);

		if (_animation) glPopMatrix();
	}
}

void	Human::draw_body() {
	draw_rect(-0.125, -0.1, -0.05,  0.125, -0.1,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05,  0.125,  0.3,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05,  0.125, -0.1, -0.05, _body_color);
	draw_rect(-0.125,  0.3,  0.05,  0.125, -0.1,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05, -0.125, -0.1,  0.05, _body_color);
	draw_rect( 0.125,  0.3, -0.05,  0.125, -0.1,  0.05, _body_color);
}

void	Human::draw_arms() {
	float angle = sin((glfwGetTime() - _animation_frame) * 5.0f) * 30.0f;

	/* right arm */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK) {
			glTranslatef(0.0f, 0.25f, 0.0f);
			glRotatef(-angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.25f, 0.0f);
		}

		// upper arm
		draw_rect(-0.225,  0.1, -0.05, -0.225,  0.2,  0.05, _arms_color);
		draw_rect(-0.125,  0.1, -0.05, -0.225,  0.2, -0.05, _arms_color);
		draw_rect(-0.125,  0.1,  0.05, -0.225,  0.2,  0.05, _arms_color);
		draw_rect(-0.125,  0.1, -0.05, -0.125,  0.2,  0.05, _arms_color);

		// shoulder
		draw_rect(-0.125,  0.3, -0.05, -0.225,  0.3,  0.05, _body_color);
		draw_rect(-0.225,  0.2, -0.05, -0.225,  0.3,  0.05, _body_color);
		draw_rect(-0.125,  0.2, -0.05, -0.225,  0.3, -0.05, _body_color);
		draw_rect(-0.125,  0.2,  0.05, -0.225,  0.3,  0.05, _body_color);
		draw_rect(-0.125,  0.2, -0.05, -0.125,  0.3,  0.05, _body_color);

		if (_animation == WALK) {
			glTranslatef(0.0f, 0.1f, 0.0f);
			glRotatef(-angle < 0 ? -angle / 2 : 0, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_rect(-0.125, -0.10, -0.05, -0.225, -0.10,  0.05, _arms_color);
		draw_rect(-0.225, -0.10, -0.05, -0.225,  0.12,  0.05, _arms_color);
		draw_rect(-0.125, -0.10, -0.05, -0.225,  0.12, -0.05, _arms_color);
		draw_rect(-0.125, -0.10,  0.05, -0.225,  0.12,  0.05, _arms_color);
		draw_rect(-0.125, -0.10, -0.05, -0.125,  0.12,  0.05, _arms_color);

		if (_animation) glPopMatrix();
	}
	/* left arm */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK) {
			glTranslatef(0.0f, 0.25f, 0.0f);
			glRotatef(angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.25f, 0.0f);
		}
		
		// upper arm
		draw_rect( 0.225,  0.1, -0.05,  0.225,  0.2,  0.05, _arms_color);
		draw_rect( 0.125,  0.1, -0.05,  0.225,  0.2, -0.05, _arms_color);
		draw_rect( 0.125,  0.1,  0.05,  0.225,  0.2,  0.05, _arms_color);
		draw_rect( 0.125,  0.1, -0.05,  0.125,  0.2,  0.05, _arms_color);
		
		// shoulder
		draw_rect( 0.125,  0.3, -0.05,  0.225,  0.3,  0.05, _body_color);
		draw_rect( 0.225,  0.2, -0.05,  0.225,  0.3,  0.05, _body_color);
		draw_rect( 0.125,  0.2, -0.05,  0.225,  0.3, -0.05, _body_color);
		draw_rect( 0.125,  0.2,  0.05,  0.225,  0.3,  0.05, _body_color);
		draw_rect( 0.125,  0.2, -0.05,  0.125,  0.3,  0.05, _body_color);

		if (_animation == WALK) {
			glTranslatef(0.0f, 0.1f, 0.0f);
			glRotatef(angle < 0 ? angle / 2 : 0, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_rect( 0.125, -0.10, -0.05,  0.225, -0.10,  0.05, _arms_color);
		draw_rect( 0.225, -0.10, -0.05,  0.225,  0.12,  0.05, _arms_color);
		draw_rect( 0.125, -0.10, -0.05,  0.225,  0.12, -0.05, _arms_color);
		draw_rect( 0.125, -0.10,  0.05,  0.225,  0.12,  0.05, _arms_color);
		draw_rect( 0.125, -0.10, -0.05,  0.125,  0.12,  0.05, _arms_color);
		
		if (_animation) glPopMatrix();
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
