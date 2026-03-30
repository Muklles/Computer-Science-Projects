#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid_key(string key);
void cipher_text(string key, string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!valid_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    cipher_text(argv[1], plaintext);
    printf("\n");

    return 0;
}

bool valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                return false;
            }
        }
    }

    return true;
}

void cipher_text(string key, string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            int pos = text[i] - 'A';
            printf("%c", toupper(key[pos]));
        }
        else if (islower(text[i]))
        {
            int pos = text[i] - 'a';
            printf("%c", tolower(key[pos]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}
