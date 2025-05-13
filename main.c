/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:42:15 by azmakhlo          #+#    #+#             */
/*   Updated: 2025/05/13 18:56:45 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd_list(t_cmd *token)
{
	t_cmd	*next;

	while (token)
	{
		next = token->next;
		free_cmd_node(token);
		token = next;
	}
}

int	process_line(char *line, t_cmd **token_ptr)
{
	if (ft_strlen(line) <= 0)
		return (printf("strlen is <= 0 in main\n"), 1);
	add_history(line);
	*token_ptr = tokenization(line);
	free(line);
	return (0);
}

int	main(int ac, char **av)
{
	char *line;
	t_cmd *token;

	(void)av;
	if (ac != 1)
		return (1);

	while (1)
	{
		token = NULL;
		line = readline("minishell> ");
		if (!line)
			return (printf("line is NULL in main\n"), 1);
		token->line = line;
		if (process_line(line, &token) != 0)
			return (1);
		if (token)
			print_cmd_list(token);
		//!parcing(token);
		if (token)
			free_cmd_list(token);
	}
}
