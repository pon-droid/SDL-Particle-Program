/*
 * Particle.cpp
 *
 *  Created on: 2 Sept 2021
 *      Author: tp
 */

#include "Particle.h"

namespace tbg {

Particle::Particle() {

	Init();

}

void Particle::Init(){
	par_x = 0;
	par_y = 0;
	direction = (2 * M_PI * rand())/RAND_MAX;
	speed = (0.04 * rand())/RAND_MAX;

	speed *= speed;



}

void Particle::Update(int interval) {



	double xspeed = speed * cos(direction);
	double yspeed = speed * sin(direction);

	par_x += xspeed * interval;
	par_y += yspeed * interval;

	 const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

	 if( currentKeyStates[SDL_SCANCODE_UP]){
		 direction += interval*0.0025;
	 }
	 if( currentKeyStates[SDL_SCANCODE_DOWN]){
		 direction -= interval*0.0025;
	 }

/*
	if(rand() < RAND_MAX/200){
		Init();
	}
*/

}

} /* namespace tbg */
