#include <iostream>
#include<SFML/Graphics.hpp>

using namespace sf;

struct S_Point
{
	int x;
	int y;
	S_Point(int x, int y):x(x),y(y){}
};

int main()
{
    RenderWindow window(VideoMode(400, 400), "Hello");
	S_Point circle_pos(1, 1);
	while (window.isOpen())
	{
		Event event;
		window.clear(Color(154, 205, 50, 250));
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code==Keyboard::D)
				{
					circle_pos.x++;
				}
				if (event.key.code == Keyboard::S)
				{
					circle_pos.y++;
				}
			}
		}
		CircleShape circle(50.0f);
		circle.setFillColor(Color(230, 0, 120));
		circle.setOutlineThickness(2);
		circle.setOutlineColor(Color(0, 0, 0));

		circle.move(circle_pos.x, circle_pos.y);

		window.draw(circle);
		window.display();
	}
}