#include "Human.hpp"

Human::Human()
{
	_rightHand = new Hand("right");
	_leftHand = new Hand("left");
	_showBody = true;
	_showHead = true;

	_showRightUpperArm = true;
	_showRightForearm = true;
	_showLeftUpperArm = true;
	_showLeftForearm = true;

	_showRightTigh = true;
	_showRightLowerLeg = true;
	_showLeftTigh = true;
	_showLeftLowerLeg = true;
}

Human::~Human()	{delete _rightHand; delete _leftHand;}

void	Human::draw(ModelStack &modelStack, Shaders &shader, bool cube)
{
	float angle = sin((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	if (human.get_animation() == JUMP) {
		float angle = -sin((glfwGetTime() - human.get_animation_frame()) * 5.0f);
		modelStack.push();
		if (angle > 0.0f) modelStack.translate(0.0f, angle * 0.5f, 0.0f);
		else modelStack.translate(0.0f, angle * 0.05f, 0.0f);
	}

	if (_animation == SPRINT) {
		modelStack.push();
		modelStack.translate(0.0f, -0.1f * _size, -0.05f);
		modelStack.rotate(10.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size, 0.05f);
	}

	if (_showBody) draw_body(modelStack, shader);
	if (_showHead) draw_head(modelStack, shader);

	draw_left_arm(modelStack, shader, angle);
	draw_right_arm(modelStack, shader, angle);
	draw_left_arm(modelStack, shader, angle);

	if (_animation == SPRINT) modelStack.pop();

	draw_right_leg(modelStack, shader, angle);
	draw_left_leg(modelStack, shader, angle);

	if (cube) draw_cube(shader, modelStack.current());

	if (human.get_animation() == JUMP) modelStack.pop();
}

void	Human::draw_right_arm(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, 0.25f * _size, 0.0f);
		modelStack.rotate(-angle, 'X');
		modelStack.translate(0.0f, -0.25f * _size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, 0.25f * _size, 0.0f);
		modelStack.rotate(angle < 0.0f ? angle : 0.0f, 'X');
		modelStack.translate(0.0f, -0.25f * _size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, 0.25f * _size, 0.0f);
		modelStack.rotate(-angle * 1.5f, 'X');
		modelStack.translate(0.0f, -0.25f * _size, 0.0f);
	}

	if (_showRightUpperArm) {

		// upper arm
		draw_right_upper_arm(modelStack, shader);

		// shoulder
		draw_right_shoulder(modelStack, shader);
	}

	if (_animation == WALK) {
		modelStack.translate(0.0f, 0.1f * _size, -0.05f);
		modelStack.rotate(-angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, -0.1f * _size, 0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, 0.1f * _size, -0.05f);
		modelStack.rotate(angle < 0.0f ? angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, -0.1f * _size, 0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, 0.1f * _size, -0.05f);
		modelStack.rotate(-60.0f - angle, 'X');
		modelStack.translate(0.0f, -0.1f * _size, 0.05f);
	}

	if (_showRightForearm) {

		// forearm
		draw_right_forearm(modelStack, shader);
	}
	_rightHand->draw(_skin_color, _size, modelStack, shader);

	if (_animation) modelStack.pop();
}

void	Human::draw_left_arm(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, 0.25f * _size, 0.0f);
		modelStack.rotate(angle, 'X');
		modelStack.translate(0.0f, -0.25f * _size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, 0.25f * _size, 0.0f);
		modelStack.rotate(angle < 0.0f ? angle : 0.0f, 'X');
		modelStack.translate(0.0f, -0.25f * _size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, 0.25f * _size, 0.0f);
		modelStack.rotate(angle * 1.5f, 'X');
		modelStack.translate(0.0f, -0.25f * _size, 0.0f);
	}

	if (_showLeftUpperArm) {
		// upper arm
		draw_left_upper_arm(modelStack, shader);

		// shoulder
		draw_left_shoulder(modelStack, shader);
	}

	if (_animation == WALK) {
		modelStack.translate(0.0f, 0.1f * _size, -0.05f);
		modelStack.rotate(angle < 0.0f ? angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, -0.1f * _size, 0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, 0.1f * _size, -0.05f);
		modelStack.rotate(angle < 0.0f ? angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, -0.1f * _size, 0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, 0.1f * _size, -0.05f);
		modelStack.rotate(-60.0f + angle, 'X');
		modelStack.translate(0.0f, -0.1f * _size, 0.05f);
	}

	if (_showLeftForearm) {
		// forearm
		draw_left_forearm(modelStack, shader);
	}
	_leftHand->draw(_skin_color, _size, modelStack, shader);

	if (_animation) modelStack.pop();
}

