#pragma once

#include "Includes.hpp"

class Human
{
	private:

		float	_foots_color[3]	= { 0.2f, 0.2f, 0.2f };
		float	_legs_color[3]	= { 0.0f, 0.0f, 1.0f };

	public:

		Human()		{};
		~Human()	{};

		void	set_foots_color(float r, float g, float b)	{ _foots_color[0] = r, _foots_color[1] = g, _foots_color[2] = b; };
		void	set_legs_color(float r, float g, float b)	{ _legs_color[0]  = r, _legs_color[1]  = g, _legs_color[2]  = b; };

		void	draw_legs();
};
