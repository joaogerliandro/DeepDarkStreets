#pragma once

#include <config.hpp>
#include <camera.h>

namespace DeepDarkStreets
{   
    class Controls
    {
        public: 
            void camera_controller(Camera&, sf::Keyboard::Key);

            void window_controller(sf::Window&, sf::ContextSettings&, sf::Keyboard::Key);
        
        private:
            void fullscreen_controller(sf::Window&, sf::ContextSettings&);

        protected:
            bool m_fullscreen = false;

    };
}