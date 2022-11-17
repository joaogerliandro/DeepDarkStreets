#pragma once

#include <object.hpp>
#include <render.hpp>

namespace DeepDarkStreets
{
    class Game
    {
        public:
            Game(sf::Window&, DeepDarkStreets::Config);

            sf::ContextSettings get_settings();

            void run();

        private:
            void load_perspective();
        protected:
            //Measuring timing to help in game physics
            // sf::Clock response_clock;
            // sf::Clock game_clock;
            // Camera
            //Camera camera;
            //double rotate_angule = 0.0;

            //Window Options
            boolean m_fullscreen;
            boolean m_debug_mode;
            boolean m_degub_tools;

            sf::ContextSettings m_settings;

            sf::Window  *m_window;
            sf::Vector2u m_window_size;

            glm::fvec4 m_background_color;
    };
}