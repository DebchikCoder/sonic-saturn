#pragma once
#include "Engine/Dobject.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Background.hpp"

class Player : public Engine::IDynamicObject
{
private:
      SRL::Math::Vector3D m_vel;
      SRL::Input::Digital m_pad;

      SRL::Math::Vector2D m_BGposition;
      
      Engine::Camera m_camera;
public:
      Player(SRL::Math::Vector3D startPosition, int8_t padID);
      void Update() override;
      void CameraLookAt();
      SRL::Math::Vector3D GetCameraPosition();
      SRL::Math::Angle GetCameraAngle();
      SRL::Math::Vector2D GetBackgroundPos(); //i know its dumb way
      ~Player() =default;
};
