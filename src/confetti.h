#ifndef Confetti_H_
#define Confetti_H_

#include "particlesystem.h"

namespace agl {

   class Confetti : public ParticleSystem {
   public:
      virtual void createParticles(int size) override;
      virtual void update(float dt) override;
      //virtual bool sort_help(const Particle& a, const Particle& b);
   };
}
#endif