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
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        m_objects.clear();
        load_objects();
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

    void Game::draw_context()
    {
        Render::draw_context(m_objects);

        if(m_controls.get_game_mode())
            Render::draw_debug();
    }

    void Game::load_objects()
    {
        Object lantern(OBJ_PATH + std::string("lantern.obj"), TEX_PATH + std::string("lantern.png"));
        lantern.set_position(1, 1, 1);
        m_objects.push_back(lantern);

        Object apartment_obj(OBJ_PATH + std::string("apartment.obj"), TEX_PATH + std::string("apartment.png"));
        apartment_obj.set_position(10, 2.8, 0);
        m_objects.push_back(apartment_obj);

        Object poste_obj(OBJ_PATH + std::string("poste.obj"), TEX_PATH + std::string("poste.png"));
        poste_obj.set_position(0, 0, 0);
        m_objects.push_back(poste_obj);

        Object tree_obj(OBJ_PATH + std::string("tree.obj"), TEX_PATH + std::string("txTree.png"));
        tree_obj.set_position(0, 0, 0);
        m_objects.push_back(tree_obj);
    }
}
