/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:21:20 by julauren          #+#    #+#             */
/*   Updated: 2026/07/01 08:20:52 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	error_arg(int ac, char **av)
{
	int	len, n;
	if (ac != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(av[1]);
	if (len < 5 || (n = ft_strcmp(&av[1][len - 4], ".cub") != 0))
	{
		ft_putstr_fd("Error: Invalid argument.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	error_arg(ac, av);
	parsing(av[1]);
}
