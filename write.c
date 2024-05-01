#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Worker{
    char name[20];
    char phone[11];
    int birthday[3];
};

int main(){ 

    FILE *f;
    struct Worker worker;
    f = fopen("worker.dat", "wb");
    char ch;

   printf("\n Ввод информации о сотрудниках: ");
   do
    {
        printf("\nИмя сотрудника: "); scanf("%s", &worker.name);
        printf("\nНомер телефона "); scanf("%s", worker.phone);
        printf("\nкол-во жителей: "); scanf("%d", &worker.birthday[0]);
        printf("\nкол-во жителей: "); scanf("%d", &worker.birthday[1]);
        printf("\nкол-во жителей: "); scanf("%d", &worker.birthday[2]);
        fwrite(&worker, sizeof(worker), 1, f);
        printf("\n END Закончить? ( y/n): "); scanf("\n");
        ch=getchar();
    }
    while (ch != 'y');
    fclose(f);
}

