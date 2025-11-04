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
	_showHands = false;
	_showHands = false;
	_showWings = false;

	_showRightthigh = true;
	_showRightLowerLeg = true;
	_showLeftthigh = true;
	_showLeftLowerLeg = true;
}

Human::~Human()	{delete _rightHand; delete _leftHand;}

void	Human::reset_size()
{
	_size = 1.0f;

	_head_size				= 1.0f;
	_body_size				= 1.0f;
	_left_upper_arm_size	= 1.0f;
	_right_upper_arm_size	= 1.0f;
	_left_forearm_size		= 1.0f;
	_right_forearm_size		= 1.0f;
	_left_thigh_size		= 1.0f;
	_right_thigh_size		= 1.0f;
	_left_lower_leg_size	= 1.0f;
	_right_lower_leg_size	= 1.0f;
}

void	Human::draw(ModelStack &modelStack, Shaders &modelShader, Shaders &colorShader, bool cube)
{
	float angle = sinf((glfwGetTime() - _animation_frame) * (_animation == SPRINT ? 10.0f : 5.0f)) * 30.0f;

	if (human.get_animation() == JUMP) {
		float angle = -sinf((glfwGetTime() - human.get_animation_frame()) * 5.0f);
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

	if (_animation != DISCO_DANCE) { _discoAngle = 0.0f; _discoTranslate = 0.0f; _discoStartFinished = false; _rightHand->indexFingerPhalangeAngle[0] = 0.0f; }
	if (_animation == DISCO_DANCE) {
		if (_discoAngle >= -10.0f)
			_discoAngle -= 0.5f;
		if (_discoTranslate >= -0.02f)
			_discoTranslate += -0.001f;
		if (_discoAngle <= -10.0f && _discoTranslate <= -0.02f) {_discoStartFinished = true; _rightHand->indexFingerPhalangeAngle[0] = -90.0f; }
	}

	if (_animation == FLY) {
		modelStack.push();
		modelStack.translate(0.0f, -0.1f * _size, -0.05f);
		modelStack.translate(0.0f, 0.3f + angle * 0.001f * _size, 0.05f);
	}

	if (_showBody) draw_body(modelStack, modelShader);

	glUseProgram(colorShader.shaderProgram);
	draw_wings(modelStack, colorShader, angle);
	glUseProgram(modelShader.shaderProgram);

	if (_showHead) draw_head(modelStack, modelShader);

	draw_left_arm(modelStack, modelShader, colorShader, angle);
	draw_right_arm(modelStack, modelShader, colorShader, angle);

	if (_animation == SPRINT) modelStack.pop();

	draw_right_leg(modelStack, modelShader, angle);
	draw_left_leg(modelStack, modelShader, angle);

	glUseProgram(colorShader.shaderProgram);
	if (cube) draw_cube(colorShader, modelStack.current());
	glUseProgram(modelShader.shaderProgram);

	if (human.get_animation() == JUMP) modelStack.pop();
}

void	Human::draw_right_arm(ModelStack &modelStack, Shaders &shader, Shaders &colorShader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(-angle, 'X');
		modelStack.translate(0.0f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(angle < 0.0f ? angle : 0.0f, 'X');
		modelStack.translate(0.0f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(-angle * 1.5f, 'X');
		modelStack.translate(0.0f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == FLY) {
		modelStack.translate(-0.15f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(-15.0f + angle * -0.3f, 'Z');
		modelStack.translate(0.15f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == DISCO_DANCE) {
		if (_discoStartFinished) {
			modelStack.translate(-0.15f, 0.25f * _size, 0.0f);
			float t = (float)(glfwGetTime() - _animation_frame);
			float freq = 0.8f;

			float u = 0.5f * (1.0f - cosf(2.0f * M_PIf * freq * t));
			if (u < 0.0f) u = 0.0f;
			if (u > 1.0f) u = 1.0f;

			float rx = 90.0f * u;
			float ry = 60.0f * u;
			float rz = -90.0f * u;

			modelStack.rotate(rx, 'X');
			modelStack.rotate(rz, 'Z');
			modelStack.rotate(ry, 'Y');

			modelStack.translate(0.15f, -0.25f * _size, 0.0f);
		}
		modelStack.translate(-0.15f, 0.25f * _size, 0.0f);
		modelStack.rotate(_discoAngle * 11.42f, 'Z');
		modelStack.translate(0.15f, -0.25f * _size, 0.0f);
	}

	if (_showRightUpperArm) {
		draw_right_upper_arm(modelStack, shader);
		draw_right_shoulder(modelStack, shader);
	}

	if (_animation == WALK) {
		modelStack.translate(0.0f, (0.3f * _size * _body_size) - (0.2f * _right_upper_arm_size * _size), -0.05f);
		modelStack.rotate(-angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, (-0.3f * _size * _body_size) + (0.2f * _right_upper_arm_size * _size), 0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, (0.3f * _size * _body_size) - (0.2f * _right_upper_arm_size * _size), -0.05f);
		modelStack.rotate(angle < 0.0f ? angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, (-0.3f * _size * _body_size) + (0.2f * _right_upper_arm_size * _size), 0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, (0.3f * _size * _body_size) - (0.2f * _right_upper_arm_size * _size), -0.05f);
		modelStack.rotate(-60.0f - angle, 'X');
		modelStack.translate(0.0f, (-0.3f * _size * _body_size) + (0.2f * _right_upper_arm_size * _size), 0.05f);
	} else if (_animation == FLY) {
		modelStack.translate(-0.15f, (0.3f * _size * _body_size) - (0.2f * _size * _right_upper_arm_size), 0.05f);
		modelStack.rotate(5.0f + (sinf((glfwGetTime() + 3000.0f - _animation_frame) * 5.0f) * 30.0f) * 0.2f, 'Z');
		modelStack.translate(0.15f, (-0.29f * _size * _body_size) + (0.2f * _size * _right_upper_arm_size), -0.05f);
	} else if (_animation == DISCO_DANCE) {
		if (_discoStartFinished) {
			modelStack.translate(-0.175f, 0.1f * _size, 0.0f);
			modelStack.rotate(180.0f, 'Y');
			modelStack.translate(0.175f, -0.1f * _size, 0.0f);
		}
		modelStack.translate(-0.22f, 0.08f * _size * _body_size, 0.0f);
		modelStack.rotate(-_discoAngle * 2.85f, 'Z');
		modelStack.translate(0.22f, -0.08f * _size * _body_size, 0.0f);
	}

	if (_showRightForearm) draw_right_forearm(modelStack, shader);

	if (_showHands) {
		glUseProgram(colorShader.shaderProgram);
		GLint colorLoc = glGetUniformLocation(colorShader.shaderProgram, "uColor");
		glUniform3fv(colorLoc, 1, _skin_color);
		_rightHand->draw(_skin_color, modelStack, colorShader);
		glUseProgram(shader.shaderProgram);
	}

	if (_animation) modelStack.pop();
}

void	Human::draw_left_arm(ModelStack &modelStack, Shaders &shader, Shaders &colorShader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(angle, 'X');
		modelStack.translate(0.0f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(angle < 0.0f ? angle : 0.0f, 'X');
		modelStack.translate(0.0f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(angle * 1.5f, 'X');
		modelStack.translate(0.0f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == FLY) {
		modelStack.translate(0.15f, 0.25f * _size * _body_size, 0.0f);
		modelStack.rotate(15.0f + angle * 0.3f, 'Z');
		modelStack.translate(-0.15f, -0.25f * _size * _body_size, 0.0f);
	} else if (_animation == DISCO_DANCE) {
		modelStack.translate(-_discoTranslate * 5.0f, (_discoTranslate - 0.01f) * _size * _body_size, 0.0f);
		modelStack.rotate(-_discoAngle * 2.0f, 'Z');
	}

	if (_showLeftUpperArm) {
		draw_left_upper_arm(modelStack, shader);
		draw_left_shoulder(modelStack, shader);
	}

	if (_animation == WALK) {
		modelStack.translate(0.0f, (0.3f * _size * _body_size) - (0.2f * _left_upper_arm_size * _size), -0.05f);
		modelStack.rotate(angle < 0.0f ? angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, (-0.3f * _size * _body_size) + (0.2f * _left_upper_arm_size * _size), 0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, (0.3f * _size * _body_size) - (0.2f * _left_upper_arm_size * _size), -0.05f);
		modelStack.rotate(angle < 0.0f ? angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, (-0.3f * _size * _body_size) + (0.2f * _left_upper_arm_size * _size), 0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, (0.3f * _size * _body_size) - (0.2f * _left_upper_arm_size * _size), -0.05f);
		modelStack.rotate(-60.0f + angle, 'X');
		modelStack.translate(0.0f, (-0.3f * _size * _body_size) + (0.2f * _left_upper_arm_size * _size), 0.05f);
	} else if (_animation == FLY) {
		modelStack.translate(0.15f, (0.3f * _size * _body_size) - (0.2f * _size * _left_upper_arm_size), 0.05f);
		modelStack.rotate(-5.0f + (sinf((glfwGetTime() + 1000.0f - _animation_frame) * 5.0f) * 30.0f) * 0.2f, 'Z');
		modelStack.translate(-0.15f, (-0.29f * _size * _body_size) + (0.2f * _size * _left_upper_arm_size), -0.05f);
	} else if (_animation == DISCO_DANCE) {
		modelStack.translate(0.0f, _discoTranslate * -8.0f * _size * _body_size, 0.0f);
		modelStack.rotate(_discoAngle * 4.0f, 'Z');
	}

	if (_showLeftForearm) draw_left_forearm(modelStack, shader);

	if (_showHands) {
		glUseProgram(colorShader.shaderProgram);
		GLint colorLoc = glGetUniformLocation(colorShader.shaderProgram, "uColor");
		glUniform3fv(colorLoc, 1, _skin_color);
		_leftHand->draw(_skin_color, modelStack, colorShader);
		glUseProgram(shader.shaderProgram);
	}
	if (_animation) modelStack.pop();
}

void	Human::draw_right_leg(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(angle, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(-angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(angle * 2.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == FLY) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(5.0f + (sinf((glfwGetTime() + 1000.0f - _animation_frame) * 5.0f) * 30.0f) * 0.1f, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == DISCO_DANCE) {
		modelStack.translate(0.0f, _discoTranslate * _size, 0.0f);
		modelStack.rotate(_discoAngle, 'Z');
	}

	if (_showRightthigh) draw_right_thigh(modelStack, shader);

	if (_animation == WALK) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _right_thigh_size), 0.05f);
		modelStack.rotate(angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _right_thigh_size), -0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _right_thigh_size), 0.05f);
		modelStack.rotate(angle > 0.0f ? angle : 0.0f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _right_thigh_size), -0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _right_thigh_size), 0.05f);
		modelStack.rotate(angle < 0.0f ? -angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _right_thigh_size), -0.05f);
	} else if (_animation == FLY) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _right_thigh_size), 0.05f);
		modelStack.rotate(40.0f + (sinf((glfwGetTime() + 1000.0f - _animation_frame) * 5.0f) * 30.0f) * 0.2f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _right_thigh_size), -0.05f);
	}

	if (_showRightLowerLeg) {
		draw_right_lower_leg(modelStack, shader);
		draw_right_foot(modelStack, shader);
	}

	if (_animation) modelStack.pop();
}

