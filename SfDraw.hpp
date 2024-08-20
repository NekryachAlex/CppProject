#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class SfDraw {
public:
    
    std::shared_ptr<sf::RenderWindow> window;
    sf::Color color;

    SfDraw() {}
    SfDraw(sf::Color _color, std::shared_ptr<sf::RenderWindow> _window) : color{ _color }, window{ _window }{}
    SfDraw(sf::Color _color = sf::Color::White) : color{ _color }{}
    virtual void draw() = 0;

    virtual void set_window(std::shared_ptr<sf::RenderWindow> window) {
        this->window = window;
    }
    
};
