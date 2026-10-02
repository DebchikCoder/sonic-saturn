#include "Camera.hpp"

namespace Engine
{
      Camera::Camera(SRL::Math::Angle pitch, SRL::Math::Angle yaw, SRL::Math::Fxp radius)
      {
            m_position = SRL::Math::Vector3D(SRL::Math::Fxp(0));
            m_radius = radius;
            m_pitch = pitch;
            m_yaw = yaw;

            //im a bit scared thet vector is uninitialized so i will init it here
            // m_foward.X = SRL::Math::Trigonometry::Cos(m_angles.pitch) * SRL::Math::Trigonometry::Sin(m_angles.yaw);
            // m_foward.Y = 0;
            // m_foward.Z = SRL::Math::Trigonometry::Cos(m_angles.pitch) * SRL::Math::Trigonometry::Cos(m_angles.yaw);

            m_up = SRL::Math::Vector3D(SRL::Math::Vector3D::Up(), 0);
            // m_right = m_foward.Cross(m_up);
            // m_right.Normalize();
      }

      void Camera::Update(SRL::Input::Digital& pad, SRL::Math::Vector3D& target)
      {
            //first we check if we update camera angles
            if(pad.IsHeld(SRL::Input::Digital::Button::L))
                  m_yaw += SRL::Math::Angle::FromDegrees(3);
            if(pad.IsHeld(SRL::Input::Digital::Button::R))
                  m_yaw -= SRL::Math::Angle::FromDegrees(3);

            //then update vectors
            m_foward.X = SRL::Math::Trigonometry::Cos(m_pitch) * SRL::Math::Trigonometry::Sin(m_yaw);
            m_foward.Y = 0;
            m_foward.Z = SRL::Math::Trigonometry::Cos(m_pitch) * SRL::Math::Trigonometry::Cos(m_yaw);
            m_foward.Normalize();

            m_right = m_foward.Cross(m_up);

            m_target = target;

            m_position.X = m_target.X + m_radius * m_foward.X;
            m_position.Y = m_target.Y - 10;
            m_position.Z = m_target.Z + m_radius * m_foward.Z;
            SRL::Debug::Print(1, 1, "Cam pos: %f, %f, %f", m_position.X, m_position.Y, m_position.Z);
            //SRL::Debug::Print(1, 2, "Cam angles: %f, %f", m_pitch, m_yaw);
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
            m_yaw = SRL::Math::Angle::BuildRaw(0);
            m_pitch = SRL::Math::Angle::BuildRaw(0);

            m_foward = m_up = m_foward = SRL::Math::Vector3D::Zero();
            m_radius = 0;
      }

} // namespace Engine
