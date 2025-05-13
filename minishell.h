/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azmakhlo <azmakhlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:23:24 by azmakhlo          #+#    #+#             */
/*   Updated: 2025/05/13 18:29:27 by azmakhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "readline/readline.h"
# include <stdio.h>

typedef enum s_type
{
	D_FILE,
	D_APPEND,
	D_HERDOC
}						t_type;

typedef struct s_redirec
{
	char				*name;
	t_type				type;
	struct s_redirec	*next;
}						t_redirec;

typedef struct s_cmd
{
	char 				*line;
	char				**cmd;
	t_redirec			*input;
	t_redirec			*output;
	struct s_cmd		*next;
}				t_cmd;

// typedef struct s_cmd_ex
// {
// 	char				**cmd;
// 	t_redirec			*input;
// 	t_redirec			*output;
// 	struct s_cmd		*next;
// }						t_cmd_ex;

int	free_cmd_array(char **cmds);
int	allocate_token(t_cmd **token, char **cmds);
int	setup_cmd_struct(t_cmd *current, char *cmd_str);
int	create_next_node(t_cmd *current, int has_next);
int	arg_create(t_cmd *token, char **cmds);
t_cmd	*handle_token_error(char **cmds, t_cmd *token);
t_cmd	*tokenization(char *line);
void	print_cmd_list(t_cmd *token);
void	 free_cmd_node(t_cmd *node);

#endif