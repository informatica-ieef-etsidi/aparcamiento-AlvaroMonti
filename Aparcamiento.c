#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

struct plaza {
	int estado;
	char tipo;
	char matricula[8];
	int tiempo1, tiempo2;
};

struct usuario {
	char nombre[50];
	char password[50];
};

void main() {

	float precio;
	int finBucle = 1, a = 0, i, p = 0;
	struct plaza plaza1 = { 0, 'C' }, plaza2 = { 0, 'C' }, plaza3 = { 0, 'M' }, plaza4 = { 0, 'M' };
	struct usuario persona1 = { "admin", "1234" };
	char opcion, posicion, comprobarMatricula[8], eleccion, user[50], contraseña[50];

	printf("Bienvenido, el precio del parking es de 2 centimos por segundo\n");
	Sleep(2500);

	while (p < 3) {

		system("cls");
		printf("Numero de intentos para iniciar sesion: %d\n\n", 3 - p);
		printf("Introduce el usuario: ");
		gets(user);
		system("cls");

		if (strcmp(user, persona1.nombre) == 0) {
			printf("Numero de intentos para iniciar sesion: %d\n\n", 3 - p);
			printf("Introduce la contrasena: ");
			gets(contraseña);
			system("cls");

			if (strcmp(contraseña, persona1.password) == 0) {
				system("cls");
				printf("Accediendo al sistema\n");
				p = 3;
				finBucle = 0;
				Sleep(1300);
			}
			else {
				printf("Contrasena incorrecta\n");
				p++;
				printf("\n");
				system("pause");
			}
		}
		else {
			printf("Usuario no registrado\n");
			p++;
			printf("\n");
			system("pause");
		}

	}

	while (finBucle == 0) {

		system("cls");
		time_t result = time(NULL);
		char str[26];
		ctime_s(str, sizeof str, &result);
		printf("%s\n", str);

		printf("Que accion desea realizar?\n\n");
		printf("Pulse 'R' para reservar plaza\n");
		printf("Pulse 'A' para abandonar plaza\n");
		printf("Pulse 'E' para ver el estado de aparcamiento\n");
		printf("Pulse 'B' para buscar vehiculo por matricula\n");
		printf("Pulse 'S' para finalizar sesion\n\n");
		scanf_s("%c", &opcion, 1);
		getchar();
		system("cls");

		switch (opcion) {
		case 'r':
		case 'R':
			printf("Has elegido la opcion reservar plaza\n");
			Sleep(1300);
			system("cls");
			printf("Que tipo de vehiculo tienes? coche (c) o moto (m):\n\n");
			scanf_s("%c", &eleccion, 1);
			getchar();
			system("cls");

			switch (eleccion) {
			case 'C':
			case 'c':
				if (plaza1.estado == 0) {
					printf("Has reservado la plaza 1 de coche\n\n");
					printf("Para registrarlo, introduce tu matricula: ");
					scanf_s("%s", plaza1.matricula, 8);
					getchar();

					for (i = 0; i < 7; i++) {
						if (97 <= plaza1.matricula[i] && plaza1.matricula[i] <= 122) {
							plaza1.matricula[i] -= 32;
						}
					}

					for (i = 0; i < 7; i++) {
						if (a == 0 && 48 <= plaza1.matricula[i] && plaza1.matricula[i] <= 57) {
							a++;
						}
						else if (a == 1 && 48 <= plaza1.matricula[i] && plaza1.matricula[i] <= 57) {
							a++;
						}
						else if (a == 2 && 48 <= plaza1.matricula[i] && plaza1.matricula[i] <= 57) {
							a++;
						}
						else if (a == 3 && 48 <= plaza1.matricula[i] && plaza1.matricula[i] <= 57) {
							a++;
						}
						else if (a == 4 && 65 <= plaza1.matricula[i] && plaza1.matricula[i] <= 90) {
							a++;
						}
						else if (a == 5 && 65 <= plaza1.matricula[i] && plaza1.matricula[i] <= 90) {
							a++;
						}
						else if (a == 6 && 65 <= plaza1.matricula[i] && plaza1.matricula[i] <= 90) {
							a++;
						}
						else {
							plaza1.matricula[0] = 0;
							a = 0;
							break;
						}
					}

					if (a == 7) {
						if (strcmp(plaza1.matricula, plaza2.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 2 de coche\n");
						}
						else if (strcmp(plaza1.matricula, plaza3.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 1 de moto\n");
						}
						else if (strcmp(plaza1.matricula, plaza4.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 2 de moto\n");
						}
						else {
							plaza1.estado = 1;
							plaza1.tiempo1 = time(NULL);
						}
						a = 0;
					}
					else {
						printf("\n");
						printf("Matricula incorrecta\n");
					}
				}
				else if (plaza2.estado == 0) {
					printf("Has reservado la plaza 2 de coche\n\n");
					printf("Para registrarlo, introduce tu matricula: ");
					scanf_s("%s", plaza2.matricula, 8);
					getchar();

					for (i = 0; i < 7; i++) {
						if (97 <= plaza2.matricula[i] && plaza2.matricula[i] <= 122) {
							plaza2.matricula[i] -= 32;
						}
					}

					for (i = 0; i < 7; i++) {
						if (a == 0 && 48 <= plaza2.matricula[i] && plaza2.matricula[i] <= 57) {
							a++;
						}
						else if (a == 1 && 48 <= plaza2.matricula[i] && plaza2.matricula[i] <= 57) {
							a++;
						}
						else if (a == 2 && 48 <= plaza2.matricula[i] && plaza2.matricula[i] <= 57) {
							a++;
						}
						else if (a == 3 && 48 <= plaza2.matricula[i] && plaza2.matricula[i] <= 57) {
							a++;
						}
						else if (a == 4 && 65 <= plaza2.matricula[i] && plaza2.matricula[i] <= 90) {
							a++;
						}
						else if (a == 5 && 65 <= plaza2.matricula[i] && plaza2.matricula[i] <= 90) {
							a++;
						}
						else if (a == 6 && 65 <= plaza2.matricula[i] && plaza2.matricula[i] <= 90) {
							a++;
						}
						else {
							plaza2.matricula[0] = 0;
							a = 0;
							break;
						}
					}

					if (a == 7) {
						if (strcmp(plaza2.matricula, plaza1.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 1 de coche\n");
						}
						else if (strcmp(plaza2.matricula, plaza3.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 1 de moto\n");
						}
						else if (strcmp(plaza2.matricula, plaza4.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 2 de moto\n");
						}
						else {
							plaza2.estado = 1;
							plaza2.tiempo1 = time(NULL);
						}
						a = 0;
					}
					else {
						printf("\n");
						printf("Matricula incorrecta\n");
					}
				}
				else {
					printf("Lo siento, no quedan plazas libres para coches\n");
				}
				break;
			case'M':
			case'm':
				if (plaza3.estado == 0) {
					printf("Has reservado la plaza 1 de moto\n\n");
					printf("Para registrarlo, introduce tu matricula: ");
					scanf_s("%s", plaza3.matricula, 8);
					getchar();

					for (i = 0; i < 7; i++) {
						if (97 <= plaza3.matricula[i] && plaza3.matricula[i] <= 122) {
							plaza3.matricula[i] -= 32;
						}
					}

					for (i = 0; i < 7; i++) {
						if (a == 0 && 48 <= plaza3.matricula[i] && plaza3.matricula[i] <= 57) {
							a++;
						}
						else if (a == 1 && 48 <= plaza3.matricula[i] && plaza3.matricula[i] <= 57) {
							a++;
						}
						else if (a == 2 && 48 <= plaza3.matricula[i] && plaza3.matricula[i] <= 57) {
							a++;
						}
						else if (a == 3 && 48 <= plaza3.matricula[i] && plaza3.matricula[i] <= 57) {
							a++;
						}
						else if (a == 4 && 65 <= plaza3.matricula[i] && plaza3.matricula[i] <= 90) {
							a++;
						}
						else if (a == 5 && 65 <= plaza3.matricula[i] && plaza3.matricula[i] <= 90) {
							a++;
						}
						else if (a == 6 && 65 <= plaza3.matricula[i] && plaza3.matricula[i] <= 90) {
							a++;
						}
						else {
							plaza3.matricula[0] = 0;
							a = 0;
							break;
						}
					}

					if (a == 7) {
						if (strcmp(plaza3.matricula, plaza1.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 1 de coche\n");
						}
						else if (strcmp(plaza3.matricula, plaza2.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 2 de coche\n");
						}
						else if (strcmp(plaza3.matricula, plaza4.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 2 de moto\n");
						}
						else {
							plaza3.estado = 1;
							plaza3.tiempo1 = time(NULL);
						}
						a = 0;
					}
					else {
						printf("\n");
						printf("Matricula incorrecta\n");
					}
				}
				else if (plaza4.estado == 0) {
					printf("Has reservado la plaza 2 de moto\n\n");
					printf("Para registrarlo, introduce tu matricula: ");
					scanf_s("%s", plaza4.matricula, 8);
					getchar();

					for (i = 0; i < 7; i++) {
						if (97 <= plaza4.matricula[i] && plaza4.matricula[i] <= 122) {
							plaza4.matricula[i] -= 32;
						}
					}

					for (i = 0; i < 7; i++) {
						if (a == 0 && 48 <= plaza4.matricula[i] && plaza4.matricula[i] <= 57) {
							a++;
						}
						else if (a == 1 && 48 <= plaza4.matricula[i] && plaza4.matricula[i] <= 57) {
							a++;
						}
						else if (a == 2 && 48 <= plaza4.matricula[i] && plaza4.matricula[i] <= 57) {
							a++;
						}
						else if (a == 3 && 48 <= plaza4.matricula[i] && plaza4.matricula[i] <= 57) {
							a++;
						}
						else if (a == 4 && 65 <= plaza4.matricula[i] && plaza4.matricula[i] <= 90) {
							a++;
						}
						else if (a == 5 && 65 <= plaza4.matricula[i] && plaza4.matricula[i] <= 90) {
							a++;
						}
						else if (a == 6 && 65 <= plaza4.matricula[i] && plaza4.matricula[i] <= 90) {
							a++;
						}
						else {
							plaza4.matricula[0] = 0;
							a = 0;
							break;
						}
					}

					if (a == 7) {
						if (strcmp(plaza4.matricula, plaza1.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 1 de coche\n");
						}
						else if (strcmp(plaza4.matricula, plaza2.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 2 de coche\n");
						}
						else if (strcmp(plaza4.matricula, plaza3.matricula) == 0) {
							system("cls");
							printf("Esa matricula se encuentra registrada en la plaza 1 de moto\n");
						}
						else {
							plaza4.estado = 1;
							plaza4.tiempo1 = time(NULL);
						}
						a = 0;
					}
					else {
						printf("\n");
						printf("Matricula incorrecta\n");
					}
				}
				else {
					printf("Lo siento, no quedan plazas libres para coches\n");
				}
				break;

			default:
				printf("Te has equivocado de opcion\n");
			}
			break;
			
		case 'a':
		case 'A':
			printf("Has elegido la opcion abandonar plaza\n");
			Sleep(1300);
			system("cls");
			printf("Que tipo de vehiculo has aparcado? coche (c) o moto (m):\n\n");
			scanf_s("%c", &eleccion, 1);
			getchar();
			system("cls");

			switch (eleccion) {
			case 'C':
			case 'c':
				if (plaza1.estado == 1 || plaza2.estado == 1) {

					printf("En que plaza estaba tu coche?\n\n");
					scanf_s("%c", &posicion, 1);
					getchar();
					system("cls");

					switch (posicion) {

					case '1':
						if (plaza1.estado == 1) {
							printf("Para verificarlo, introduce tu matricula: ");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");

							for (i = 0; i < 7; i++) {
								if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
									comprobarMatricula[i] -= 32;
								}
							}

							if (strcmp(plaza1.matricula, comprobarMatricula) == 0) {
								printf("Has abandonado la plaza 1 de coche\n\n");

								plaza1.tiempo2 = time(NULL);
								precio = 0.02*(plaza1.tiempo2 - plaza1.tiempo1);
								printf("Has permanecido aparcado %d segundos\n", plaza1.tiempo2 - plaza1.tiempo1);
								printf("El precio total suma %.2f euros\n\n", precio);
								printf("Vuelve pronto\n");
								plaza1.matricula[0] = 0;
								plaza1.estado = 0;
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
						if (plaza2.estado == 1) {
							printf("Para verificarlo, introduce tu matricula: ");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");

							for (i = 0; i < 7; i++) {
								if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
									comprobarMatricula[i] -= 32;
								}
							}

							if (strcmp(plaza2.matricula, comprobarMatricula) == 0) {
								printf("Has abandonado la plaza 2 de coche\n\n");

								plaza2.tiempo2 = time(NULL);
								precio = 0.02*(plaza2.tiempo2 - plaza2.tiempo1);
								printf("Has permanecido aparcado %d segundos\n", plaza2.tiempo2 - plaza2.tiempo1);
								printf("El precio total suma %.2f euros\n\n", precio);
								printf("Vuelve pronto\n");
								plaza2.matricula[0] = 0;
								plaza2.estado = 0;
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
				if (plaza3.estado == 1 || plaza4.estado == 1) {

					printf("En que plaza estaba tu moto?\n\n");
					scanf_s("%c", &posicion, 1);
					getchar();
					system("cls");

					switch (posicion) {

					case '1':
						if (plaza3.estado == 1) {
							printf("Para verificarlo, introduce tu matricula: ");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");

							for (i = 0; i < 7; i++) {
								if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
									comprobarMatricula[i] -= 32;
								}
							}

							if (strcmp(plaza3.matricula, comprobarMatricula) == 0) {
								printf("Has abandonado la plaza 1 de moto\n\n");

								plaza3.tiempo2 = time(NULL);
								precio = 0.02*(plaza3.tiempo2 - plaza3.tiempo1);
								printf("Has permanecido aparcado %d segundos\n", plaza3.tiempo2 - plaza3.tiempo1);
								printf("El precio total suma %.2f euros\n\n", precio);
								printf("Vuelve pronto\n");
								plaza3.matricula[0] = 0;
								plaza3.estado = 0;
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
						if (plaza4.estado == 1) {
							printf("Para verificarlo, introduce tu matricula: ");
							scanf_s("%s", comprobarMatricula, 8);
							getchar();
							system("cls");

							for (i = 0; i < 7; i++) {
								if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
									comprobarMatricula[i] -= 32;
								}
							}

							if (strcmp(plaza4.matricula, comprobarMatricula) == 0) {
								printf("Has abandonado la plaza 2 de moto\n\n");

								plaza4.tiempo2 = time(NULL);
								precio = 0.02*(plaza4.tiempo2 - plaza4.tiempo1);
								printf("Has permanecido aparcado %d segundos\n", plaza4.tiempo2 - plaza4.tiempo1);
								printf("El precio total suma %.2f euros\n\n", precio);
								printf("Vuelve pronto\n");
								plaza4.matricula[0] = 0;
								plaza4.estado = 0;
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

			default:
				printf("Te has equivocado de opcion\n");
			}
			break;

		case 'e':
		case 'E':
			printf("Has elegido la opcion estado de aparcamiento\n");
			Sleep(1300);
			system("cls");
			printf("A continuacion se le mostrara un listado de las plazas del garaje:\n\n");
			printf("Plaza 1 - C - ");
			if (plaza1.estado == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", plaza1.matricula);
			}
			printf("Plaza 2 - C - ");
			if (plaza2.estado == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", plaza2.matricula);
			}
			printf("Plaza 1 - M - ");
			if (plaza3.estado == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", plaza3.matricula);
			}
			printf("Plaza 2 - M - ");
			if (plaza4.estado == 0) {
				printf("Libre\n");
			}
			else {
				printf("Ocupada - matricula: %s\n", plaza4.matricula);
			}
			break;

		case'b':
		case'B':
			printf("Has elegido la opcion de buscar vehiculo por matricula\n");
			Sleep(1300);
			system("cls");
			printf("Que tipo de vehiculo quieres buscar? coche (c) o moto (m):\n\n");
			scanf_s("%c", &eleccion, 1);
			getchar();
			system("cls");

			switch (eleccion) {
			case 'C':
			case 'c':
				if (plaza1.estado == 1 || plaza2.estado == 1) {
					printf("Introduce la matricula que buscas: ");
					scanf_s("%s", comprobarMatricula, 8);
					getchar();
					system("cls");

					for (i = 0; i < 7; i++) {
						if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
							comprobarMatricula[i] -= 32;
						}
					}

					if (strcmp(plaza1.matricula, comprobarMatricula) == 0) {
						printf("El coche se encuentra en la plaza 1\n");
					}
					else if (strcmp(plaza2.matricula, comprobarMatricula) == 0) {
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
				if (plaza3.estado == 1 || plaza4.estado == 1) {
					printf("Introduce la matricula que buscas: ");
					scanf_s("%s", comprobarMatricula, 8);
					getchar();
					system("cls");

					for (i = 0; i < 7; i++) {
						if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
							comprobarMatricula[i] -= 32;
						}
					}

					if (strcmp(plaza3.matricula, comprobarMatricula) == 0) {
						printf("La moto se encuentra en la plaza 1\n");
					}
					else if (strcmp(plaza4.matricula, comprobarMatricula) == 0) {
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

			default:
				printf("Te has equivocado de opcion\n");
			}
			break;
			
		case's':
		case'S':
			printf("Has elegido la opcion de finalizar sesion\n\n");
			printf("Vuelve pronto\n");
			finBucle = 1;
			break;

		default:
			printf("Lo siento, te has equivocado de opcion\n");
		}

		printf("\n");
		system("pause");
	}
	
}