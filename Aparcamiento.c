#include <stdio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#define PLAZASM 5
#define PLAZASC 5

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(struct usuario usuarioValido, char username[], char password[]);

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
	int finBucle = 1, a = 0, i, p = 0, j, k = 0, posicion, l = 0, auxC = 0, auxM = 0;
	struct plaza plazaC[PLAZASC] = { 0, 'C' }, plazaM[PLAZASM] = { 0, 'M' };
	struct usuario persona1 = { "admin", "1234" };
	char opcion, comprobarMatricula[8], eleccion, user[50], contraseña[50];
	

	printf("Bienvenido, el precio del parking es de 2 centimos por segundo\n");
	Sleep(2500);

	while (p < 3) {

		system("cls");
		printf("Numero de intentos para iniciar sesion: %d\n\n", 3 - p);
		printf("Introduce el usuario: ");
		gets(user);
		printf("\nIntroduce la contrasena: ");
		gets(contraseña);
		system("cls");

		if (existeUsuario(persona1, user, contraseña)) {
			system("cls");
			printf("Accediendo al sistema");
			p = 3;
			finBucle = 0;
			Sleep(350);
			printf(".");
			Sleep(350);
			printf(".");
			Sleep(350);
			printf(".");
			Sleep(200);
		}
		else {
			printf("Usuario o contrasena incorrectos\n\n");
			p++;
			system("pause");
		}

	}

	while (finBucle == 0) {

		system("cls");
		time_t result = time(NULL);
		char str[26];
		ctime_s(str, sizeof str, &result);
		printf("%s\n", str);

		opcion = menu();

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
				for (i = 0; i < PLAZASC; i++) {

					if (auxC == PLAZASC) {
						printf("Lo siento, no quedan plazas libres para coches\n");
						break;
					}
					else {
						if (plazaC[i].estado == 0) {
							printf("Has reservado la plaza %d de coche\n\n", i + 1);
							printf("Para registrarlo, introduce tu matricula: ");
							scanf_s("%s", plazaC[i].matricula, 8);
							getchar();

							for (j = 4; j < 7; j++) {
								if (97 <= plazaC[i].matricula[j] && plazaC[i].matricula[j] <= 122) {
									plazaC[i].matricula[j] -= 32;
								}
							}

							if (esMatriculaValida(plazaC[i].matricula)) {
								for (j = 0; j < PLAZASC; j++) {
									if (i != j) {
										if (strcmp(plazaC[i].matricula, plazaC[j].matricula) == 0) {
											system("cls");
											printf("Esa matricula se encuentra registrada en la plaza %d de coche\n", j + 1);
											k = 1;
										}
									}
								}

								for (j = 0; j < PLAZASM; j++) {
									if (strcmp(plazaC[i].matricula, plazaM[j].matricula) == 0) {
										system("cls");
										printf("Esa matricula se encuentra registrada en la plaza %d de moto\n", j + 1);
										k = 1;
									}
								}

								if (k == 0) {
									plazaC[i].estado = 1;
									plazaC[i].tiempo1 = time(NULL);
									auxC++;
								}
								else {
									plazaC[i].matricula[0] = 0;
								}

								a = 0;
								k = 0;
								break;
							}
							else {
								printf("\n");
								printf("Matricula incorrecta\n");
								plazaC[i].matricula[0] = 0;
								break;
							}
						}
					}
				}
				break;

			case'M':
			case'm':
				for (i = 0; i < PLAZASM; i++) {

					if (auxM == PLAZASM) {
						printf("Lo siento, no quedan plazas libres para motos\n");
						break;
					}
					else {
						if (plazaM[i].estado == 0) {
							printf("Has reservado la plaza %d de moto\n\n", i + 1);
							printf("Para registrarlo, introduce tu matricula: ");
							scanf_s("%s", plazaM[i].matricula, 8);
							getchar();

							for (j = 4; j < 7; j++) {
								if (97 <= plazaM[i].matricula[j] && plazaM[i].matricula[j] <= 122) {
									plazaM[i].matricula[j] -= 32;
								}
							}

							if (esMatriculaValida(plazaM[i].matricula)) {
								for (j = 0; j < PLAZASM; j++) {
									if (i != j) {
										if (strcmp(plazaM[i].matricula, plazaM[j].matricula) == 0) {
											system("cls");
											printf("Esa matricula se encuentra registrada en la plaza %d de moto\n", j + 1);
											k = 1;
										}
									}
								}

								for (j = 0; j < PLAZASC; j++) {
									if (strcmp(plazaM[i].matricula, plazaC[j].matricula) == 0) {
										system("cls");
										printf("Esa matricula se encuentra registrada en la plaza %d de coche\n", j + 1);
										k = 1;
									}
								}

								if (k == 0) {
									plazaM[i].estado = 1;
									plazaM[i].tiempo1 = time(NULL);
									auxM++;
								}
								else {
									plazaM[i].matricula[0] = 0;
								}

								a = 0;
								k = 0;
								break;
							}
							else {
								printf("\n");
								printf("Matricula incorrecta\n");
								plazaM[i].matricula[0] = 0;
								break;
							}
						}
					}
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
				for (i = 0; i < PLAZASC; i++) {

					if (auxC == 0) {
						printf("En estos momentos ningun coche se encuentra aparcado\n");
						break;
					}
					else {
						printf("En que plaza estaba tu coche?\n\n");
						scanf_s("%d", &posicion, 1);
						getchar();
						system("cls");
						posicion -= 1;

						if (posicion < PLAZASC) {
							if (plazaC[posicion].estado == 1) {
								printf("Para verificarlo, introduce tu matricula: ");
								scanf_s("%s", comprobarMatricula, 8);
								getchar();
								system("cls");

								for (i = 0; i < 7; i++) {
									if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
										comprobarMatricula[i] -= 32;
									}
								}

								if (strcmp(plazaC[posicion].matricula, comprobarMatricula) == 0) {
									printf("Has abandonado la plaza %d de coche\n\n", posicion + 1);

									plazaC[posicion].tiempo2 = time(NULL);
									precio = 0.02*(plazaC[posicion].tiempo2 - plazaC[posicion].tiempo1);
									printf("Has permanecido aparcado %d segundos\n", plazaC[posicion].tiempo2 - plazaC[posicion].tiempo1);
									printf("El precio total suma %.2f euros\n\n", precio);
									printf("Vuelve pronto\n");
									plazaC[posicion].matricula[0] = 0;
									plazaC[posicion].estado = 0;
									auxC--;
								}
								else {
									printf("La matricula no coincide con el coche aparcado en esta plaza\n");
								}
							}
							else {
								printf("En la plaza %d no hay ningun coche\n", posicion + 1);
								break;
							}
						}
						else {
							printf("Actualmente no disponemos de esa plaza para coches\n");
							break;
						}
					}
				}
				break;

			case 'M':
			case 'm':
				for (i = 0; i < PLAZASM; i++) {
					if (auxM == 0) {
						printf("En estos momentos ninguna moto se encuentra aparcada\n");
						break;
					}
					else {
						printf("En que plaza estaba tu moto?\n\n");
						scanf_s("%d", &posicion, 1);
						getchar();
						system("cls");
						posicion -= 1;

						if (posicion < PLAZASM) {
							if (plazaM[posicion].estado == 1) {
								printf("Para verificarlo, introduce tu matricula: ");
								scanf_s("%s", comprobarMatricula, 8);
								getchar();
								system("cls");

								for (i = 0; i < 7; i++) {
									if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
										comprobarMatricula[i] -= 32;
									}
								}

								if (strcmp(plazaM[posicion].matricula, comprobarMatricula) == 0) {
									printf("Has abandonado la plaza %d de moto\n\n", posicion + 1);

									plazaM[posicion].tiempo2 = time(NULL);
									precio = 0.02*(plazaM[posicion].tiempo2 - plazaM[posicion].tiempo1);
									printf("Has permanecido aparcado %d segundos\n", plazaM[posicion].tiempo2 - plazaM[posicion].tiempo1);
									printf("El precio total suma %.2f euros\n\n", precio);
									printf("Vuelve pronto\n");
									plazaM[posicion].matricula[0] = 0;
									plazaM[posicion].estado = 0;
									auxM--;
								}
								else {
									printf("La matricula no coincide con la moto aparcado en esta plaza\n");
								}
							}
							else {
								printf("En la plaza %d no hay ninguna moto\n", posicion + 1);
								break;
							}
						}
						else {
							printf("Actualmente no disponemos de esa plaza para motos\n");
							break;
						}
					}
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
			
			for (i = 0; i < PLAZASC; i++) {
				printf("Plaza %d - %c - ", i + 1, plazaC->tipo);
				if (plazaC[i].estado == 0) {
					printf("Libre\n\n");
				}
				else {
					printf("Ocupada - matricula: %s\n\n", plazaC[i].matricula);
				}
			}

			for (i = 0; i < PLAZASM; i++) {
				printf("Plaza %d - %c - ", i + 1, plazaM->tipo);
				if (plazaM[i].estado == 0) {
					printf("Libre\n\n");
				}
				else {
					printf("Ocupada - matricula: %s\n\n", plazaM[i].matricula);
				}
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
				if (auxC == 0) {
					printf("En este momento no se encuentra ningun coche aparcado\n");
					break;
				}
				else {
					printf("Introduce la matricula que buscas: ");
					scanf_s("%s", comprobarMatricula, 8);
					getchar();
					system("cls");

					for (i = 0; i < 7; i++) {
						if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
							comprobarMatricula[i] -= 32;
						}
					}

					for (i = 0; i < PLAZASC; i++) {
						if (strcmp(plazaC[i].matricula, comprobarMatricula) == 0) {
							printf("El coche se encuentra en la plaza %d\n", i + 1);
							l = 1;
						}
					}

					if (l == 0) {
						printf("El coche no esta registrado en el garaje\n");
					}

					l = 0;
				}
				break;

			case 'M':
			case 'm':
				if (auxM == 0) {
					printf("En este momento no se encuentra ninguna moto aparcada\n");
					break;
				}
				else {
					printf("Introduce la matricula que buscas: ");
					scanf_s("%s", comprobarMatricula, 8);
					getchar();
					system("cls");

					for (i = 0; i < 7; i++) {
						if (97 <= comprobarMatricula[i] && comprobarMatricula[i] <= 122) {
							comprobarMatricula[i] -= 32;
						}
					}

					for (i = 0; i < PLAZASM; i++) {
						if (strcmp(plazaM[i].matricula, comprobarMatricula) == 0) {
							printf("La moto se encuentra en la plaza %d\n", i + 1);
							l = 1;
						}
					}

					if (l == 0) {
						printf("La moto no esta registrada en el garaje\n");
					}

					l = 0;
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

char menu() {

	char opcion;

	printf("Que accion desea realizar?\n\n");
	printf("Pulse 'R' para reservar plaza\n");
	printf("Pulse 'A' para abandonar plaza\n");
	printf("Pulse 'E' para ver el estado de aparcamiento\n");
	printf("Pulse 'B' para buscar vehiculo por matricula\n");
	printf("Pulse 'S' para finalizar sesion\n\n");
	scanf_s("%c", &opcion, 1);
	getchar();
	system("cls");

	return opcion;
}

int esDigitoValido(char caracter) {

	if (48 <= caracter && caracter <= 57) {
		return 1;
	}

	return 0;
}

int esLetraValida(char caracter) {

	if (66 <= caracter && caracter <= 90 && caracter != 73 && caracter != 85 && caracter != 69 && caracter != 79) {
		return 1;
	}

	return 0;
}

int esMatriculaValida(char matricula[]) {

	int i, a = 0;

	for (i = 0; i < 4; i++) {
		if (esDigitoValido(matricula[i])) {
			a++;
		}
	}

	for (i = 4; i < 7; i++) {
		if (esLetraValida(matricula[i])) {
			a++;
		}
	}

	if (a == 7) {
		return 1;
	}

	return 0;
}

int existeUsuario(struct usuario usuarioValido, char username[], char password[]) {

	if (strcmp(usuarioValido.nombre, username) == 0) {

		if (strcmp(usuarioValido.password, password) == 0) {
			return 1;
		}
	}

	return 0;
}