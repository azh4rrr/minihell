/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:42:15 by azmakhlo          #+#    #+#             */
/*   Updated: 2025/05/25 20:23:29 by azmakhlo         ###   ########.fr       */
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
		return (0);
	add_history(line);
	*token_ptr = tokenization(line);
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
		if (process_line(line, &token) != 0)
			return (1);
		if(syntax_error(line))
			free_cmd_list(token);
		else if (token)
		{
			print_cmd_list(token);
			free_cmd_list(token);
		}
		else
			free(line);
	}
}
