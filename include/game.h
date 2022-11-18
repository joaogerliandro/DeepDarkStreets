#pragma once

#include <object.hpp>
#include <render.hpp>
#include <camera.h>
#include <controls.h>

namespace DeepDarkStreets
{
    class Game
    {
        public:
            Game(sf::Window&, DeepDarkStreets::Config);

            sf::ContextSettings get_settings();

            void run();

        private:
            inline void load_perspective();
            inline void load_camera();
            inline void draw_context();
            inline void controls_handler(sf::Keyboard::Key key);
        protected:
            // Clock
            // sf::Clock response_clock;
            // sf::Clock game_clock;

            // Camera
            Camera m_camera;
            //double rotate_angule = 0.0;

            //Window Options
            Controls m_controls;

            sf::ContextSettings m_settings;

            sf::Window  *m_window;
            sf::Vector2u m_window_size;

            glm::fvec4 m_background_color;
    };
}