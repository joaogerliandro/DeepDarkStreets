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
            Game(sf::RenderWindow&, DeepDarkStreets::Config);

            sf::ContextSettings get_settings();

            void run();

        private:
            inline void load_perspective();
            inline void load_camera();
            inline void controls_handler(sf::Keyboard::Key key);
            inline void mouse_handler();
            void draw_context();
            void load_objects();
        protected:
            Camera m_camera;

            Controls m_controls;

            std::vector<Object> m_objects;

            sf::ContextSettings m_settings;

            sf::RenderWindow *m_window;
            sf::Vector2u      m_window_size;

            glm::fvec4 m_background_color;
    };
}