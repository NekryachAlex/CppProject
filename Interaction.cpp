#include "Interaction.hpp"
#include <iostream>

void Interaction::calc_force() {
    if (algebra::dist((*object1).position, (*object2).position) < (*object1).radius + (*object2).radius) return;

	sf::Vector2f dir_for_grav = ((*object1).position - (*object2).position) / (float)pow(algebra::length(((*object1).position - (*object2).position)), 3);
	(*object1).acceleration -= dir_for_grav * (*object2).mass;
	(*object2).acceleration += dir_for_grav * (*object1).mass;
}

void Interaction::do_collision() {

    if (algebra::dist((*object1).position, (*object2).position) < (*object1).radius + (*object2).radius) {
	 
	 
		float mass1 = (*object1).mass;
		float mass2 = (*object2).mass;
		float angle_for_calc = algebra::angle((*object2).position-(*object1).position);

		if ((*object1).mass > (*object2).mass){
			(*object2).position = (*object1).position - algebra::norm((*object1).position - (*object2).position) * ((*object1).radius + (*object2).radius);
		}
		else{
			(*object1).position = (*object2).position - algebra::norm((*object1).position - (*object2).position) * ((*object1).radius + (*object2).radius);	
		}
		
		

		sf::Vector2f v1_proj = algebra::rotate((*object1).velocity, - angle_for_calc);
		sf::Vector2f v2_proj = algebra::rotate((*object2).velocity, - angle_for_calc);

		sf::Vector2f previous_v1_proj = v1_proj;
		v1_proj.x -= (1+(*object1).bounciness) * mass2 / (mass1+mass2) * (v1_proj.x - v2_proj.x);
		v2_proj.x += (1+(*object2).bounciness) * mass1 / (mass1+mass2) * (previous_v1_proj.x - v2_proj.x);
		
		(*object1).velocity = algebra::rotate(v1_proj, angle_for_calc);
		(*object2).velocity = algebra::rotate(v2_proj, angle_for_calc);
	}
}
