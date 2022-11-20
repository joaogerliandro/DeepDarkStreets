#include <controls.h>

namespace DeepDarkStreets
{
    Controls::Controls()
    {
        m_fullscreen = false;
        m_lock_mouse = false;
    }

    void Controls::camera_controller(Camera& camera, sf::Keyboard::Key key)
    {
        switch (key)
        {
            case sf::Keyboard::W:
                camera.move_camera(Camera::DIRECTION::FORWARD);
                break;
            case sf::Keyboard::S:
                camera.move_camera(Camera::DIRECTION::BACK);
                break;
            case sf::Keyboard::A:
                camera.move_camera(Camera::DIRECTION::LEFT);
                break;
            case sf::Keyboard::D:
                camera.move_camera(Camera::DIRECTION::RIGHT);
                break;
            case sf::Keyboard::LControl:
            case sf::Keyboard::RControl:
                camera.move_camera(Camera::DIRECTION::DOWN);
                break;
            case sf::Keyboard::LShift:
            case sf::Keyboard::RShift:
                camera.move_camera(Camera::DIRECTION::UP);
                break;
        }
    }

    void Controls::window_controller(sf::RenderWindow& window, sf::ContextSettings& settings, sf::Keyboard::Key key)
    {
        switch (key)
        {
            case sf::Keyboard::Escape:
                window.close();
                break;
            case sf::Keyboard::F11:
                fullscreen_controller(window, settings);
                break;
            case sf::Keyboard::M:
                lock_mouse(window);
                break;
        }
    }

    void Controls::fullscreen_controller(sf::RenderWindow& window, sf::ContextSettings& settings)
    {
        m_fullscreen = !m_fullscreen;

        if (m_fullscreen)
            window.create(sf::VideoMode::getDesktopMode(), "Deep Dark Streets", sf::Style::Fullscreen, settings);
        else
            window.create(sf::VideoMode::getDesktopMode(), "Deep Dark Streets", sf::Style::Close, settings);

        //window.setMouseCursorVisible(m_lock_mouse);
        glEnable(GL_DEPTH_TEST);
    }

    void Controls::lock_mouse(sf::RenderWindow& window)
    {
        m_lock_mouse = !m_lock_mouse;

        //window.setMouseCursorVisible(m_lock_mouse);
        window.setMouseCursorGrabbed(m_lock_mouse);
    }

    void Controls::mouse_controller(sf::RenderWindow& window, Camera& camera)
    {   
        if(m_lock_mouse)
        {
            sf::Vector2u window_size = window.getSize();
            sf::Vector2i mid_point = sf::Vector2i(ceil(window_size.x / 2.0), ceil(window_size.y / 2.0));
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

            std::cout << "Mouse X = " << mouse_position.x << std::endl;
            std::cout << "Mid X = " << mid_point.x << std::endl;

            // case sf::Keyboard::Q:
            //     camera.update_rotation(Camera::SENSE::ANTICLOCKWISE);
            //     break;
            // case sf::Keyboard::E:
            //     camera.update_rotation(Camera::SENSE::CLOCKWISE);
            //     break;

            //sf::Mouse::setPosition(sf::Vector2i(mid_point.x, mid_point.y));          
        }
    }
}