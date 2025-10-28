#include "Hand.hpp"

Hand::Hand():_attribut("none") {}

Hand::Hand(string attribut):_attribut(attribut) {}

Hand::~Hand() {}

void Hand::draw(float _skin_color[3], ModelStack &modelStack, Shaders &shader)
{
	//base
	(void)_skin_color;
	(void)shader;
	modelStack.push();
	modelStack.translate(-0.175f, -0.1001f, 0.0f);
	draw_paving_shape({-0.05f, -0.001f, -0.0f}, {0.05f, -0.0f,  0.01f}, _skin_color, shader, modelStack);

	modelStack.pop();

	//index
}
