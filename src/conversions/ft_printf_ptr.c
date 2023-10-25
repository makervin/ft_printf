#include "ft_printf.h"

char	*ft_convert_ptr(void *ptr, t_format fmt)
{
	char	*tmp;

	if (ptr == NULL)
		ptr = ft_strdup("(nil)");
	else
	{
		tmp = ft_ultoa_base((unsigned long)ptr, "0123456789abcdef");
		ptr = ft_strjoin("0x", tmp);
		free(tmp);
	}
	ptr = ft_apply_padding(ptr, fmt.width, fmt.flags & FFLAG_MINUS);
	return (ptr);
}