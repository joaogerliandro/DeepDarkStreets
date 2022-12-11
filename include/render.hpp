#pragma once

#include <config.hpp>

namespace DeepDarkStreets
{
    class Render
    {
        public:
            static void load_viewport(sf::RenderWindow *window, sf::Vector2u& window_size, glm::fvec4& background_color)
            {
                window_size = window->getSize();

                glViewport(0, 0, window_size.x, window_size.y);

                glClearColor(
                    background_color.x / 255.f,
                    background_color.y / 255.f,
                    background_color.z / 255.f,
                    background_color.w / 255.f
                );

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            }

            static void load_perspective(sf::RenderWindow *window, sf::Vector2u& window_size, glm::fvec4& background_color)
            {
                load_viewport(window, window_size, background_color); 

                float aspect_ratio = float(window_size.x) / float(window_size.y);
                
                glm::mat4 projection_mat = glm::perspective(45.0f, aspect_ratio, 0.1f, 500.0f);

                glMatrixMode(GL_PROJECTION);
                glLoadMatrixf(glm::value_ptr(projection_mat));
            }

            static void draw_context()
            {

            }

            static void draw_debug()
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
    };
}