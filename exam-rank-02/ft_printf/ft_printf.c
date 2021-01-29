#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int		e_p = 0;
int		e_w = 0;
int		prec = 0;
int		wid = 0;
int		ret_print;

void	ft_rwrite(char c)
{
	write(1, &c, 1);
	ret_print++;
}

size_t	ft_strlen(char *s)
{
	int		i = 0;

	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

long long	ft_size_int(long long i, int base)
{
	int		ret = 0;

	if (i == 0)
		ret = 1;
	if (i < 0)
	{
		if (base == 10)
		{
			i = -i;
			ret++;
		}
		else
		{
			ret = 8;
			i = 0;
		}
	}
	while (i > 0)
	{
		ret++;
		i /= base;
	}
	return (ret);
}

char	*ft_itoa(long long i, int base)
{
	int		len = 0;
	int		flag = 0;
	char	*ret;
	int		j = 0;
	len = ft_size_int(i, base);
	if (e_p == 1 && prec >= len && (flag = 1))
		len = prec;
	if (e_p == 1 && prec == 0 && i == 0)
		len = 0;
	if (!(ret = malloc(sizeof(char *) * len + 1)))
		return (NULL);
	if (i < 0)
	{
		if (base == 10)
		{
			i = -i;
			if (flag == 1)
				len++;
			ret[j++] = '-';
		}
		else
			i = 4294967296 - (-i);
	}
	while (j < len)
		ret[j++] = '0';
	ret[len--] = '\0';
	while (i > 0)
	{
		j = i % base;
		i /= base;
		j = (j > 9) ? j += 39 : j;
		ret[len--] = (j + 48);
	}
	return (ret);
}

void	ft_conversion_int(va_list args, int base)
{
	char	*num;
	int		len = 0;
	int		i = 0;

	num = ft_itoa(va_arg(args, int), base);
	len = ft_strlen(num);
	while (e_w == 1 && wid > len)
	{
		ft_rwrite(' ');
		wid--;
	}
	while (len > i)
		ft_rwrite(num[i++]);
	free(num);
}

void	ft_conversion_str(va_list args)
{
	char	*tab;
	char	str[7] = "(null)";
	int		len = 6;
	int		i = 0;

	tab = va_arg(args, char *);
	if (tab)
		len = ft_strlen(tab);
	if (e_p == 1 && prec < len)
		len = prec;
	while (len < wid && e_w == 1)
	{
		ft_rwrite(' ');
		wid--;
	}
	while (len > i)
	{
		if (tab)
			ft_rwrite(tab[i++]);
		else
			ft_rwrite(str[i++]);
	}
}

int		ft_parse_conversion(const char **str, va_list args)
{
	if (**str == 's')
		ft_conversion_str(args);
	else if (**str == 'd')
		ft_conversion_int(args, 10);
	else if (**str == 'x')
		ft_conversion_int(args, 16);
	else
		return (-1);
	(*str)++;
	return (0);
}

int		ft_flag(const char **str, char a)
{
	int		ret = 0;

	a == 'p' ? ret = 1 : 0;
	while ((*str)[ret] >= '0' && (*str)[ret] <= '9' && (*str)[ret] != '\0')
	{
		if (a == 'p')
			prec = prec * 10 + ((*str)[ret] - 48);
		else
			wid = wid * 10 + ((*str)[ret] - 48);
		ret++;
	}
	a == 'p' ? e_p = 1 : 0;
	a == 'w' ? e_w = 1 : 0;
	return (ret);
}

int		ft_parse_flags(const char **str)
{
	while (**str)
	{
		if (**str >= '0' && **str <= '9')
			*str += ft_flag(str, 'w');
		else if (**str == '.' && e_p == 0)
			*str += ft_flag(str, 'p');
		else if (**str == '.')
			return (-1);
		else
			return (0);
	}
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;

	ret_print = 0;
	va_start(args, str);
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_parse_flags(&str) == -1)
				return (-1);
			if (ft_parse_conversion(&str, args) == -1)
				return (-1);
			e_p = 0;
			e_w = 0;
			prec = 0;
			wid = 0;
		}
		else
			ft_rwrite(*str++);
	}
	return (ret_print);
}

