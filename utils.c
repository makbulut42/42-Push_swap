/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:32:41 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/26 11:04:15 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int	ft_atoi(const char *str, int *num)
{
	char	*ptr;
	long	nbr;
	int		sign;
	size_t	i;

	ptr = (char *)str;
	nbr = 0;
	sign = 1;
	if (*ptr == '-' && ptr++)
		sign *= -1;
	if (*ptr == '\0')
		return (0);
	i = 0;
	while (*ptr >= '0' && *ptr <= '9' && i++ < 10)
		nbr = nbr * 10 + *ptr++ - '0';
	if (*ptr != '\0' || nbr * sign > 2147483647 || nbr * sign < -2147483648)
		return (1);
	*num = nbr * sign;
	return (0);
}

size_t ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_putnbr(int n)
{
	char c;
	long nnbr;

	nnbr = n;
	if (nnbr < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		nnbr *= -1;
	}
	if (nnbr != 0)
	{
		if (nnbr / 10 > 0)
			ft_putnbr(nnbr / 10);
		c = nnbr % 10 + 48;
		write(STDOUT_FILENO, &c, 1);
	}
	if (n == 0)
		write(STDOUT_FILENO, "0", 1);
}

// putnumber
// int main(void)
// {
// 	int a;
// 	a = -28;
// 	ft_putnbr(a);
// 	return (0);
// }

// ft_strlen
// int main(void)
// {
// 	char *a;	
// 	a = "mehmet";
// 	printf("%zu", ft_strlen(a));
// 	return (0);
// }

//ft_atoi
// int	ft_atoi(char *s)
// {
// 	int i;
// 	int res;
// 	int neg;
// 	i = 0;
// 	neg = 1;
// 	res = 0;
// 	if (s[i] == '-' || s[i] == '+')
// 	{
// 		if (s[i] == '-')
// 			neg *= -1;
// 		i++;
// 	}
// 	while (s[i])
// 	{
// 		if (!(s[i] >= '0' && s[i] <= '9' || s[i] == ' '))
// 			printf("wrong number bro");
// 		if (s[i] == ' ' || s[i] == '\t')
// 			return (res * neg);
// 		res = (res * 10) + s[i++] - '0';
// 	}
// 	return (res * neg);
// }

//ft_strcmp
// int main(int ac, char **av)
// {
// 	int c;
// 	char *a;
// 	char *b;	
// 	a = "mehmet";
// 	b = "ahmet";
// // 	c = ft_strcmp(a, b);
// 	if (--ac < 1 || (!ft_strcmp(av[1], "-v") && ac == 1))
// 	{	
// 		printf("fail");
// 		exit(1);
// 	}
// 	if (!ft_strcmp(av[1], "-v"))
// 	{
// 		printf("sucsess");
// 	}
// 	return (0);
// }
// int main(void)
// {
// 	int c;
// 	char *a;
// 	char *b;	
// 	a = "-v 93 ";
// 	b = "ahmet";
// 	//c = ft_strcmp(a, "-v");
// 	//printf("%d", c);
// 	if (!ft_strcmp(a, "-v"))
// 	{
// 		printf("sucsess");
// 	}
// 	return (0);
// }