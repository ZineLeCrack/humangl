#include "Human.hpp"

void Human::draw_right_wing1_1_1(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.06f, 0.18f * _size, -0.01f);
	modelStack.rotate(20.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.09f, 0.18f * _size, -0.01f);
	modelStack.rotate(0.0f, 'Z');
	draw_paving_shape({0.025, -0.09, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.13f, 0.18f * _size, -0.01f);
	modelStack.rotate(-5.0f, 'Z');
	draw_paving_shape({0.025, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.17f, 0.18f * _size, -0.01f);
	modelStack.rotate(-10.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_right_wing1_1_2(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.05f, 0.12f * _size, -0.009f);
	modelStack.rotate(20.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.09f, 0.12f * _size, -0.009f);
	modelStack.rotate(10.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.14f, 0.12f * _size, -0.009f);
	modelStack.rotate(7.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.18f, 0.12f * _size, -0.009f);
	modelStack.rotate(-3.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_right_wing1_1_3(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.06f, 0.1f * _size, -0.008f);
	modelStack.rotate(20.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.1f, 0.1f * _size, -0.008f);
	modelStack.rotate(10.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.135f, 0.1f * _size, -0.008f);
	modelStack.rotate(10.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.17f, 0.1f * _size, -0.008f);
	modelStack.rotate(5.0f, 'Z');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_right_wing1_1(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	// modelStack.translate(-0.05f, 0.25f * _size, -0.051f);
	// modelStack.translate(0.05f, -0.2f * _size, 0.0f);
	_opening_frame += 0.1f;
	float angle1_1 = sin(_opening_frame * 1.1) * 15;
	if (_open_wings == true) {
		modelStack.translate(-0.05f, 0.25f * _size, -0.051f);
		if (angle1_1 >= 20.0f)
			modelStack.rotate(-20.0f, 'Z'); //-
		else
			modelStack.rotate(-40.0f + angle1_1, 'Z'); //-
		if (angle1_1 >= 10.0f)
			modelStack.rotate(-20.0f, 'Y'); //-
		else
			modelStack.rotate(-10 - angle1_1, 'Y');//-
		modelStack.translate(0.05f, -0.2f * _size, 0.0f);
	}
	else {
		modelStack.translate(-0.05f, 0.25f * _size, -0.051f);
		if (angle1_1 >= 20.0f)
			modelStack.rotate(-40.0f, 'Z');//-
		else
			modelStack.rotate(-20.0f - angle1_1, 'Z');//-
		if (angle1_1 >= 10.0f)
			modelStack.rotate(-10.0f, 'Y');//-
		else
			modelStack.rotate(-20 + angle1_1, 'Y');//-
		modelStack.translate(0.05f, -0.2f * _size, 0.0f);
	}
	// draw_paving_shape( {-0.2, 0.15, 0.0}, {-0.05, 0.2, -0.02}, wings_color, shader, modelStack);
	(void)shader;
	(void)modelStack;
	(void)wings_color;
}

void Human::draw_right_wing1_2_1(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.26f, 0.185f * _size, -0.012f);
	modelStack.rotate(20.0f, 'Z');
	modelStack.rotate(-20.0f, 'Y');
	draw_paving_shape({0.025, -0.05, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.29f, 0.18f * _size, -0.012f);
	modelStack.rotate(5.0f, 'Z');
	draw_paving_shape({0.025, -0.06, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.34f, 0.18f * _size, -0.012f);
	modelStack.rotate(0.0f, 'Z');
	draw_paving_shape({0.025, -0.05, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.39f, 0.18f * _size, -0.012f);
	modelStack.rotate(-3.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.43f, 0.18f * _size, -0.012f);
	modelStack.rotate(-8.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape({0.025, -0.06, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.47f, 0.18f * _size, -0.01f);
	modelStack.rotate(-28.0f, 'Z');
	modelStack.rotate(-15.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape({0.025, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_right_wing1_2_2(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.25f, 0.15f * _size, -0.008f);
	modelStack.rotate(30.0f, 'Z');
	modelStack.rotate(-15.0f, 'X');
	modelStack.rotate(-10.0f, 'Y');
	draw_paving_shape({0.023, -0.09, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.27f, 0.17f * _size, -0.01f);
	modelStack.rotate(20.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape({0.023, -0.125, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.30f, 0.17f * _size, -0.01f);
	modelStack.rotate(10.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape({0.023, -0.135, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.33f, 0.17f * _size, -0.01f);
	modelStack.rotate(0.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape({0.023, -0.13, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.36f, 0.17f * _size, -0.01f);
	modelStack.rotate(-5.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape({0.023, -0.12, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_right_wing1_2_3(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.2f, 0.1f * _size, 0.009f);
	modelStack.rotate(40.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(-20.0f, 'Y');
	draw_paving_shape({0.023, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.23f, 0.08f * _size, 0.0f);
	modelStack.rotate(30.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(-10.0f, 'Y');
	draw_paving_shape({0.023, -0.065, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.26f, 0.07f * _size, 0.0f);
	modelStack.rotate(10.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	draw_paving_shape({0.023, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.3f, 0.07f * _size, 0.0f);
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape({0.023, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.34f, 0.07f * _size, 0.0f);
	modelStack.rotate(-10.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape({0.023, -0.09, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.37f, 0.07f * _size, 0.0f);
	modelStack.rotate(-20.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape({0.023, -0.1, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.39f, 0.11f * _size, 0.0f);
	modelStack.rotate(-30.0f, 'Z');
	modelStack.rotate(-15.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape({0.023, -0.15, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.43f, 0.125f * _size, 0.0f);
	modelStack.rotate(-30.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape({0.023, -0.17, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.46f, 0.13f * _size, 0.0f);
	modelStack.rotate(-40.0f, 'Z');
	modelStack.rotate(-25.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape({0.023, -0.17, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.5f, 0.13f * _size, 0.01f);
	modelStack.rotate(-45.0f, 'Z');
	modelStack.rotate(-30.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape({0.023, -0.19, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_right_wing1_2(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	// modelStack.translate(-0.2f, 0.2f * _size, 0.0f);
	// modelStack.translate(0.27f, -0.2f * _size, 0.0f);
	float angle1_2 = sin(_opening_frame * 1.1) * 20;
	if (_open_wings == true) {
		modelStack.translate(-0.2f, 0.2f * _size, 0.0f);
		modelStack.rotate(-40.0f, 'Z');//-
		if (angle1_2 >= 40.0f)
			modelStack.rotate(20.0f, 'Y');
		else
			modelStack.rotate(60.0f - angle1_2, 'Y');
		if (angle1_2 >= 30.0f)
			modelStack.rotate(0.0f, 'X');
		else
			modelStack.rotate(-30.0f + angle1_2, 'X');
		modelStack.translate(0.27f, -0.2f * _size, 0.0f);
	} else {
		modelStack.translate(-0.2f, 0.2f * _size, 0.0f);
		modelStack.rotate(-40.0f, 'Z');//-
		if (angle1_2 >= 40.0f)
			modelStack.rotate(60.0f, 'Y');
		else
			modelStack.rotate(20.0f + angle1_2, 'Y');
		if (angle1_2 >= 30.0f)
			modelStack.rotate(-30.0f, 'X');
		else
			modelStack.rotate(0.0f - angle1_2, 'X');
		modelStack.translate(0.27f, -0.2f * _size, 0.0f);
	}
	// draw_paving_shape({-0.5, 0.15, 0.0}, {-0.25, 0.2, -0.02}, wings_color, shader, modelStack);
	(void)shader;
	(void)modelStack;
	(void)wings_color;
}

void Human::draw_right_wing(float wings_color, Shaders &shader, ModelStack &modelStack)
{
	float	color[3]	= { 1.00f, 1.00f, 1.00f };
	// modelStack.push();

	color[0]	= 0.1f + wings_color;
	color[2]	= 0.1f + wings_color;
	color[1]	= 0.1f + wings_color;
	
	draw_right_wing1_1(color, shader, modelStack);

	color[0]	= 0.2f + wings_color;
	color[2]	= 0.2f + wings_color;
	color[1]	= 0.2f + wings_color;

	draw_right_wing1_1_1(color, shader, modelStack);

	color[0]	= 0.3f + wings_color;
	color[2]	= 0.3f + wings_color;
	color[1]	= 0.3f + wings_color;

	draw_right_wing1_1_2(color, shader, modelStack);

	color[0]	= 0.4f + wings_color;
	color[2]	= 0.4f + wings_color;
	color[1]	= 0.4f + wings_color;

	draw_right_wing1_1_3(color, shader, modelStack);


	color[0]	= 0.1f + wings_color;
	color[2]	= 0.1f + wings_color;
	color[1]	= 0.1f + wings_color;

	draw_right_wing1_2(color, shader, modelStack);

	color[0]	= 0.2f + wings_color;
	color[2]	= 0.2f + wings_color;
	color[1]	= 0.2f + wings_color;

	draw_right_wing1_2_1(color, shader, modelStack);

	color[0]	= 0.3f + wings_color;
	color[2]	= 0.3f + wings_color;
	color[1]	= 0.3f + wings_color;

	draw_right_wing1_2_2(color, shader, modelStack);

	color[0]	= 0.4f + wings_color;
	color[2]	= 0.4f + wings_color;
	color[1]	= 0.4f + wings_color;

	draw_right_wing1_2_3(color, shader, modelStack);

	// modelStack.pop();
}

void Human::draw_left_wing(float wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.scale(-1, 1, 1);
	draw_right_wing(wings_color, shader, modelStack);
	modelStack.pop();
}

void	Human::draw_wings(ModelStack &modelStack, Shaders &shader)
{
	float	wings_color	= 1.0f;

	modelStack.push();
	draw_right_wing(wings_color, shader, modelStack);
	modelStack.pop();

	// modelStack.push();
	// modelStack.rotate(-175.0f, 'Z');
	// modelStack.translate(0.0f, -0.15f * _size, 0.0f);
	// draw_right_wing(wings_color, shader, modelStack);
	// modelStack.pop();

	modelStack.push();
	draw_left_wing(wings_color, shader, modelStack);
	modelStack.pop();

	// modelStack.push();
	// modelStack.rotate(175.0f, 'Z');
	// modelStack.translate(0.0f, -0.15f * _size, 0.0f);
	// draw_left_wing(wings_color, shader, modelStack);
	// modelStack.pop();
}