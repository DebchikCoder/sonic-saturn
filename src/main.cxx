#include <srl.hpp>
#include "Engine/System.hpp"
#include "Engine/Background.hpp"
#include "Player.hpp"

// Using to shorten names for Vector and HighColor
using namespace SRL::Types;
using namespace SRL::Math::Types;
using namespace SRL::Input;

// Light shading table
HighColor shadingTable[32] =
{
	HighColor::FromRGB555(  0,  0,  0 ),
	HighColor::FromRGB555(  1,  1,  1 ),
	HighColor::FromRGB555(  2,  2,  2 ),
	HighColor::FromRGB555(  3,  3,  3 ),
	HighColor::FromRGB555(  4,  4,  4 ),
	HighColor::FromRGB555(  5,  5,  5 ),
	HighColor::FromRGB555(  6,  6,  6 ),
	HighColor::FromRGB555(  7,  7,  7 ),
	HighColor::FromRGB555(  8,  8,  8 ),
	HighColor::FromRGB555(  9,  9,  9 ),
	HighColor::FromRGB555( 10, 10, 10 ),
	HighColor::FromRGB555( 11, 11, 11 ),
	HighColor::FromRGB555( 12, 12, 12 ),
	HighColor::FromRGB555( 13, 13, 13 ),
	HighColor::FromRGB555( 14, 14, 14 ),
	HighColor::FromRGB555( 15, 15, 15 ),
	HighColor::FromRGB555( 16, 16, 16 ),
	HighColor::FromRGB555( 17, 17, 17 ),
	HighColor::FromRGB555( 18, 18, 18 ),
	HighColor::FromRGB555( 19, 19, 19 ),
	HighColor::FromRGB555( 20, 20, 20 ),
	HighColor::FromRGB555( 21, 21, 21 ),
	HighColor::FromRGB555( 22, 22, 22 ),
	HighColor::FromRGB555( 23, 23, 23 ),
	HighColor::FromRGB555( 24, 24, 24 ),
	HighColor::FromRGB555( 25, 25, 25 ),
	HighColor::FromRGB555( 26, 26, 26 ),
	HighColor::FromRGB555( 27, 27, 27 ),
	HighColor::FromRGB555( 28, 28, 28 ),
	HighColor::FromRGB555( 29, 29, 29 ),
	HighColor::FromRGB555( 30, 30, 30 ),
	HighColor::FromRGB555( 31, 31, 31 ),
};

// Main program entry
int main()
{
    //TODO: write seprate game file which handle main loop
    // Initialize library
    Engine::System::initEngine();
    SRL::Debug::Print(1,1, "VDP1 3D Smooth shaded teapot");

    SRL::Cd::ChangeDir("MODELS");
    std::array<ModelObject*, 2> models;
    models[0] = new ModelObject("SONIC.NYA");
    SRL::Cd::ChangeDir((char*)NULL);

    //temporary code for testing backgrounds loading
    SRL::Cd::ChangeDir("BG");
    Engine::BG::loadBG("SKY.TGA");
    SRL::Cd::ChangeDir((char*)NULL);
    
    Player player = Player(Vector3D(0, 0, 0), 0);
    SRL::Debug::Print(1, 8, "Mesh count: %d", models[0]->GetMeshCount());

    Vector2D BGpos = player.GetBackgroundPos();

    // Setup light, we can use scale of the vector to manipulate light intensity
    Vector3D lightDirection = Vector3D(0.4, 0.0, 0.4);
    
    // Set light vector
    SRL::Scene3D::SetDirectionalLight(lightDirection);

    // Initialize shading table and work table
    uint32_t polygons = models[0]->GetFaceCount();
    SRL::Types::HighColor workTable[models[0]->GetFaceCount() <<2];
    uint8_t vertWork[models[0]->GetVertexCount()];

    // Initializes gouraud table work area
    SRL::Scene3D::LightInitGouraudTable(0, vertWork, workTable, polygons);

    // Sets current light shading table
    SRL::Scene3D::LightSetGouraudTable(shadingTable);

    // Setups copy event at each vblank
    SRL::Core::OnVblank += SRL::Scene3D::LightCopyGouraudTable;

    // Main program loop
	while(1)
	{
        // Load identity matrix
        SRL::Scene3D::LoadIdentity();

        // Set camera location and direction
        SRL::Scene3D::LookAt(player.GetCameraPosition(), player.GetPosition(), 0);

        SRL::Scene3D::PushMatrix();
        {
            // Rotate teapot
            player.Update();
            models[player.GetModelID()]->Draw(lightDirection);
        }
        SRL::Scene3D::PopMatrix();
        BGpos = player.GetBackgroundPos();

        Engine::BG::ScrollBG(BGpos);
        
        // Refresh screen
        SRL::Core::Synchronize();
	}

	return 0;
}
