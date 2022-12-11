#include <game.h>

namespace DeepDarkStreets
{
    Game::Game(sf::RenderWindow& window, DeepDarkStreets::Config config)
    {
        m_window = &window;

        m_window->setFramerateLimit(60);
        m_window->setKeyRepeatEnabled(true);
        m_window->setMouseCursorVisible(true);

        m_background_color = glm::fvec4(76.5f, 76.5f, 76.5f, 1.0f);

        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
                    case sf::Event::MouseMoved:
                        mouse_handler();
                        break;
                    case sf::Event::KeyPressed:
                        controls_handler(event.key.code);
                        break;
                }
            }

            load_perspective();

            load_camera();

            draw_context();

            m_window->display();
        }
    }

    inline void Game::controls_handler(sf::Keyboard::Key key)
    {
        m_controls.camera_controller(m_camera, key);
        m_controls.window_controller(*m_window, m_settings, key);
    }

    inline void Game::mouse_handler()
    {
        m_controls.mouse_controller(*m_window, m_camera);
    }

    inline void Game::load_perspective()
    {
        Render::load_perspective(m_window, m_window_size, m_background_color);
    }

    inline void Game::load_camera()
    {
        m_camera.load_camera();
    }

    inline void Game::draw_context()
    {
        Render::draw_context();

        if(m_controls.get_game_mode())
            Render::draw_debug();
    }
}
