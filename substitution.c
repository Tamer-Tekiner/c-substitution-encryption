#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if ((int) strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    char alphabet[26];
    int seen[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        char k = argv[1][i];

        if (!isalpha((unsigned char) k))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        int idx = tolower((unsigned char) k) - 'a';

        if (seen[idx])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }

        seen[idx] = 1;
        alphabet[i] = (char) tolower((unsigned char) k);
    }

    char plaintext[100];
    printf("plaintext: ");
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL)
    {
        return 1;
    }

    plaintext[strcspn(plaintext, "\n")] = '\0';

    int length = strlen(plaintext);
    char ciphertext[100];

    for (int i = 0; i < length; i++)
    {
        char c = plaintext[i];

        if (islower((unsigned char) c))
        {
            ciphertext[i] = alphabet[c - 'a'];
        }
        else if (isupper((unsigned char) c))
        {
            ciphertext[i] = toupper((unsigned char) alphabet[c - 'A']);
        }
        else
        {
            ciphertext[i] = c;
        }
    }

    ciphertext[length] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
