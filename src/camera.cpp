#include <camera.h>

namespace DeepDarkStreets
{
    Camera::Camera()
    {
        m_eye = glm::fvec3(1.0f, 1.0f, 3.0f);
        m_at  = glm::fvec3(m_eye.x, m_eye.y, (m_eye.z) - 2.0f);
        m_up  = glm::fvec3(0.0f, 1.0f, 0.0f); 
    }

    void Camera::load_camera()
    {
        glm::mat4 view_mat = glm::lookAt(m_eye, m_at, m_up);

        glMatrixMode(GL_MODELVIEW);
        glLoadMatrixf(glm::value_ptr(view_mat));
    }

    void Camera::move_camera(glm::fvec3 new_position)
    {
        m_eye = new_position;
        m_at  = glm::fvec3(m_eye.x, m_eye.y, m_eye.z - 2.0f);
    }
}