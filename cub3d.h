/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:05:57 by amahi             #+#    #+#             */
/*   Updated: 2022/10/19 13:07:40 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "GNL/get_next_line.h"

# define KEYDOWN 2
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define WINDOW_W 2000
# define WINDOW_H 1000


typedef struct s_data 
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;

	int		bpp;
	int		size_line;
	int		endian;
	
}	t_data;

#endif