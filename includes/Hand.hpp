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
		void draw(float _skin_color[3], ModelStack &modelStack, Shaders &shader);
};
