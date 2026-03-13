#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i;
    int Upper = 0, Lower = 0, Digit = 0, Special = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(i = 0; i < length; i++) {
        if(isupper(password[i]))
            Upper = 1;
        else if(islower(password[i]))
            Lower = 1;
        else if(isdigit(password[i]))
            Digit = 1;
        else
            Special = 1;
    }

    printf("\n--- Password Analysis ---\n");

    if(length >= 8)
        printf("Length: Good\n");
    else
        printf("Length: Too Short\n");

    printf("Uppercase: %s\n", Upper ? "Yes" : "No");
    printf("Lowercase: %s\n", Lower ? "Yes" : "No");
    printf("Digits: %s\n", Digit ? "Yes" : "No");
    printf("Special Characters: %s\n", Special ? "Yes" : "No");

    if(length >= 8 && Upper && Lower && Digit && Special)
        printf("\nPassword Strength: STRONG 🔥");
    else if(length >= 6 && (Upper || Lower) && Digit)
        printf("\nPassword Strength: MEDIUM ⚠");
    else
        printf("\nPassword Strength: WEAK ❌");

    return 0;
}
