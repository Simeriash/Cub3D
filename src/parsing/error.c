/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 08:01:09 by julauren          #+#    #+#             */
/*   Updated: 2026/07/10 15:58:18 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	error_parsing(t_error error)
{
	if (error == MALLOC)
		ft_putstr_fd("Error: Memory allocation failure.\n", 2);
	else if (error == INPUT)
		ft_putstr_fd("Error: Wrong Input.\n", 2);
	else if (error == MAP)
		ft_putstr_fd("Error: Invalid map.\n", 2);
	exit(EXIT_FAILURE);
}
