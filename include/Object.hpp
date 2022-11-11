#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <ifstream>

#include <glm/glm.hpp>
#include <glm/ext.hlp>

using namespace DeepDarkStreets
{
   public class Object
   {
        public:
            Object();

            Objetct(std::stringview path_stream);
        private:
            std::vector<glm::fvec3> vertex_list;
            std::vector<glm::fvec2> texture_cords;
            std::vector<glm::fvec2> normals_list;

            std::vector<glm::fvec3> positivo;
    };
}

