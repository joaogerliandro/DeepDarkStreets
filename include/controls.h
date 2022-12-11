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

            bool get_game_mode();

        private:
            void lock_mouse(sf::RenderWindow&);

            inline void change_game_mode();

            Camera::SENSE mouse_mapper(sf::RenderWindow&);

        protected:
            bool m_fullscreen;
            bool m_lock_mouse;
            bool m_debugmode;
    };
}