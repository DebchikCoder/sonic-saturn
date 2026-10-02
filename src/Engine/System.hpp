#pragma once
#include <srl.hpp>

//main defenition file and system classes and variebles that engine use
//TODO: write loading class(should handle both file foading and level loading)

namespace Engine
{
      namespace System
      {
            constexpr int16_t SCREEN_WIDTH = 320;
            constexpr int16_t SCREEN_HEIGHT = 240;

            enum class GAME_STATE
            {
                  SPLASH,
                  MENU,
                  GAME,
                  PAUSED
            };

            void initEngine();
      } // namespace System
      
} // namespace Engine
