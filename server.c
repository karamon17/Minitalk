/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:54:25 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/03/20 18:54:28 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_handler(int signum, siginfo_t *sig, void *context)
{
	static unsigned char	res;
	static int				i;

	(void)sig;
	(void)context;
	if (signum == SIGUSR1)
		res |= (1 << i);
	i++;
	if (i == 8)
	{	
		write(1, &res, 1);
		res = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	my_struct;

	write(1, "PID:", 4);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	my_struct.sa_flags = SA_SIGINFO;
	my_struct.sa_sigaction = ft_handler;
	while (1)
	{
		sigaction(SIGUSR1, &my_struct, NULL);
		sigaction(SIGUSR2, &my_struct, NULL);
		pause();
	}
	return (0);
}
