#include "Human.hpp"

Human::Human()
{
	_rightHand = new Hand("right");
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

	_showRightFoot = true;
	_showLeftFoot = true;
}

Human::~Human()	{delete _rightHand;}

void	Human::draw(ModelStack &modelStack, Shaders &shader)
{
	float angle = sin((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	if (_showHead) draw_head(modelStack, shader);
	if (_showBody) draw_body(modelStack, shader);

	draw_left_arm(modelStack, shader, angle);
	draw_right_arm(modelStack, shader, angle);

	draw_right_leg(modelStack, shader, angle);
	draw_left_leg(modelStack, shader, angle);
}

void	Human::draw_head(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.1f,  0.3f, -0.1f}, { 0.1f, 0.3f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.5f, -0.1f}, { 0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.3f, -0.1f}, {-0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({ 0.1f,  0.3f, -0.1f}, { 0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.3f, -0.1f}, { 0.1f, 0.5f, -0.1f}, _skin_color, shader, modelStack);
	draw_rect({-0.1f,  0.3f,  0.1f}, { 0.1f, 0.5f,  0.1f}, _skin_color, shader, modelStack);
}

void	Human::draw_body(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f, -0.1f, -0.05f}, { 0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f, -0.05f}, { 0.125f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f, -0.05f}, { 0.125f, -0.1f, -0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f,  0.05f}, { 0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({-0.125f,  0.3f, -0.05f}, {-0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({ 0.125f,  0.3f, -0.05f}, { 0.125f, -0.1f,  0.05f}, _body_color, shader, modelStack);
}

void	Human::draw_right_arm(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK || _animation == SPRINT) {
		modelStack.translate(0.0f, 0.25f, 0.0f);
		modelStack.rotate(-angle, 'X');
		modelStack.translate(0.0f, -0.25f, 0.0f);
	}

	if (_showRightUpperArm) {

		// upper arm
		draw_right_upper_arm(modelStack, shader);
		
		// shoulder
		draw_right_shoulder(modelStack, shader);
	}

	if (_animation == WALK || _animation == SPRINT) {
		modelStack.translate(0.0f, 0.1f, 0.0f);
		modelStack.rotate(-angle < 0 ? -angle / 2 : 0, 'X');
		modelStack.translate(0.0f, -0.1f, 0.0f);
	}

	if (_showRightForearm) {

		// forearm
		draw_right_forearm(modelStack, shader);
	}
	_rightHand->draw(_body_color, modelStack, shader);

	if (_animation) modelStack.pop();
}

void	Human::draw_left_arm(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK || _animation == SPRINT) {
		modelStack.translate(0.0f, 0.25f, 0.0f);
		modelStack.rotate(angle, 'X');
		modelStack.translate(0.0f, -0.25f, 0.0f);
	}

	if (_showLeftUpperArm) {
		// upper arm
		draw_left_upper_arm(modelStack, shader);
	
		// shoulder
		draw_left_shoulder(modelStack, shader);
	}

	if (_animation == WALK || _animation == SPRINT) {
		modelStack.translate(0.0f, 0.1f, 0.0f);
		modelStack.rotate(angle < 0 ? angle / 2 : 0, 'X');
		modelStack.translate(0.0f, -0.1f, 0.0f);
	}

	if (_showLeftForearm) {
		// forearm
		draw_left_forearm(modelStack, shader);
	}

	if (_animation) modelStack.pop();
}

void	Human::draw_right_leg(ModelStack &modelStack, Shaders &shader, float angle)
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

	if (_showRightTigh) {
		// thigh
		draw_right_thigh(modelStack, shader);
	}

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

	if (_showRightLowerLeg) {
		// lower part
		draw_right_lower_leg(modelStack, shader);
	}

	if (_showRightFoot) {
		// foot
		draw_right_foot(modelStack, shader);
	}

	if (_animation) modelStack.pop();
}

void	Human::draw_left_leg(ModelStack &modelStack, Shaders &shader, float angle)
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

	if (_showLeftTigh) {
		// thigh
		draw_left_thigh(modelStack, shader);
	}

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

	if (_showLeftLowerLeg) {
		// lower part
		draw_left_lower_leg(modelStack, shader);
	}

	if (_showLeftFoot) {
		// foot
		draw_left_foot(modelStack, shader);
	}

	if (_animation) modelStack.pop();
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
	draw_rect({0.125f,  0.3f, -0.05f}, {0.225f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({0.225f,  0.2f, -0.05f}, {0.225f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({0.125f,  0.2f, -0.05f}, {0.225f,  0.3f, -0.05f}, _body_color, shader, modelStack);
	draw_rect({0.125f,  0.2f,  0.05f}, {0.225f,  0.3f,  0.05f}, _body_color, shader, modelStack);
	draw_rect({0.125f,  0.2f, -0.05f}, {0.125f,  0.3f,  0.05f}, _body_color, shader, modelStack);
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
	draw_rect({-0.12499f, -0.1f, -0.05f}, {-0.02499f, -0.1f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.12499f, -0.1f, -0.05f}, {-0.12499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.02499f, -0.1f, -0.05f}, {-0.02499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.12499f, -0.1f,  0.05f}, {-0.02499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.12499f, -0.1f, -0.05f}, {-0.02499f, -0.3f, -0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.12499f, -0.3f, -0.05f}, {-0.02499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
}

void	Human::draw_left_thigh(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.12499f, -0.1f, -0.05f}, {0.02499f, -0.1f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.02499f, -0.1f, -0.05f}, {0.02499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.12499f, -0.1f, -0.05f}, {0.12499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.12499f, -0.1f,  0.05f}, {0.02499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.12499f, -0.1f, -0.05f}, {0.02499f, -0.3f, -0.05f}, _legs_color, shader, modelStack);
	draw_rect({0.12499f, -0.3f, -0.05f}, {0.02499f, -0.3f,  0.05f}, _legs_color, shader, modelStack);
}

void	Human::draw_right_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.125f, -0.3f,  -0.05f}, {-0.025f,  -0.3f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.29f, -0.05f}, {-0.125f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.025f, -0.29f, -0.05f}, {-0.025f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.29f,  0.05f}, {-0.025f, -0.45f,  0.05f}, _legs_color, shader, modelStack);
	draw_rect({-0.125f, -0.29f, -0.05f}, {-0.025f, -0.45f, -0.05f}, _legs_color, shader, modelStack);
}

void	Human::draw_left_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	draw_rect({0.125f, -0.3f,  -0.05f}, {0.025f, -0.3f,   0.05f}, _legs_color, shader, modelStack);
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
