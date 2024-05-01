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
    f = fopen("worker.dat", "rb");
    char search[30];
    printf("Введите Фамилию: ");
    scanf("%s", search);

    fread(&worker, sizeof(struct Worker), 1, f);
        while (!feof(f)){
            if(strcmp(worker.name, search) == 0){
            printf("Сотрудник найден \n");
            printf("ФИО: %s\n", worker.name);
            printf("Номер телефона: %s\n", worker.phone);
            printf("День Рождения: %d.%d.%d\n", worker.birthday[0], worker.birthday[1], worker.birthday[2]);
            fread(&worker, sizeof(worker), 1, f);
            }
            fclose(f);
        }


    printf("Not Found Сотрудник с фамилией %s не найден\n", search);
    fclose(f);

    return 0;
}