#include "Background.hpp"

namespace Engine
{
      namespace BG
      {
            void loadBG(const char* fileName)
            {
                  SRL::VDP2::ClearVRAM();
                  SRL::Bitmap::TGA* bitmap = new SRL::Bitmap::TGA(fileName);
                  SRL::Tilemap::Interfaces::Bmp2Tile* tile = new SRL::Tilemap::Interfaces::Bmp2Tile(*bitmap);

                  SRL::VDP2::NBG2::ScrollDisable();
                  SRL::VDP2::NBG2::LoadTilemap(*tile);
                  SRL::VDP2::NBG2::ScrollEnable();
            }

            void ScrollBG(SRL::Math::Vector2D& newPos)
            {
                  SRL::VDP2::NBG2::SetPosition(newPos);
            }
            
      } // namespace Background
      
} // namespace Engine
