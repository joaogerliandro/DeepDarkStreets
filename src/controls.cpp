#include <controls.h>

namespace DeepDarkStreets
{
    Controls::Controls()
    {
        m_fullscreen = false;
    }

    void Controls::camera_controller(Camera& camera, sf::Keyboard::Key key)
    {
        glm::fvec3 cam_move = camera.get_eye();

        switch (key)
        {
            case sf::Keyboard::Q:
                camera.rotate_camera(Camera::SENSE::ANTICLOCKWISE);
                break;
            case sf::Keyboard::E:
                camera.rotate_camera(Camera::SENSE::CLOCKWISE);
                break;
            case sf::Keyboard::W:
                cam_move.z -= 0.5f;
                break;
            case sf::Keyboard::S:
                cam_move.z += 0.5f;
                break;
            case sf::Keyboard::A:
                cam_move.x -= 0.5f;
                break;
            case sf::Keyboard::D:
                cam_move.x += 0.5f;
                break;
            case sf::Keyboard::LControl:
            case sf::Keyboard::RControl:
                cam_move.y -= 0.5f;
                break;
            case sf::Keyboard::LShift:
            case sf::Keyboard::RShift:
                cam_move.y += 0.5f;
                break;
        }

        camera.move_camera(cam_move);
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