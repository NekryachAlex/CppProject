#pragma once

#include <SFML/Graphics.hpp>



namespace figures 
{
	template <typename T>
	inline void easy_line(const sf::Vector2f& vector1, const sf::Vector2f& vector2, T& window, sf::Color color = sf::Color::Black) {
		sf::Vertex vtx[] = {sf::Vertex(vector1), sf::Vertex(vector2) };
		vtx[0].color = vtx[1].color = color;
	    window.draw(vtx, 2, sf::LinesStrip);
	}

	template <typename T>
	inline void easy_circle(const sf::Vector2f& position, float r, T& window, sf::Color color = sf::Color::Black) {
		sf::CircleShape circle(r);
		circle.setFillColor(color);
		circle.setPosition(sf::Vector2f(position - sf::Vector2f(r, r)));

		window.draw(circle);
	}
}
