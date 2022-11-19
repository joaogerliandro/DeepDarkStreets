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

            enum DIRECTION
            {
                FORWARD,
                BACK,
                LEFT,
                RIGHT,
                DOWN,
                UP
            };

            Camera();

            void load_camera();

            void move_camera(DIRECTION);

            void update_rotation(SENSE);

            inline glm::fvec3 get_eye()
            {
                return m_eye;
            }
        private:
            void rotate_camera();

        protected:
            glm::fvec3 m_eye; 
            glm::fvec3 m_at;
            glm::fvec3 m_up;

            double m_rotate_angule;
    };
}