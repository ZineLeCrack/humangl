#include "Hand.hpp"

Hand::Hand():_attribut("none") {}

Hand::Hand(string attribut):_attribut(attribut) {}

Hand::~Hand() {}

void Hand::draw(float _skin_color[3], ModelStack &modelStack, Shaders &shader)
{
	//base

	(void)_skin_color;
	// (void)shader;
	// (void)modelStack;
	modelStack.push();
	modelStack.translate(-0.175f, -0.1001f, 0.0f);

	float red[3] ={1.0f, 0.0f, 0.0f};
	modelStack.push();
	modelStack.translate(-0.042f, -0.007f, 0.039f);
	modelStack.rotate(littleFingerPhalangeAngle[0], 'X');
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, shader, modelStack); //debug

	draw_paving_shape({-0.008f, -0.007f, 0.0107f}, {0.008f, 0.007f, -0.0107}, _skin_color, shader, modelStack);

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.02f);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, shader, modelStack); //debug
	modelStack.rotate(littleFingerPhalangeAngle[1], 'X');
	draw_paving_shape({-0.008f, -0.007f, 0.0107f}, {0.008f, 0.007f, -0.0107f}, _skin_color, shader, modelStack);

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.02f);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, shader, modelStack); //debug
	modelStack.rotate(littleFingerPhalangeAngle[2], 'X');
	draw_paving_shape({-0.008f, -0.007f, 0.0107f}, {0.008f, 0.007f, -0.0107f}, _skin_color, shader, modelStack);


	modelStack.pop(); // second phalange
	modelStack.pop(); // first phalange
	modelStack.pop(); // base
}
