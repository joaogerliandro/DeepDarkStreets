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
        glBegin(GL_LINES);
            //X Axis
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(500.0f, 0.0f, 0.0f);
            glColor3f(0.5f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(-500.0f, 0.0f, 0.0f);

            //Y Axis
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 500.0f, 0.0f);
            glColor3f(0.0f, 0.5f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, -500.0f, 0.0f);

            //Z Axis
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 500.0f);
            glColor3f(0.0f, 0.0f, 0.5f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, -500.0f);
        glEnd();
        
        glPointSize(12.5f);

        //Origin point
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_POINTS);
            glVertex3f(0.0f, 0.0f, 0.0f);
        glEnd();
    }
}
