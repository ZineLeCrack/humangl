#include "Hand.hpp"

Hand::Hand():_attribut("none") {}

Hand::Hand(string attribut):_attribut(attribut) {}

Hand::~Hand() {}

void Hand::draw(float _skin_color[3], ModelStack &modelStack, Shaders &shader)
{
	draw_rect({-0.225f, -0.101f, -0.05f}, { -0.200f, -0.101f,  0.05f}, _skin_color, 0.0f, 0.0f, 0.0f, 0.0f, false, shader, modelStack);
}
