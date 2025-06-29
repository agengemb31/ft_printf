# fr_printf

Recode the printf function from libc which produce output according to a format:
  - A Ordinary characters, which are copied unchanged to the output stream.
  - A Conversion specifications is introduced by the character %, and ends with a conversion specifier(cspdiuxX%).

[Subject](https://github.com/agengemb31/ft_printf/blob/main/en.subject.pdf)

## Usage

`make` to compile ft_printf function.

Create a main.c file that includes ft_printf.h so you can use the ft_printf function.

Prototype:
`int ft_printf(const char *, ...);`

Example of usage:  
  
`ft_printf("Number: %d\n", number);`  
`ft_printf("String: %s, Character: %c", "Hello, world!", 'A');`  

## The following conversions have been implemented:

- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.
