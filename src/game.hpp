#pragma once
#include "Engine/System.hpp"
#include "Engine/modelObject.hpp"
#include "Engine/Background.hpp"
#include "Engine/Rendering.hpp"

#include "Player.hpp"

class Game
{
private:
    uint32_t polygons, vertecies;
    SRL::Math::Vector3D lightDirection;
    Player player;
    Engine::Rendering renderer;

    std::array<ModelObject*, 2> models;
public:
    //Put things that need to be initialized right after game started
    Game();
    //Put things that need to be loaded or initialized after necesery stuff
    void Start();
    void Update();
};