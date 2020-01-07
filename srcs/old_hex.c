static char	*ft_zero_padding(t_format *format, char *hex_str, int pre)
{
	char		*padded_ret;
	size_t		hex_len;
	size_t		padded_len;
	int			offset;

	offset = 0;
	if (format->conv == 'p' || ft_str_set(format->flag, "#") != 0)
		offset = 2;
	hex_len = ft_strlen(hex_str);
	if (pre < 0)
		pre = 0;
	padded_len = hex_len + offset;
	if (pre > (int)hex_len)
		padded_len = pre + offset;
	padded_ret = (char *)ft_calloc(padded_len + 1, sizeof(char));
	if (padded_ret == NULL)
		return (NULL);
	ft_memset(padded_ret, '0', padded_len);
	if (format->conv == 'p' || ft_str_set(format->flag, "#") != 0)
		ft_memcpy(padded_ret, "0x", 2);
	ft_memcpy(padded_ret + (padded_len - hex_len), hex_str, hex_len);
	free(hex_str);
	return (padded_ret);
}

