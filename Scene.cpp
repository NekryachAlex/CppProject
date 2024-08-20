#include <omp.h>


#include "Scene.hpp"

void Scene::draw() {
	for (auto& b : objects) b->draw();
}


void Scene::set_window(std::shared_ptr<sf::RenderWindow> w) { 
	window = w; 
	for (auto& existing_obj : objects) (*existing_obj).set_window(w);
}

void Scene::update() {
	double dt = 1. / FPS;

	#pragma omp parallel for	
	for (int i=0; i < objects.size(); i++) 
			objects[i]->update(dt);
	 
	#pragma omp parallel for	
	for (int i=0; i < interactions.size(); i++) {
		interactions[i].calc_force();
		interactions[i].do_collision();
	}
}

void Scene::add_object(std::shared_ptr<PhysicalObject> object) {
	(*object).set_window(window);
	for (auto& existing : objects) {
		Interaction new_interaction(existing, object);
		interactions.push_back(new_interaction);
	}
	objects.push_back(object);
}
