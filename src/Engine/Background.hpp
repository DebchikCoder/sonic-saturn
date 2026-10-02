#pragma once
#include <srl.hpp>

//background classes to make easier loading and working with them

namespace Engine
{
      namespace BG
      {
            //TODO: add function for copying tilemaps for RBG and NBG

            void loadBG(const char* fileName);
            void ScrollBG(SRL::Math::Vector2D& newPos);
            
      } // namespace BG
      
} // namespace Engine
