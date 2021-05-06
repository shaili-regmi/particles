#ifndef ParticleSystem_H_
#define ParticleSystem_H_

#include "AGL.h"
#include "image.h"
#include "renderer.h"
#include <vector>

namespace agl {

   //glm::vec3 cam_pos = glm::vec3(0.0f,0.0f,4.0f);

   struct Particle {
      glm::vec3 pos;
      glm::vec3 vel;
      glm::vec4 color;
      float size;
      float mass;
      glm::vec3 cam_pos;
      
      bool operator<(const Particle& a) const
      {
          float d1 = glm::distance(a.pos, a.cam_pos);
          float d2 = glm::distance(pos, cam_pos);
          return (d2 < d1);
      }
   };

   class ParticleSystem {
   public:
      ParticleSystem();
      virtual ~ParticleSystem();

      void init(int size);
      virtual void update(float dt) = 0;
      virtual void draw();
      //virtual bool sort_help(const Particle& a, const Particle& b);

      static Renderer& GetRenderer();
      
   protected:
      virtual void createParticles(int size) = 0;

   protected:

      std::vector<Particle> mParticles;
      GLuint mTexture;
      BlendMode mBlendMode;
      static Renderer theRenderer;
   };
}
#endif