#include <game.h>

namespace DeepDarkStreets
{
    Game::Game(sf::Window& window, DeepDarkStreets::Config config)
    {
        m_window = &window;

        m_window->setFramerateLimit(60);
        m_window->setKeyRepeatEnabled(true);

        m_fullscreen  = false;
        m_debug_mode  = false;
        m_degub_tools = false;

        m_background_color = glm::fvec4(76.5f, 76.5f, 76.5f, 1.0f);

        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        //Camera Start
    }

    inline sf::ContextSettings Game::get_settings()
    {
        return m_settings;
    }

    void Game::run()
    {
        while (m_window->isOpen())
        {
            sf::Event event;
            while (m_window->pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        m_window->close();
                        break;  
                    case sf::Event::KeyPressed:
                        //keyboard_handler(event.key.code);
                        break;
                }
            }

            load_perspective();
        }
    }

    inline void Game::load_perspective()
    {
        Render::load_perspective(m_window, m_window_size, m_background_color);
    }
}
