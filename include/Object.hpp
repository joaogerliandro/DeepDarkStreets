#pragma once

#include <config.h>
#include <material.hpp>
#include <mesh.hpp>

namespace DeepDarkStreets
{
    class Object
    {
        public:
            Object(std::string_view objpath) 
                : m_mesh{ objpath.data() }
            {
            }

            Object(std::string_view objpath, std::string_view mtlpath) 
            : m_mesh{ objpath.data() },
              m_material{ mtlpath.data() }
            {

            }
        protected:
            Material m_material;
            Mesh m_mesh;
    };
}

