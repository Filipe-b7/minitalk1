/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:09 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/06 18:01:31 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void char_to_bit(char c)
{
	int bit;
	int i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		send_bit(bit);
		i--;
	}
}

void	send_bit(int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
		
}
int main(int ac, char ** argv)
{
	int	i = 0;
	if (ac == 3)
	{
		// e se o Pid nao for o correto 
		pid_t pid = (pid_t)ft_atoi(argv[1]);
		// e se a mensagem for nula
		char *message = argv[2];
		if (kill(pid, SIGUSR1) == 0)
			ft_printf("KILL FUNCIONOU");
		else
			ft_printf("kill nao funcionou");
		while (message[i])
		{
			char_to_bit(message[i]);
			i++;
		}
	}
	else
	{
		ft_printf("Please insert the PID and the Message");
	}
}