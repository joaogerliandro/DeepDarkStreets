#pragma once

#include <material.h>
#include <mesh.h>

#define OBJ_PATH "../../../assets/meshes/"
#define TEX_PATH "../../../assets/textures/"

namespace DeepDarkStreets
{
    class Object
    {
        public:
            Object(std::string_view objpath, std::string_view mtlpath) 
            : m_mesh{ objpath.data() },
              m_material{ mtlpath.data() }
            {
                position = glm::dvec3(0.0, 0.0, 0.0);
            }

            Mesh get_mesh()
            {
                return m_mesh;
            }

            glm::dvec3 get_position()
            {
                return position;
            }

            Material get_material()
            {
                return m_material;
            }

            void set_position(double x, double y, double z)
            {
                position = glm::dvec3(x, y, z);
            }
        protected:
            Material m_material;
            Mesh     m_mesh;

            glm::dvec3 position;
    };
}

