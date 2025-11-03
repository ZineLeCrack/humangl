#pragma once
#include "Includes.hpp"

class Hand
{
	private:

		string	_attribut; // right - left

	public:

		Hand();
		Hand(string attribut);
		~Hand();

		float	thumbFingerPhalangeAngle[2] = {0.0f, 0.0f};
		float	indexFingerPhalangeAngle[3] = {0.0f, 0.0f, 0.0f};
		float	middleFingerPhalangeAngle[3] = {0.0f, 0.0f, 0.0f};
		float	ringFingerPhalangeAngle[3] = {0.0f, 0.0f, 0.0f};
		float	littleFingerPhalangeAngle[3] = {0.0f, 0.0f, 0.0f};

		void	reset(int idx);

		void	draw(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader);
		void	drawThumbFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader);
		void	drawIndexFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader);
		void	drawMiddleFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader);
		void	drawRingFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader);
		void	drawLittleFinger(const float _skin_color[3], const float _size, ModelStack &modelStack, Shaders &shader);
};
