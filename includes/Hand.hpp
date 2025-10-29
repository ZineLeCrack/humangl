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

		void	draw(float _skin_color[3], ModelStack &modelStack, Shaders &shader);
};
