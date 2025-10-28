#include "Hand.hpp"

Hand::Hand():_attribut("none") {}

Hand::Hand(string attribut):_attribut(attribut) {}

Hand::~Hand() {}

void Hand::draw(float _skin_color[3], ModelStack &modelStack, Shaders &shader)
{
	//base

	modelStack.push();
	modelStack.translate(-0.175f, -0.1001f, 0.0f);
	// draw_paving_shape({-0.05f, -0.0001f, -0.05f}, {0.05f, -0.0f,  0.05f}, _skin_color, shader, modelStack);

	modelStack.push();
	modelStack.translate(-0.02f, 0.0f, 0.0f);
	// modelStack.rotate(-30, 'X');
	draw_paving_shape({-0.03f, -0.02f, 0.05f}, {-0.01f, -0.0f,  0.03f}, _skin_color, shader, modelStack);

	modelStack.push();
	modelStack.translate(-0.02f, 0.0f, -0.02f);
	// modelStack.rotate(10, 'X');
	draw_paving_shape({-0.01f, -0.02f, 0.05f}, {0.01f, -0.0f,  0.025f}, _skin_color, shader, modelStack);

	modelStack.pop(); // second phalange
	modelStack.pop(); // first phalange
	modelStack.pop(); // base
}
