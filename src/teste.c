#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int	ft_atol(const char *str)
{
	int	sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num * sign);
}
int main(int ac, char **av)
{
    long nbr;
    int i;

    nbr = 0;
    i = 0;
    while (av[i])
    {
        nbr = ft_atol(av[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
        {
            printf("ERROR \n");
            return(0);
        }
        i++;
    }
    return(0);
}
