// ship.cpp
#include "ship.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"

using param = Parameters; //renaming the struct Parameters into param to have a more compact and readable code
using gs = GameSystem; //renaming the struct GameSystem into gs to have a more compact and readable code

bool Invader::direction = true;
float Invader::speed = 20.f;

Ship::Ship() {};

Ship::Ship(const Ship &s) :
	_sprite(s._sprite){}

Ship::Ship(sf::IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(gs::spritesheet);
	setTextureRect(_sprite);
};

void Ship::update(const float &dt) {}

// Define the ship deconstructor
// Although we set this to pure virtual, we still have to define it 
Ship::~Ship() = default;

Invader::Invader() : Ship() {}
Invader::Invader(const Invader& inv) : Ship(inv) {}
Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(sf::Vector2f(16.f, 16.f));
	setPosition(pos);
}

void Ship::move_down() {
	move(sf::Vector2f(0.0f, param::down));
}

void Invader::update(const float& dt) {
	Ship::update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f);

	if ((direction && getPosition().x > param::game_width - param::sprite_size / 2.f) ||
		(!direction && getPosition().x < param::sprite_size / 2.f)) {
		direction = !direction;
		for (std::shared_ptr<Ship>& ship : gs::ships) {
			ship->move_down();
		}
	}
}