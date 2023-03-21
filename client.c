/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:54:03 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/03/20 18:54:05 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_send(int pid, char c)
{
	int	n;

	n = 0;
	while (n < 8)
	{
		if ((c & (1 << n)) > 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		n++;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		j;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		j = 0;
		while (str[j])
		{	
			ft_send(pid, str[j]);
			j++;
		}
		ft_send(pid, '\n');
	}
	return (0);
}
