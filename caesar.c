#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Prototyping
void encrypt(string text, int key);
// Getting the key
int main(int argc, string argv[1])
{
    // Check if the command line arg count is 2.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check if the command line argv is a number.
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Prompting the user for a plain text and converting the argv into a number
    int key = atoi(argv[1]);

    string text = get_string("plaintext: ");

    printf("ciphertext: ");
    encrypt(text, key);
    return 0;
}

// Encryption function
void encrypt(string text, int key)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (isupper(c))
        {
            printf("%c", ((c - 'A') + key) % 26 + 'A');
        }
        else if (islower(c))
        {
            printf("%c", ((c - 'a') + key) % 26 + 'a');
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
}