void	Human::draw_right_leg(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, -0.1f * _size, 0.0f);
		modelStack.rotate(angle, 'X');
		modelStack.translate(0.0f, 0.1f * _size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, -0.1f * _size, 0.0f);
		modelStack.rotate(-angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, -0.1f * _size, 0.0f);
		modelStack.rotate(angle * 2.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size, 0.0f);
	}

	if (_showRightTigh) {
		// thigh
		draw_right_thigh(modelStack, shader);
	}

	if (_animation == JUMP) modelStack.pop();

	if (_animation == JUMP) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, -0.3f * _size, 0.05f);
		modelStack.rotate(angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.3f * _size, -0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, (-angle < 0.0f ? -0.5f + (angle * 0.001f) : -0.5f) * _size, 0.05f);
		modelStack.rotate(-angle < 0.0f ? angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.5f * _size, -0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, -0.3f * _size, 0.05f);
		modelStack.rotate(angle < 0.0f ? -angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.3f * _size, -0.05f);
	}

	if (_showRightLowerLeg) {
		// lower part
		draw_right_lower_leg(modelStack, shader);
		draw_right_foot(modelStack, shader);

	}

	if (_animation) modelStack.pop();
}

void	Human::draw_left_leg(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, -0.1f * _size, 0.0f);
		modelStack.rotate(-angle, 'X');
		modelStack.translate(0.0f, 0.1f * _size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, -0.1f * _size, 0.0f);
		modelStack.rotate(-angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, -0.1f * _size, 0.0f);
		modelStack.rotate(-angle * 2.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size, 0.0f);
	}

	if (_showLeftTigh) {
		// thigh
		draw_left_thigh(modelStack, shader);
	}

	if (_animation == JUMP) modelStack.pop();

	if (_animation == JUMP) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, -0.3f * _size, 0.05f);
		modelStack.rotate(-angle < 0.0f ? angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.3f * _size, -0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, (-angle < 0.0f ? -0.5f + (angle * 0.001f) : -0.5f) * _size, 0.05f);
		modelStack.rotate(-angle < 0.0f ? angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.5f * _size, -0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, -0.3f * _size, 0.05f);
		modelStack.rotate(-angle < 0.0f ? angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.3f * _size, -0.05f);
	}

	if (_showLeftLowerLeg) {
		// lower part
		draw_left_lower_leg(modelStack, shader);
		draw_left_foot(modelStack, shader);

	}

	if (_animation) modelStack.pop();
}

void	Human::draw_head(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.1f,  0.5f * _size, -0.1f}, { 0.1f, 0.5f * _size,  0.1f}, _skin_color, 0.125f, 0.000f, 0.125f, 0.25f,  true, shader, modelStack);
	draw_rect({-0.1f,  0.3f * _size, -0.1f}, { 0.1f, 0.3f * _size,  0.1f}, _skin_color, 0.250f, 0.000f, 0.125f, 0.25f, false, shader, modelStack);
	draw_rect({-0.1f,  0.3f * _size, -0.1f}, {-0.1f, 0.5f * _size,  0.1f}, _skin_color, 0.000f, 0.250f, 0.125f, 0.25f,  true, shader, modelStack);
	draw_rect({ 0.1f,  0.3f * _size, -0.1f}, { 0.1f, 0.5f * _size,  0.1f}, _skin_color, 0.250f, 0.250f, 0.125f, 0.25f, false, shader, modelStack);
	draw_rect({-0.1f,  0.3f * _size,  0.1f}, { 0.1f, 0.5f * _size,  0.1f}, _skin_color, 0.125f, 0.250f, 0.125f, 0.25f,  true, shader, modelStack);
	draw_rect({-0.1f,  0.3f * _size, -0.1f}, { 0.1f, 0.5f * _size, -0.1f}, _skin_color, 0.375f, 0.250f, 0.125f, 0.25f, false, shader, modelStack);

}

