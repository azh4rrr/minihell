/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:40:04 by azmakhlo          #+#    #+#             */
/*   Updated: 2025/05/15 14:46:18 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_cmd_array(char **cmds)
{
	int	i;

	if (!cmds)
		return (1);
	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
	return (1);
}

int	allocate_token(t_cmd **token, char **cmds)
{
	int	i;

	*token = (t_cmd *)malloc(sizeof(t_cmd));
	if (!*token)
	{
		i = 0;
		while (cmds[i])
			free(cmds[i++]);
		free(cmds);
		return (1);
	}
	(*token)->cmd = NULL;
	(*token)->line = NULL;
	(*token)->next = NULL;
	return (0);
}

int	setup_cmd_struct(t_cmd *current, char *cmd_str)
{
	if (!current || !cmd_str)
		return (1);
	current->cmd = ft_split(cmd_str, ' ');
	if (!current->cmd)
		return (1);
	current->line = NULL;
	current->redirec = NULL;
	return (0);
}

int	create_next_node(t_cmd *current, int has_next)
{
	if (!current)
		return (1);
	if (has_next)
	{
		current->next = (t_cmd *)malloc(sizeof(t_cmd));
		if (!current->next)
			return (1);
		current->next->cmd = NULL;
		current->next->line = NULL;
		current->next->redirec = NULL;
		current->next->next = NULL;
	}
	else
		current->next = NULL;
	return (0);
}
