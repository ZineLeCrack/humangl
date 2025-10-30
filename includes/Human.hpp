#pragma once

#include "Includes.hpp"
#include "Hand.hpp"
class Hand;

class Human
{
	private:

		float	_rotX = 0.0f;
		float	_rotY = 0.0f;

		float	_zoom = 16.0f;
		float	_size = 1.0f;

		float	_foots_color[3]	= { 0.20f, 0.20f, 0.20f };
		float	_legs_color[3]	= { 0.00f, 0.00f, 1.00f };
		float	_body_color[3]	= { 0.00f, 0.70f, 0.00f };
		float	_skin_color[3]	= { 0.96f, 0.87f, 0.70f };

		int		_animation			= STAY;
		double	_animation_frame	= 0;

		bool	_use_texture	= false;
		GLuint	_tex			= 0;

		bool	_slim = false;

		Hand	*_rightHand;

	public:

		bool	_showBody;
		bool	_showHead;

		bool	_showRightUpperArm;
		bool	_showRightForearm;
		bool	_showLeftUpperArm;
		bool	_showLeftForearm;

		bool	_showRightTigh;
		bool	_showRightLowerLeg;
		bool	_showLeftTigh;
		bool	_showLeftLowerLeg;

		bool	_showRightFoot;
		bool	_showLeftFoot;

		Human();
		~Human();

		float	&get_rotX() 			{ return _rotX; }
		float	&get_rotY() 			{ return _rotY; }
		float	&get_zoom() 			{ return _zoom; }
		float	&get_size()				{ return _size; }
		float	*get_foots_color()		{ return _foots_color; }
		float	*get_legs_color()		{ return _legs_color; }
		float	*get_body_color()		{ return _body_color; }
		float	*get_skin_color()		{ return _skin_color; }
		int		&get_animation()		{ return _animation; }
		double	&get_animation_frame()	{ return _animation_frame; }
		bool	&get_use_texture()		{ return _use_texture; }
		GLuint	&get_texture()			{ return _tex; }
		bool	&get_slim()				{ return _slim; }

		void	set_foots_color(float r, float g, float b)	{ _foots_color[0] = r, _foots_color[1] = g, _foots_color[2] = b; };
		void	set_legs_color(float r, float g, float b)	{ _legs_color[0]  = r, _legs_color[1]  = g, _legs_color[2]  = b; };
		void	set_body_color(float r, float g, float b)	{ _body_color[0]  = r, _body_color[1]  = g, _body_color[2]  = b; };
		void	set_skin_color(float r, float g, float b)	{ _skin_color[0]  = r, _skin_color[1]  = g, _skin_color[2]  = b; };
		void	set_texture(GLuint tex)				{ _tex = tex; }

		void	change_texture()					{ _use_texture = !_use_texture; }
		void	change_slim()						{ _slim = !_slim; }

		void	draw(ModelStack &modelStack, Shaders &shader);
		void	draw_body(ModelStack &modelStack, Shaders &shader);
		void	draw_head(ModelStack &modelStack, Shaders &shader);

		/*Right arm*/
		void	draw_right_arm(ModelStack &modelStack, Shaders &shader, float angle);
		void	draw_right_upper_arm(ModelStack &modelStack, Shaders &shader);
		void	draw_right_shoulder(ModelStack &modelStack, Shaders &shader);
		void	draw_right_forearm(ModelStack &modelStack, Shaders &shader);

		/*Left arm*/
		void	draw_left_arm(ModelStack &modelStack, Shaders &shader, float angle);
		void	draw_left_upper_arm(ModelStack &modelStack, Shaders &shader);
		void	draw_left_shoulder(ModelStack &modelStack, Shaders &shader);
		void	draw_left_forearm(ModelStack &modelStack, Shaders &shader);

		/*Right leg*/
		void	draw_right_leg(ModelStack &modelStack, Shaders &shader, float angle);
		void	draw_right_thigh(ModelStack &modelStack, Shaders &shader);
		void	draw_right_lower_leg(ModelStack &modelStack, Shaders &shader);
		void	draw_right_foot(ModelStack &modelStack, Shaders &shader);

		/*Left leg*/
		void	draw_left_leg(ModelStack &modelStack, Shaders &shader, float angle);
		void	draw_left_thigh(ModelStack &modelStack, Shaders &shader);
		void	draw_left_lower_leg(ModelStack &modelStack, Shaders &shader);
		void	draw_left_foot(ModelStack &modelStack, Shaders &shader);
};
