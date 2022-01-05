This printf realisation is only for cspdiuxX% flags.

This realization doesnt handle width, so the only way to use falgs is to write it in the double quotes, like this:

  x = ft_printf("main string\n\t%%\n\t%c\n\t%s\n\t%p\n\t%d\n\t%i\n\t%u\n\t%x\n\t%X\n\n", 'R', "READ ME!", &x, -2047, -2047, -2047, -2047, -2047);

ft_printf is also returning a number of signs has been displayed.

Here is some description for functions has been used in the project:


ft_printf_utils.c: // all these functions (except ft_strlen) print something and return number of printed signs
  size_t	ft_strlen(const char *s);                   // returns a length of a string
  int		ft_printchar(char c);                         // prints a sign
  int		ft_printstr(char *s);                         // prints a string
  int		ft_putnbr_alphab(ssize_t n, char *alphabet);  // prints a singed number in given alphabet, for example: decimal alphabet looks like "0123456789"  
  int		ft_putunbr_alphab(size_t n, char *alphabet);  // prints an unsinged number in given alphabet, for example: hexadecmal alphabet looks like "0123456789abcdef"

ft_printf.c:
  int		ft_printf(const char *s, ...);                // the printf itself
  int		ft_choosefunc(char s, va_list ag);            // function that handle flags and choosing other fuctions, dont think you should use this in other projects.
