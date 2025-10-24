#include "Human.hpp"

void	Human::draw(ModelStack &modelStack)
{
	draw_legs(modelStack);
	draw_body(modelStack);
	draw_arms(modelStack);
	draw_head(modelStack);
}

void	Human::draw_legs(ModelStack &modelStack)
{
	float angle = sin((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	/* right leg */
	{
		if (_animation) modelStack.push();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, -0.1f, 0.0f);
			modelStack.rotate(angle, 'X');
			modelStack.translate(0.0f, 0.1f, 0.0f);
		} else if (_animation == JUMP) {
			modelStack.translate(0.0f, -0.1f, 0.0f);
			modelStack.rotate(-angle < 0 ? -angle / 2 : 0.0f, 'X');
			modelStack.translate(0.0f, 0.1f, 0.0f);
		}

		// thigh
		draw_right_thigh_leg(modelStack);

		if (_animation == JUMP) glPopMatrix();

		if (_animation == JUMP) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, -0.3f, 0.0f);
			modelStack.rotate(angle < 0 ? -angle / 2 : 0.0f, 'X');
			modelStack.translate(0.0f, 0.3f, 0.0f);
		} else if (_animation == JUMP) {
			modelStack.translate(0.0f, -angle < 0 ? -0.5f + (angle * 0.001f) : -0.5f, 0.0f);
			modelStack.rotate(-angle < 0 ? angle / 2 : 0.0f, 'X');
			modelStack.translate(0.0f, 0.5f, 0.0f);
		}

		// lower part
		draw_right_lower_leg(modelStack);

		// foot
		draw_right_foot(modelStack);

		if (_animation) glPopMatrix();
	}
	/* left leg */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, -0.1f, 0.0f);
			modelStack.rotate(-angle, 'X');
			modelStack.translate(0.0f, 0.1f, 0.0f);
		} else if (_animation == JUMP) {
			modelStack.translate(0.0f, -0.1f, 0.0f);
			modelStack.rotate(-angle < 0 ? -angle / 2 : 0.0f, 'X');
			modelStack.translate(0.0f, 0.1f, 0.0f);
		}

		// thigh
		draw_left_thigh_leg(modelStack);

		if (_animation == JUMP) glPopMatrix();

		if (_animation == JUMP) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, -0.3f, 0.0f);
			modelStack.rotate(-angle < 0 ? angle / 2 : 0.0f, 'X');
			modelStack.translate(0.0f, 0.3f, 0.0f);
		} else if (_animation == JUMP) {
			modelStack.translate(0.0f, -angle < 0 ? -0.5f + (angle * 0.001f) : -0.5f, 0.0f);
			modelStack.rotate(-angle < 0 ? angle / 2 : 0.0f, 'X');
			modelStack.translate(0.0f, 0.5f, 0.0f);
		}

		// lower part
		draw_left_lower_leg(modelStack);

		// foot
		draw_left_foot(modelStack);

		if (_animation) glPopMatrix();
	}
}

void	Human::draw_body(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.125, -0.1, -0.05,  0.125, -0.1,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05,  0.125,  0.3,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05,  0.125, -0.1, -0.05, _body_color);
	draw_rect(-0.125,  0.3,  0.05,  0.125, -0.1,  0.05, _body_color);
	draw_rect(-0.125,  0.3, -0.05, -0.125, -0.1,  0.05, _body_color);
	draw_rect( 0.125,  0.3, -0.05,  0.125, -0.1,  0.05, _body_color);
}

