#pragma once

#include <config.hpp>

#define CAM_SPEED 0.5

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

            inline glm::dvec3 get_eye()
            {
                return m_eye;
            }
        private:
            void rotate_camera();

            inline glm::dvec2 calculate_metrics(double angle)
            {
                return glm::dvec2(cos(angle), sin(angle));
            }
        protected:
            glm::dvec3 m_eye; 
            glm::dvec3 m_at;
            glm::dvec3 m_up;

            glm::dvec2 m_rotate_angule;
            glm::dvec3 m_rotate_values;
    };
}