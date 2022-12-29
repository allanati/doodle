#include "Game.hpp"
#include <iostream>

namespace an {
    //Constructor/Destructor

    Game::~Game()
    {
        if (m_window != nullptr)
            delete m_window;
    }

    //Functions
    void Game::SetCaption(const std::string& caption)
    {
        m_caption = caption;
    }

    void Game::SetResolution(int width, int height)
    {
        m_width = width;
        m_height = height;
    }

    void Game::Setup()
    {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
        m_window->setFramerateLimit(60);
        m_texture.loadFromFile("images/background.png");
        m_sprite.setTexture(m_texture);
    }

    void Game::Run()
    {
        sf::Texture t1, t2;
        t1.loadFromFile("images/doodle.png");
        t2.loadFromFile("images/platform.png");

        sf::Sprite sPlat(t2), sPers(t1);
        an::utils::point plat[20];
        for (int i = 0; i < 10; i++)
        {
            plat[i].x = rand() % (400 - 68);
            plat[i].y = rand() % (533 - 14);
        }
        float x = 100, y = 100, h = 200, dx = 0, dy = 0;        //coordinates of doodle
        while (m_window->isOpen())
        {
            sf::Event event;
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += 3;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= 3;

            dy += 0.2;      //velocity of doodle falling down
            y += dy;
            if (y > 500)  dy = -10;       //so that doodle bounces off the bottom

            if (y < h)
                for (int i = 0; i < 10; i++)    //moving platforms
                {
                    y = h;
                    plat[i].y = plat[i].y - dy;
                    if (plat[i].y > 533) { plat[i].y = 0; plat[i].x = rand() % (400 - 68); }
                }

            for (int i = 0; i < 10; i++)        //checking if doodle jumpes on a platform
                if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                    && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;

            sPers.setPosition(x, y);

            m_window->clear();
            PrepareForDisplay();
            m_window->draw(sPers);
            for (int i = 0; i < 10; i++)
            {
                sPlat.setPosition(plat[i].x, plat[i].y);
                m_window->draw(sPlat);
            }
            m_window->display();
        }
    }
}
