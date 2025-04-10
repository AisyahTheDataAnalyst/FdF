# include "../include/fdf.h"


static void prepare_params(t_line *line, int x0, int y0, int x1, int y1)
{
	line->a.x = x0;
	line->a.y = y0;
	line->b.x = x1;
	line->b.y = y1;
	line->dx = abs(line->b.x - line->a.x);
	line->dy = abs(line->b.y - line->a.y);
	line->err = line->dx - line->dy;
	line->x_inc = (line->a.x < line->b.x) ? 1 : -1;
	line->y_inc = (line->a.y < line->b.y) ? 1 : -1;
}

static void test_draw_line(t_img *img, t_line *line)
{
	int x = line->a.x;
	int y = line->a.y;

	while (1)
	{
		if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
			my_mlx_pixel_put(img, x, y, 0xFFFFFF); // white color for test

		if (x == line->b.x && y == line->b.y)
			break;

		bresenham_formula(line, &x, &y);
	}
}


void test_all_octants(t_line *line, t_img *img)
{

	prepare_params(line, 50, 50, 100, 60);  // Octant 0
	test_draw_line(img, line);

	prepare_params(line, 50, 50, 60, 100);  // Octant 1
	test_draw_line(img, line);

	prepare_params(line, 50, 50, 40, 100);  // Octant 2
	test_draw_line(img, line);

	prepare_params(line, 50, 50, 0, 60);    // Octant 3
	test_draw_line(img, line);

	prepare_params(line, 50, 50, 0, 40);    // Octant 4
	test_draw_line(img, line);

	prepare_params(line, 50, 50, 40, 0);    // Octant 5
	test_draw_line(img, line);

	prepare_params(line, 50, 50, 60, 0);    // Octant 6
	test_draw_line(img, line);

	prepare_params(line, 50, 50, 100, 40);  // Octant 7
	test_draw_line(img, line);
}

// _____________________________________________________________

// no need
// static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
// 		return;
// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// _________________________________________________________


// static void	draw_simple_line(t_line *line, t_img *img, int color)
// {
// 	int	x = line->a.x;
// 	int	y = line->a.y;
// 	int	err = line->dx - line->dy;

// 	while (1)
// 	{
// 		my_mlx_pixel_put(img, x, y, color);
// 		if (x == line->b.x && y == line->b.y)
// 			break;
// 		int e2 = 2 * err;
// 		if (e2 > -line->dy)
// 		{
// 			err -= line->dy;
// 			x += line->x_inc;
// 		}
// 		if (e2 < line->dx)
// 		{
// 			err += line->dx;
// 			y += line->y_inc;
// 		}
// 	}
// }

// void	test_all_octants(t_line *line, t_img *img)
// {
// 	int	center_x = WIN_WIDTH / 2;
// 	int	center_y = WIN_HEIGHT / 2;
// 	int	len = 100;

// 	int dx[16] = {
// 		+len,  +len,    0,    -len,
// 		-len,  -len,    0,    +len,
// 		+len,  +len/2,  -len/2, -len,
// 		-len,  -len/2,  +len/2, +len
// 	};

// 	int dy[16] = {
// 		0,     -len,    -len, -len,
// 		0,     +len,    +len, +len,
// 		+len,  +len/2,  +len/2, +len,
// 		-len,  -len/2,  -len/2, -len
// 	};

// 	for (int i = 0; i < 16; i++)
// 	{
// 		line->a.x = center_x;
// 		line->a.y = center_y;
// 		line->b.x = center_x + dx[i];
// 		line->b.y = center_y + dy[i];

// 		line->dx = abs(line->b.x - line->a.x);
// 		line->dy = abs(line->b.y - line->a.y);
// 		line->x_inc = (line->a.x < line->b.x) ? 1 : -1;
// 		line->y_inc = (line->a.y < line->b.y) ? 1 : -1;

// 		int color = 0xFF0000 >> (i % 3 * 8); // Red, Green, Blue cycling
// 		draw_simple_line(line, img, color);
// 	}
// }
