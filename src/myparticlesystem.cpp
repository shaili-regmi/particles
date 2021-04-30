// Bryn Mawr College, alinen, 2020
// Smoke Flare

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;

void MyParticleSystem::createParticles(int size) 
{
   mBlendMode = ALPHA;
   mTexture = theRenderer.loadTexture("../textures/ParticleCloudWhite.png");

   for (int i = 0; i < size; i++)
   {
	   float z_pos = -1.0f + ((float)i / size);
	   vec3 position = vec3(-1.0f, -1.0f, z_pos);
	   float x = random_float(-1.0f, 1.0f);
	   float y = abs(random_float(0.0f, 5.0f));
	   vec3 velocity = vec3(x, y, 0.1);
	   vec4 color = vec4(0.9f, 0.6f, 0.9f, 1.0f);
	   float part_size = 0.5f;
	   float mass = 2.0f;

	   Particle particle = { position, velocity, color, part_size, mass };

	   mParticles.push_back(particle);
   }
}

void MyParticleSystem::update(float dt)
{
	vec3 cam_pos = theRenderer.cameraPosition();

	for (int i = 0; i < mParticles.size(); i++)
	{
		Particle current_particle = mParticles[i];
		vec3 new_pos = current_particle.pos + current_particle.vel * dt;
		current_particle.size += 0.01;
		float alpha = current_particle.color.w;
		current_particle.color = vec4(0.9f, 0.6f, 0.9f, (alpha - 0.01f));


		if (new_pos.x > 0.5f || new_pos.x < -2.0f || new_pos.y > 0.7f)
		{ // Reuse particle
			float z_pos = -1.0f + ((float)i / mParticles.size());
			new_pos = vec3(-1.0f, -1.0f, z_pos);
			current_particle.color = vec4(0.9f, 0.6f, 0.9f, 1.0f);
			current_particle.size = 0.5f;
		}

		current_particle.pos = new_pos;
		mParticles[i] = current_particle;

		//sorting particles
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
		}
	}
}

