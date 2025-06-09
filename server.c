/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:16:03 by frocha-b          #+#    #+#             */
/*   Updated: 2025/06/06 16:40:38 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("bit 0 recebido");
	if (signal == SIGUSR2)
		ft_printf("bit 1 recebido");
}
int main(void)
{
	int pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	
	while (1)
		pause();
}