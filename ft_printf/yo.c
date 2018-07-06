#include <stdio.h>
#include <locale.h>
#include "libft/includes/libft.h"

char			*ft_wtoa(wchar_t n)
{
	char	*s;

	if (n <= 0x7F)
	{
		s = ft_strnew(1);
		s[0] = (unsigned char)n;
	}
	else if (n <= 0x7FF)
	{
		s = ft_strnew(2);
		s[0] = (unsigned char)((n >> 6) + 0xC0);
		s[1] = (unsigned char)((n & 0x3F) + 0x80);
	}
	else if (n <= 0xFFFF)
	{
		s = ft_strnew(3);
		s[0] = (unsigned char)((n >> 12) + 0xE0);
		s[1] = (unsigned char)(((n >> 6) & 0x3F) + 0x80);
		s[2] = (unsigned char)((n & 0x3F) + 0x80);
	}
	else
	{
		s = ft_strnew(4);
		s[0] = (unsigned char)((n >> 18) + 0xF0);
		s[1] = (unsigned char)((((n >> 12) & 0x3F) + 0x80));
		s[2] = (unsigned char)(((n >> 6) & 0x3F) + 0x80);
		s[3] = (unsigned char)((n & 0x3F) + 0x80);
	}
	return (s);
}

int main(void)
{
        setlocale(LC_ALL, "en_US.UTF-8");

        wchar_t value = L'ي';
		printf("%s\n", ft_wtoa(value));
		printf("%zu\n", sizeof(wchar_t));
        //我是一只猫。
        // unsigned int mask0 = 0;
        // unsigned int mask1 = 49280;
        // unsigned int mask2= 14712960;
        // unsigned int mask3= 4034953344;
        //
        // unsigned int v = value;
        // int size = size_bin(value);
        // int res = 0;
        // printf("size %d\n", size);
        // unsigned char octet;
        //
        // if (size <= 7)
        // {
        //         octet = value;
        //         write(1, &octet, 1);
        // }
        // else  if (size <= 11)
        // {
        //         unsigned char o2 = (v << 26) >> 26; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
        //         unsigned char o1 = ((v >> 6) << 27) >> 27; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx
        //
        //         octet = (mask1 >> 8) | o1; // application des bits du premier octet sur le premier octet mask
        //         write(1, &octet, 1);
        //         octet = ((mask1 << 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
        //         write(1, &octet, 1);
        // }
        // else  if (size <= 16)
        // {
        //         unsigned char o3 = (v << 26) >> 26; // recuperation des 6 premiers bits 1110xxxx 10xxxxxx 10(xxxxxx)
        //         unsigned char o2 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 1110xxxx 10(xxxxxx) 10xxxxxx
        //         unsigned char o1 = ((v >> 12) << 28) >> 28; // recuperation des 4 derniers bits 1110(xxxx) 10xxxxxx 10xxxxxx
        //
        //         octet = (mask2 >> 16) | o1; // application des bits du premier octet sur le premier octet mask
        //         write(1, &octet, 1);
        //         octet = ((mask2 << 16) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
        //         write(1, &octet, 1);
        //         octet = ((mask2 << 24) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
        //         write(1, &octet, 1);
        // }
        // else
        // {
        //         unsigned char o4 = (v << 26) >> 26; // recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
        //         unsigned char o3 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
        //         unsigned char o2 = ((v >> 12) << 26) >> 26;  // recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
        //         unsigned char o1 = ((v >> 18) << 29) >> 29; // recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx
        //
        //         octet = (mask3 >> 24) | o1; // application des bits du premier octet sur le premier octet mask
        //         write(1, &octet, 1);
        //         octet = ((mask3 << 8) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
        //         write(1, &octet, 1);
        //         octet = ((mask3 << 16) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
        //         write(1, &octet, 1);
        //         octet = ((mask3 << 24) >> 24) | o4; // application des bits du quatrieme octet sur le quatrieme octet du mask
        //         write(1, &octet, 1);
        // }
        return (0);
}
