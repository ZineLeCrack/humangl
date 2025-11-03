#include "Human.hpp"

void Human::draw_paving_shape_for_wing(const Vec3 &a, const Vec3 &b, const float color[3], Shaders &shader, ModelStack &modelStack)
{
	if (_showWings == true) {
		draw_rect({a.x, a.y * _size * _body_size, a.z}, {b.x, b.y * _size * _body_size, a.z}, color, 0, 0, 0, 0, false, shader, true, modelStack);
		draw_rect({a.x, a.y * _size * _body_size, b.z}, {b.x, b.y * _size * _body_size, b.z}, color, 0, 0, 0, 0, false, shader, true, modelStack);

		draw_rect({a.x, a.y * _size * _body_size, a.z}, {a.x, b.y * _size * _body_size, b.z}, color, 0, 0, 0, 0, false, shader, true, modelStack);
		draw_rect({b.x, a.y * _size * _body_size, a.z}, {b.x, b.y * _size * _body_size, b.z}, color, 0, 0, 0, 0, false, shader, true, modelStack);

		draw_rect({a.x, a.y * _size * _body_size, a.z}, {b.x, a.y * _size * _body_size, b.z}, color, 0, 0, 0, 0, false, shader, true, modelStack);
		draw_rect({a.x, b.y * _size * _body_size, a.z}, {b.x, b.y * _size * _body_size, b.z}, color, 0, 0, 0, 0, false, shader, true, modelStack);
	}
}

