#include "Hand.hpp"
float red[3] ={1.0f, 0.0f, 0.0f};

Hand::Hand():_attribut("none") {}

Hand::Hand(string attribut):_attribut(attribut) {}

Hand::~Hand() {}

void Hand::reset(int idx)
{
	switch (idx)
	{
		case 0:
			thumbFingerPhalangeAngle[0] = 0.0f;
			thumbFingerPhalangeAngle[1] = 0.0f;
			break;
		case 1:
			indexFingerPhalangeAngle[0] = 0.0f;
			indexFingerPhalangeAngle[1] = 0.0f;
			indexFingerPhalangeAngle[2] = 0.0f;
			break;
		case 2:
			middleFingerPhalangeAngle[0] = 0.0f;
			middleFingerPhalangeAngle[1] = 0.0f;
			middleFingerPhalangeAngle[2] = 0.0f;
			break;
		case 3:
			ringFingerPhalangeAngle[0] = 0.0f;
			ringFingerPhalangeAngle[1] = 0.0f;
			ringFingerPhalangeAngle[2] = 0.0f;
			break;
		case 4:
			littleFingerPhalangeAngle[0] = 0.0f;
			littleFingerPhalangeAngle[1] = 0.0f;
			littleFingerPhalangeAngle[2] = 0.0f;
			break;
		default:
			thumbFingerPhalangeAngle[0] = 0.0f;
			thumbFingerPhalangeAngle[1] = 0.0f;
			indexFingerPhalangeAngle[0] = 0.0f;
			indexFingerPhalangeAngle[1] = 0.0f;
			indexFingerPhalangeAngle[2] = 0.0f;
			middleFingerPhalangeAngle[0] = 0.0f;
			middleFingerPhalangeAngle[1] = 0.0f;
			middleFingerPhalangeAngle[2] = 0.0f;
			ringFingerPhalangeAngle[0] = 0.0f;
			ringFingerPhalangeAngle[1] = 0.0f;
			ringFingerPhalangeAngle[2] = 0.0f;
			littleFingerPhalangeAngle[0] = 0.0f;
			littleFingerPhalangeAngle[1] = 0.0f;
			littleFingerPhalangeAngle[2] = 0.0f;
			break;
	}
}

void Hand::drawThumbFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader)
{
	(void)_skin_color;
	modelStack.push();
	if (_attribut == "right") modelStack.translate(0.043f, -0.007f, -0.0382f);
	else modelStack.translate(-0.043f, -0.007f, -0.0382f);
	
	modelStack.rotate(thumbFingerPhalangeAngle[0], 'Z');
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	if (_attribut == "right") draw_paving_shape({-0.021f, -0.007f, -0.0114f}, {0.007f, 0.007f, 0.0114f}, _skin_color, _size, shader, modelStack);
	else draw_paving_shape({0.021f, -0.007f, -0.0114f}, {-0.007f, 0.007f, 0.0114f}, _skin_color, _size, shader, modelStack);

	modelStack.push();
	if (_attribut == "right") modelStack.translate(-0.0214f, 0.00f, 0.0f);
	else modelStack.translate(0.0214f, 0.00f, 0.0f);

	modelStack.rotate(thumbFingerPhalangeAngle[1], 'Z');
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug
	if (_attribut == "right") draw_paving_shape({-0.0217f, -0.007f, -0.0114f}, {0.01f, 0.007f, 0.0114f}, _skin_color, _size, shader, modelStack);
	else draw_paving_shape({0.0217f, -0.007f, -0.0114f}, {-0.01f, 0.007f, 0.0114f}, _skin_color, _size, shader, modelStack);

	modelStack.pop();
	modelStack.pop();
}

