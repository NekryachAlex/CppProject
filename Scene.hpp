#pragma once

#include "SfDraw.hpp"
#include "Interaction.hpp"
#include "PhysicalObject.hpp"
#include <vector>
#include <memory>



class Scene : public SfDraw
{
public:
	Scene(sf::Color _color, std::shared_ptr<sf::RenderWindow> _window) : SfDraw{_color, _window} {}
	std::vector<std::shared_ptr<PhysicalObject>> objects{};
	double delta_time = 0.01;

	void update();

	void draw() override;


	void add_object(std::shared_ptr<PhysicalObject>);
	void set_window(std::shared_ptr<sf::RenderWindow> w) override;


private:
    sf::Clock delta_clock;
	std::vector<Interaction> interactions{};
};

