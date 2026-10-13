#include "Player.hpp"

Player::Player(SRL::Math::Vector3D startPosition, int8_t padID) : m_pad(0), IDynamicObject(startPosition, 0),
m_camera(SRL::Math::Angle(0), SRL::Math::Fxp(35), 16)
{
      m_vel = SRL::Math::Vector3D::Zero();
}

void Player::Update()
{
      m_vel = SRL::Math::Vector3D::Zero();
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Up))
            m_vel = m_camera.GetFoward() * SRL::Math::Fxp(3);
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Down))
            m_vel = m_camera.GetFoward() * -SRL::Math::Fxp(3);
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Left))
            m_vel = m_camera.GetRight() * -SRL::Math::Fxp(3);
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Right))
            m_vel = m_camera.GetRight() * SRL::Math::Fxp(3);
      
      if(m_pad.IsHeld(SRL::Input::Digital::Button::L))
      {
            m_BGposition.X -= 2.0;
            m_camera.yaw -= SRL::Math::Angle::FromDegrees(3);
      }
      if(m_pad.IsHeld(SRL::Input::Digital::Button::R))
      {
            m_BGposition.X += 2.0;
            m_camera.yaw += SRL::Math::Angle::FromDegrees(3);
      }
      
      m_vel.Normalize();

      m_position -= m_vel;
      Engine::BG::ScrollBG(m_BGposition);
      m_camera.Update(m_position);
      SRL::Scene3D::Translate(m_position);

      SRL::Debug::Print(1, 3, "Player pos: %f, %f, %f", m_position.X, m_position.Y, m_position.Z);
}

void Player::CameraLookAt()
{
      m_camera.LookAt();
}

SRL::Math::Vector3D Player::GetCameraPosition()
{
      return m_camera.GetPosition();
}

SRL::Math::Vector2D Player::GetBackgroundPos()
{
      return m_BGposition;
}
