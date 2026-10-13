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

                  delete bitmap;
                  delete tile;
            }

            void ScrollBG(SRL::Math::Vector2D& newPos)
            {
                  SRL::VDP2::NBG2::SetPosition(newPos);
            }

            //it doesnt working i need to figure out why

            void loadRBG(const char* filename)
            {
                  SRL::Bitmap::TGA* bitmap = new SRL::Bitmap::TGA(filename);
                  SRL::Tilemap::Interfaces::Bmp2Tile* tile = new SRL::Tilemap::Interfaces::Bmp2Tile(*bitmap);

                  for(int i = 0; i < 32; i += 4)
                  {
                        for(int j = 0; j < 32; j += 4)
                        {
                              tile->CopyMap(0, SRL::Tilemap::Coord(0, 0), SRL::Tilemap::Coord(3, 3), 0, SRL::Tilemap::Coord(i, j));
                        }
                  }

                  SRL::VDP2::RBG0::ScrollDisable();
                  SRL::VDP2::RBG0::LoadTilemap(*tile);
                  SRL::VDP2::RBG0::SetRotationMode(SRL::VDP2::RotationMode::TwoAxis);
                  SRL::VDP2::RBG0::ScrollEnable();

                  delete bitmap;
                  delete tile;
            }
            
      } // namespace Background
      
} // namespace Engine
