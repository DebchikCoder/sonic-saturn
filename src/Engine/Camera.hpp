#pragma once

#include <srl.hpp>

namespace Engine
{
      class Camera
      {
      private:
            SRL::Math::Vector3D m_position;
            SRL::Math::Vector3D m_target;
            SRL::Math::Fxp m_radius;

            //camera vectors, 
            SRL::Math::Vector3D m_foward, m_right, m_up;

            SRL::Math::Angle m_pitch, m_yaw;
      public:
            Camera(SRL::Math::Angle pitch, SRL::Math::Angle yaw, SRL::Math::Fxp radius);

            void Update(SRL::Input::Digital& pad, SRL::Math::Vector3D& target);

            SRL::Math::Vector3D GetPosition();
            SRL::Math::Vector3D GetFoward();
            SRL::Math::Vector3D GetRight();

            ~Camera();
      };
} // namespace Engine

