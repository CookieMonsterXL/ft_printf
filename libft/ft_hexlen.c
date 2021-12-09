//
// Created by Tiemen Bouma on 12/6/21.
//
int	ft_hexlen(long n)
{
	int	i;

	i = 0;
	while (n > 1)
	{
		n /= 16;
		i++;
	}
	return (i);
}
