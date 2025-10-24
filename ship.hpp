// ship.hpp
#pragma once
#include <SFML/Graphics.hpp>


class Ship : public sf::Sprite {
public:
	Ship();
	// Copy constructor
	Ship(const Ship& s);

	// Constructor takes a sprite
	Ship(sf::IntRect ir);

	// Pure virtual deconstructor -- makes an abstract class and avoids undefined behaviour
	virtual ~Ship() = 0;

	// Update, virtual so can be overridden, but not pure virtual
	virtual void update(const float& dt);

	// Move the ship down, virtual so invaders can override
	virtual void move_down();

protected:
	sf::IntRect _sprite;
};

class Invader : public Ship {
public:
	Invader();
	Invader(const Invader& inv);
	Invader(sf::IntRect ir, sf::Vector2f pos);
	void update(const float& dt) override;

	static bool direction;
	static float speed;
};

class Player : public Ship {
public:
	Player();
	void update(const float& dt) override;
	void move_down() override {}
	static constexpr int speed = 100.f;
};




