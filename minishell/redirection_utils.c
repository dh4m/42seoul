/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:40:44 by dham              #+#    #+#             */
/*   Updated: 2023/01/28 15:23:32 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

int	close_redirect_fd(t_astnode *node)
{
	t_strnode	*cur_node;

	cur_node = node->redi.prenode.next;
	while (cur_node && cur_node->content.fd != -1)
	{
		close(cur_node->content.fd);
		cur_node = cur_node->next;
	}
	while (cur_node)
	{
		if (cur_node->type == RE_HEREDOC || cur_node->type == RE_HEREDOC_EXPAND)
			close(cur_node->content.fd);
		cur_node = cur_node->next;
	}
	return (1);
}