void	Human::draw_body(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f,  0.3f * _size, -0.05f}, { 0.125f,  0.3f * _size,  0.05f}, _body_color, 0.3125f, 0.500f, 0.1250f, 0.125f,  true, shader, modelStack);
	draw_rect({-0.125f, -0.1f * _size, -0.05f}, { 0.125f, -0.1f * _size,  0.05f}, _body_color, 0.4375f, 0.500f, 0.1250f, 0.125f, false, shader, modelStack);
	draw_rect({-0.125f, -0.1f * _size, -0.05f}, {-0.125f,  0.3f * _size,  0.05f}, _body_color, 0.2500f, 0.625f, 0.0625f, 0.375f,  true, shader, modelStack);
	draw_rect({ 0.125f, -0.1f * _size, -0.05f}, { 0.125f,  0.3f * _size,  0.05f}, _body_color, 0.4375f, 0.625f, 0.0625f, 0.375f, false, shader, modelStack);
	draw_rect({-0.125f, -0.1f * _size,  0.05f}, { 0.125f,  0.3f * _size,  0.05f}, _body_color, 0.3125f, 0.625f, 0.1250f, 0.375f,  true, shader, modelStack);
	draw_rect({-0.125f, -0.1f * _size, -0.05f}, { 0.125f,  0.3f * _size, -0.05f}, _body_color, 0.5000f, 0.625f, 0.1250f, 0.375f, false, shader, modelStack);
}

