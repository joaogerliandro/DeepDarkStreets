#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{   
    class Controls
    {
        public: 
            static void camera_controller(Camera& camera, sf::Keyboard::Key key)
            {
                glm::fvec3 cam_move = camera.get_eye();

                switch (key)
                {
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
                    case sf::Keyboard::LShift:
                    case sf::Keyboard::RShift:
                        cam_move.y += 0.5f;
                        break;
                    case sf::Keyboard::LControl:
                    case sf::Keyboard::RControl:
                        cam_move.y -= 0.5f;
                        break;
                }

                camera.move_camera(cam_move);
            }
        
        private:

    };
}