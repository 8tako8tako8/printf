#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
    int d1, d2;

    d1 = ft_printf("[%c]", 'a');
    d2 = printf("[%c]\n", 'a');
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%s]", "tokyo");
    d2 = printf("[%s]\n", "tokyo");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%p]", &d1);
    d2 = printf("[%p]\n", &d1);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%d]", -1234);
    d2 = printf("[%d]\n", -1234);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%i]", 1234);
    d2 = printf("[%i]\n", 1234);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%u]", 42);
    d2 = printf("[%u]\n", 42);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%x]", 100);
    d2 = printf("[%x]\n", 100);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%X]", 1000);
    d2 = printf("[%X]\n", 1000);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%%]");
    d2 = printf("[%%]\n");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);

    d1 = ft_printf("[%d]", INT_MIN);
    d2 = printf("[%d]\n", INT_MIN);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%u]", INT_MAX+1);
    d2 = printf("[%u]\n", INT_MAX+1);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%x]", 0);
    d2 = printf("[%x]\n", 0);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%X]", 0);
    d2 = printf("[%X]\n", 0);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%c]", '\0');
    d2 = printf("[%c]\n", '\0');
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%s]", NULL);
    d2 = printf("[%s]\n", NULL);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%p]", NULL);
    d2 = printf("[%p]\n", NULL);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);

    d1 = ft_printf("I am a student at %d Tokyo. My student ID is %p. ", 42, &d2);
    d2 = printf("I am a student at %d Tokyo. My student ID is %p. ", 42, &d2);
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[abcdefghi, %d, %s, %c, %u, %p, jklmn, %x, %p, %p, opqrstu, %d, %s, vwxyz]", 42, "tokyo", '!', 4200, 100, 20, 100000, 10, -100, "point");
    d2 = printf("[abcdefghi, %d, %s, %c, %u, %p, jklmn, %x, %p, %p, opqrstu, %d, %s, vwxyz]", 42, "tokyo", '!', 4200, 100, 20, 100000, 10, -100, "point");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);

    d1 = ft_printf("[%7s][%4s][%2s]", "abcd", "abcd", "abcd");
    d2 = printf("[%7s][%4s][%2s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%-7s][%-4s][%-2s]", "abcd", "abcd", "abcd");
    d2 = printf("[%-7s][%-4s][%-2s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%07s][%04s][%02s]", "abcd", "abcd", "abcd");
    d2 = printf("[%07s][%04s][%02s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%.6s][%.4s][%.s]", "abcd", "abcd", "abcd");
    d2 = printf("[%.6s][%.4s][%.s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%-8.6s][%-6.6s][%-2.3s]", "abcd", "abcd", "abcd");
    d2 = printf("[%-8.6s][%-6.6s][%-2.3s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%08.6s][%06.6s][%02.3s]", "abcd", "abcd", "abcd");
    d2 = printf("[%08.6s][%06.6s][%02.3s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);

    d1 = ft_printf("[%*.3s][%*.6s][%*.2s]", -6, "abcd", 1, "abcd", 0, "abcd");
    d2 = printf("[%*.3s][%*.6s][%*.2s]", -6, "abcd", 1, "abcd", 0, "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%3.*s][%6.*s][%2.*s]", -6, "abcd", 1, "abcd", 0, "abcd");
    d2 = printf("[%3.*s][%6.*s][%2.*s]", -6, "abcd", 1, "abcd", 0, "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%*.*s][%*.*s][%*.*s]", -6, 1, "abcd", 1, -5, "abcd", 0, 7, "abcd");
    d2 = printf("[%*.*s][%*.*s][%*.*s]", -6, 1, "abcd", 1, -5, "abcd", 0, 7, "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%*.*s][%*.*s][%*.*s]", -6, 0, "abcd", 5, 5, "abcd", 8, 5, "abcd");
    d2 = printf("[%*.*s][%*.*s][%*.*s]", -6, 0, "abcd", 5, 5, "abcd", 8, 5, "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);

    d1 = ft_printf("[%-08.6s][%-06.6s][%-02.3s]", "abcd", "abcd", "abcd");
    d2 = printf("[%-08.6s][%-06.6s][%-02.3s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%0-8.6s][%0-6.6s][%0-2.3s]", "abcd", "abcd", "abcd");
    d2 = printf("[%0-8.6s][%0-6.6s][%0-2.3s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%0--8.6s][%0--6.6s][%0--2.3s]", "abcd", "abcd", "abcd");
    d2 = printf("[%0--8.6s][%0--6.6s][%0--2.3s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%-008.6s][%-006.6s][%-002.3s]", "abcd", "abcd", "abcd");
    d2 = printf("[%-008.6s][%-006.6s][%-002.3s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);
    d1 = ft_printf("[%-0-8.6s][%-0-6.6s][%-0-2.3s]", "abcd", "abcd", "abcd");
    d2 = printf("[%-0-8.6s][%-0-6.6s][%-0-2.3s]", "abcd", "abcd", "abcd");
    printf("===== ft: %d, honke: %d =====\n", d1, d2);

}