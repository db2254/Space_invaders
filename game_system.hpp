// game_system.hpp

struct GameSystem {
	// Global variables go here

	// Game system functions
    static sf::Texture spritesheet;
    static sf::Sprite invader;


    static void init();  // Initialise game resources
    static void clean();  // Clean up game resources 
    static void update(const float& dt);  // Update game state 
    static void render(sf::RenderWindow &window);  // Render game entities
};