void	Human::draw_left_leg(ModelStack &modelStack, Shaders &shader, float angle)
{
	if (_animation) modelStack.push();

	if (_animation == WALK) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(-angle, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(-angle < 0.0f ? -angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(-angle * 2.0f, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == FLY) {
		modelStack.translate(0.0f, -0.1f * _size * _body_size, 0.0f);
		modelStack.rotate(10.0f + angle * 0.1f, 'X');
		modelStack.translate(0.0f, 0.1f * _size * _body_size, 0.0f);
	} else if (_animation == DISCO_DANCE) {
		modelStack.translate(0.0f, _discoTranslate * _size, 0.0f);
		modelStack.rotate(-_discoAngle, 'Z');
	}

	if (_showLeftthigh) draw_left_thigh(modelStack, shader);

	if (_animation == WALK) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _left_thigh_size), 0.05f);
		modelStack.rotate(-angle < 0.0f ? angle * 0.5f : 0.0f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _left_thigh_size), -0.05f);
	} else if (_animation == JUMP) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _left_thigh_size), 0.05f);
		modelStack.rotate(angle > 0.0f ? angle : 0.0f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _left_thigh_size), -0.05f);
	} else if (_animation == SPRINT) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _left_thigh_size), 0.05f);
		modelStack.rotate(-angle < 0.0f ? angle * 2.0f : 0.0f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _left_thigh_size), -0.05f);
	} else if (_animation == FLY) {
		modelStack.translate(0.0f, (-0.1f * _size * _body_size) - (0.2f * _size * _left_thigh_size), 0.05f);
		modelStack.rotate(20.0f + angle * 0.3f, 'X');
		modelStack.translate(0.0f, (0.1f * _size * _body_size) + (0.2f * _size * _left_thigh_size), -0.05f);
	}

	if (_showLeftLowerLeg) {
		draw_left_lower_leg(modelStack, shader);
		draw_left_foot(modelStack, shader);
	}

	if (_animation) modelStack.pop();
}

