/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 08:01:09 by julauren          #+#    #+#             */
/*   Updated: 2026/07/01 08:55:44 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	error_parsing(t_error error)
{
	if (error == FD)
		ft_putstr_fd("Error: Invalid fd.\n", 2);
	else if (error == MALLOC)
		ft_putstr_fd("Error: Memory allocation failure", 2);
	exit(EXIT_FAILURE);
}
