#include <stdio.h>
struct{
    int class; int X; int Y; int Z;
    char name[8];
    }mud[50];
int main()
{
    int i, j;
    int volume = 0;
    int pervol;
    int rub;
    int vic;
    for (i = 1; ; i++)
    {
        scanf("%d", &mud[0].class);
        if (mud[0].class == -1)
        break;
        volume = 0;
        for (j = 0; j < mud[0].class; j++)
        {
            scanf("%d%d%d%s", &mud[j].X, &mud[j].Y, &mud[j].Z, mud[j].name);
            volume = volume + mud[j].X * mud[j].Y * mud[j].Z;
        }
        volume = volume / mud[0].class;

        //printf("Average is %d\n", volume);

        for (j = 0; j < mud[0].class; j++)
        {
        pervol = mud[j].X * mud[j].Y * mud[j].Z;
        if (volume < pervol)
        rub = j;
        else if (volume > pervol)
        vic = j;
        }
        printf("%s took clay from %s.\n", mud[rub].name, mud[vic].name);
    }
    return 0;
}
