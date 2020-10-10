/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:59:53 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/10 10:45:16 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/include/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct	s_flags
{

	int			nb_exist;
	int			precision_exist;
	int			size_exist;
	int			zero_exist;
	int			nb;
	int			precision;
	int			size;
	int			zero;
	int			value;

}				t_flags;

int				ft_flags_nbr(const char **str, t_flags **flags, int i);
int				ft_flags_precision(const char **str, va_list args,
	t_flags **ap, int i);
int				ft_flag_size(const char **str, va_list args,
	t_flags **ap, int i);
int				ft_flags_zero(char const **str, va_list args,
	t_flags **ap, int i);
int				ft_flags_args(va_list args, t_flags **ap, int i);
void			ft_conversion_char(va_list args, t_flags **flags);
void			ft_conversion_string(va_list args, t_flags **flags);
void			ft_conversion_pointer(va_list args, t_flags **flags);
void			ft_conversion_int(va_list args, t_flags **ap);
void			ft_conversion_unsint(va_list args, t_flags **flags);
void			ft_conversion_littlehexa(va_list args, t_flags **flags);
void			ft_conversion_bighexa(va_list args, t_flags **flags);
void			ft_conversion_porcent(t_flags **flags);
void			ft_write(char c, t_flags ***ap);
void			ft_write_space(int i, t_flags ***ap);
#endif
