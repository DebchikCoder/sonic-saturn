#include "Dobject.hpp"

namespace Engine
{
      IDynamicObject::IDynamicObject(SRL::Math::Vector3D startPosOff, int8_t modelID)
      {
            m_isActive = true;
            m_modelID = modelID;
            m_position = startPosOff;
      }

      void IDynamicObject::Rotate(SRL::Math::Angle& x, SRL::Math::Angle& y, SRL::Math::Angle& z)
      {
            SRL::Scene3D::RotateX(x);
            SRL::Scene3D::RotateY(y);
            SRL::Scene3D::RotateZ(z);
      }

      void IDynamicObject::Scale(SRL::Math::Fxp& x, SRL::Math::Fxp& y, SRL::Math::Fxp& z)
      {
            SRL::Scene3D::Scale(x, y, z);
      }

      void IDynamicObject::Translate(SRL::Math::Fxp& x, SRL::Math::Fxp& y, SRL::Math::Fxp& z)
      {
            m_position.X += x;
            m_position.Y += y;
            m_position.Z += z;

            SRL::Scene3D::Translate(m_position.X, m_position.Y, m_position.Z);
      }

      int8_t IDynamicObject::GetModelID()
      {
            return m_modelID;
      }

      SRL::Math::Vector3D IDynamicObject::GetPosition()
      {
            return m_position;
      }

      void IDynamicObject::Update()
      {
            SRL::Math::Fxp x, y, z = SRL::Math::Fxp(0);
            Translate(x, y, z);
      }
} // namespace Engine

