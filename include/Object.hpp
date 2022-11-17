#pragma once

#include <material.h>
#include <mesh.h>

namespace DeepDarkStreets
{
    class Object
    {
        public:
            Object(std::string_view objpath, std::string_view mtlpath) 
            : m_mesh{ objpath.data() },
              m_material{ mtlpath.data() }
            {
            }
        protected:
            Material m_material;
            Mesh     m_mesh;

            glm::fvec3 position;
    };
}

