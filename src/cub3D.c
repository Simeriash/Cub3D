/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:21:20 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 15:16:40 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static void	error_arg(int ac, char **av)
{
	int	len;
	int	n;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(av[1]);
	n = ft_strcmp(&av[1][len - 4], ".cub");
	if (len < 5 || (n != 0))
	{
		ft_putstr_fd("Error: Invalid argument.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**map;

	error_arg(ac, av);
	ft_bzero(&data, sizeof(data));
	map = parsing(av[1], &data);
	free_struct(&data, map);
}
