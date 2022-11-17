#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Mesh
    {
        public:
            Mesh(std::string_view meshpath);
        protected:
            std::vector<glm::fvec3> m_vertices;
    }; 
}