void Human::draw_wing1_1_1(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.06f, 0.18f * _size * _body_size, -0.01f);
	modelStack.rotate(20.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.09f, 0.18f * _size * _body_size, -0.01f);
	modelStack.rotate(0.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.09, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.13f, 0.18f * _size * _body_size, -0.01f);
	modelStack.rotate(-5.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.17f, 0.18f * _size * _body_size, -0.01f);
	modelStack.rotate(-10.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_wing1_1_2(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.05f, 0.12f * _size * _body_size, -0.009f);
	modelStack.rotate(20.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.09f, 0.12f * _size * _body_size, -0.009f);
	modelStack.rotate(10.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.14f, 0.12f * _size * _body_size, -0.009f);
	modelStack.rotate(7.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.18f, 0.12f * _size * _body_size, -0.009f);
	modelStack.rotate(-3.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_wing1_1_3(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.06f, 0.1f * _size * _body_size, -0.008f);
	modelStack.rotate(20.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.1f, 0.1f * _size * _body_size, -0.008f);
	modelStack.rotate(10.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.135f, 0.1f * _size * _body_size, -0.008f);
	modelStack.rotate(10.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.17f, 0.1f * _size * _body_size, -0.008f);
	modelStack.rotate(5.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_wing1_2_1(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.26f, 0.185f * _size * _body_size, -0.012f);
	modelStack.rotate(20.0f, 'Z');
	modelStack.rotate(-20.0f, 'Y');
	draw_paving_shape_for_wing({0.025, -0.05, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.29f, 0.18f * _size * _body_size, -0.012f);
	modelStack.rotate(5.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.06, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.34f, 0.18f * _size * _body_size, -0.012f);
	modelStack.rotate(0.0f, 'Z');
	draw_paving_shape_for_wing({0.025, -0.05, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.39f, 0.18f * _size * _body_size, -0.012f);
	modelStack.rotate(-3.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape_for_wing({0.025, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.43f, 0.18f * _size * _body_size, -0.012f);
	modelStack.rotate(-8.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape_for_wing({0.025, -0.06, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.47f, 0.18f * _size * _body_size, -0.01f);
	modelStack.rotate(-28.0f, 'Z');
	modelStack.rotate(-15.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape_for_wing({0.025, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_wing1_2_2(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.25f, 0.15f * _size * _body_size, -0.008f);
	modelStack.rotate(30.0f, 'Z');
	modelStack.rotate(-15.0f, 'X');
	modelStack.rotate(-10.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.09, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.27f, 0.17f * _size * _body_size, -0.01f);
	modelStack.rotate(20.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape_for_wing({0.023, -0.125, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.30f, 0.17f * _size * _body_size, -0.01f);
	modelStack.rotate(10.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape_for_wing({0.023, -0.135, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.33f, 0.17f * _size * _body_size, -0.01f);
	modelStack.rotate(0.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape_for_wing({0.023, -0.13, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.36f, 0.17f * _size * _body_size, -0.01f);
	modelStack.rotate(-5.0f, 'Z');
	modelStack.rotate(-10.0f, 'X');
	draw_paving_shape_for_wing({0.023, -0.12, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_wing1_2_3(float *wings_color, Shaders &shader, ModelStack &modelStack)
{
	modelStack.push();
	modelStack.translate(-0.2f, 0.1f * _size * _body_size, 0.009f);
	modelStack.rotate(40.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(-20.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.07, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.23f, 0.08f * _size * _body_size, 0.0f);
	modelStack.rotate(30.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(-10.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.065, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.26f, 0.07f * _size * _body_size, 0.0f);
	modelStack.rotate(10.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	draw_paving_shape_for_wing({0.023, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.3f, 0.07f * _size * _body_size, 0.0f);
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.08, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.34f, 0.07f * _size * _body_size, 0.0f);
	modelStack.rotate(-10.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.09, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.37f, 0.07f * _size * _body_size, 0.0f);
	modelStack.rotate(-20.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.1, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.39f, 0.11f * _size * _body_size, 0.0f);
	modelStack.rotate(-30.0f, 'Z');
	modelStack.rotate(-15.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.15, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.43f, 0.125f * _size * _body_size, 0.0f);
	modelStack.rotate(-30.0f, 'Z');
	modelStack.rotate(-20.0f, 'X');
	modelStack.rotate(5.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.17, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.46f, 0.13f * _size * _body_size, 0.0f);
	modelStack.rotate(-40.0f, 'Z');
	modelStack.rotate(-25.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.17, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();

	modelStack.push();
	modelStack.translate(-0.5f, 0.13f * _size * _body_size, 0.01f);
	modelStack.rotate(-45.0f, 'Z');
	modelStack.rotate(-30.0f, 'X');
	modelStack.rotate(10.0f, 'Y');
	draw_paving_shape_for_wing({0.023, -0.19, 0.01}, {-0.025, 0.0, -0.01}, wings_color, shader, modelStack);
	modelStack.pop();
}

void Human::draw_wing(float wings_color, Shaders &shader, ModelStack &modelStack, float angle)
{
	float	color[3]	= { 1.00f, 1.00f, 1.00f };

	modelStack.translate(-0.05f, 0.25f * _size * _body_size, -0.051f);
	if (_animation == FLY) {
		if (angle > 0) {
			modelStack.rotate(-20.0f - angle * 0.5f, 'Z');
			modelStack.rotate(-20 + angle * 0.5f, 'Y');
		} else {
			modelStack.rotate(-20.0f - angle, 'Z');
			modelStack.rotate(-20 + angle, 'Y');
		}
	} else {
		modelStack.rotate(-20.0f, 'Z');
		modelStack.rotate(-20, 'Y');
	}
	modelStack.translate(0.05f, -0.2f * _size * _body_size, 0.0f);

	color[0]	= 0.2f + wings_color;
	color[2]	= 0.2f + wings_color;
	color[1]	= 0.2f + wings_color;

	draw_wing1_1_1(color, shader, modelStack);

	color[0]	= 0.3f + wings_color;
	color[2]	= 0.3f + wings_color;
	color[1]	= 0.3f + wings_color;

	draw_wing1_1_2(color, shader, modelStack);

	color[0]	= 0.4f + wings_color;
	color[2]	= 0.4f + wings_color;
	color[1]	= 0.4f + wings_color;

	draw_wing1_1_3(color, shader, modelStack);

	modelStack.translate(-0.2f, 0.2f * _size * _body_size, 0.0f);
	modelStack.rotate(-40.0f, 'Z');
	if (_animation == FLY) {
		modelStack.rotate(20.0f + angle * 0.5f, 'Y');
		modelStack.rotate(0.0f - angle * 0.5f, 'X');
	} else {
		modelStack.rotate(20.0f, 'Y');
		modelStack.rotate(0.0f, 'X');
	}
	modelStack.translate(0.27f, -0.2f * _size * _body_size, 0.0f);

	color[0]	= 0.2f + wings_color;
	color[2]	= 0.2f + wings_color;
	color[1]	= 0.2f + wings_color;

	draw_wing1_2_1(color, shader, modelStack);

	color[0]	= 0.3f + wings_color;
	color[2]	= 0.3f + wings_color;
	color[1]	= 0.3f + wings_color;

	draw_wing1_2_2(color, shader, modelStack);

	color[0]	= 0.4f + wings_color;
	color[2]	= 0.4f + wings_color;
	color[1]	= 0.4f + wings_color;

	draw_wing1_2_3(color, shader, modelStack);

}

void Human::draw_left_wing(float wings_color, Shaders &shader, ModelStack &modelStack, float angle)
{
	modelStack.push();
	modelStack.scale(-1.0f, 1.0f, 1.0f);
	draw_wing(wings_color, shader, modelStack, angle);
	modelStack.pop();
}

void Human::draw_right_wing(float wings_color, Shaders &shader, ModelStack &modelStack, float angle)
{
	modelStack.push();
	modelStack.scale(1.0f, 1.0f, 1.0f);
	draw_wing(wings_color, shader, modelStack, angle);
	modelStack.pop();
}

void	Human::draw_wings(ModelStack &modelStack, Shaders &shader, float angle)
{
	float	wings_color	= 1.0f;

	draw_right_wing(wings_color, shader, modelStack, angle);

	draw_left_wing(wings_color, shader, modelStack, angle);

}