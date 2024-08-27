/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:14:02 by phkevin           #+#    #+#             */
/*   Updated: 2024/08/27 10:39:00 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Compte le nombre de commandes dans une chaîne en fonction des pipes 
 * ('|').
 *
 * Cette fonction analyse une chaîne de caractères représentant une ligne de 
 * commande et compte le nombre de commandes distinctes en se basant sur la 
 * présence de pipes ('|').
 *
 * @param str La chaîne de caractères à analyser.
 * @return int Retourne le nombre de commandes distinctes.
 */
int	ft_getnbcmd(char *str)
{
	int i;
	int cmd;

	i = 0;
	cmd = 1;
	while (str[i])
	{
		if (ft_gettype(str[i]) == PIPE)
			cmd++;
		i++;
	}
	return (cmd);
}