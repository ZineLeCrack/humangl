#pragma once

#include "Includes.hpp"

class Human
{
	private:

		float	_rotX = 0.0f;
		float	_rotY = 0.0f;

		float	_zoom = 16.0f;

		float	_foots_color[3]	= { 0.20f, 0.20f, 0.20f };
		float	_legs_color[3]	= { 0.00f, 0.00f, 1.00f };
		float	_body_color[3]	= { 0.00f, 0.70f, 0.00f };
		float	_arms_color[3]	= { 0.96f, 0.87f, 0.70f };
		float	_head_color[3]	= { 0.96f, 0.87f, 0.70f };

		int		_animation			= STAY;
		double	_animation_frame	= 0;

	public:

		Human()		{};
		~Human()	{};

		float	&get_rotX() 			{ return _rotX; }
		float	&get_rotY() 			{ return _rotY; }
		float	&get_zoom() 			{ return _zoom; }
		float	*get_foots_color()		{ return _foots_color; }
		float	*get_legs_color()		{ return _legs_color; }
		float	*get_body_color()		{ return _body_color; }
		float	*get_arms_color()		{ return _arms_color; }
		float	*get_head_color()		{ return _head_color; }
		int		&get_animation()		{ return _animation; }
		double	&get_animation_frame()	{ return _animation_frame; }

		void	set_foots_color(float r, float g, float b)	{ _foots_color[0] = r, _foots_color[1] = g, _foots_color[2] = b; };
		void	set_legs_color(float r, float g, float b)	{ _legs_color[0]  = r, _legs_color[1]  = g, _legs_color[2]  = b; };
		void	set_body_color(float r, float g, float b)	{ _body_color[0]  = r, _body_color[1]  = g, _body_color[2]  = b; };
		void	set_arms_color(float r, float g, float b)	{ _arms_color[0]  = r, _arms_color[1]  = g, _arms_color[2]  = b; };
		void	set_head_color(float r, float g, float b)	{ _head_color[0]  = r, _head_color[1]  = g, _head_color[2]  = b; };

		void	draw_legs();
		void	draw_body();
		void	draw_arms();
		void	draw_head();
};
