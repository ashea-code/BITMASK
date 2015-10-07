#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"
#include <string>

class GraphicComponent : public Component
{
	public:
		GraphicComponent(std::string imgPath, GameObject* owner);
		sf::Texture mTexture;
		sf::Sprite mSprite;
};