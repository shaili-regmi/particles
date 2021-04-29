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

   for (int i = 0; i < size; i++)
   {
	   vec3 position = random_unit_cube();
	   vec3 velocity = vec3(random_float(-2.0f, 2.0f), random_float(-2.0f, 2.0f), random_float(-2.0f, 2.0f));
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
	vec3 cam_pos = theRenderer.cameraPosition();

	for (int i = 0; i < mParticles.size(); i++)
	{
		Particle current_particle = mParticles[i];
		vec3 current_vel = current_particle.vel;

		vec3 new_pos = current_particle.pos + current_vel * dt;

		if (new_pos.x > 1.0f || new_pos.x < -1.0f)
		{
			current_vel.x = -1.0f * current_vel.x;
			new_pos = current_particle.pos + current_vel * dt;
		}
		if (new_pos.y > 1.0f || new_pos.y < -1.0f)
		{
			current_vel.y = -1.0f * current_vel.y;
			new_pos = current_particle.pos + current_vel * dt;
		}
		if (new_pos.z > 1.0f || new_pos.z < -1.0f)
		{
			current_vel.z = -1.0f * current_vel.z;
			new_pos = current_particle.pos + current_vel * dt;
		}

		current_particle.pos = new_pos;
		current_particle.vel = current_vel;
		mParticles[i] = current_particle;

		//sorting particles
		/*
		if (i != 0)
		{
			Particle prev = mParticles[i - 1];
			float d1 = distance(prev.pos, cam_pos);
			float d2 = distance(current_particle.pos, cam_pos);
			if (d2 > d1)
			{
				mParticles[i] = prev;
				mParticles[i - 1] = current_particle;
			}
			*/



			//sorting particles
		/*
		for (int i = 1; i < mParticles.size(); i++)
		{
			Particle prev = mParticles[i - 1];
			Particle current = mParticles[i];
			float d1 = distance(prev.pos, cam_pos);
			float d2 = distance(current.pos, cam_pos);
			if (d2 > d1)
			{
				mParticles[i - 1] = current;
				mParticles[i] = prev;
			}
		}
		*/

		for (int i = 0; i < mParticles.size(); i++)
		{
			for (int j = 0; j < mParticles.size() - i; j++)
			{
				Particle p_i = mParticles[i];
				Particle p_j = mParticles[j];
				float d1 = distance(p_i.pos, cam_pos);
				float d2 = distance(p_j.pos, cam_pos);
				if (d2 < d1)
				{
					mParticles[i] = p_j;
					mParticles[j] = p_i;
				}
			}
		}
	}
}


