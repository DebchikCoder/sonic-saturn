#include "game.hpp"

Game::Game() : player(SRL::Math::Vector3D(0, 0, 0), 0)
{
    Engine::System::initEngine();
    for(int i = 0; i < 32; i++)
    {
        shadingTable[i] = SRL::Types::HighColor::FromRGB555(i, i, i);
    }
}

void Game::Start()
{
    //TODO: write seprate game file which handle main loop
    // Initialize library
    SRL::Debug::Print(1,1, "VDP1 3D Smooth shaded teapot");

    SRL::Cd::ChangeDir("MODELS");
    models[0] = new ModelObject("SONIC.NYA");
    SRL::Cd::ChangeDir((char*)NULL);

    //temporary code for testing backgrounds loading
    SRL::Cd::ChangeDir("BG");
    Engine::BG::loadBG("SKY.TGA");
    SRL::Cd::ChangeDir((char*)NULL);
    
    SRL::Debug::Print(1, 8, "Mesh count: %d", models[0]->GetMeshCount());

    // Setup light, we can use scale of the vector to manipulate light intensity
    lightDirection = SRL::Math::Vector3D(0.4, 0.0, 0.4);
    
    // Set light vector
    SRL::Scene3D::SetDirectionalLight(lightDirection);

    // Initialize shading table and work table
    uint32_t polygons = models[0]->GetFaceCount();
    workTable = new SRL::Types::HighColor[polygons << 2];
    vertWork  = new uint8_t[models[0]->GetVertexCount()];

    // Initializes gouraud table work area
    SRL::Scene3D::LightInitGouraudTable(0, vertWork, workTable, polygons);

    // Sets current light shading table
    SRL::Scene3D::LightSetGouraudTable(shadingTable);

    // Setups copy event at each vblank
    SRL::Core::OnVblank += SRL::Scene3D::LightCopyGouraudTable;

}

void Game::Update()
{
    SRL::Debug::Print(1, 9, "Beep");

    SRL::Debug::Print(1, 10, "Beep");
        // Load identity matrix
    SRL::Scene3D::LoadIdentity();

    // Set camera location and direction
    player.CameraLookAt();
    SRL::Debug::Print(1, 11, "Beep1");
        
    SRL::Scene3D::PushMatrix();
    {
        // Rotate teapot
        player.Update();
        models[player.GetModelID()]->Draw(lightDirection);
        SRL::Debug::Print(1, 12, "Beep2");
    }
    SRL::Scene3D::PopMatrix();
    SRL::Debug::Print(1, 13, "Beep3");
        
    // Refresh screen
    SRL::Core::Synchronize();
}
