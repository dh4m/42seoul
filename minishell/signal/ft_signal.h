/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:47:04 by dham              #+#    #+#             */
/*   Updated: 2023/01/11 15:10:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# define SIGINT_CATCH -256

void	ft_readline_signal_set(void);
void	ft_excute_signal_set(void);
void	ft_default_signal_set(void);
void	ft_heredoc_signal_set(void);
void	end_heredoc_set(void);

void	readline_proc(int sig);
void	heredoc_sig_proc(int sig);
void	newline_proc(int sig);
int		empty_event(void);

#endif