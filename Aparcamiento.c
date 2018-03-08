#include <stdio.h>
#include <string.h>
#include <time.h>

void main() {

	int plaza1 = 0, plaza2 = 0, mismaMatricula, coincideMatricula1, coincidematricula2;
	char opcion, matricula1[8], matricula2[8], comprobarMatricula[8];

	printf("Bienvenido al parking\n");
	system("pause");

	while (1) {
		system("cls");
		printf("Que accion desea realizar?\n");
		printf("Pulse 'R' para reservar plaza\n");
		printf("Pulse 'A' para abandonar plaza\n");
		printf("Pulse 'E' para ver el estado de aparcamiento\n");
		scanf_s("%c", &opcion, 1);
		getchar();
		system("cls");

		switch (opcion) {
		case 'r':
		case 'R':
			printf("Has elegido la opcion reservar plaza\n");
			system("pause");
			system("cls");
			if (plaza1 == 0) {
				printf("Has reservado la plaza 1\n");
				printf("Para registrarlo, introduce tu matricula:\n");
				scanf_s("%s", matricula1, 8);
				getchar();

				mismaMatricula = strcmp(matricula1, matricula2);
				if (mismaMatricula == 0) {
					system("cls");
					printf("El coche con esa matricula se encuentra en la plaza 2\n");
				}
				else {
					plaza1 = plaza1 + 1;
				}
			}
			else if (plaza2 == 0) {
				printf("Has reservado la plaza 2\n");
				printf("Para registrarlo, introduce tu matricula:\n");
				scanf_s("%s", matricula2, 8);
				getchar();

				mismaMatricula = strcmp(matricula1, matricula2);
				if (mismaMatricula == 0) {
					system("cls");
					printf("El coche con esa matricula se encuentra en la plaza 1\n");
				}
				else {
					plaza2 = plaza2 + 1;
				}
			}
			else {
				printf("Lo siento, no quedan plazas libres\n");
			}
			break;
		case 'a':
		case 'A':
			printf("Has elegido la opcion abandonar plaza\n");
			system("pause");
			system("cls");

			if (plaza1 == 1 || plaza2 == 1) {

				printf("Introduce tu matricula:\n");
				scanf_s("%s", comprobarMatricula, 8);
				getchar();
				system("cls");

				coincideMatricula1 = strcmp(matricula1, comprobarMatricula);
				coincidematricula2 = strcmp(matricula2, comprobarMatricula);
				if (coincideMatricula1 == 0) {
					printf("Has abandonado la plaza 1\n");
					printf("Vuelve pronto\n");
					plaza1 = plaza1 - 1;
				}
				else if (coincidematricula2 == 0) {
					printf("Has abandonado la plaza 2\n");
					printf("Vuelve pronto\n");
					plaza2 = plaza2 - 1;
				}
				else {
					printf("No hay aparcado ningun coche con esa matricula\n");
				}
			}
			else {
				printf("En estos momentos ningun coche se encuentra aparcado\n");
			}
			break;
		case 'e':
		case 'E':
			printf("Has elegido la opcion estado de aparcamiento\n");
			system("pause");
			system("cls");
			printf("A continuacion se le mostrara un listado de las plazas del garaje:\n");
			printf("Plaza 1 - ");
			if (plaza1 == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", matricula1);
			}
			printf("Plaza 2 - ");
			if (plaza2 == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", matricula2);
			}
			break;
		default:
			printf("Lo siento, te has equivocado de opcion\n");
		}

		system("pause");
	}
	
}