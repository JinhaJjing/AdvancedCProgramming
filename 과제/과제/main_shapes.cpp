#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl(100, 300);
	Simple_window win(tl, 800, 800, "Box");


	Graph_lib::Box a(Point(100, 100), 150, 100,30);
	a.set_color(Color::cyan);
	a.set_style(Line_style(Line_style::dash, 4));
	win.attach(a);
	Graph_lib::Box b(Point(200, 200), 300, 150, 50);
	b.set_color(Color::red);
	win.attach(b);
	Graph_lib::Box c(Point(400, 400), 350, 200, 40);
	c.set_color(Color::dark_green);
	c.set_style(Line_style(Line_style::dash, 2));
	win.attach(c);

	win.wait_for_button();
	win.detach(a);
	win.detach(b);
	win.detach(c);

	win.set_label("Reguar_polygon");

	Graph_lib::Regular_polygon d(Point(100, 100), 3,50);
	d.set_color(Color::black);
	d.set_style(Line_style(Line_style::dash, 4));
	win.attach(d);
	Graph_lib::Regular_polygon e(Point(300, 300), 7, 100);
	e.set_color(Color::yellow);
	win.attach(e);
	Graph_lib::Regular_polygon f(Point(500, 500),12, 180);
	f.set_color(Color::blue);
	f.set_style(Line_style(Line_style::dash, 2));
	win.attach(f);

	win.wait_for_button();
	win.detach(d);
	win.detach(e);
	win.detach(f);

	win.set_label("Star");

	Graph_lib::Star g(Point(100, 100), 4, 20,70);
	g.set_color(Color::black);
	g.set_style(Line_style(Line_style::dash, 4));
	win.attach(g);
	Graph_lib::Star h(Point(250, 300), 6, 50, 120);
	h.set_color(Color::yellow);
	win.attach(h);
	Graph_lib::Star i(Point(500, 500), 8, 100, 250);
	i.set_color(Color::blue);
	i.set_style(Line_style(Line_style::dash, 2));
	win.attach(i);

	win.wait_for_button();
}