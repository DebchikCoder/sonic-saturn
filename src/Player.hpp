#pragma once
#include "Engine/Dobject.hpp"
#include "Engine/Camera.hpp"

class Player : public Engine::IDynamicObject
{
private:
      SRL::Math::Vector3D m_vel;
      SRL::Input::Digital m_pad;
      
      Engine::Camera camera;
public:
      Player(SRL::Math::Vector3D startPosition, int8_t padID);
      void Update() override;
      SRL::Math::Vector3D GetCameraPosition();
      ~Player() =default;
};
