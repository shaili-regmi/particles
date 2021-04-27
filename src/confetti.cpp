// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) 
{
   mTexture = theRenderer.loadTexture("../textures/particle.png");
   
   // TODO: Create particles

   mParticles = vector<Particle>(size);

   for (int i = 0; i < size; i++)
   {
	   vec3 position = random_unit_cube();
	   vec3 velocity = vec3(random_float(0.0f, 1.0f), random_float(0.0f, 1.0f), random_float(0.0f, 1.0f));
	   vec4 color = vec4(random_float(0.0f, 1.0f), random_float(0.0f, 1.0f), random_float(0.0f, 1.0f), 1.0f);
	   float part_size = 0.25f;
	   float mass = 1.0f;

	   Particle particle = { position, velocity, color, part_size, mass };

	   mParticles.push_back(particle);
   }
}

void Confetti::update(float dt)
{
  // update particles

	for (int i = 0; i < mParticles.size(); i++)
	{
		Particle current_particle = mParticles[i];
		vec3 current_vel = current_particle.vel;
		vec3 new_pos = current_vel * dt;
		current_particle.pos = new_pos;
	}
}

