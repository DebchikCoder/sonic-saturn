#include "Rendering.hpp"

Engine::Rendering::Rendering()
{
    for(int i = 0; i < 32; i++)
    {
        shadingTable[i] = SRL::Types::HighColor::FromRGB555(i, i, i);
        vertWork = nullptr;
        workTable = nullptr;
    }
}

void Engine::Rendering::initGouraud(uint32_t TotalPolygons, uint32_t vertexCount)
{
    workTable = new SRL::Types::HighColor[TotalPolygons << 2];
    vertWork = new uint8_t[vertexCount];

    SRL::Scene3D::LightInitGouraudTable(0, vertWork, workTable, TotalPolygons);

    SRL::Scene3D::LightSetGouraudTable(shadingTable);

    SRL::Core::OnVblank += SRL::Scene3D::LightCopyGouraudTable;
}

void Engine::Rendering::drawModel(ModelObject& model)
{
    model.Draw();
}

void Engine::Rendering::drawModel(ModelObject& model, SRL::Math::Vector3D& lightDir)
{
    model.Draw(lightDir);
}

void Engine::Rendering::drawMesh(SRL::Types::Mesh& mesh)
{
    SRL::Scene3D::DrawMesh(mesh);
}

void Engine::Rendering::drawMesh(SRL::Types::SmoothMesh& mesh, SRL::Math::Vector3D& lightDir)
{
    SRL::Scene3D::DrawSmoothMesh(mesh, lightDir);
}

Engine::Rendering::~Rendering()
{
    workTable = nullptr;
    vertWork = nullptr;
    for (size_t i = 0; i < 32; i++)
    {
        shadingTable[i] = SRL::Types::HighColor::FromRGB555(0, 0, 0);
    }
    
}
