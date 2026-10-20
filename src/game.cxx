#include "game.hpp"

Game::Game() : player(SRL::Math::Vector3D(0, 0, 0), 0)
{
    Engine::System::initEngine();
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
    Engine::BG::loadRBG("FLOOR.TGA");
    SRL::Cd::ChangeDir((char*)NULL);
    
    SRL::Debug::Print(1, 8, "Mesh count: %d", models[0]->GetMeshCount());

    // Setup light, we can use scale of the vector to manipulate light intensity
    lightDirection = SRL::Math::Vector3D(0.4, 0.0, 0.4);
    
    // Set light vector
    SRL::Scene3D::SetDirectionalLight(lightDirection);

    polygons = models[0]->GetFaceCount();
    vertecies = models[0]->GetVertexCount();

    renderer.initGouraud(polygons, vertecies);
}

void Game::Update()
{
    // Load identity matrix
    SRL::Scene3D::LoadIdentity();
    
    // Set camera location and direction
    player.CameraLookAt();
    
        
    SRL::Scene3D::PushMatrix();
    {
        // Rotate teapot
        player.Update();
        renderer.drawModel(*models[player.GetModelID()], lightDirection);
    }
    SRL::Scene3D::PopMatrix();

    SRL::Scene3D::RotateY(SRL::Math::Angle(90.0));
    SRL::VDP2::RBG0::SetCurrentTransform();
        
    // Refresh screen
    SRL::Core::Synchronize();
}
