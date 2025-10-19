// game_parameters.hpp
#pragma once// insure that this file is included only once and there will be no multiple definition of the same thing

struct Parameters {
	static constexpr int game_width = 800;
	static constexpr int game_height = 600;
	static constexpr float time_step = 0.017f;
	static constexpr int sprite_size = 32;
	static constexpr int spacing = 18;
	static constexpr int rows = 5;
	static constexpr int columns = 12;
	static constexpr int down = 24;
	static constexpr int acc = 10.f;
};