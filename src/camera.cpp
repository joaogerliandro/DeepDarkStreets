#include <camera.h>

namespace DeepDarkStreets
{
    Camera::Camera()
    {
        m_eye           = glm::fvec3(1.0, 1.0, 3.0);
        m_at            = glm::fvec3(m_eye.x, m_eye.y, (m_eye.z) - 1.0);
        m_up            = glm::fvec3(0.0, 1.0, 0.0); 
        m_rotate_angule = glm::dvec2(0.0, 0.0);
        m_rotate_values = glm::dvec3(0.0, 0.0, 2.0);
    }

    void Camera::load_camera()
    {
        glm::mat4 view_mat = glm::lookAt(m_eye, m_at, m_up);

        glMatrixMode(GL_MODELVIEW);
        glLoadMatrixf(glm::value_ptr(view_mat));
    }

    void Camera::move_camera(DIRECTION move_direction)
    {
        glm::dvec3 direction = glm::dvec3(m_eye.x - m_at.x, 0.0, m_eye.z - m_at.z);

        switch (move_direction)
        {
            case DIRECTION::FORWARD:
                m_eye -= direction * CAM_SPEED;
                break;
            case DIRECTION::BACK:
                m_eye += direction * CAM_SPEED;
                break;
            case DIRECTION::LEFT:
                m_eye += glm::normalize(glm::cross(direction, m_up)) * CAM_SPEED;
                break;
            case DIRECTION::RIGHT:
                m_eye -= glm::normalize(glm::cross(direction, m_up)) * CAM_SPEED;
                break;
            case DIRECTION::DOWN:
                m_eye.y -= CAM_SPEED;
                break;
            case DIRECTION::UP:
                m_eye.y += CAM_SPEED;
                break;
        }

        rotate_camera();
    }

    void Camera::update_rotation(SENSE rotation_sense)
    {
        switch (rotation_sense)
        {
            case SENSE::X_CLOCKWISE:
                m_rotate_angule.x -= 3.0;
                break;
            case SENSE::X_ANTICLOCKWISE:
                m_rotate_angule.x += 3.0;
                break;
            case SENSE::Y_CLOCKWISE:
                if(m_rotate_angule.y > -90)
                    m_rotate_angule.y -= 3.0;
                break;
            case SENSE::Y_ANTICLOCKWISE:
                if(m_rotate_angule.y < 90)
                    m_rotate_angule.y += 3.0;
                break;
        }

        rotate_camera();
    }

    void Camera::rotate_camera()
    {
        // X-Axis Rotation

        glm::dvec2 trig_metrics = calculate_metrics(glm::radians(m_rotate_angule.y)); //Cos and Sin
        
        glm::fvec3 rotate_lookat = glm::fvec3(
            (m_rotate_values.x),
            (trig_metrics.x * m_rotate_values.y) - (trig_metrics.y * m_rotate_values.z),
            (trig_metrics.x * m_rotate_values.z) - (trig_metrics.y * m_rotate_values.y)
        );

        // Y-Axis Rotation

        trig_metrics = calculate_metrics(glm::radians(m_rotate_angule.x)); //Cos and Sin

        rotate_lookat = glm::fvec3(
            (trig_metrics.x * rotate_lookat.x) - (trig_metrics.y * rotate_lookat.z),
            (rotate_lookat.y),
            (trig_metrics.y * rotate_lookat.x) + (trig_metrics.x * rotate_lookat.z)
        );

        m_at = glm::fvec3(
            (m_eye.x) + rotate_lookat.x,
            (m_eye.y) + rotate_lookat.y,
            (m_eye.z) - rotate_lookat.z
        ); 
    }
}