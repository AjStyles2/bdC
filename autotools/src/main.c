
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char needChar(int num){
  char t[3];
  while(t[0] < 49 || t[0] > 55-num)
  {
  if (fgets(t, 3, stdin)) 
    {
      {
        if (t[0] < 49 || t[0] > 55-num) 
        {
        printf("Неверное значение\n");
        }
      }
    }
  }
  return t[0];
}

void main() {
  node head = createNode();
  char string1[512];
  char string2[512];
  char string3[512];
  char string4[512];
  char string5[512];
  char file[512];
  char inp[512];
  int check = 1;
  while (check) {
    printf("Выберете действие:\n\n1. Добавить\n2. Удалить\n3. Изменить\n4. Вывод\n5. Загрузить\n6. Сохранить\n7. Выходa\n\n");
    //printf("%d((((((sxsxsxsxxsxs\n", needChar());
    switch (needChar(0)) {
      /*Добавление элемента в БД*/
      case '1':
        printf("\nВведите название: ");
        if (fgets(string1, 512, stdin) == NULL) //fgets чтение строки из указанного потока данных //stdin стандартный поток ввода
        {
          perror("Ошибка считывания строки");
          return;
        } 
        printf("\nВведите тип: ");
        if (fgets(string2, 512, stdin) == NULL) 
        {
          perror("Ошибка считывания строки");
          return;
        }
        printf("\nВведите weight: ");
        if (fgets(string3, 512, stdin) == NULL) 
        {
          perror("Ошибка считывания строки");
          return;
        } 
        printf("\nВведите power: ");
        if (fgets(string4, 512, stdin) == NULL) 
        {
          perror("Ошибка считывания строки");
          return;
        }                  
        printf("Наличие пьезоподжига:\n\n1. да\n2. нет\n\n");
        switch (needChar(5)) {
          case '1':
            strcpy(string5, "Да ");
            break;
          case '2':
            strcpy(string5, "Нет ");
            break;
        }
        for (size_t i = 0; i < 512; i++) { //for split word to merge in one string
          if (string1[i] == '\n') {
            string1[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string2[i] == '\n') {
            string2[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string3[i] == '\n') {
            string3[i] = ' ';
            break;
          }
        }
        for (size_t i = 0; i < 512; i++) {
          if (string4[i] == '\n') {
            string4[i] = ' ';
            break;
          }
        }
        strcat(string1, string2);
        strcat(string1, string3);
        strcat(string1, string4);
        strcat(string1, string5);
        //printf("\n%s", string1);
        addNode(head, string1);
        break;
      case '2': //Удаление
      {
        int i = 0;
        printf("Выберите элемент: ");
	      if (scanf("%d", &i) == 0) 
        {
          perror("Ошибка ввода");
        }
        while(i > HowMuchNode(head) || i < 1)
        {
	        printf("Выберите элемент в доступном диапазоне: ");
	        if (scanf("%d", &i) == 0 )
          {
            perror("Ошибка ввода");
          }
    	  }
        head = DelByIndex(i, head);
      }
      break;
      case '3': //Изменение
        printf("\nВведите номер записи: ");
        int x = 0;
        if (scanf("%d", &x) == 1 ) 
        {
          getchar(); // Получить символ из стандартного потока ввода.
          printf("\nВведите название: ");
          //fgets(string1, 512, stdin); 
          if (fgets(string1, 512, stdin) == NULL) //fgets чтение строки из указанного потока данных //stdin стандартный поток ввода
          {
            perror("Ошибка считывания строки");
            return;
          }          
          printf("\nВведите тип: ");
          if (fgets(string2, 512, stdin) == NULL) 
          {
            perror("Ошибка считывания строки");
            return;
          }
          printf("\nВведите weight: ");
          if (fgets(string3, 512, stdin) == NULL) 
          {
            perror("Ошибка считывания строки");
            return;
          }
          printf("\nВведите power: ");
          if (fgets(string4, 512, stdin) == NULL) 
          {
            perror("Ошибка считывания строки");
            return;
          }             
          printf("Наличие пьезоподжига:\n\n1. да\n2. нет\n\n");
          switch (needChar(5)) {
            case '1':
              strcpy(string5, "Да ");
              break;
            case '2':
              strcpy(string5, "Нет ");
              break;
          }

          for (size_t i = 0; i < 512; i++) {
            if (string1[i] == '\n') {
              string1[i] = ' ';
              break;
            }
          }
          for (size_t i = 0; i < 512; i++) {
            if (string2[i] == '\n') {
              string2[i] = ' ';
              break;
            }
          }
          for (size_t i = 0; i < 512; i++) {
            if (string3[i] == '\n') {
              string3[i] = ' ';
              break;
            }
          }
          for (size_t i = 0; i < 512; i++) {
            if (string4[i] == '\n') {
              string4[i] = ' ';
              break;
            }
          }
          strcat(string1, string2);
          strcat(string1, string3);
          strcat(string1, string4);
          strcat(string1, string5);
          printf("\n%s\n\n", string1);
          strcpy(NodeByIndex(x, head)->data, string1);
        }
        break;
      case '4': //Output
        {
          node n = head;
          n = n->next;
          int i = 1;
          while (n != NULL) {
            printf("%d. %s\n",i++ , n->data);
            n = n->next;
          }
          printf("\n");
        }
        break;
      case '5':
        printf("Введите имя файла без расширения: ");
        //fgets(file, 512, stdin);
        if (fgets(file, 512, stdin) == NULL) 
        {
          perror("Ошибка считывания строки");
          return;
        }
        for (size_t i = 0; i < 512; i++) 
        {
          if (file[i] == '\n') 
          {
            file[i] = '\0';
            break;
          } 
        } 
        strcat(file, ".bd");

        FILE *fp2;
        if ((fp2 = fopen(file, "rt") )!= NULL) 
        {
          char str[512];
          while(fgets(str, 512, fp2) != NULL)
          {
            addNode(head, str);
          }

          fclose(fp2);
        }
        else
        {
          perror("Ошибка чтения файла");
        }
        printf("\n");
        break;
      case '6': // load
        printf("Введите имя файла без расширения: ");
        //fgets(file, 512, stdin);
        if (fgets(file, 512, stdin) == NULL) 
        {
          perror("Ошибка считывания строки");
          return;
        }        
        for (size_t i = 0; i < 512; i++) 
        {
          if (file[i] == '\n') 
          {
            file[i] = '\0';
            break;
          } 
        } 
        strcat(file, ".bd");

        FILE *fp;
        
        if ((fp = fopen(file, "a+t") )!= NULL) // open or create
        { 
          if(head->data != "")
          {
            node tmp = head;
            while(tmp->next != NULL)
            {
              fputs(tmp->data, fp);
              tmp = tmp->next;
            }
            fputs(tmp->data, fp);
          }

          fclose(fp);
        }
        else 
        {
          perror("Ошибка открытия/создания файла");
        }
        printf("\n");
        break;
      case '7': //Exit
        return;
        break;
    }
  }
}
