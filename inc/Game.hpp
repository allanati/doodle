#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
namespace an::utils {
	struct point
	{
		int x, y;
	};
}
namespace an {

	// Class that acts as game engine

	class Game
	{
	private:
		int m_width, m_height;
		std::string m_caption;
		sf::Texture m_texture;
		sf::Sprite m_sprite;
		sf::RenderWindow* m_window = nullptr;
	private:
		void PrepareForDisplay()
		{
			m_window->draw(m_sprite);
		}
	public:
		void SetCaption(const std::string& caption);
		void SetResolution(int width, int height);

		//Consrtuctor and Destructor
		Game() {}
		~Game();

		//Functions
		void Setup();
		void Run();
	};
}