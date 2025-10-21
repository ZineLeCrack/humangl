#pragma once

#include "Includes.hpp"

class Human
{
	private:

		float	_foots_color[3]	= { 0.20f, 0.20f, 0.20f };
		float	_legs_color[3]	= { 0.00f, 0.00f, 1.00f };
		float	_body_color[3]	= { 0.00f, 0.70f, 0.00f };
		float	_arms_color[3]	= { 0.96f, 0.87f, 0.70f };
		float	_head_color[3]	= { 0.96f, 0.87f, 0.70f };

	public:

		Human()		{};
		~Human()	{};

		void	set_foots_color(float r, float g, float b)	{ _foots_color[0] = r, _foots_color[1] = g, _foots_color[2] = b; };
		void	set_legs_color(float r, float g, float b)	{ _legs_color[0]  = r, _legs_color[1]  = g, _legs_color[2]  = b; };

		void	draw_legs();
		void	draw_body();
		void	draw_arms();
		void	draw_head();
};
