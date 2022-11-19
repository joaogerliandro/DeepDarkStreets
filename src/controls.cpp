#include <controls.h>

namespace DeepDarkStreets
{
    Controls::Controls()
    {
        m_fullscreen = false;
    }

    void Controls::camera_controller(Camera& camera, sf::Keyboard::Key key)
    {
        switch (key)
        {
            case sf::Keyboard::Q:
                camera.update_rotation(Camera::SENSE::ANTICLOCKWISE);
                break;
            case sf::Keyboard::E:
                camera.update_rotation(Camera::SENSE::CLOCKWISE);
                break;
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

    void Controls::window_controller(sf::Window& window, sf::ContextSettings& settings, sf::Keyboard::Key key)
    {
        switch (key)
        {
            case sf::Keyboard::Escape:
                window.close();
                break;
            case sf::Keyboard::F11:
                fullscreen_controller(window, settings);
                break;
        }
    }

    void Controls::fullscreen_controller(sf::Window& window, sf::ContextSettings& settings)
    {
        m_fullscreen = !m_fullscreen;

        if (m_fullscreen)
            window.create(sf::VideoMode::getDesktopMode(), "Deep Dark Streets", sf::Style::Fullscreen, settings);
        else
            window.create(sf::VideoMode::getDesktopMode(), "Deep Dark Streets", sf::Style::Default, settings);

        glEnable(GL_DEPTH_TEST);
    }
}