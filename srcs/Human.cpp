#include "Human.hpp"

void	Human::draw_legs() {
	float angle = sin((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	/* right leg */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, -0.1f, 0.0f);
			glRotatef(angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.1f, 0.0f);
		} else if (_animation == JUMP) {
			glTranslatef(0.0f, -0.1f, 0.0f);
			glRotatef(-angle < 0 ? -angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.1f, 0.0f);
		}

		// thigh
		draw_right_thigh_leg();

		if (_animation == JUMP) glPopMatrix();

		if (_animation == JUMP) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, -0.3f, 0.0f);
			glRotatef(angle < 0 ? -angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.3f, 0.0f);
		} else if (_animation == JUMP) {
			glTranslatef(0.0f, -angle < 0 ? -0.5f + (angle * 0.001f) : -0.5f, 0.0f);
			glRotatef(-angle < 0 ? angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.5f, 0.0f);
		}

		// lower part
		draw_right_lower_leg();

		// foot
		draw_right_foot();

		if (_animation) glPopMatrix();
	}
	/* left leg */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, -0.1f, 0.0f);
			glRotatef(-angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.1f, 0.0f);
		} else if (_animation == JUMP) {
			glTranslatef(0.0f, -0.1f, 0.0f);
			glRotatef(-angle < 0 ? -angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.1f, 0.0f);
		}

		// thigh
		draw_left_thigh_leg();

		if (_animation == JUMP) glPopMatrix();

		if (_animation == JUMP) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, -0.3f, 0.0f);
			glRotatef(-angle < 0 ? angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.3f, 0.0f);
		} else if (_animation == JUMP) {
			glTranslatef(0.0f, -angle < 0 ? -0.5f + (angle * 0.001f) : -0.5f, 0.0f);
			glRotatef(-angle < 0 ? angle / 2 : 0.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.5f, 0.0f);
		}

		// lower part
		draw_left_lower_leg();

		// foot
		draw_left_foot();

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
	float angle = sin((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	/* right arm */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, 0.25f, 0.0f);
			glRotatef(-angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.25f, 0.0f);
		}

		// upper arm
		draw_right_upper_arm();

		// shoulder
		draw_right_shoulder();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, 0.1f, 0.0f);
			glRotatef(-angle < 0 ? -angle / 2 : 0, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_right_forearm();

		if (_animation) glPopMatrix();
	}
	/* left arm */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, 0.25f, 0.0f);
			glRotatef(angle, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.25f, 0.0f);
		}

		// upper arm
		draw_left_upper_arm();

		// shoulder
		draw_left_shoulder();

		if (_animation == WALK || _animation == SPRINT) {
			glTranslatef(0.0f, 0.1f, 0.0f);
			glRotatef(angle < 0 ? angle / 2 : 0, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_left_forearm();

		if (_animation) glPopMatrix();
	}
}

void	Human::draw_head() {
	draw_rect(-0.1,  0.3, -0.1,  0.1,  0.3,  0.1, _skin_color);
	draw_rect(-0.1,  0.5, -0.1,  0.1,  0.5,  0.1, _skin_color);
	draw_rect(-0.1,  0.3, -0.1, -0.1,  0.5,  0.1, _skin_color);
	draw_rect( 0.1,  0.3, -0.1,  0.1,  0.5,  0.1, _skin_color);
	draw_rect(-0.1,  0.3, -0.1,  0.1,  0.5, -0.1, _skin_color);
	draw_rect(-0.1,  0.3,  0.1,  0.1,  0.5,  0.1, _skin_color);
}

void	Human::draw_right_upper_arm()
{
	draw_rect(-0.225,  0.1, -0.05, -0.225,  0.2,  0.05, _skin_color);
	draw_rect(-0.125,  0.1, -0.05, -0.225,  0.2, -0.05, _skin_color);
	draw_rect(-0.125,  0.1,  0.05, -0.225,  0.2,  0.05, _skin_color);
	draw_rect(-0.125,  0.1, -0.05, -0.125,  0.2,  0.05, _skin_color);
}

void	Human::draw_left_upper_arm()
{
	draw_rect( 0.225,  0.1, -0.05,  0.225,  0.2,  0.05, _skin_color);
	draw_rect( 0.125,  0.1, -0.05,  0.225,  0.2, -0.05, _skin_color);
	draw_rect( 0.125,  0.1,  0.05,  0.225,  0.2,  0.05, _skin_color);
	draw_rect( 0.125,  0.1, -0.05,  0.125,  0.2,  0.05, _skin_color);
}

void	Human::draw_right_shoulder()
{
	draw_rect(-0.125,  0.3, -0.05, -0.225,  0.3,  0.05, _body_color);
	draw_rect(-0.225,  0.2, -0.05, -0.225,  0.3,  0.05, _body_color);
	draw_rect(-0.125,  0.2, -0.05, -0.225,  0.3, -0.05, _body_color);
	draw_rect(-0.125,  0.2,  0.05, -0.225,  0.3,  0.05, _body_color);
	draw_rect(-0.125,  0.2, -0.05, -0.125,  0.3,  0.05, _body_color);
}

