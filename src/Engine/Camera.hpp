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

            int8_t m_height;
      public:

            /// @brief initialize camera
            /// @param yaw start yaw angle
            /// @param radius how far camera from player
            /// @param height camera height
            /// @note Set radius to 1 if you want first person camera
            Camera(SRL::Math::Angle yaw, SRL::Math::Fxp radius, int8_t height);

            /// @brief update camera that pointing to target
            /// @param target target position
            void Update(SRL::Math::Vector3D& target);

            /// @brief update camera without target
            void Update();

            void ChangeYaw(SRL::Math::Angle value);
            void SetYaw(SRL::Math::Angle value);

            void LookAt();

            SRL::Math::Vector3D GetPosition();
            SRL::Math::Vector3D GetFoward();
            SRL::Math::Vector3D GetRight();

            ~Camera();
      };
} // namespace Engine

