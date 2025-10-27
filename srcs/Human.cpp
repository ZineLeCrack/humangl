#include "Human.hpp"

void	Human::draw(ModelStack &modelStack, Shaders &shader)
{
	draw_head(modelStack, shader);
	draw_body(modelStack, shader);
	draw_arms(modelStack, shader);
	draw_legs(modelStack, shader);
}

void	Human::draw_legs(ModelStack &modelStack, Shaders &shader)
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
		draw_right_thigh(modelStack, shader);

		if (_animation == JUMP) modelStack.pop();

		if (_animation == JUMP) modelStack.push();

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
		draw_right_lower_leg(modelStack, shader);

		// foot
		draw_right_foot(modelStack, shader);

		if (_animation) modelStack.pop();
	}
	/* left leg */
	{
		if (_animation) modelStack.push();

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
		draw_left_thigh(modelStack, shader);

		if (_animation == JUMP) modelStack.pop();

		if (_animation == JUMP) modelStack.push();

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
		draw_left_lower_leg(modelStack, shader);

		// foot
		draw_left_foot(modelStack, shader);

		if (_animation) modelStack.pop();
	}
}

void	Human::draw_body(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f, -0.1f, -0.05f}, {0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f, -0.05f}, {0.125f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f, -0.05f}, {0.125f, -0.1f, -0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f,  0.05f}, {0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f, -0.05f}, {0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({ 0.125f,  0.3f, -0.05f}, {0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
}

void	Human::draw_arms(ModelStack &modelStack, Shaders &shader)
{
	float angle = sin((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	/* right arm */
	{
		if (_animation) modelStack.push();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.25f, 0.0f);
			modelStack.rotate(-angle, 'X');
			modelStack.translate(0.0f, -0.25f, 0.0f);
		}

		// upper arm
		draw_right_upper_arm(modelStack, shader);

		// shoulder
		draw_right_shoulder(modelStack, shader);

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.1f, 0.0f);
			modelStack.rotate(-angle < 0 ? -angle / 2 : 0, 'X');
			modelStack.translate(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_right_forearm(modelStack, shader);

		if (_animation) modelStack.pop();
	}
	/* left arm */
	{
		if (_animation) modelStack.push();

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.25f, 0.0f);
			modelStack.rotate(angle, 'X');
			modelStack.translate(0.0f, -0.25f, 0.0f);
		}

		// upper arm
		draw_left_upper_arm(modelStack, shader);

		// shoulder
		draw_left_shoulder(modelStack, shader);

		if (_animation == WALK || _animation == SPRINT) {
			modelStack.translate(0.0f, 0.1f, 0.0f);
			modelStack.rotate(angle < 0 ? angle / 2 : 0, 'X');
			modelStack.translate(0.0f, -0.1f, 0.0f);
		}

		// forearm
		draw_left_forearm(modelStack, shader);

		if (_animation) modelStack.pop();
	}
}

