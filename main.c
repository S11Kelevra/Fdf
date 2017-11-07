#include "./minilibx/mlx.h"
#include <stdio.h>

int main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "Testing");
	y = 0;
	x = 0;
	/*while(y < 200)
	{
		x = 0;
		while(x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	y = 200;
	x = 200;
	while(y < 400)
	{
		x = 0;
		while(x < 400)
		{
			mlx_pixel_put(mlx, win, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}*/
	y = 0;
	x = 0;
	int j;
	j = 0;
	while(j < 400)
	{
		while(x + j < 400)
		{
			mlx_pixel_put(mlx, win, x, (y + j), 0x000000FF + j);
			x++;
			y++;
		}
		y = 0;
		x = 0;
		j = j + 5;
	}
	printf("Done");
	mlx_loop(mlx);
	return(0);
}
