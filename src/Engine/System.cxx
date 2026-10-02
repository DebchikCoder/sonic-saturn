#include "System.hpp"

namespace Engine
{
      namespace System
      {
            void initEngine()
            {
                  SRL::Core::Initialize(SRL::Types::HighColor(0x31, 0x14, 0x32), SRL::TV::Resolutions::Normal320x240);
                  SRL::Scene3D::SetDepthDisplayLevel(4);
            }
      } // namespace System
      
} // namespace name

