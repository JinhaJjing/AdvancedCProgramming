#include "Character.h"

using namespace Graph_lib;

const int grid_width = 8;
const int grid_height = 8;

Character::Character(Graph_lib::Window* win, int r, int c)
	: my_window{ win }, pos_row { r }, pos_col{ c }, my_enemy{ nullptr }
{
}

void Character::move()
{
	pair<int, int> dir = nextDirection();

	int dr = dir.first;
	int dc = dir.second;
	pos_row += dr;
	pos_col += dc;

	int w = my_window->x_max() / grid_width;
	int h = my_window->y_max() / grid_height;
	for (Shape* s : body_shapes)
	{
		s->move(w*dc, h*dr);
	}
} 

pair<int, int> Character::nextDirection()
{
	return make_pair(0, 0);
}

Pursuer::Pursuer(Graph_lib::Window * win, int r, int c)
	: Character(win, r, c)
{
	int w = win->x_max() / grid_width;
	int h = win->y_max() / grid_height;

	Graph_lib::Circle* head = new Graph_lib::Circle(Point(c*w + w / 2, r*h + h / 4), w /4);
	Graph_lib::Circle* eye1 = new Graph_lib::Circle(Point(c*w + w / 16 * 6, r*h + h / 16 * 3), w / 16);
	Graph_lib::Circle* eye2 = new Graph_lib::Circle(Point(c*w + w / 16*11, r*h + h / 16*3), w / 16);
	Graph_lib::Rectangle* body = new Graph_lib::Rectangle(Point(c*w + w / 4, r*h + h / 2), w / 2, h / 2);
	head->set_fill_color(Color::red);
	eye1->set_fill_color(Color::black);
	eye2->set_fill_color(Color::black);
	body->set_fill_color(Color::red);
	body_shapes.push_back(head);
	body_shapes.push_back(eye1);
	body_shapes.push_back(eye2);
	body_shapes.push_back(body);
	win->attach(*head);
	win->attach(*eye1);
	win->attach(*eye2);
	win->attach(*body);
}

Evader::Evader(Graph_lib::Window * win, int r, int c)
	: Character(win, r, c)
{
	int w = win->x_max() / grid_width;
	int h = win->y_max() / grid_height;

	Graph_lib::Circle* head = new Graph_lib::Circle(Point(c*w + w / 2, r*h + h / 4), w / 4);
	Graph_lib::Circle* eye1 = new Graph_lib::Circle(Point(c*w + w / 16 * 7, r*h + h / 16 * 3), w / 16);
	Graph_lib::Circle* eye2 = new Graph_lib::Circle(Point(c*w + w / 16 * 10, r*h + h / 16 * 3), w / 16);
	Graph_lib::Rectangle* body = new Graph_lib::Rectangle(Point(c*w + w / 4, r*h + h / 2), w / 2, h / 2);
	head->set_fill_color(Color::blue);
	eye1->set_fill_color(Color::black);
	eye2->set_fill_color(Color::black);
	body->set_fill_color(Color::blue);
	body_shapes.push_back(head);
	body_shapes.push_back(eye1);
	body_shapes.push_back(eye2);
	body_shapes.push_back(body);
	win->attach(*head);
	win->attach(*eye1);
	win->attach(*eye2);
	win->attach(*body);
}


pair<int, int> Pursuer::nextDirection()
{
	vector<pair<int, int>> directions = { { -1,0 },{ +1,0 },{ 0,-1 },{ 0,+1 } };
	random_shuffle(directions.begin(), directions.end());

	int dr = 0, dc = 0, new_r = 0, new_c = 0;

	int row_dis = pos_row - enemy()->row();
	int col_dis = pos_col - enemy()->col();

	double distance = sqrt((row_dis)*(row_dis)+(col_dis)*(col_dis));


	for (int i = 0; i < 4; i++)
	{
		dr = directions[i].first;
		dc = directions[i].second;
		new_r = pos_row + dr;
		new_c = pos_col + dc;

		int new_row_dis = new_r - enemy()->row();
		int new_col_dis = new_c - enemy()->col();

		double new_distance = sqrt((new_row_dis*new_row_dis + new_col_dis * new_col_dis));

		if (new_distance <= distance)
		{
			if (new_r >= 0 && new_r < grid_height &&new_c >= 0 && new_c < grid_width)
				return directions[i];
		}
	}
}

pair<int, int> Evader::nextDirection()
{
	vector<pair<int, int>> directions = { { -1,0 },{ +1,0 },{ 0,-1 },{ 0,+1 } };
	random_shuffle(directions.begin(), directions.end());

	int dr = 0, dc = 0, new_r = 0, new_c = 0;

	int row_dis = pos_row - enemy()->row();
	int col_dis = pos_col - enemy()->col();

	double distance = sqrt((row_dis)*(row_dis)+(col_dis)*(col_dis));

	for (int i = 0; i < 4; i++)
	{
		dr = directions[i].first;
		dc = directions[i].second;
		new_r = pos_row + dr;
		new_c = pos_col + dc;

		int new_row_dis = new_r - enemy()->row();
		int new_col_dis = new_c - enemy()->col();

		double new_distance = sqrt((new_row_dis*new_row_dis + new_col_dis * new_col_dis));

		if (pos_row == 0 && pos_col == 0)
		{
			if (new_r >= 0 && new_r < grid_height &&new_c >= 0 && new_c < grid_width)
				return directions[i];
		}
		if (pos_row == 7 && pos_col == 0)
		{
			if (new_r >= 0 && new_r < grid_height &&new_c >= 0 && new_c < grid_width)
				return directions[i];
		}
		if (pos_row == 0 && pos_col == 7)
		{
			if (new_r >= 0 && new_r < grid_height &&new_c >= 0 && new_c < grid_width)
				return directions[i];
		}
		if (pos_row == 7 && pos_col == 7)
		{
			if (new_r >= 0 && new_r < grid_height &&new_c >= 0 && new_c < grid_width)
				return directions[i];
		}

		if (new_distance >= distance)
		{
			if (new_r >= 0 && new_r < grid_height &&new_c >= 0 && new_c < grid_width)
				return directions[i];
		}
	}
}