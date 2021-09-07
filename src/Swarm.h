/*
 * Swarm.h
 *
 *  Created on: 2 Sept 2021
 *      Author: tp
 */

#ifndef SWARM_H_
#define SWARM_H_

#include"Particle.h"

namespace tbg {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle *m_Particle;
	int ticks;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();

	const Particle* const Get_Particles() {
		return m_Particle;
	}
	;

	void Update(int ticks);
};

} /* namespace tbg */

#endif /* SWARM_H_ */
