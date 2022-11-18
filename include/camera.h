#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Camera
    {
        public:
            Camera();

            void load_camera();

            void move_camera(glm::fvec3);

            inline glm::fvec3 get_eye()
            {
                return m_eye;
            }
        private:

        protected:
            glm::fvec3 m_eye; 
            glm::fvec3 m_at;
            glm::fvec3 m_up;
    };
}