void	Human::draw_arms(ModelStack &modelStack)
{
	float angle = sin((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	/* right arm */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.25f, 0.0f);
			modelStack.rotate(-angle, 'X');
			modelStack.translate(0.0f, -0.25f, 0.0f);
		}

		// upper arm
		draw_right_upper_arm(modelStack);

		// shoulder
		draw_right_shoulder(modelStack);

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.1f, 0.0f);
			modelStack.rotate(-angle < 0 ? -angle / 2 : 0, 'X');
			modelStack.translate(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_right_forearm(modelStack);

		if (_animation) glPopMatrix();
	}
	/* left arm */
	{
		if (_animation) glPushMatrix();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.25f, 0.0f);
			modelStack.rotate(angle, 'X');
			modelStack.translate(0.0f, -0.25f, 0.0f);
		}

		// upper arm
		draw_left_upper_arm(modelStack);

		// shoulder
		draw_left_shoulder(modelStack);

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.1f, 0.0f);
			modelStack.rotate(angle < 0 ? angle / 2 : 0, 'X');
			modelStack.translate(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_left_forearm(modelStack);

		if (_animation) glPopMatrix();
	}
}

void	Human::draw_head(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.1,  0.3, -0.1,  0.1,  0.3,  0.1, _head_color);
	draw_rect(-0.1,  0.5, -0.1,  0.1,  0.5,  0.1, _head_color);
	draw_rect(-0.1,  0.3, -0.1, -0.1,  0.5,  0.1, _head_color);
	draw_rect( 0.1,  0.3, -0.1,  0.1,  0.5,  0.1, _head_color);
	draw_rect(-0.1,  0.3, -0.1,  0.1,  0.5, -0.1, _head_color);
	draw_rect(-0.1,  0.3,  0.1,  0.1,  0.5,  0.1, _head_color);
}

void	Human::draw_right_upper_arm(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.225,  0.1, -0.05, -0.225,  0.2,  0.05, _arms_color);
	draw_rect(-0.125,  0.1, -0.05, -0.225,  0.2, -0.05, _arms_color);
	draw_rect(-0.125,  0.1,  0.05, -0.225,  0.2,  0.05, _arms_color);
	draw_rect(-0.125,  0.1, -0.05, -0.125,  0.2,  0.05, _arms_color);
}

void	Human::draw_left_upper_arm(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect( 0.225,  0.1, -0.05,  0.225,  0.2,  0.05, _arms_color);
	draw_rect( 0.125,  0.1, -0.05,  0.225,  0.2, -0.05, _arms_color);
	draw_rect( 0.125,  0.1,  0.05,  0.225,  0.2,  0.05, _arms_color);
	draw_rect( 0.125,  0.1, -0.05,  0.125,  0.2,  0.05, _arms_color);
}

void	Human::draw_right_shoulder(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.125,  0.3, -0.05, -0.225,  0.3,  0.05, _body_color);
	draw_rect(-0.225,  0.2, -0.05, -0.225,  0.3,  0.05, _body_color);
	draw_rect(-0.125,  0.2, -0.05, -0.225,  0.3, -0.05, _body_color);
	draw_rect(-0.125,  0.2,  0.05, -0.225,  0.3,  0.05, _body_color);
	draw_rect(-0.125,  0.2, -0.05, -0.125,  0.3,  0.05, _body_color);
}

void	Human::draw_left_shoulder(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect( 0.125,  0.3, -0.05,  0.225,  0.3,  0.05, _body_color);
	draw_rect( 0.225,  0.2, -0.05,  0.225,  0.3,  0.05, _body_color);
	draw_rect( 0.125,  0.2, -0.05,  0.225,  0.3, -0.05, _body_color);
	draw_rect( 0.125,  0.2,  0.05,  0.225,  0.3,  0.05, _body_color);
	draw_rect( 0.125,  0.2, -0.05,  0.125,  0.3,  0.05, _body_color);
}

void	Human::draw_left_forearm(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect( 0.125, -0.10, -0.05,  0.225, -0.10,  0.05, _arms_color);
	draw_rect( 0.225, -0.10, -0.05,  0.225,  0.12,  0.05, _arms_color);
	draw_rect( 0.125, -0.10, -0.05,  0.225,  0.12, -0.05, _arms_color);
	draw_rect( 0.125, -0.10,  0.05,  0.225,  0.12,  0.05, _arms_color);
	draw_rect( 0.125, -0.10, -0.05,  0.125,  0.12,  0.05, _arms_color);
}

