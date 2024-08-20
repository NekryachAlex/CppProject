#include <SFML/Graphics.hpp>
#include <memory>
#include <math.h>

#include "algebra.hpp"
#include "Constants.hpp"  
#include "figures.hpp" 
#include "Scene.hpp" 
#include "PhysicalObject.hpp"
#include "pattern_loop.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(W, H), "Gravity", sf::Style::Close | sf::Style::Titlebar, settings);
    window->setFramerateLimit(FPS);
    // Earth - 6e24, Moon - 7.3e22, Sun - 2e30

    Scene scene(sf::Color(20, 25, 30), window);


    auto star_ptr = std::make_shared<PhysicalObject>(1e6, 0.09, sf::Color::Yellow); 
    star_ptr->radius = 20;
    star_ptr->velocity = sf::Vector2f(0, 0);
    star_ptr->position = sf::Vector2f(W/2, H/2);

    scene.add_object(star_ptr);

    
    // auto planet_ptr = std::make_shared<PhysicalObject>(1e6, 0.02, sf::Color::Blue); 
    // planet_ptr->radius = 10;
    // planet_ptr->velocity = sf::Vector2f(0, -500);
    // planet_ptr->position = sf::Vector2f(W/2-300, H/2);
    // scene.add_object(planet_ptr);

    auto big_planet_ptr = std::make_shared<PhysicalObject>(1e4, 0.02, sf::Color::Red); 
    big_planet_ptr->radius = 13;
    big_planet_ptr->velocity = sf::Vector2f(0, -30);
    big_planet_ptr->position = sf::Vector2f(W/2-400, H/2);
    scene.add_object(big_planet_ptr);
    
    pattern_loop([&]
    {
       
        for (auto& object : scene.objects) {
    
            if (object->position.x < 0 or object->position.x > W) { 
                object->velocity.x *= -1.; 
                object->position.x = std::max(std::min(object->position.x, (float)W), (float)0.); 
            }
            if (object->position.y < 0 or object->position.y > H) { 
                object->velocity.y *= -1.; 
                object->position.y = std::max(std::min(object->position.y, (float)H), (float)0.);
            }
            
        }
        
        

    }, 
    scene);

    return 0;
}