void Hand::drawIndexFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader)
{
	//Z max 59 / 3 -> 19.6
	modelStack.push();
	if (_attribut == "right") modelStack.translate(0.035f, -0.007f, 0.043f);
	else modelStack.translate(-0.04f, -0.007f, 0.043f);
	
	modelStack.rotate(indexFingerPhalangeAngle[0], 'X');
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug
	draw_paving_shape({-0.01f, -0.007f, -0.0196f}, {0.015f, 0.007f, 0.007f}, _skin_color, _size, shader, modelStack);

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.0206f);
	modelStack.rotate(indexFingerPhalangeAngle[1], 'X');
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	draw_paving_shape({-0.01f, -0.007f, -0.0196f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.0206f);
	modelStack.rotate(indexFingerPhalangeAngle[2], 'X');
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	draw_paving_shape({-0.01f, -0.007f, -0.0196f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);

	modelStack.pop();
	modelStack.pop();
	modelStack.pop();
}

void Hand::drawMiddleFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader)
{
	//Z max 68 / 3 -> 22.6
	modelStack.push();
	if (_attribut == "right") modelStack.translate(0.01f, -0.007f, 0.043f);
	else modelStack.translate(-0.015f, -0.007f, 0.043f);

	modelStack.rotate(middleFingerPhalangeAngle[0], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.0226f}, {0.015f, 0.007f, 0.007f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.0236f);
	modelStack.rotate(middleFingerPhalangeAngle[1], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.0226f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.0236f);
	modelStack.rotate(middleFingerPhalangeAngle[2], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.0226f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.pop();
	modelStack.pop();
	modelStack.pop();
}

void Hand::drawRingFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader)
{
	//Z max 62 / 3 -> 20.6
	modelStack.push();
	if (_attribut == "right") modelStack.translate(-0.015f, -0.007f, 0.043f);
	else modelStack.translate(0.01f, -0.007f, 0.043f);

	modelStack.rotate(ringFingerPhalangeAngle[0], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.0206f}, {0.015f, 0.007f, 0.007f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.0216f);
	modelStack.rotate(ringFingerPhalangeAngle[1], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.0206f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.0216f);
	modelStack.rotate(ringFingerPhalangeAngle[2], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.0206f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.pop();
	modelStack.pop();
	modelStack.pop();
}

void Hand::drawLittleFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader)
{
	modelStack.push();
	if (_attribut == "right") modelStack.translate(-0.039f, -0.007f, 0.043f);
	else modelStack.translate(0.035f, -0.007f, 0.043f);

	modelStack.rotate(littleFingerPhalangeAngle[0], 'X');
	draw_paving_shape({-0.001f,  -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug
	draw_paving_shape({-0.01f, -0.007f, -0.014f}, {0.015f, 0.007f, 0.007f}, _skin_color, _size, shader, modelStack);

	modelStack.push();
	modelStack.translate(0.0f, -0.0f, -0.015f);
	modelStack.rotate(littleFingerPhalangeAngle[1], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.014f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f, -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.push();
	modelStack.translate(0.0f, 0.0f, -0.015f);
	modelStack.rotate(littleFingerPhalangeAngle[2], 'X');
	draw_paving_shape({-0.01f, -0.007f, -0.014f}, {0.015f, 0.007f, 0.001f}, _skin_color, _size, shader, modelStack);
	draw_paving_shape({-0.001f, -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack); //debug

	modelStack.pop(); // third phalange
	modelStack.pop(); // second phalange
	modelStack.pop(); // first phalange
}

void Hand::draw(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader)
{
	modelStack.push();
	if (!_attribut.compare("right"))
		modelStack.translate(-0.175f, -0.1001f, 0.0f);
	else if (!_attribut.compare("left"))
		modelStack.translate(0.175f, -0.1001f, 0.0f);

	draw_paving_shape({-0.001f, -0.001f, 0.001f}, { 0.001f, 0.001f, -0.001f}, red, _size, shader, modelStack);

	drawLittleFinger(_skin_color, _size, modelStack, shader);
	drawRingFinger(_skin_color, _size, modelStack, shader);
	drawMiddleFinger(_skin_color, _size, modelStack, shader);
	drawIndexFinger(_skin_color, _size, modelStack, shader);
	drawThumbFinger(_skin_color, _size, modelStack, shader);

	modelStack.pop();
}
