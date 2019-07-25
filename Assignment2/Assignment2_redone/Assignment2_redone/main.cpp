#include <SFML\graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	texture.create(1280, 720);
	image.create(1280, 720, sf::Color::Black);

	for (unsigned x = 0; x < 1280; x++)
		for (unsigned y = 0; y < 80; y++)
			image.setPixel(x, y, sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		window.clear();
		texture.update(image);
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();
	}

	return 0;
}