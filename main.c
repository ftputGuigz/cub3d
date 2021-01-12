#include <mlx.h>
#include <math.h>
#include <stdio.h>


int	ft_check(int x, int y, int a, int b, int r)
{
	if (pow((x - a), 2) + pow((y - b), 2) <= pow(r, 2))
		return (1);
	else
		return (0);
}

int	main(void)
{
	void *mlx_ptr;
	void *mlx_wdw;


	typedef struct s_struct
	{
		int x;
		int y;

	}			t_coord;
	
	int r;
	int x;
	int y;
	t_coord a;
	t_coord b;

	a.x = 500;
	a.y = 500;
	y = 0;
	r = 200;
	mlx_ptr = mlx_init();
	mlx_wdw = mlx_new_window(mlx_ptr, 1000, 1000, "my_window");
	while (y <= 1000)
	{
		x = 0;	
		while (x <= 1000)
		{
			if (ft_check(x, y, a.x, a.y, r))
				mlx_pixel_put (mlx_ptr, mlx_wdw, x, y, 255000000);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
