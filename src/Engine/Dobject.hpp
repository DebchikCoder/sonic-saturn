#pragma once
#include <srl.hpp>
#include "modelObject.hpp"

//interface for Dynamic objects NOTE: they can use only models and model 0 and 1 reserved for level and player
namespace Engine
{
      class IDynamicObject
      {
      protected:
            SRL::Math::Vector3D m_position;
            int8_t m_modelID;                //model id in loaded model array
            bool m_isActive;                 //do we even need to do something with object

      public:
            /// @brief initialize Dynamic object
            /// @param startPosOff position offset in transform matrix
            /// @param modelID modelID, if it set to -1 dummy model will be used
            IDynamicObject(SRL::Math::Vector3D startPosOff, int8_t modelID);

            void Rotate(SRL::Math::Angle& x, SRL::Math::Angle& y, SRL::Math::Angle& z);
            void Scale(SRL::Math::Fxp& x, SRL::Math::Fxp& y, SRL::Math::Fxp& z);
            void Translate(SRL::Math::Fxp& x, SRL::Math::Fxp& y, SRL::Math::Fxp& z);

            int8_t GetModelID();
      
            SRL::Math::Vector3D GetPosition();

            virtual void Update();
            virtual ~IDynamicObject() = default;
      };

} // namespace Engine

