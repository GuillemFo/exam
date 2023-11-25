#include <unistd.h>

// Function to write a character to standard output
void putchar(char c)
{
    write(1, &c, 1);
}

// Function to calculate the length of a string
int ft_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')  // Added condition to check for null terminator
        i++;
    return (i);
}

// Function to rotate words in a string
void ft_rostring(char *s)
{
    int i = 0;
    int j = 0;
    int word = 0;
    int x = ft_strlen(s);

    // Skip leading spaces, tabs, and newlines
    while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
    {
        i++;
        j++;
    }

    // Count the length of the first word
    while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
    {
        word++;
        i++;
    }

    // Print the rotated string
    while (s[i] && (x - j) > 0)
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')  // Added conditions to exclude spaces, tabs, and newlines
        {
            putchar(s[i]);
            x--;
        }
        i++;
    }

    // Print a space if there are more words
    if (word > 0)
        putchar(' ');

    // Print the remaining part of the rotated string
    while (word > 0)
    {
        putchar(s[j]);
        j++;
        word--;
    }
}

// Main function
int main(int ac, char **av)
{
    // Check if the number of arguments is not 2
    if (ac != 2)
        return (write(1, "\n", 1), 1);
    else
    {
        // Rotate the words in the given string and print the result
        ft_rostring(av[1]);
        write(1, "\n", 1);
    }
    return (0);
}
