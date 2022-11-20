#pragma once

#include <config.hpp>
#include <camera.h>

namespace DeepDarkStreets
{   
    class Controls
    {
        public: 
            Controls();

            void camera_controller(Camera&, sf::Keyboard::Key);

            void mouse_controller(sf::RenderWindow&, Camera&);

            void window_controller(sf::RenderWindow&, sf::ContextSettings&, sf::Keyboard::Key);

            void set_mid_point(sf::Vector2u);

        private:
            void fullscreen_controller(sf::RenderWindow&, sf::ContextSettings&);

            void lock_mouse(sf::RenderWindow&);

        protected:
            bool m_fullscreen;
            bool m_lock_mouse;
    };
}