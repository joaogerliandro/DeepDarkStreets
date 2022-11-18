#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Camera
    {
        public:
            enum SENSE
            {
                CLOCKWISE,
                ANTICLOCKWISE
            };


            Camera();

            void load_camera();

            void move_camera(glm::fvec3);

            void rotate_camera(SENSE);

            inline glm::fvec3 get_eye()
            {
                return m_eye;
            }
        private:

        protected:
            glm::fvec3 m_eye; 
            glm::fvec3 m_at;
            glm::fvec3 m_up;

            double m_rotate_angule;
    };
}