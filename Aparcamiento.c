#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void main() {

	int plaza1 = 0, plaza2 = 0, mismaMatricula, coincideMatricula, coincideMatricula2;
	int coincideMatricula3, coincideMatricula4, finBucle = 0;
	int plaza3 = 0, plaza4 = 0; //Para las motos
	char opcion, posicion, matricula1[8], matricula2[8], comprobarMatricula[8];
	char eleccion, matricula3[8], matricula4[8];

	printf("Bienvenido al parking\n");
	Sleep(1500);

	while (finBucle == 0) {
		system("cls");
		printf("Que accion desea realizar?\n");
		printf("Pulse 'R' para reservar plaza\n");
		printf("Pulse 'A' para abandonar plaza\n");
		printf("Pulse 'E' para ver el estado de aparcamiento\n");
		printf("Pulse 'B' para buscar vehiculo por matricula\n");
		printf("Pulse 'S' para finalizar sesion\n");
		scanf_s("%c", &opcion, 1);
		getchar();
		system("cls");

		switch (opcion) {
		case 'r':
		case 'R':
			printf("Has elegido la opcion reservar plaza\n");
			Sleep(1300);
			system("cls");
			printf("Que tipo de vehiculo tienes? coche (c) o moto (m):\n");
			scanf_s("%c", &eleccion, 1);
			getchar();
			system("cls");

			switch (eleccion) {
			case 'C':
			case 'c':
				if (plaza1 == 0) {
					printf("Has reservado la plaza 1 de coche\n");
					printf("Para registrarlo, introduce tu matricula:\n");
					scanf_s("%s", matricula1, 8);
					getchar();

					mismaMatricula = strcmp(matricula1, matricula2);
					if (mismaMatricula == 0) {
						system("cls");
						printf("El coche con esa matricula se encuentra en la plaza 2\n");
					}
					else {
						plaza1 = 1;
					}
				}
				else if (plaza2 == 0) {
					printf("Has reservado la plaza 2 de coche\n");
					printf("Para registrarlo, introduce tu matricula:\n");
					scanf_s("%s", matricula2, 8);
					getchar();

					mismaMatricula = strcmp(matricula1, matricula2);
					if (mismaMatricula == 0) {
						system("cls");
						printf("El coche con esa matricula se encuentra en la plaza 1\n");
					}
					else {
						plaza2 = 1;
					}
				}
				else {
					printf("Lo siento, no quedan plazas libres para coches\n");
				}
				break;
			case'M':
			case'm':
				if (plaza3 == 0) {
					printf("Has reservado la plaza 1 de moto\n");
					printf("Para registrarlo, introduce tu matricula:\n");
					scanf_s("%s", matricula3, 8);
					getchar();

					mismaMatricula = strcmp(matricula3, matricula4);
					if (mismaMatricula == 0) {
						system("cls");
						printf("La moto con esa matricula se encuentra en la plaza 2\n");
					}
					else {
						plaza3 = 1;
					}
				}
				else if (plaza4 == 0) {
					printf("Has reservado la plaza 2 de moto\n");
					printf("Para registrarlo, introduce tu matricula:\n");
					scanf_s("%s", matricula4, 8);
					getchar();

					mismaMatricula = strcmp(matricula3, matricula4);
					if (mismaMatricula == 0) {
						system("cls");
						printf("La moto con esa matricula se encuentra en la plaza 1\n");
					}
					else {
						plaza4 = 1;
					}
				}
				else {
					printf("Lo siento, no quedan plazas libres para motos\n");
				}
				break;
			}
			break;
			
		case 'a':
		case 'A':
			printf("Has elegido la opcion abandonar plaza\n");
			Sleep(1300);
			system("cls");
			printf("Que tipo de vehiculo has aparcado? coche (c) o moto (m):\n");
			scanf_s("%c", &eleccion, 1);
			getchar();
			system("cls");

			switch (eleccion) {
			case 'C':
			case 'c':
				if (plaza1 == 1 || plaza2 == 1) {

					printf("En que plaza estaba tu coche?\n");
					scanf_s("%c", &posicion, 1);
					getchar();
					system("cls");

					switch (posicion) {

					case '1':
						if (plaza1 == 1) {
							printf("Para verificarlo, introduce tu matricula:\n");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");
							coincideMatricula = strcmp(matricula1, comprobarMatricula);

							if (coincideMatricula == 0) {
								printf("Has abandonado la plaza 1 de coche\n");
								printf("Vuelve pronto\n");
								matricula1[0] = 0;
								plaza1 = 0;
							}
							else {
								printf("La matricula no coincide con el coche aparcado en esta plaza\n");
							}
						}
						else {
							printf("En la plaza 1 no hay ningun coche\n");
						}
						break;

					case '2':
						if (plaza2 == 1) {
							printf("Para verificarlo, introduce tu matricula:\n");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");
							coincideMatricula2 = strcmp(matricula2, comprobarMatricula);

							if (coincideMatricula2 == 0) {
								printf("Has abandonado la plaza 2 de coche\n");
								printf("Vuelve pronto\n");
								matricula2[0] = 0;
								plaza2 = 0;
							}
							else {
								printf("La matricula no coincide con el coche aparcado en esta plaza\n");
							}
						}
						else {
							printf("En la plaza 2 no hay ningun coche\n");
						}
						break;

					default:
						printf("Actualmente no disponemos de esa plaza para coches\n");
					}
				}
				else {
					printf("En estos momentos ningun coche se encuentra aparcado\n");
				}
				break;
			case 'M':
			case 'm':
				if (plaza3 == 1 || plaza4 == 1) {

					printf("En que plaza estaba tu moto?\n");
					scanf_s("%c", &posicion, 1);
					getchar();
					system("cls");

					switch (posicion) {

					case '1':
						if (plaza3 == 1) {
							printf("Para verificarlo, introduce tu matricula:\n");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");
							coincideMatricula3 = strcmp(matricula3, comprobarMatricula);

							if (coincideMatricula3 == 0) {
								printf("Has abandonado la plaza 1 de moto\n");
								printf("Vuelve pronto\n");
								matricula3[0] = 0;
								plaza3 = 0;
							}
							else {
								printf("La matricula no coincide con la moto aparcada en esta plaza\n");
							}
						}
						else {
							printf("En la plaza 1 no hay ninguna moto\n");
						}
						break;

					case '2':
						if (plaza4 == 1) {
							printf("Para verificarlo, introduce tu matricula:\n");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");
							coincideMatricula4 = strcmp(matricula4, comprobarMatricula);

							if (coincideMatricula4 == 0) {
								printf("Has abandonado la plaza 2 de moto\n");
								printf("Vuelve pronto\n");
								matricula4[0] = 0;
								plaza4 = 0;
							}
							else {
								printf("La matricula no coincide con la moto aparcada en esta plaza\n");
							}
						}
						else {
							printf("En la plaza 2 no hay ninguna moto\n");
						}
						break;

					default:
						printf("Actualmente no disponemos de esa plaza para motos\n");
					}
				}
				else {
					printf("En estos momentos ninguna moto se encuentra aparcada\n");
				}
				break;
			}
			break;

		case 'e':
		case 'E':
			printf("Has elegido la opcion estado de aparcamiento\n");
			Sleep(1300);
			system("cls");
			printf("A continuacion se le mostrara un listado de las plazas del garaje:\n");
			printf("Plaza 1 - Coche -");
			if (plaza1 == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", matricula1);
			}
			printf("Plaza 2 - Coche -");
			if (plaza2 == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", matricula2);
			}
			printf("Plaza 1 - Moto -");
			if (plaza3 == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", matricula3);
			}
			printf("Plaza 2 - Moto -");
			if (plaza4 == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", matricula4);
			}
			break;

		case'b':
		case'B':
			printf("Has elegido la opcion de buscar vehiculo por matricula\n");
			Sleep(1300);
			system("cls");
			printf("Que tipo de vehiculo quieres buscar? coche (c) o moto (m):\n");
			scanf_s("%c", &eleccion, 1);
			getchar();
			system("cls");

			switch (eleccion) {
			case 'C':
			case 'c':
				if (plaza1 == 1 || plaza2 == 1) {
					printf("Introduce la matricula que buscas:\n");
					scanf_s("%s", comprobarMatricula, 8);
					getchar();
					system("cls");
					coincideMatricula = strcmp(matricula1, comprobarMatricula);
					coincideMatricula2 = strcmp(matricula2, comprobarMatricula);

					if (coincideMatricula == 0) {
						printf("El coche se encuentra en la plaza 1\n");
					}
					else if (coincideMatricula2 == 0) {
						printf("El coche se encuentra en la plaza 2\n");
					}
					else {
						printf("El coche no esta registrado en el garaje\n");
					}
				}
				else {
					printf("En este momento no se encuentra ningun coche aparcado\n");
				}
				break;
			case 'M':
			case 'm':
				if (plaza3 == 1 || plaza4 == 1) {
					printf("Introduce la matricula que buscas:\n");
					scanf_s("%s", comprobarMatricula, 8);
					getchar();
					system("cls");
					coincideMatricula3 = strcmp(matricula3, comprobarMatricula);
					coincideMatricula4 = strcmp(matricula4, comprobarMatricula);

					if (coincideMatricula3 == 0) {
						printf("La moto se encuentra en la plaza 1\n");
					}
					else if (coincideMatricula4 == 0) {
						printf("La moto se encuentra en la plaza 2\n");
					}
					else {
						printf("La moto no esta registrada en el garaje\n");
					}
				}
				else {
					printf("En este momento no se encuentra ninguna moto aparcada\n");
				}
				break;
			}
			break;
			
		case's':
		case'S':
			printf("Has elegido la opcion de finalizar sesion\n");
			printf("Vuelve pronto\n");
			finBucle = 1;
			break;

		default:
			printf("Lo siento, te has equivocado de opcion\n");
		}

		system("pause");
	}
	
}