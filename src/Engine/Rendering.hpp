#pragma once
#include <srl.hpp>
#include "modelObject.hpp"

//3d rendering class

namespace Engine
{
    class Rendering
    {
    private:
        SRL::Types::HighColor* workTable;
        uint8_t* vertWork;
        SRL::Types::HighColor shadingTable[32];
    public:
        Rendering(/* args */);
        void initGouraud(uint32_t TotalPolygons, uint32_t vertexCount);
        void drawModel(ModelObject& model);
        void drawModel(ModelObject& model, SRL::Math::Vector3D& lightDir);

        void drawMesh(SRL::Types::Mesh& mesh);
        void drawMesh(SRL::Types::SmoothMesh& mesh, SRL::Math::Vector3D& lightDir);
        ~Rendering();
    };
    
} // namespace Engine
