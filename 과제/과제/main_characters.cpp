#include "Graph.h"
#include "Simple_window.h"
#include "Character.h"

using namespace Graph_lib;

int main()
{
	srand(time(nullptr));

	Point tl(100, 100);
	Simple_window win(tl,800, 800, "Chasing");

	vector<Character*> pursuer;
	vector<Character*> evader;


	pursuer.push_back(new Pursuer(&win, 3, 0));
	evader.push_back(new Evader(&win, 4, 7));
	pursuer[0]->setEnemy(evader[0]);
	evader[0]->setEnemy(pursuer[0]);

	do
	{
		win.wait_for_button();

		for (Character* ch : pursuer)
		{
			ch->move();
		}
		for (Character* ch : evader)
		{
			ch->move();
		}
	} while (!(pursuer[0]->row() == evader[0]->row() && pursuer[0]->col() == evader[0]->col()));//같은위치가아닐때만

	win.set_label("Game Over");
	Text t(Point(300, 400), "The End");
	t.set_color(Color::red);
	t.set_font(Font::times_bold);
	t.set_font_size(50);
	win.attach(t);
	win.wait_for_button();
}
