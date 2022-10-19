/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:04:38 by amahi             #+#    #+#             */
/*   Updated: 2022/10/19 14:25:42 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void painting_floor_and_ceiling(t_data *data) {
	unsigned int *dst;
	unsigned int i;
	
	data->img = mlx_new_image(data->mlx, WINDOW_W, WINDOW_H);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->size_line, &data->endian);
	
	printf("addr - %p\n", data->addr);
	
	dst = (unsigned int *)data->addr;
	int floor = create_trgb(0, 220, 100, 0);
	int ceiling = create_trgb(0, 225, 30, 0);
	printf("floor - %d\nceiling - %d\n", floor, ceiling);
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = ceiling;
	i = WINDOW_W * WINDOW_H / 2 + 1;
	while (--i > 0)
		*dst++ = floor;
	
}

t_data *init_struct() {
	t_data	*data;
	
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(-1);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_W, WINDOW_H, "cub3d");
	painting_floor_and_ceiling(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);

	
}

int main(int ac, char **av) {
	char	*str;
	int		fd;
	t_data	*data;

	fd = open("firstMap.cub", O_RDONLY);
	str = get_next_line(fd);
	while (str[0] != 'F')
		str = get_next_line(fd);
		
	data = init_struct();
			
	printf("\nOutput:\n");
	printf("str - %s\n", str);
}