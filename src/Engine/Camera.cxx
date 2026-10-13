#include "Camera.hpp"

namespace Engine
{
      Camera::Camera(SRL::Math::Angle yaw, SRL::Math::Fxp radius, int8_t height)
      {
            m_position = SRL::Math::Vector3D(SRL::Math::Fxp(0));
            m_radius = radius;
            this->yaw = yaw;
            m_height = height;

            m_up = SRL::Math::Vector3D(SRL::Math::Vector3D::Up(), 0);
      }

      void Camera::Update(SRL::Math::Vector3D& target)
      {
            //update vectors
            m_foward.X = SRL::Math::Trigonometry::Sin(yaw);
            m_foward.Y = 0;
            m_foward.Z = SRL::Math::Trigonometry::Cos(yaw);

            m_right = m_foward.Cross(m_up);

            m_target = target;

            m_position.X = m_target.X + m_radius * m_foward.X;
            m_position.Y = m_target.Y - 16;
            m_position.Z = m_target.Z + m_radius * m_foward.Z;
            SRL::Debug::Print(1, 1, "Cam pos: %f, %f, %f", m_position.X, m_position.Y, m_position.Z);
            //SRL::Debug::Print(1, 2, "Cam yaw: %f", yaw);
            //SRL::Debug::Print(1, 2, "Cam angles: %f, %f", m_pitch, m_yaw);
      }

      void Camera::Update()
      {
            //update vectors
            m_foward.X = SRL::Math::Trigonometry::Sin(yaw);
            m_foward.Y = 0;
            m_foward.Z = SRL::Math::Trigonometry::Cos(yaw);

            m_right = m_foward.Cross(m_up);

            m_target = m_foward;

            m_position.X = m_target.X + m_radius * m_foward.X;
            m_position.Y = m_target.Y - 16;
            m_position.Z = m_target.Z + m_radius * m_foward.Z;
            SRL::Debug::Print(1, 1, "Cam pos: %f, %f, %f", m_position.X, m_position.Y, m_position.Z);
      }

      void Camera::LookAt()
      {
            SRL::Scene3D::LookAt(m_position, m_target, SRL::Math::Angle::FromDegrees(0));
      }

      SRL::Math::Vector3D Camera::GetPosition()
      {
            return m_position;
      }

      SRL::Math::Vector3D Camera::GetFoward()
      {
            return m_foward;
      }

      SRL::Math::Vector3D Camera::GetRight()
      {
            return m_right;
      }

      Camera::~Camera()
      {
            yaw = SRL::Math::Angle::BuildRaw(0);

            m_foward = m_up = m_foward = SRL::Math::Vector3D::Zero();
            m_radius = 0;
      }

} // namespace Engine