void	Human::draw_right_forearm(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.125, -0.10, -0.05, -0.225, -0.10,  0.05, _arms_color);
	draw_rect(-0.225, -0.10, -0.05, -0.225,  0.12,  0.05, _arms_color);
	draw_rect(-0.125, -0.10, -0.05, -0.225,  0.12, -0.05, _arms_color);
	draw_rect(-0.125, -0.10,  0.05, -0.225,  0.12,  0.05, _arms_color);
	draw_rect(-0.125, -0.10, -0.05, -0.125,  0.12,  0.05, _arms_color);
}

void	Human::draw_right_thigh_leg(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.125, -0.1, -0.05, -0.025, -0.1,  0.05, _legs_color);
	draw_rect(-0.125, -0.1, -0.05, -0.125, -0.3,  0.05, _legs_color);
	draw_rect(-0.025, -0.1, -0.05, -0.025, -0.3,  0.05, _legs_color);
	draw_rect(-0.125, -0.1,  0.05, -0.025, -0.3,  0.05, _legs_color);
	draw_rect(-0.125, -0.1, -0.05, -0.025, -0.3, -0.05, _legs_color);
}

void	Human::draw_left_thigh_leg(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect( 0.125, -0.1, -0.05,  0.025, -0.1,  0.05, _legs_color);
	draw_rect( 0.025, -0.1, -0.05,  0.025, -0.3,  0.05, _legs_color);
	draw_rect( 0.125, -0.1, -0.05,  0.125, -0.3,  0.05, _legs_color);
	draw_rect( 0.125, -0.1,  0.05,  0.025, -0.3,  0.05, _legs_color);
	draw_rect( 0.125, -0.1, -0.05,  0.025, -0.3, -0.05, _legs_color);
}

void	Human::draw_right_lower_leg(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.125, -0.29, -0.05, -0.125, -0.45,  0.05, _legs_color);
	draw_rect(-0.025, -0.29, -0.05, -0.025, -0.45,  0.05, _legs_color);
	draw_rect(-0.125, -0.29,  0.05, -0.025, -0.45,  0.05, _legs_color);
	draw_rect(-0.125, -0.29, -0.05, -0.025, -0.45, -0.05, _legs_color);
}

void	Human::draw_left_lower_leg(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect( 0.025, -0.29, -0.05,  0.025, -0.45,  0.05, _legs_color);
	draw_rect( 0.125, -0.29, -0.05,  0.125, -0.45,  0.05, _legs_color);
	draw_rect( 0.125, -0.29,  0.05,  0.025, -0.45,  0.05, _legs_color);
	draw_rect( 0.125, -0.29, -0.05,  0.025, -0.45, -0.05, _legs_color);
}

void	Human::draw_right_foot(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect(-0.125, -0.50, -0.05, -0.025, -0.50,  0.05, _foots_color);
	draw_rect(-0.125, -0.50, -0.05, -0.125, -0.45,  0.05, _foots_color);
	draw_rect(-0.025, -0.50, -0.05, -0.025, -0.45,  0.05, _foots_color);
	draw_rect(-0.125, -0.50,  0.05, -0.025, -0.45,  0.05, _foots_color);
	draw_rect(-0.125, -0.50, -0.05, -0.025, -0.45, -0.05, _foots_color);
}

void	Human::draw_left_foot(ModelStack &modelStack)
{
	(void)modelStack;
	draw_rect( 0.125, -0.50, -0.05,  0.025, -0.50,  0.05, _foots_color);
	draw_rect( 0.025, -0.50, -0.05,  0.025, -0.45,  0.05, _foots_color);
	draw_rect( 0.125, -0.50, -0.05,  0.125, -0.45,  0.05, _foots_color);
	draw_rect( 0.125, -0.50,  0.05,  0.025, -0.45,  0.05, _foots_color);
	draw_rect( 0.125, -0.50, -0.05,  0.025, -0.45, -0.05, _foots_color);
}
