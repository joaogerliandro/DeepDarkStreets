#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Camera
    {
        public:
            enum SENSE
            {
                X_CLOCKWISE,
                X_ANTICLOCKWISE,
                Y_CLOCKWISE,
                Y_ANTICLOCKWISE,
                NONE
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

            glm::dvec2 calculate_metrics(double);
        protected:
            glm::fvec3 m_eye; 
            glm::fvec3 m_at;
            glm::fvec3 m_up;

            glm::dvec2 m_rotate_angule;
            glm::dvec3 m_rotate_values;
    };
}