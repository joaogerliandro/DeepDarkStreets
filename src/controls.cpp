#include <controls.h>

namespace DeepDarkStreets
{
    Controls::Controls()
    {
        m_fullscreen = false;
        m_lock_mouse = false;
        m_debugmode  = false;
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
                if(m_debugmode)
                    camera.move_camera(Camera::DIRECTION::DOWN);
                break;
            case sf::Keyboard::LShift:
            case sf::Keyboard::RShift:
                if(m_debugmode)
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
            case sf::Keyboard::M:
                lock_mouse(window);
                break;
            case sf::Keyboard::B:
                change_game_mode();
                break;
        }
    }

    void Controls::lock_mouse(sf::RenderWindow& window)
    {
        window.setMouseCursorVisible(m_lock_mouse);
        window.setMouseCursorGrabbed(m_lock_mouse);

        m_lock_mouse = !m_lock_mouse;
    }

    inline void Controls::change_game_mode()
    {
        m_debugmode = !m_debugmode;
    }
    
    bool Controls::get_game_mode()
    {
        return m_debugmode;
    }

    void Controls::mouse_controller(sf::RenderWindow& window, Camera& camera)
    {   
        if(m_lock_mouse)
        {
            switch (mouse_mapper(window))
            {
                case Camera::SENSE::X_CLOCKWISE:
                    camera.update_rotation(Camera::SENSE::X_CLOCKWISE);
                    break;
                case Camera::SENSE::X_ANTICLOCKWISE:
                    camera.update_rotation(Camera::SENSE::X_ANTICLOCKWISE);
                    break;
                case Camera::SENSE::Y_CLOCKWISE:
                    camera.update_rotation(Camera::SENSE::Y_CLOCKWISE);
                    break;
                case Camera::SENSE::Y_ANTICLOCKWISE:
                    camera.update_rotation(Camera::SENSE::Y_ANTICLOCKWISE);
                    break;
                case Camera::SENSE::NONE:
                    break;
            }       
        }
    }

    Camera::SENSE Controls::mouse_mapper(sf::RenderWindow& window)
    {
        sf::Vector2u window_size = window.getSize();
        sf::Vector2i mid_point = sf::Vector2i(ceil(window_size.x / 2.0), ceil(window_size.y / 2.0));
        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

        sf::Mouse::setPosition(sf::Vector2i(mid_point.x, mid_point.y)); 

        if(mouse_position.x > mid_point.x + 2)
            return Camera::SENSE::X_CLOCKWISE;
        else if(mouse_position.x < mid_point.x - 2)
            return Camera::SENSE::X_ANTICLOCKWISE;
        else if(mouse_position.y < mid_point.y - 2)
            return Camera::SENSE::Y_CLOCKWISE;
        else if(mouse_position.y > mid_point.y + 2)
            return Camera::SENSE::Y_ANTICLOCKWISE;
        else
            return Camera::SENSE::NONE;
    }
}