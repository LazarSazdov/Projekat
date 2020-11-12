#ifndef PROJEKAT_H_INCLUDED
#define PROJEKAT_H_INCLUDED
typedef struct{
char ime[20];
char prezime[20];
char email[30];
char nickname[20];
char password[20];
char status[10];
}nalog;

int username();
int provera();
int meni();
int email(char* niz);
void dodaj();
void login();
void logout();
void izmena();
void brisanje();
void kreiranje_grupe();
void izmena_grupe();
void brisanje_grupe();
void ulazak();
void prijateljli();
void akcije_grupe();

#endif // PROJEKAT_H_INCLUDED
