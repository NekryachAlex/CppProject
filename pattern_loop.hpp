#include <SFML/Graphics.hpp>

#include "Scene.hpp"

template<typename T>
void pattern_loop(T actions, Scene& scene) {
	bool is_focuse = true;
	while (scene.window->isOpen())
	{

		sf::Event e;
		while (scene.window->pollEvent(e)) {
			if (e.type == sf::Event::Closed) scene.window->close();

			if (e.type == sf::Event::LostFocus) is_focuse = false;
			if (e.type == sf::Event::GainedFocus) is_focuse = true;
		}
		if (!is_focuse) continue;

		scene.window->clear(scene.color);

		scene.draw();
		
		actions();
		
		scene.update();

		scene.window->display();
	}
}