void	Human::draw_head(ModelStack &modelStack, Shaders &shader)
{
	float	head_mul_sizes = _size * _head_size;
	float	body_mul_sizes = _size * _body_size;
	float	start = 0.3f * body_mul_sizes;
	float	end = start + (0.2f * head_mul_sizes);

	draw_rect({-0.1f,    end, -0.1f}, { 0.1f,   end,  0.1f}, _skin_color, 0.125f, 0.000f, 0.125f, 0.25f,  true, shader, false, modelStack);
	draw_rect({-0.1f,  start, -0.1f}, { 0.1f, start,  0.1f}, _skin_color, 0.250f, 0.000f, 0.125f, 0.25f, false, shader, false, modelStack);
	draw_rect({-0.1f,  start, -0.1f}, {-0.1f,   end,  0.1f}, _skin_color, 0.000f, 0.250f, 0.125f, 0.25f,  true, shader, false, modelStack);
	draw_rect({ 0.1f,  start, -0.1f}, { 0.1f,   end,  0.1f}, _skin_color, 0.250f, 0.250f, 0.125f, 0.25f, false, shader, false, modelStack);
	draw_rect({-0.1f,  start,  0.1f}, { 0.1f,   end,  0.1f}, _skin_color, 0.125f, 0.250f, 0.125f, 0.25f,  true, shader, false, modelStack);
	draw_rect({-0.1f,  start, -0.1f}, { 0.1f,   end, -0.1f}, _skin_color, 0.375f, 0.250f, 0.125f, 0.25f, false, shader, false, modelStack);
}

