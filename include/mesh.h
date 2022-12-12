#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Mesh
    {
        public:
            Mesh(std::string_view);

            inline std::vector<glm::fvec3> get_vertices()
            {
                return m_vertices;
            }

            inline std::vector<glm::fvec3> get_normals()
            {
                return m_normals;
            }

            inline std::vector<glm::fvec2> get_texture()
            {
                return m_texture;
            }
        protected:
            std::vector<glm::fvec3> m_vertices;
            std::vector<glm::fvec3> m_normals;
            std::vector<glm::fvec2> m_texture;
    }; 
}