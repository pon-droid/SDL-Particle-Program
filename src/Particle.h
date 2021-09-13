/*
 * Particle.h
 *
 *  Created on: 2 Sept 2021
 *      Author: tp
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include<stdlib.h>
#include<math.h>
#include<SDL2/SDL.h>
#include<iostream>


namespace tbg {

struct Particle {
	double par_x;
	double par_y;

	double direction;
	double speed;
public:
	Particle();
	void Init();
	void Update(int interval);
};

} /* namespace tbg */

#endif /* PARTICLE_H_ */