void	Human::draw_body(ModelStack &modelStack, Shaders &shader)
{
	float	body_mul_sizes = _size * _body_size;
	float	start = -0.1f * body_mul_sizes;
	float	end = start + (0.4f * body_mul_sizes);

	draw_rect({-0.125f,   end, -0.05f}, { 0.125f,   end,  0.05f}, _body_color, 0.3125f, 0.500f, 0.1250f, 0.125f,  true, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, { 0.125f, start,  0.05f}, _body_color, 0.4375f, 0.500f, 0.1250f, 0.125f, false, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {-0.125f,   end,  0.05f}, _body_color, 0.2500f, 0.625f, 0.0625f, 0.375f,  true, shader, false, modelStack);
	draw_rect({ 0.125f, start, -0.05f}, { 0.125f,   end,  0.05f}, _body_color, 0.4375f, 0.625f, 0.0625f, 0.375f, false, shader, false, modelStack);
	draw_rect({-0.125f, start,  0.05f}, { 0.125f,   end,  0.05f}, _body_color, 0.3125f, 0.625f, 0.1250f, 0.375f,  true, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, { 0.125f,   end, -0.05f}, _body_color, 0.5000f, 0.625f, 0.1250f, 0.375f, false, shader, false, modelStack);
}

void	Human::draw_left_shoulder(ModelStack &modelStack, Shaders &shader)
{
	float	left_shoulder_mul_sizes = _size * _left_upper_arm_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = 0.3f * body_mul_sizes;
	float	start = end - (0.1f * left_shoulder_mul_sizes);

	float	width = (human.get_slim() ? 0.2f : 0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({0.125f,   end, -0.05f}, { width, end,  0.05f}, _body_color, 0.6875f, 0.500f,  uscale, 0.12500f,  true, shader, false, modelStack);
	draw_rect({ width, start, -0.05f}, { width, end,  0.05f}, _body_color, 0.6250f, 0.625f, 0.0625f, 0.09375f,  true, shader, false, modelStack);
	draw_rect({0.125f, start, -0.05f}, {0.125f, end,  0.05f}, _body_color,    gap1, 0.625f, 0.0625f, 0.09375f, false, shader, false, modelStack);
	draw_rect({0.125f, start,  0.05f}, { width, end,  0.05f}, _body_color, 0.6875f, 0.625f,  uscale, 0.09375f, false, shader, false, modelStack);
	draw_rect({0.125f, start, -0.05f}, { width, end, -0.05f}, _body_color,    gap2, 0.625f,  uscale, 0.09375f,  true, shader, false, modelStack);
}

void	Human::draw_right_shoulder(ModelStack &modelStack, Shaders &shader)
{
	float	right_shoulder_mul_sizes = _size * _right_upper_arm_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = 0.3f * body_mul_sizes;
	float	start = end - (0.1f * right_shoulder_mul_sizes);

	float	width = (human.get_slim() ? -0.2f : -0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({-0.125f,   end, -0.05f}, {  width, end,  0.05f}, _body_color, 0.6875f, 0.500f,  uscale, 0.12500f,  true, shader, false, modelStack);
	draw_rect({  width, start, -0.05f}, {  width, end,  0.05f}, _body_color, 0.6250f, 0.625f, 0.0625f, 0.09375f,  true, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {-0.125f, end,  0.05f}, _body_color,    gap1, 0.625f, 0.0625f, 0.09375f, false, shader, false, modelStack);
	draw_rect({-0.125f, start,  0.05f}, {  width, end,  0.05f}, _body_color, 0.6875f, 0.625f,  uscale, 0.09375f, false, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {  width, end, -0.05f}, _body_color,    gap2, 0.625f,  uscale, 0.09375f,  true, shader, false, modelStack);
}

void	Human::draw_left_upper_arm(ModelStack &modelStack, Shaders &shader)
{
	float	left_shoulder_mul_sizes = _size * _left_upper_arm_size;
	float	left_upper_arm_mul_sizes = _size * _left_upper_arm_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = 0.3f * body_mul_sizes - (0.1f * left_shoulder_mul_sizes);
	float	start = end - (0.1f * left_upper_arm_mul_sizes);

	float	width = (human.get_slim() ? 0.2f : 0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({0.125f, start, -0.05f}, { width, start,  0.05f}, _skin_color,    gap1, 0.50000f,  uscale, 0.12500f, false, shader, false, modelStack);
	draw_rect({ width, start, -0.05f}, { width,   end,  0.05f}, _skin_color, 0.6250f, 0.71875f, 0.0625f, 0.12500f,  true, shader, false, modelStack);
	draw_rect({0.125f, start, -0.05f}, {0.125f,   end,  0.05f}, _skin_color,    gap1, 0.71875f, 0.0625f, 0.09375f, false, shader, false, modelStack);
	draw_rect({0.125f, start,  0.05f}, { width,   end,  0.05f}, _skin_color, 0.6875f, 0.71875f,  uscale, 0.09375f, false, shader, false, modelStack);
	draw_rect({0.125f, start, -0.05f}, { width,   end, -0.05f}, _skin_color,    gap2, 0.71875f,  uscale, 0.09375f,  true, shader, false, modelStack);
}

void	Human::draw_right_upper_arm(ModelStack &modelStack, Shaders &shader)
{
	float	right_shoulder_mul_sizes = _size * _right_upper_arm_size;
	float	right_upper_arm_mul_sizes = _size * _right_upper_arm_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = 0.3f * body_mul_sizes - (0.1f * right_shoulder_mul_sizes);
	float	start = end - (0.1f * right_upper_arm_mul_sizes);

	float	width = (human.get_slim() ? -0.2f : -0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({-0.125f, start, -0.05f}, {  width, start,  0.05f}, _skin_color,    gap1, 0.50000f,  uscale, 0.12500f, false, shader, false, modelStack);
	draw_rect({  width, start, -0.05f}, {  width,   end,  0.05f}, _skin_color, 0.6250f, 0.71875f, 0.0625f, 0.12500f,  true, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {-0.125f,   end,  0.05f}, _skin_color,    gap1, 0.71875f, 0.0625f, 0.09375f, false, shader, false, modelStack);
	draw_rect({-0.125f, start,  0.05f}, {  width,   end,  0.05f}, _skin_color, 0.6875f, 0.71875f,  uscale, 0.09375f, false, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {  width,   end, -0.05f}, _skin_color,    gap2, 0.71875f,  uscale, 0.09375f,  true, shader, false, modelStack);
}

void	Human::draw_left_forearm(ModelStack &modelStack, Shaders &shader)
{
	float	left_shoulder_mul_sizes = _size * _left_upper_arm_size;
	float	left_upper_arm_mul_sizes = _size * _left_upper_arm_size;
	float	left_forearm_mul_sizes = _size * _left_forearm_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = 0.3f * body_mul_sizes - (0.1f * left_shoulder_mul_sizes) -(0.1f * left_upper_arm_mul_sizes);
	float	start = end - (0.2f * left_forearm_mul_sizes);

	float	width = (human.get_slim() ? 0.2f : 0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({0.125f,   end, -0.05f}, {  width,   end,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, false, modelStack);
	draw_rect({0.125f, start, -0.05f}, {  width, start,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, false, modelStack);
	draw_rect({ width, start, -0.05f}, {  width,   end,  0.05f}, _skin_color, 0.6250f, 0.8125f, 0.0625f, 0.1875f,  true, shader, false, modelStack);
	draw_rect({0.125f, start, -0.05f}, { 0.125f,   end,  0.05f}, _skin_color,    gap1, 0.8125f, 0.0625f, 0.1875f, false, shader, false, modelStack);
	draw_rect({0.125f, start,  0.05f}, {  width,   end,  0.05f}, _skin_color, 0.6875f, 0.8125f,  uscale, 0.1875f, false, shader, false, modelStack);
	draw_rect({0.125f, start, -0.05f}, {  width,   end, -0.05f}, _skin_color,    gap2, 0.8125f,  uscale, 0.1875f,  true, shader, false, modelStack);
}

void	Human::draw_right_forearm(ModelStack &modelStack, Shaders &shader)
{
	float	right_shoulder_mul_sizes = _size * _right_upper_arm_size;
	float	right_upper_arm_mul_sizes = _size * _right_upper_arm_size;
	float	right_forearm_mul_sizes = _size * _right_forearm_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = 0.3f * body_mul_sizes - (0.1f * right_shoulder_mul_sizes) -(0.1f * right_upper_arm_mul_sizes);
	float	start = end - (0.2f * right_forearm_mul_sizes);

	float	width = (human.get_slim() ? -0.2f : -0.225f);
	float	uscale = (human.get_slim() ? 0.046875f : 0.0625f);
	float	gap1 = 0.6875f + uscale;
	float	gap2 = 0.0625f + gap1;

	draw_rect({-0.125f,   end, -0.05f}, {  width,   end,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {  width, start,  0.05f}, _skin_color,    gap1, 0.5000f,  uscale, 0.1250f, false, shader, false, modelStack);
	draw_rect({  width, start, -0.05f}, {  width,   end,  0.05f}, _skin_color, 0.6250f, 0.8125f, 0.0625f, 0.1875f,  true, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {-0.125f,   end,  0.05f}, _skin_color,    gap1, 0.8125f, 0.0625f, 0.1875f, false, shader, false, modelStack);
	draw_rect({-0.125f, start,  0.05f}, {  width,   end,  0.05f}, _skin_color, 0.6875f, 0.8125f,  uscale, 0.1875f, false, shader, false, modelStack);
	draw_rect({-0.125f, start, -0.05f}, {  width,   end, -0.05f}, _skin_color,    gap2, 0.8125f,  uscale, 0.1875f,  true, shader, false, modelStack);
}

void	Human::draw_left_thigh(ModelStack &modelStack, Shaders &shader)
{
	float	left_thigh_mul_sizes = _size * _left_thigh_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = -0.1f * body_mul_sizes;
	float	start = end - (0.2f * left_thigh_mul_sizes);

	draw_rect({0.02499f,   end,  0.05f}, {0.12499f,   end, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f,  true, shader, false, modelStack);
	draw_rect({0.02499f, start,  0.05f}, {0.12499f, start, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f, false, shader, false, modelStack);
	draw_rect({0.12499f, start,  0.05f}, {0.12499f,   end, -0.05f}, _legs_color, 0.0000f, 0.625f, 0.0625f, 0.1875f,  true, shader, false, modelStack);
	draw_rect({0.02499f, start,  0.05f}, {0.02499f,   end, -0.05f}, _legs_color, 0.1250f, 0.625f, 0.0625f, 0.1875f, false, shader, false, modelStack);
	draw_rect({0.02499f, start,  0.05f}, {0.12499f,   end,  0.05f}, _legs_color, 0.0625f, 0.625f, 0.0625f, 0.1875f,  true, shader, false, modelStack);
	draw_rect({0.02499f, start, -0.05f}, {0.12499f,   end, -0.05f}, _legs_color, 0.1875f, 0.625f, 0.0625f, 0.1875f, false, shader, false, modelStack);
}

void	Human::draw_right_thigh(ModelStack &modelStack, Shaders &shader)
{
	float	right_thigh_mul_sizes = _size * _right_thigh_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = -0.1f * body_mul_sizes;
	float	start = end - (0.2f * right_thigh_mul_sizes);

	draw_rect({-0.02499f,   end,  0.05f}, {-0.12499f,   end, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f,  true, shader, false, modelStack);
	draw_rect({-0.02499f, start,  0.05f}, {-0.12499f, start, -0.05f}, _legs_color, 0.0625f, 0.500f, 0.0625f, 0.1250f, false, shader, false, modelStack);
	draw_rect({-0.12499f, start,  0.05f}, {-0.12499f,   end, -0.05f}, _legs_color, 0.0000f, 0.625f, 0.0625f, 0.1875f,  true, shader, false, modelStack);
	draw_rect({-0.02499f, start,  0.05f}, {-0.02499f,   end, -0.05f}, _legs_color, 0.1250f, 0.625f, 0.0625f, 0.1875f, false, shader, false, modelStack);
	draw_rect({-0.02499f, start,  0.05f}, {-0.12499f,   end,  0.05f}, _legs_color, 0.0625f, 0.625f, 0.0625f, 0.1875f,  true, shader, false, modelStack);
	draw_rect({-0.02499f, start, -0.05f}, {-0.12499f,   end, -0.05f}, _legs_color, 0.1875f, 0.625f, 0.0625f, 0.1875f, false, shader, false, modelStack);
}

void	Human::draw_left_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	float	left_lower_leg_mul_sizes = _size * _left_lower_leg_size;
	float	left_thigh_mul_sizes = _size * _left_thigh_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = -0.1f * body_mul_sizes - (0.2f * left_thigh_mul_sizes);
	float	start = end - (0.15f * left_lower_leg_mul_sizes);

	draw_rect({0.025f,   end,  0.05f}, {0.125f, end, -0.05f}, _legs_color, 0.0625f, 0.5000f, 0.0625f, 0.125000f,  true, shader, false, modelStack);
	draw_rect({0.125f, start,  0.05f}, {0.125f, end, -0.05f}, _legs_color, 0.0000f, 0.8125f, 0.0625f, 0.140625f,  true, shader, false, modelStack);
	draw_rect({0.025f, start,  0.05f}, {0.025f, end, -0.05f}, _legs_color, 0.1250f, 0.8125f, 0.0625f, 0.140625f, false, shader, false, modelStack);
	draw_rect({0.025f, start,  0.05f}, {0.125f, end,  0.05f}, _legs_color, 0.0625f, 0.8125f, 0.0625f, 0.140625f,  true, shader, false, modelStack);
	draw_rect({0.025f, start, -0.05f}, {0.125f, end, -0.05f}, _legs_color, 0.1875f, 0.8125f, 0.0625f, 0.140625f, false, shader, false, modelStack);
}

void	Human::draw_right_lower_leg(ModelStack &modelStack, Shaders &shader)
{
	float	right_lower_leg_mul_sizes = _size * _right_lower_leg_size;
	float	right_thigh_mul_sizes = _size * _right_thigh_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = -0.1f * body_mul_sizes - (0.2f * right_thigh_mul_sizes);
	float	start = end - (0.15f * right_lower_leg_mul_sizes);

	draw_rect({-0.025f,   end,  0.05f}, {-0.125f, end, -0.05f}, _legs_color, 0.0625f, 0.5000f, 0.0625f, 0.125000f,  true, shader, false, modelStack);
	draw_rect({-0.125f, start,  0.05f}, {-0.125f, end, -0.05f}, _legs_color, 0.0000f, 0.8125f, 0.0625f, 0.140625f,  true, shader, false, modelStack);
	draw_rect({-0.025f, start,  0.05f}, {-0.025f, end, -0.05f}, _legs_color, 0.1250f, 0.8125f, 0.0625f, 0.140625f, false, shader, false, modelStack);
	draw_rect({-0.025f, start,  0.05f}, {-0.125f, end,  0.05f}, _legs_color, 0.0625f, 0.8125f, 0.0625f, 0.140625f,  true, shader, false, modelStack);
	draw_rect({-0.025f, start, -0.05f}, {-0.125f, end, -0.05f}, _legs_color, 0.1875f, 0.8125f, 0.0625f, 0.140625f, false, shader, false, modelStack);
}

void	Human::draw_left_foot(ModelStack &modelStack, Shaders &shader)
{
	float	left_lower_leg_mul_sizes = _size * _left_lower_leg_size;
	float	left_thigh_mul_sizes = _size * _left_thigh_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = -0.1f * body_mul_sizes - (0.2f * left_thigh_mul_sizes) - (0.15f * left_lower_leg_mul_sizes);
	float	start = end - 0.05f;

	draw_rect({0.025f,   end,  0.05f}, {0.125f,   end, -0.05f}, _foots_color, 0.1250f, 0.500000f, 0.0625f, 0.125000f, false, shader, false, modelStack);
	draw_rect({0.025f, start,  0.05f}, {0.125f, start, -0.05f}, _foots_color, 0.1250f, 0.500000f, 0.0625f, 0.125000f, false, shader, false, modelStack);
	draw_rect({0.125f, start,  0.05f}, {0.125f,   end, -0.05f}, _foots_color, 0.0000f, 0.953125f, 0.0625f, 0.046875f,  true, shader, false, modelStack);
	draw_rect({0.025f, start,  0.05f}, {0.025f,   end, -0.05f}, _foots_color, 0.1250f, 0.953125f, 0.0625f, 0.046875f, false, shader, false, modelStack);
	draw_rect({0.025f, start,  0.05f}, {0.125f,   end,  0.05f}, _foots_color, 0.0625f, 0.953125f, 0.0625f, 0.046875f,  true, shader, false, modelStack);
	draw_rect({0.025f, start, -0.05f}, {0.125f,   end, -0.05f}, _foots_color, 0.1875f, 0.953125f, 0.0625f, 0.046875f, false, shader, false, modelStack);
}

void	Human::draw_right_foot(ModelStack &modelStack, Shaders &shader)
{
	float	right_lower_leg_mul_sizes = _size * _right_lower_leg_size;
	float	right_thigh_mul_sizes = _size * _right_thigh_size;
	float	body_mul_sizes = _size * _body_size;
	float	end = -0.1f * body_mul_sizes - (0.2f * right_thigh_mul_sizes) - (0.15f * right_lower_leg_mul_sizes);
	float	start = end - 0.05f;

	draw_rect({-0.025f,   end,  0.05f}, {-0.125f,   end, -0.05f}, _foots_color, 0.1250f, 0.500000f, 0.0625f, 0.125000f, false, shader, false, modelStack);
	draw_rect({-0.025f, start,  0.05f}, {-0.125f, start, -0.05f}, _foots_color, 0.1250f, 0.500000f, 0.0625f, 0.125000f, false, shader, false, modelStack);
	draw_rect({-0.125f, start,  0.05f}, {-0.125f,   end, -0.05f}, _foots_color, 0.0000f, 0.953125f, 0.0625f, 0.046875f,  true, shader, false, modelStack);
	draw_rect({-0.025f, start,  0.05f}, {-0.025f,   end, -0.05f}, _foots_color, 0.1250f, 0.953125f, 0.0625f, 0.046875f, false, shader, false, modelStack);
	draw_rect({-0.025f, start,  0.05f}, {-0.125f,   end,  0.05f}, _foots_color, 0.0625f, 0.953125f, 0.0625f, 0.046875f,  true, shader, false, modelStack);
	draw_rect({-0.025f, start, -0.05f}, {-0.125f,   end, -0.05f}, _foots_color, 0.1875f, 0.953125f, 0.0625f, 0.046875f, false, shader, false, modelStack);
}
