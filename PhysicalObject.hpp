#pragma once

#include <memory>

#include "Constants.hpp"
#include "algebra.hpp"
#include "figures.hpp"
#include "SfDraw.hpp"



class PhysicalObject : public SfDraw
{
    

public:
	PhysicalObject(float _mass, float bounciness, sf::Color color, std::shared_ptr<sf::RenderWindow> _window) : 
		mass{_mass}, bounciness{bounciness}, SfDraw{color, _window} {}
	PhysicalObject(float _mass, float bounciness, sf::Color color = sf::Color::White) : 
		mass{_mass}, bounciness{bounciness}, SfDraw{color} {}
	void update(float dt);

	void draw() override;
    float radius = 4;
    sf::Vector2f position = algebra::zero_vector, 
                 prev_position = algebra::zero_vector, 
                 velocity, 
                 acceleration;
	float mass, 
          bounciness; 
	bool collised = false;
};