int main()
{

	// printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	ft_printf(" ret : %d", ft_printf("|%d|", INT_MIN)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%d|", INT_MIN)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%d|", INT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%d|", INT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%d|", 0)) ;
	printf("\n\n") ;

	// printf("---------------------------------------\n") ;
	ft_printf(" ret : %d", ft_printf("|%30d|", INT_MIN)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%30d|", INT_MIN)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%3d|", INT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%3d|", INT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%30d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%30d|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%0d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%0d|", 0)) ;
	printf("\n\n") ;

	// printf("-----------------------d_prec--------\n") ;
	ft_printf(" ret : %d", ft_printf("|%.30d|", INT_MIN)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.30d|", INT_MIN)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.3d|", INT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.3d|", INT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.30d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.30d|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.0d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.0d|", 0));
	printf("\n\n") ;

	// printf("----------------------d_width_prec--------------------\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20d|", INT_MIN)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20d|", INT_MIN)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20d|", INT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20d|", INT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20d|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.0d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.0d|", 0));
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%15.0d|", INT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%15.0d|", INT_MAX)) ;
	printf("\n\n") ;

	// printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	ft_printf(" ret : %d", ft_printf("|%x|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%x|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%x|", UINT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%x|", UINT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%x|", -123)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%x|", -123)) ;
	printf("\n\n") ;

	// printf("-----------------------\n") ;
	ft_printf(" ret : %d", ft_printf("|%30x|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%30x|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%3x|", UINT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%3x|", UINT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%30x|", -123)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%30x|", -123)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%0x|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%0x|", 0)) ;
	printf("\n\n") ;


	// printf("----------------------\n") ;
	ft_printf(" ret : %d", ft_printf("|%.30x|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.30x|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.3x|", UINT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.3x|", UINT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.30x|", -123)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.30x|", -123));
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.x|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.x|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.0x|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.0x|", 0)) ;
	printf("\n\n") ;


	// printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	ft_printf(" ret : %d", ft_printf("|%45.20d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20d|", 0)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20d|", UINT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20d|", UINT_MAX)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20d|", -123)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20d|", -123)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.0d|", 0)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.0d|", 0));
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%15.0d|", UINT_MAX)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%15.0d|", UINT_MAX)) ;
	printf("\n\n") ;


	// printf("----------------------s_no_flags--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	ft_printf(" ret : %d", ft_printf("|%s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%s|", NULL)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%s|", NULL)) ;
	printf("\n\n") ;


	// printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	ft_printf(" ret : %d", ft_printf("|%30s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%30s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%3s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%3s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%30s|", NULL)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%30s|", NULL)) ;
	printf("\n\n") ;


	// printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	ft_printf(" ret : %d", ft_printf("|%.30s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.30s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.6s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.6s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.30s|", NULL)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.30s|", NULL)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.3s|", NULL)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.3s|", NULL)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%.s|", NULL)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%.s|", NULL)) ;
	printf("\n\n") ;

	// printf("------------------------s_width_prec--------------------\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20s|", "abcdefghij")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20s|", "abcdefghij")) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%45.20s|", NULL)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%45.20s|", NULL)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|%10.2s|", "toto")) ;
	printf("\n") ;
	printf(" ret : %d", printf("|%10.2s|", "toto"));
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|Magic %s est %5d|", "number", 42)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|Magic %s est %5d|", "number", 42)) ;
	printf("\n\n") ;
	ft_printf(" ret : %d", ft_printf("|Hexadécimal pour %d est %x|", 42, 42)) ;
	printf("\n") ;
	printf(" ret : %d", printf("|Hexadécimal pour %d est %x|", 42, 42)) ;
	printf("\n\n") ;


	ft_printf(" ret : %d", ft_printf(" %d ", 0));
    printf("\n") ;
    printf(" ret : %d", printf(" %d ", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf(" %.d ", 0));
    printf("\n") ;
    printf(" ret : %d", printf(" %.d ", 0));
    printf("\n") ;
    printf("\n") ;
    ft_printf(" ret : %d", ft_printf(" %3.2d %10.42d ", 0, 0));
    printf("\n") ;
    printf(" ret : %d", printf(" %3.2d %10.42d ", 0, 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf(" %3.2d %10.42d ", 1, -1));
    printf("\n") ;
    printf(" ret : %d", printf(" %3.2d %10.42d ", 1, -1));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf(" %3.2d %10.42d ", 10, -10));
    printf("\n") ;
    printf(" ret : %d", printf(" %3.2d %10.42d ", 10, -10));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%9.2d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%9.2d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%9.10d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%9.10d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%10.0d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%10.0d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%10.1d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%10.1d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%10.2d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%10.2d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%10.10d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%10.10d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%11.0d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%11.0d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%11.1d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%11.1d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%11.2d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%11.2d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%11.10d", UINT_MAX));
    printf("\n") ;
    printf(" ret : %d", printf("%11.10d", UINT_MAX));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%.0d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%.0d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%.0d", 5));
    printf("\n") ;
    printf(" ret : %d", printf("%.0d", 5));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%.0d", 10));
    printf("\n") ;
    printf(" ret : %d", printf("%.0d", 10));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%1.d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%1.d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%2.d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%2.d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%3.d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%3.d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%1.1d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%1.1d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%1.2d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%1.2d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%1.3d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%1.3d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%1.1d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%1.1d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%2.2d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%2.2d", 0));
    printf("\n") ;
    printf("\n") ;
	ft_printf(" ret : %d", ft_printf("%3.3d", 0));
    printf("\n") ;
    printf(" ret : %d", printf("%3.3d", 0));
    printf("\n") ;
	printf("\n\n") ;
	return(0) ;
}