/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:40:04 by azmakhlo          #+#    #+#             */
/*   Updated: 2025/05/13 18:37:21 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_cmd_array(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
	return (1);
}

int	allocate_token(t_cmd **token, char **cmds)
{
	int	i;

	*token = malloc(sizeof(t_cmd));
	if (!*token)
	{
		i = 0;
		while (cmds[i])
			free(cmds[i++]);
		free(cmds);
		return (1);
	}
	return (0);
}

int	setup_cmd_struct(t_cmd *current, char *cmd_str)
{
    
	current->cmd = ft_split(cmd_str, ' ');
	if (!current->cmd)
		return (1);
	current->input = NULL;
	current->output = NULL;
	return (0);
}

int	create_next_node(t_cmd *current, int has_next)
{
	if (has_next)
	{
		current->next = malloc(sizeof(t_cmd));
		if (!current->next)
			return (1);
	}
	else
		current->next = NULL;
	return (0);
}

