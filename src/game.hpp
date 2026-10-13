#pragma once
#include "Engine/System.hpp"
#include "Engine/modelObject.hpp"
#include "Engine/Background.hpp"

#include "Player.hpp"

class Game
{
private:
    SRL::Types::HighColor shadingTable[32];
    SRL::Math::Vector3D lightDirection;
    Player player;
    SRL::Types::HighColor* workTable = nullptr;
    uint8_t* vertWork = nullptr;

    std::array<ModelObject*, 2> models;
public:
    //Put things that need to be initialized right after game started
    Game();
    //Put things that need to be loaded or initialized after necesery stuff
    void Start();
    void Update();
};