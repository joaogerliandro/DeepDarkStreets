#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Camera
    {
        public:
            Camera();

            void load_camera();
        private:

        protected:
            glm::fvec3 m_eye; 
            glm::fvec3 m_at;
            glm::fvec3 m_up;
    };
}