#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include <iostream>

using namespace sf;

class Player {
public:
	float x, y, w, h, dx, dy, speed = 0;
	int dir = 0;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String F, float X, float Y, float W, float H) {
		File = F;
		w = W; h = H;
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
	}

	float getplayercoordinateX() {
		return x;
	}

	float getplayercoordinateY() {
		return y;
	}

	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0;   break;
		case 1: dx = -speed; dy = 0;   break;
		case 2: dx = 0; dy = speed;   break;
		case 3: dx = 0; dy = -speed;   break;
		
		}

		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
	}
};


int main()
{
	RenderWindow window(sf::VideoMode(910, 900), "Cyka");

	float CurrentFrame = 0;
	Clock clock;
	Clock timer;

	Texture map;
	map.loadFromFile("map.png");
	Sprite s_map;
	s_map.setTexture(map);

	Player p("penguin.png", 250, 250, 96.0, 96.0);
	p.sprite.setScale(0.2f, 0.2f);

	view.reset(FloatRect(0, 0, 910, 900));
	view.zoom(0.7f);

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 1; p.speed = 0.001;
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 0; p.speed = 0.001;
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
			}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			p.dir = 3; p.speed = 0.001;
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) { 
			p.dir = 2; p.speed = 0.001;
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}

		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			p.speed = 0.6;
		}

		if (Keyboard::isKeyPressed(Keyboard::O)) {
			view.zoom(0.99f);
		}
		if (Keyboard::isKeyPressed(Keyboard::P)) {
			view.zoom(1.01f);
		}

		p.update(time);

		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (A4Room[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (A4Room[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if ((A4Room[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));


				s_map.setPosition(j * 32, i * 32);

				window.draw(s_map);
			}

		window.draw(p.sprite);

		float timeToRestart = timer.getElapsedTime().asSeconds();
		if (timeToRestart > 5.0f) {
			std::system("cls");
			std::cout << "Coordinate X - " << p.getplayercoordinateX() << std::endl;
			std::cout << "Coordinate Y - " << p.getplayercoordinateY() << std::endl;
			timer.restart();
		}

		//std::cout << timeToRestart << std::endl;
		window.setView(view);
		window.display();
	}

	return 0;
}