void	Human::draw_left_shoulder()
{
	draw_rect( 0.125,  0.3, -0.05,  0.225,  0.3,  0.05, _body_color);
	draw_rect( 0.225,  0.2, -0.05,  0.225,  0.3,  0.05, _body_color);
	draw_rect( 0.125,  0.2, -0.05,  0.225,  0.3, -0.05, _body_color);
	draw_rect( 0.125,  0.2,  0.05,  0.225,  0.3,  0.05, _body_color);
	draw_rect( 0.125,  0.2, -0.05,  0.125,  0.3,  0.05, _body_color);
}

void	Human::draw_left_forearm()
{
	draw_rect( 0.125, -0.10, -0.05,  0.225, -0.10,  0.05, _skin_color);
	draw_rect( 0.225, -0.10, -0.05,  0.225,  0.12,  0.05, _skin_color);
	draw_rect( 0.125, -0.10, -0.05,  0.225,  0.12, -0.05, _skin_color);
	draw_rect( 0.125, -0.10,  0.05,  0.225,  0.12,  0.05, _skin_color);
	draw_rect( 0.125, -0.10, -0.05,  0.125,  0.12,  0.05, _skin_color);
}

void	Human::draw_right_forearm()
{
	draw_rect(-0.125, -0.10, -0.05, -0.225, -0.10,  0.05, _skin_color);
	draw_rect(-0.225, -0.10, -0.05, -0.225,  0.12,  0.05, _skin_color);
	draw_rect(-0.125, -0.10, -0.05, -0.225,  0.12, -0.05, _skin_color);
	draw_rect(-0.125, -0.10,  0.05, -0.225,  0.12,  0.05, _skin_color);
	draw_rect(-0.125, -0.10, -0.05, -0.125,  0.12,  0.05, _skin_color);
}

void	Human::draw_right_thigh_leg()
{
	draw_rect(-0.125, -0.1, -0.05, -0.025, -0.1,  0.05, _legs_color);
	draw_rect(-0.125, -0.1, -0.05, -0.125, -0.3,  0.05, _legs_color);
	draw_rect(-0.025, -0.1, -0.05, -0.025, -0.3,  0.05, _legs_color);
	draw_rect(-0.125, -0.1,  0.05, -0.025, -0.3,  0.05, _legs_color);
	draw_rect(-0.125, -0.1, -0.05, -0.025, -0.3, -0.05, _legs_color);
}

void	Human::draw_left_thigh_leg()
{
	draw_rect( 0.125, -0.1, -0.05,  0.025, -0.1,  0.05, _legs_color);
	draw_rect( 0.025, -0.1, -0.05,  0.025, -0.3,  0.05, _legs_color);
	draw_rect( 0.125, -0.1, -0.05,  0.125, -0.3,  0.05, _legs_color);
	draw_rect( 0.125, -0.1,  0.05,  0.025, -0.3,  0.05, _legs_color);
	draw_rect( 0.125, -0.1, -0.05,  0.025, -0.3, -0.05, _legs_color);
}

void	Human::draw_right_lower_leg()
{
	draw_rect(-0.125, -0.29, -0.05, -0.125, -0.45,  0.05, _legs_color);
	draw_rect(-0.025, -0.29, -0.05, -0.025, -0.45,  0.05, _legs_color);
	draw_rect(-0.125, -0.29,  0.05, -0.025, -0.45,  0.05, _legs_color);
	draw_rect(-0.125, -0.29, -0.05, -0.025, -0.45, -0.05, _legs_color);
}

void	Human::draw_left_lower_leg()
{
	draw_rect( 0.025, -0.29, -0.05,  0.025, -0.45,  0.05, _legs_color);
	draw_rect( 0.125, -0.29, -0.05,  0.125, -0.45,  0.05, _legs_color);
	draw_rect( 0.125, -0.29,  0.05,  0.025, -0.45,  0.05, _legs_color);
	draw_rect( 0.125, -0.29, -0.05,  0.025, -0.45, -0.05, _legs_color);
}

void	Human::draw_right_foot()
{
	draw_rect(-0.125, -0.50, -0.05, -0.025, -0.50,  0.05, _foots_color);
	draw_rect(-0.125, -0.50, -0.05, -0.125, -0.45,  0.05, _foots_color);
	draw_rect(-0.025, -0.50, -0.05, -0.025, -0.45,  0.05, _foots_color);
	draw_rect(-0.125, -0.50,  0.05, -0.025, -0.45,  0.05, _foots_color);
	draw_rect(-0.125, -0.50, -0.05, -0.025, -0.45, -0.05, _foots_color);
}

void	Human::draw_left_foot()
{
	draw_rect( 0.125, -0.50, -0.05,  0.025, -0.50,  0.05, _foots_color);
	draw_rect( 0.025, -0.50, -0.05,  0.025, -0.45,  0.05, _foots_color);
	draw_rect( 0.125, -0.50, -0.05,  0.125, -0.45,  0.05, _foots_color);
	draw_rect( 0.125, -0.50,  0.05,  0.025, -0.45,  0.05, _foots_color);
	draw_rect( 0.125, -0.50, -0.05,  0.025, -0.45, -0.05, _foots_color);
}
