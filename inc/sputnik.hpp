#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace space
{
	class Universe
	{
	public:
		Universe(double orbita_a, double orbita_b, double center_x, double center_y, double speed);

		bool init(std::string img_path, double radius);

		void get_pose(double time, double& x, double& y);

		void draw(double time, sf::RenderWindow* window);

	private:
		double orbita_a_ = 0;
		double orbita_b_ = 0;
		double speed_ = 0;
		double center_x_ = 0;
		double center_y_ = 0;

		sf::Sprite sprite_;
		sf::Texture texture_;
	};
}

