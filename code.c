#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "1234567890";

    people[1].name = "David";
    people[1].number = "8234518009";

    string name = get_string("Name: ");

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("%s", numbers[i]);
            return 0;
        }
    }

    printf("Not found");
    return 1;

}