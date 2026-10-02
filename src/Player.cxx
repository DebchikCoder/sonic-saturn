#include "Player.hpp"

Player::Player(SRL::Math::Vector3D startPosition, int8_t padID) : m_pad(0), IDynamicObject(startPosition, 0),
camera(SRL::Math::Angle(15), SRL::Math::Angle(0), SRL::Math::Fxp(35))
{
      m_vel = SRL::Math::Vector3D::Zero();
}

void Player::Update()
{
      camera.Update(m_pad, m_position);
      m_vel = SRL::Math::Vector3D::Zero();
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Up))
            m_vel = camera.GetFoward() * -SRL::Math::Fxp(3);
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Down))
            m_vel = camera.GetFoward() * SRL::Math::Fxp(3);
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Left))
            m_vel = camera.GetRight() * SRL::Math::Fxp(3);
      if(m_pad.IsHeld(SRL::Input::Digital::Button::Right))
            m_vel = camera.GetRight() * -SRL::Math::Fxp(3);
      
      m_vel.Normalize();

      Translate(m_vel.X, m_vel.Y, m_vel.Z);
      SRL::Debug::Print(1, 3, "Player pos: %f, %f, %f", m_position.X, m_position.Y, m_position.Z);
}

SRL::Math::Vector3D Player::GetCameraPosition()
{
      return camera.GetPosition();
}
