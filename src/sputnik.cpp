#include "sputnik.hpp"
#include <math.h>

#include <iostream>

namespace space
{
	Universe::Universe(double orbita_a, double orbita_b, double center_x, double center_y, double speed)
	{
		orbita_a_ = orbita_a;
		orbita_b_ = orbita_b;
		center_x_ = center_x;
		center_y_ = center_y;

		speed_ = speed;
	}

	bool Universe::init(std::string img_path, double scale)
	{
		if (!texture_.loadFromFile(img_path)) {
			std::cout << "ERROR when loading " + img_path << std::endl;
			return false;
		}

		sprite_.setTexture(texture_);
		sprite_.setScale(scale, scale);
		//      
		sprite_.setOrigin(texture_.getSize().x / 1, texture_.getSize().y / 1);
		sprite_.setPosition(center_x_, center_y_);
		return true;
	}

	void Universe::get_pose(double time, double& x, double& y)
	{
		x = orbita_a_ * cos(time) + center_x_;
		y = orbita_b_ * sin(time) + center_y_;
	}

	void Universe::draw(double time, sf::RenderWindow* window)
	{
		double new_x;
		double new_y;
		get_pose(time * speed_, new_x, new_y);
		sprite_.setPosition(new_x, new_y);
		window->draw(sprite_);
	}
}