void	Human::draw_left_shoulder(ModelStack &modelStack, Shaders &shader)
{
	float	width = (human.get_slim() ? 0.2f : 0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({0.125f,  0.3f * _size, -0.05f}, { width,  0.3f * _size,  0.05f}, _body_color, 0.6875f, 0.500f,  uscale, 0.12500f,  true, shader, modelStack);
	draw_rect({ width,  0.2f * _size, -0.05f}, { width,  0.3f * _size,  0.05f}, _body_color, 0.6250f, 0.625f, 0.0625f, 0.09375f,  true, shader, modelStack);
	draw_rect({0.125f,  0.2f * _size, -0.05f}, {0.125f,  0.3f * _size,  0.05f}, _body_color,    gap1, 0.625f, 0.0625f, 0.09375f, false, shader, modelStack);
	draw_rect({0.125f,  0.2f * _size,  0.05f}, { width,  0.3f * _size,  0.05f}, _body_color, 0.6875f, 0.625f,  uscale, 0.09375f, false, shader, modelStack);
	draw_rect({0.125f,  0.2f * _size, -0.05f}, { width,  0.3f * _size, -0.05f}, _body_color,    gap2, 0.625f,  uscale, 0.09375f,  true, shader, modelStack);
}

void	Human::draw_right_shoulder(ModelStack &modelStack, Shaders &shader)
{
	float	width = (human.get_slim() ? -0.2f : -0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({-0.125f,  0.3f * _size, -0.05f}, {  width,  0.3f * _size,  0.05f}, _body_color, 0.6875f, 0.500f,  uscale, 0.12500f,  true, shader, modelStack);
	draw_rect({  width,  0.2f * _size, -0.05f}, {  width,  0.3f * _size,  0.05f}, _body_color, 0.6250f, 0.625f, 0.0625f, 0.09375f,  true, shader, modelStack);
	draw_rect({-0.125f,  0.2f * _size, -0.05f}, {-0.125f,  0.3f * _size,  0.05f}, _body_color,    gap1, 0.625f, 0.0625f, 0.09375f, false, shader, modelStack);
	draw_rect({-0.125f,  0.2f * _size,  0.05f}, {  width,  0.3f * _size,  0.05f}, _body_color, 0.6875f, 0.625f,  uscale, 0.09375f, false, shader, modelStack);
	draw_rect({-0.125f,  0.2f * _size, -0.05f}, {  width,  0.3f * _size, -0.05f}, _body_color,    gap2, 0.625f,  uscale, 0.09375f,  true, shader, modelStack);
}

void	Human::draw_left_upper_arm(ModelStack &modelStack, Shaders &shader)
{
	float	width = (human.get_slim() ? 0.2f : 0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({0.125f,  0.1f * _size, -0.05f}, { width,  0.1f * _size,  0.05f}, _skin_color,    gap1, 0.50000f,  uscale, 0.12500f, false, shader, modelStack);
	draw_rect({ width,  0.1f * _size, -0.05f}, { width,  0.2f * _size,  0.05f}, _skin_color, 0.6250f, 0.71875f, 0.0625f, 0.12500f,  true, shader, modelStack);
	draw_rect({0.125f,  0.1f * _size, -0.05f}, {0.125f,  0.2f * _size,  0.05f}, _skin_color,    gap1, 0.71875f, 0.0625f, 0.09375f, false, shader, modelStack);
	draw_rect({0.125f,  0.1f * _size,  0.05f}, { width,  0.2f * _size,  0.05f}, _skin_color, 0.6875f, 0.71875f,  uscale, 0.09375f, false, shader, modelStack);
	draw_rect({0.125f,  0.1f * _size, -0.05f}, { width,  0.2f * _size, -0.05f}, _skin_color,    gap2, 0.71875f,  uscale, 0.09375f,  true, shader, modelStack);
}

void	Human::draw_right_upper_arm(ModelStack &modelStack, Shaders &shader)
{
	float	width = (human.get_slim() ? -0.2f : -0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({-0.125f,  0.1f * _size, -0.05f}, {  width,  0.1f * _size,  0.05f}, _skin_color,    gap1, 0.50000f,  uscale, 0.12500f, false, shader, modelStack);
	draw_rect({  width,  0.1f * _size, -0.05f}, {  width,  0.2f * _size,  0.05f}, _skin_color, 0.6250f, 0.71875f, 0.0625f, 0.12500f,  true, shader, modelStack);
	draw_rect({-0.125f,  0.1f * _size, -0.05f}, {-0.125f,  0.2f * _size,  0.05f}, _skin_color,    gap1, 0.71875f, 0.0625f, 0.09375f, false, shader, modelStack);
	draw_rect({-0.125f,  0.1f * _size,  0.05f}, {  width,  0.2f * _size,  0.05f}, _skin_color, 0.6875f, 0.71875f,  uscale, 0.09375f, false, shader, modelStack);
	draw_rect({-0.125f,  0.1f * _size, -0.05f}, {  width,  0.2f * _size, -0.05f}, _skin_color,    gap2, 0.71875f,  uscale, 0.09375f,  true, shader, modelStack);
}

void	Human::draw_left_forearm(ModelStack &modelStack, Shaders &shader)
{
	float	width = (human.get_slim() ? 0.2f : 0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({0.125f,  0.10f * _size, -0.05f}, {  width,  0.10f * _size,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, modelStack);
	draw_rect({0.125f, -0.10f * _size, -0.05f}, {  width, -0.10f * _size,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, modelStack);
	draw_rect({ width, -0.10f * _size, -0.05f}, {  width,  0.10f * _size,  0.05f}, _skin_color, 0.6250f, 0.8125f, 0.0625f, 0.1875f,  true, shader, modelStack);
	draw_rect({0.125f, -0.10f * _size, -0.05f}, { 0.125f,  0.10f * _size,  0.05f}, _skin_color,    gap1, 0.8125f, 0.0625f, 0.1875f, false, shader, modelStack);
	draw_rect({0.125f, -0.10f * _size,  0.05f}, {  width,  0.10f * _size,  0.05f}, _skin_color, 0.6875f, 0.8125f,  uscale, 0.1875f, false, shader, modelStack);
	draw_rect({0.125f, -0.10f * _size, -0.05f}, {  width,  0.10f * _size, -0.05f}, _skin_color,    gap2, 0.8125f,  uscale, 0.1875f,  true, shader, modelStack);
}

void	Human::draw_right_forearm(ModelStack &modelStack, Shaders &shader)
{
	float	width = (human.get_slim() ? -0.2f : -0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({-0.125f,  0.10f * _size, -0.05f}, {  width,  0.10f * _size,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, modelStack);
	draw_rect({-0.125f, -0.10f * _size, -0.05f}, {  width, -0.10f * _size,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, modelStack);
	draw_rect({  width, -0.10f * _size, -0.05f}, {  width,  0.10f * _size,  0.05f}, _skin_color, 0.6250f, 0.8125f, 0.0625f, 0.1875f,  true, shader, modelStack);
	draw_rect({-0.125f, -0.10f * _size, -0.05f}, {-0.125f,  0.10f * _size,  0.05f}, _skin_color,    gap1, 0.8125f, 0.0625f, 0.1875f, false, shader, modelStack);
	draw_rect({-0.125f, -0.10f * _size,  0.05f}, {  width,  0.10f * _size,  0.05f}, _skin_color, 0.6875f, 0.8125f,  uscale, 0.1875f, false, shader, modelStack);
	draw_rect({-0.125f, -0.10f * _size, -0.05f}, {  width,  0.10f * _size, -0.05f}, _skin_color,    gap2, 0.8125f,  uscale, 0.1875f,  true, shader, modelStack);
}

void	Human::draw_left_thigh(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.02499f, -0.1f * _size,  0.05f}, {0.12499f, -0.1f * _size, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f,  true, shader, modelStack);
	draw_rect({0.02499f, -0.3f * _size,  0.05f}, {0.12499f, -0.3f * _size, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f, false, shader, modelStack);
	draw_rect({0.12499f, -0.3f * _size,  0.05f}, {0.12499f, -0.1f * _size, -0.05f}, _legs_color, 0.0000f, 0.625f, 0.0625f, 0.1875f,  true, shader, modelStack);
	draw_rect({0.02499f, -0.3f * _size,  0.05f}, {0.02499f, -0.1f * _size, -0.05f}, _legs_color, 0.1250f, 0.625f, 0.0625f, 0.1875f, false, shader, modelStack);
	draw_rect({0.02499f, -0.3f * _size,  0.05f}, {0.12499f, -0.1f * _size,  0.05f}, _legs_color, 0.0625f, 0.625f, 0.0625f, 0.1875f,  true, shader, modelStack);
	draw_rect({0.02499f, -0.3f * _size, -0.05f}, {0.12499f, -0.1f * _size, -0.05f}, _legs_color, 0.1875f, 0.625f, 0.0625f, 0.1875f, false, shader, modelStack);
}

void	Human::draw_right_thigh(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.02499f, -0.1f * _size,  0.05f}, {-0.12499f, -0.1f * _size, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f,  true, shader, modelStack);
	draw_rect({-0.02499f, -0.3f * _size,  0.05f}, {-0.12499f, -0.3f * _size, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f, false, shader, modelStack);
	draw_rect({-0.12499f, -0.3f * _size,  0.05f}, {-0.12499f, -0.1f * _size, -0.05f}, _legs_color, 0.0000f, 0.625f, 0.0625f, 0.1875f,  true, shader, modelStack);
	draw_rect({-0.02499f, -0.3f * _size,  0.05f}, {-0.02499f, -0.1f * _size, -0.05f}, _legs_color, 0.1250f, 0.625f, 0.0625f, 0.1875f, false, shader, modelStack);
	draw_rect({-0.02499f, -0.3f * _size,  0.05f}, {-0.12499f, -0.1f * _size,  0.05f}, _legs_color, 0.0625f, 0.625f, 0.0625f, 0.1875f,  true, shader, modelStack);
	draw_rect({-0.02499f, -0.3f * _size, -0.05f}, {-0.12499f, -0.1f * _size, -0.05f}, _legs_color, 0.1875f, 0.625f, 0.0625f, 0.1875f, false, shader, modelStack);
}

void	Human::draw_left_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.025f, -0.30f * _size,  0.05f}, {0.125f, -0.30f * _size, -0.05f}, _legs_color, 0.0625f, 0.5000f, 0.0625f, 0.125000f,  true, shader, modelStack);
	draw_rect({0.125f, -0.45f * _size,  0.05f}, {0.125f, -0.30f * _size, -0.05f}, _legs_color, 0.0000f, 0.8125f, 0.0625f, 0.140625f,  true, shader, modelStack);
	draw_rect({0.025f, -0.45f * _size,  0.05f}, {0.025f, -0.30f * _size, -0.05f}, _legs_color, 0.1250f, 0.8125f, 0.0625f, 0.140625f, false, shader, modelStack);
	draw_rect({0.025f, -0.45f * _size,  0.05f}, {0.125f, -0.30f * _size,  0.05f}, _legs_color, 0.0625f, 0.8125f, 0.0625f, 0.140625f,  true, shader, modelStack);
	draw_rect({0.025f, -0.45f * _size, -0.05f}, {0.125f, -0.30f * _size, -0.05f}, _legs_color, 0.1875f, 0.8125f, 0.0625f, 0.140625f, false, shader, modelStack);
}

void	Human::draw_right_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.025f, -0.30f * _size,  0.05f}, {-0.125f, -0.30f * _size, -0.05f}, _legs_color, 0.0625f, 0.5000f, 0.0625f, 0.125000f,  true, shader, modelStack);
	draw_rect({-0.125f, -0.45f * _size,  0.05f}, {-0.125f, -0.30f * _size, -0.05f}, _legs_color, 0.0000f, 0.8125f, 0.0625f, 0.140625f,  true, shader, modelStack);
	draw_rect({-0.025f, -0.45f * _size,  0.05f}, {-0.025f, -0.30f * _size, -0.05f}, _legs_color, 0.1250f, 0.8125f, 0.0625f, 0.140625f, false, shader, modelStack);
	draw_rect({-0.025f, -0.45f * _size,  0.05f}, {-0.125f, -0.30f * _size,  0.05f}, _legs_color, 0.0625f, 0.8125f, 0.0625f, 0.140625f,  true, shader, modelStack);
	draw_rect({-0.025f, -0.45f * _size, -0.05f}, {-0.125f, -0.30f * _size, -0.05f}, _legs_color, 0.1875f, 0.8125f, 0.0625f, 0.140625f, false, shader, modelStack);
}

void	Human::draw_left_foot(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.025f, -0.50f * _size,  0.05f}, {0.125f, -0.50f * _size, -0.05f}, _foots_color, 0.1250f, 0.500000f, 0.0625f, 0.125000f, false, shader, modelStack);
	draw_rect({0.125f, -0.45f * _size,  0.05f}, {0.125f, -0.50f * _size, -0.05f}, _foots_color, 0.0000f, 0.953125f, 0.0625f, 0.046875f,  true, shader, modelStack);
	draw_rect({0.025f, -0.45f * _size,  0.05f}, {0.025f, -0.50f * _size, -0.05f}, _foots_color, 0.1250f, 0.953125f, 0.0625f, 0.046875f, false, shader, modelStack);
	draw_rect({0.025f, -0.45f * _size,  0.05f}, {0.125f, -0.50f * _size,  0.05f}, _foots_color, 0.0625f, 0.953125f, 0.0625f, 0.046875f,  true, shader, modelStack);
	draw_rect({0.025f, -0.45f * _size, -0.05f}, {0.125f, -0.50f * _size, -0.05f}, _foots_color, 0.1875f, 0.953125f, 0.0625f, 0.046875f, false, shader, modelStack);
}

void	Human::draw_right_foot(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.025f, -0.50f * _size,  0.05f}, {-0.125f, -0.50f * _size, -0.05f}, _foots_color, 0.1250f, 0.500000f, 0.0625f, 0.125000f, false, shader, modelStack);
	draw_rect({-0.125f, -0.45f * _size,  0.05f}, {-0.125f, -0.50f * _size, -0.05f}, _foots_color, 0.0000f, 0.953125f, 0.0625f, 0.046875f,  true, shader, modelStack);
	draw_rect({-0.025f, -0.45f * _size,  0.05f}, {-0.025f, -0.50f * _size, -0.05f}, _foots_color, 0.1250f, 0.953125f, 0.0625f, 0.046875f, false, shader, modelStack);
	draw_rect({-0.025f, -0.45f * _size,  0.05f}, {-0.125f, -0.50f * _size,  0.05f}, _foots_color, 0.0625f, 0.953125f, 0.0625f, 0.046875f,  true, shader, modelStack);
	draw_rect({-0.025f, -0.45f * _size, -0.05f}, {-0.125f, -0.50f * _size, -0.05f}, _foots_color, 0.1875f, 0.953125f, 0.0625f, 0.046875f, false, shader, modelStack);
}
