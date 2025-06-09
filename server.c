/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:03 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/09 16:16:15 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signal)
{
	// ft_printf("signal: %d\n", signal);
	if (signal == SIGUSR1)
		ft_printf("bit 0 recebido\n");
	else 
		ft_printf("bit 1 recebido\n");
}
int main(void)
{
	int pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
	}
	return (0);
}