void	Human::draw_head(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.1f,  0.3f, -0.1f}, {0.1f, 0.3f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.5f, -0.1f}, {0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.3f, -0.1f}, {0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({ 0.1f,  0.3f, -0.1f}, {0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.3f, -0.1f}, {0.1f, 0.5f, -0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.3f,  0.1f}, {0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
}

void	Human::draw_right_upper_arm(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.225f,  0.1f, -0.05f}, {-0.225f,  0.2f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({-0.125f,  0.1f, -0.05f}, {-0.225f,  0.2f, -0.05f}, _skin_color, shader, modelStack);
	draw_rect({-0.125f,  0.1f,  0.05f}, {-0.225f,  0.2f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({-0.125f,  0.1f, -0.05f}, {-0.125f,  0.2f,  0.05f}, _skin_color, shader, modelStack);
}

void	Human::draw_left_upper_arm(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.225f,  0.1f, -0.05f},  {0.225,  0.2f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({0.125f,  0.1f, -0.05f},  {0.225,  0.2f, -0.05f}, _skin_color, shader, modelStack);
	draw_rect({0.125f,  0.1f,  0.05f},  {0.225,  0.2f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({0.125f,  0.1f, -0.05f},  {0.125,  0.2f,  0.05f}, _skin_color, shader, modelStack);
}

void	Human::draw_right_shoulder(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f,  0.3f, -0.05f}, {-0.225f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.225f,  0.2f, -0.05f}, {-0.225f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.2f, -0.05f}, {-0.225f,  0.3f, -0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.2f,  0.05f}, {-0.225f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.2f, -0.05f}, {-0.125f,  0.3f,  0.05f}, _body_color, shader, modelStack);
}

void	Human::draw_left_shoulder(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.125f,  0.3f, -0.05f}, {0.225f,  0.3f, 0.05f}, _body_color, shader, modelStack);
	draw_rect({0.225f,  0.2f, -0.05f}, {0.225f,  0.3f, 0.05f}, _body_color, shader, modelStack);
	draw_rect({0.125f,  0.2f, -0.05f}, {0.225f,  0.3f, 0.05f}, _body_color, shader, modelStack);
	draw_rect({0.125f,  0.2f,  0.05f}, {0.225f,  0.3f, 0.05f}, _body_color, shader, modelStack);
	draw_rect({0.125f,  0.2f, -0.05f}, {0.125f,  0.3f, 0.05f}, _body_color, shader, modelStack);
}

void	Human::draw_left_forearm(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.125f, -0.10f, -0.05f}, { 0.225f, -0.10f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({0.225f, -0.10f, -0.05f}, { 0.225f,  0.12f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({0.125f, -0.10f, -0.05f}, { 0.225f,  0.12f, -0.05f}, _skin_color, shader, modelStack);
	draw_rect({0.125f, -0.10f,  0.05f}, { 0.225f,  0.12f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({0.125f, -0.10f, -0.05f}, { 0.125f,  0.12f,  0.05f}, _skin_color, shader, modelStack);
}

void	Human::draw_right_forearm(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f, -0.10f, -0.05f}, { -0.225f, -0.10f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({-0.225f, -0.10f, -0.05f}, { -0.225f,  0.12f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({-0.125f, -0.10f, -0.05f}, { -0.225f,  0.12f, -0.05f}, _skin_color, shader, modelStack);
	draw_rect({-0.125f, -0.10f,  0.05f}, { -0.225f,  0.12f,  0.05f}, _skin_color, shader, modelStack);
	draw_rect({-0.125f, -0.10f, -0.05f}, { -0.125f,  0.12f,  0.05f}, _skin_color, shader, modelStack);
}

void	Human::draw_right_thigh(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f, -0.1f, -0.05f}, {-0.025f, -0.1f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.1f, -0.05f}, {-0.125f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.025f, -0.1f, -0.05f}, {-0.025f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.1f,  0.05f}, {-0.025f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.1f, -0.05f}, {-0.025f, -0.3f, -0.05f}, _legs_color, shader, modelStack);
}

void	Human::draw_left_thigh(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.125f, -0.1f, -0.05f}, {0.025f, -0.1f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.025f, -0.1f, -0.05f}, {0.025f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.125f, -0.1f, -0.05f}, {0.125f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.125f, -0.1f,  0.05f}, {0.025f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.125f, -0.1f, -0.05f}, {0.025f, -0.3f, -0.05f}, _legs_color, shader, modelStack);
}

void	Human::draw_right_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f, -0.29f, -0.05f}, {-0.125f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.025f, -0.29f, -0.05f}, {-0.025f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.29f,  0.05f}, {-0.025f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.29f, -0.05f}, {-0.025f, -0.45f, -0.05f}, _legs_color, shader, modelStack);
}

void	Human::draw_left_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.025f, -0.29f, -0.05f}, {0.025f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.125f, -0.29f, -0.05f}, {0.125f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.125f, -0.29f,  0.05f}, {0.025f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.125f, -0.29f, -0.05f}, {0.025f, -0.45f, -0.05f}, _legs_color, shader, modelStack);
}

void	Human::draw_right_foot(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f, -0.50f, -0.05f}, {-0.025f, -0.50f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({-0.125f, -0.50f, -0.05f}, {-0.125f, -0.45f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({-0.025f, -0.50f, -0.05f}, {-0.025f, -0.45f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({-0.125f, -0.50f,  0.05f}, {-0.025f, -0.45f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({-0.125f, -0.50f, -0.05f}, {-0.025f, -0.45f, -0.05f}, _foots_color, shader, modelStack);
}

void	Human::draw_left_foot(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.125f, -0.50f, -0.05f}, {0.025f, -0.50f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({0.025f, -0.50f, -0.05f}, {0.025f, -0.45f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({0.125f, -0.50f, -0.05f}, {0.125f, -0.45f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({0.125f, -0.50f,  0.05f}, {0.025f, -0.45f,  0.05f}, _foots_color, shader, modelStack);
	draw_rect({0.125f, -0.50f, -0.05f}, {0.025f, -0.45f, -0.05f}, _foots_color, shader, modelStack);
}
