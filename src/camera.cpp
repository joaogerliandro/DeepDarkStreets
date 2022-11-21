#include <camera.h>

namespace DeepDarkStreets
{
    Camera::Camera()
    {
        m_eye           = glm::fvec3(1.0f, 1.0f, 3.0f);
        m_at            = glm::fvec3(m_eye.x, m_eye.y, (m_eye.z) - 2.0f);
        m_up            = glm::fvec3(0.0f, 1.0f, 0.0f); 
        m_rotate_angule = glm::fvec2(0.0f, 0.0f);
    }

    void Camera::load_camera()
    {
        glm::mat4 view_mat = glm::lookAt(m_eye, m_at, m_up);

        glMatrixMode(GL_MODELVIEW);
        glLoadMatrixf(glm::value_ptr(view_mat));
    }

    void Camera::move_camera(DIRECTION move_direction)
    {
        switch (move_direction)
        {
            case DIRECTION::FORWARD:
                m_eye.z -= 0.5f;
                break;
            case DIRECTION::BACK:
                m_eye.z += 0.5f;
                break;
            case DIRECTION::LEFT:
                m_eye.x -= 0.5f;
                break;
            case DIRECTION::RIGHT:
                m_eye.x += 0.5f;
                break;
            case DIRECTION::DOWN:
                m_eye.y -= 0.5f;
                break;
            case DIRECTION::UP:
                m_eye.y += 0.5f;
                break;
        }

        if(m_rotate_angule.x == 0 && m_rotate_angule.y == 0)
            m_at = glm::fvec3(m_eye.x, m_eye.y, m_eye.z - 2.0f);
        else
        {
            rotate_camera();
        }
    }

    void Camera::update_rotation(SENSE rotation_sense)
    {
        switch (rotation_sense)
        {
            case SENSE::X_CLOCKWISE:
                m_rotate_angule.x -= 2.0;
                break;
            case SENSE::X_ANTICLOCKWISE:
                m_rotate_angule.x += 2.0;
                break;
            case SENSE::Y_CLOCKWISE:
                m_rotate_angule.y -= 2.0;
                break;
            case SENSE::Y_ANTICLOCKWISE:
                m_rotate_angule.y += 2.0;
                break;
        }

        if (m_rotate_angule.x == 360.0f || m_rotate_angule.x == -360.0f || m_rotate_angule.y == 360.0f || m_rotate_angule.y == -360.0f)
            m_rotate_angule = glm::fvec2(0.0f, 0.0f);

        rotate_camera();
    }

    void Camera::rotate_camera()
    {
        // Y-Axis Rotation
        
        double radian = (m_rotate_angule.x * PI) / 180.0;

        glm::fvec2 rotate_lookat = glm::fvec2(
            (cos(radian) * 0.0) - (sin(radian) * 2.0f),
            (sin(radian) * 0.0) + (cos(radian) * 2.0f)
        );

        m_at = glm::fvec3(
            (m_eye.x) + rotate_lookat.x,
            (m_eye.y),
            (m_eye.z) - rotate_lookat.y
        );
    }
}