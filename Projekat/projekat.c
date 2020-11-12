#include <stdio.h>
#include <stdlib.h>
#include "projekat.h"
#include <string.h>



int username(char* niz){
FILE* dat = fopen("dokumenti.txt","r");
if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
    nalog str[100];
int i;
int a=0;
for(i=0;i<strlen(niz);i++){


        if ((niz[i] >= 65 && niz[i] <= 90) || (niz[i] >= 97 && niz[i] <= 122) || (niz[i] >= 48 && niz[i] <= 57) || niz[i]== 32 || niz[i]== 46 || niz[i]== 95){

        }else {
        a = 1;
        }

}

for(i =0;; i++)
    {
        fscanf(dat,"%[^\n]s",str[i].ime);
        if (feof(dat))
        {
            break;
        }
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].prezime);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].email);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].nickname);
        if(strcmp(niz,str[i].nickname)==0){
            a = 1;
        }
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].password);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].status);
        fgetc(dat);

    }
    if (a == 1){
        printf("Uneli ste neodgovarajuci ili vec postojeci username!!\n\n");
        fclose(dat);
        return 1;
    }
    fclose(dat);
    return 0;

}
int provera(){
FILE* dat = fopen("dokumenti.txt","r+");
if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
if (dat == NULL){
    printf("Memery failed!");
    fclose(dat);
    return;
}
char niz[30];

for (;;)
{
    fscanf(dat,"%[^\n]s",niz);

    if (feof(dat)){
        break;
    }
    fgetc(dat);
    if (strcmp(niz,"Online") == 0){
            fclose(dat);
        return 1;
    }
}
fclose(dat);
return 0;
}
int meni(){
    int x=0;
    x=provera();
if (x){
    printf("1. Logout.\n");
    printf("2. Izmena naloga.\n");
    printf("3. Brisanje naloga.\n");
    printf("4. Izlaz.\n");
}else{
    printf("1. Dodavanje novog naloga.\n");
    printf("2. Login.\n");
    printf("3. Izlaz.\n");

}

return x;
}





int email(char* niz){
    FILE* dat = fopen("dokumenti.txt","r");
    if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
    nalog str[100];
int i;
int a=0;
for (i=0;i<strlen(niz);i++){
    if(niz[i]=='@'){
        a=1;
    }
    if(niz[i] == '.' && a==1){
        a=2;
        break;
    }
}
if(a != 2){
        fclose(dat);
    return 1;
}


for(i =0;; i++)
    {
        fscanf(dat,"%[^\n]s",str[i].ime);
        if (feof(dat))
        {
            break;
        }
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].prezime);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].email);
        if(strcmp(niz,str[i].email)==0){
            fclose(dat);
            return 1;
        }
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].nickname);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].password);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].status);
        fgetc(dat);

    }
    fclose(dat);
    return 0;
}
void dodaj()
{
    nalog str;
    char niz[20];
    FILE* dat = fopen("dokumenti.txt","a+");
    if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
    fflush(stdin);
    printf("unesite ime: ");
    gets(str.ime);


    printf("unesite prezime: ");
    fflush(stdin);
    gets(str.prezime);

    imejl:
    printf("unesite email: ");
    fflush(stdin);
    gets(str.email);
    if (email(str.email)){
        printf("Uneliste pogresan ili isti email! Pokusajte ponovo!\n");
        goto imejl;
    }
    user:
    printf("unesite nickname: ");
    fflush(stdin);
    gets(str.nickname);
    if(username(str.nickname)){
        goto user;
    }

    printf("unesite sifru: ");
    fflush(stdin);
    gets(str.password);


ponovo:
    printf("potvrdite sifru: ");
    fflush(stdin);
    gets(niz);
    if (strcmp(niz,str.password) != 0)
    {
        printf("Uneli ste pogresnu podvrdu sifre!\n");
        goto ponovo;
    }
    fputs(str.ime,dat);
    fputc('\n',dat);
    fputs(str.prezime,dat);
    fputc('\n',dat);
    fputs(str.email,dat);
    fputc('\n',dat);
    fputs(str.nickname,dat);
    fputc('\n',dat);
    fputs(str.password,dat);
    fputc('\n',dat);
    fputs("Offline",dat);
    fputc('\n',dat);
    fclose(dat);
    return;
}
void login()
{

    nalog str[100];
    char niz[10] = "Online";
    int prekid;
    FILE* dat;
    FILE* dat1;
    dat = fopen("dokumenti.txt", "r+");
    if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
    dat1 = fopen("dokumenti1.txt", "w+");
    if (dat1 == NULL ){
    printf("Memory failed!\n");
    fclose(dat1);
    return;
}
    int i;
    int n;
    for(i =0;; i++)
    {
        fscanf(dat,"%[^\n]s",str[i].ime);
        if (feof(dat))
        {
            break;
        }
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].prezime);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].email);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].nickname);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].password);
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].status);
        fgetc(dat);
        if (strcmp(str[i].status,niz)==0)
        {
            printf("\nvec ste ulogovani!!!\n");
            fclose(dat);
            fclose(dat1);

            goto kraj;
        }

    }
    n = i;
    char username[10];
    char sifra[20];
ponovo:
    printf("\nUnesite username/email: ");
    fflush(stdin);
    gets(username);
    printf("\nUnesite sifru: ");
    fflush(stdin);
    gets(sifra);
    int j;
    int a = 0;
    for(j=0; j<strlen(username); j++)
    {
        if (username[j]=='@')
        {
            a=1;
            break;
        }
    }
    int broj=-1;
    for(j=0; j<i; j++)
    {

        if(a==1)
        {
            if(strcmp(username,str[j].email)==0)
            {
                broj = j;

                break;
            }
        }
        else
        {
            if(strcmp(username,str[j].nickname)==0)
            {
                broj = j;

                break;
            }
        }
    }
    if (broj ==-1)
    {
        printf("\nUneli ste pogresan username/email!\n");
        printf("Unesite \"0\" za prekid ili \"1\" za nastavak logina\n\n");
        scanf("%i",&prekid);
        if(prekid == 0)
        {
            fclose(dat);
            fclose(dat1);
            goto kraj;
        }
        else
        {
            goto ponovo;
        }
    }

    if (strcmp(sifra,str[broj].password)==0)
    {
        printf("Uspesno ste se loginovali\n\n");

        strcpy(str[broj].status,niz);
        for (i=0; i<n; i++)
        {
            fputs(str[i].ime,dat1);
            fputc('\n',dat1);
            fputs(str[i].prezime,dat1);
            fputc('\n',dat1);
            fputs(str[i].email,dat1);
            fputc('\n',dat1);
            fputs(str[i].nickname,dat1);
            fputc('\n',dat1);
            fputs(str[i].password,dat1);
            fputc('\n',dat1);
            fputs(str[i].status,dat1);
            fputc('\n',dat1);

        }


    }
    else
    {
        printf("\nUneli ste pogresnu sifru!\n");
        printf("Unesite \"0\" za prekid ili \"1\" za nastavak logina\n\n");
        scanf("%i",&prekid);
        if(prekid == 0)
        {
            fclose(dat);
            fclose(dat1);
            goto kraj;
        }
        else
        {
            goto ponovo;
        }
    }

    fclose(dat);
    fclose(dat1);
    if(0){
            kraj:
            remove("dokumenti1.txt");
            return;
        }
    remove("dokumenti.txt");
    rename("dokumenti1.txt","dokumenti.txt");
    return;
}
void logout()
{
    char niz[10] = "Offline";
    nalog str[100];
    FILE* dat = fopen("dokumenti.txt","r+");
    if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
    int i,j,n = 0;
    for(i =0;; i++)
    {
        fscanf(dat,"%[^\n]s",str[i].ime);

        if (feof(dat))
        {
            break;
        }
        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].prezime);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].email);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].nickname);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].password);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].status);
        if(strcmp(str[i].status,"Online")==0)
        {
            strcpy(str[i].status,niz);
            n = 1;
        }

        fgetc(dat);

    }
    if (n==0)
    {
        printf("Niste ulogovani !!!\n\n");
        fclose(dat);
        return;
    }

    FILE* dat1 = fopen("dokumenti1.txt","w+");
    if (dat1 == NULL ){
    printf("Memory failed!\n");
    fclose(dat1);
    return;
}



    for (j=0; j<i; j++)
    {
        fprintf(dat1,"%s",str[j].ime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].prezime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].email);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].nickname);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].password);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].status);
        fprintf(dat1,"\n");

    }

    printf("uspesno ste se odjavili sa naloga!!!\n\n");

    fclose(dat);
    fclose(dat1);
    remove("dokumenti.txt");
    rename("dokumenti1.txt","dokumenti.txt");
}
void izmena()
{
    nalog str[100];
    nalog pom;
    char niz[10] = "Online";
    FILE* dat = fopen("dokumenti.txt","r+");
    if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
    char sifra[20];
    int i,n,broj=-1;
    for(i =0;; i++)
    {
        fscanf(dat,"%[^\n]s",str[i].ime);

        if (feof(dat))
        {
        break;
        }


        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].prezime);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].email);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].nickname);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].password);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].status);
        fgetc(dat);
        if (!strcmp(str[i].status,niz)){
            broj = i;
        }
    }
    if(broj == -1){
        fclose(dat);
        printf("Niste ulogovani");
        return;
    }

    strcpy(pom.ime,str[broj].ime);
    strcpy(pom.prezime,str[broj].prezime);
    strcpy(pom.email,str[broj].email);
    strcpy(pom.nickname,str[broj].nickname);
    strcpy(pom.password,str[broj].password);


    do {
        printf("\nUnesite 1 da promenite ime. ");
        printf("\nUnesite 2 da promenite prezime. ");
        printf("\nUnesite 3 da promenite email. ");
        printf("\nUnesite 4 da promenite username. ");
        printf("\nUnesite 5 da promenite sifru. ");
        printf("\nUnesite 6 da zatvorite i sacuvate izmene");
        printf("\nUnesite 7 da zatvorite izmene bez cuvanja\n");
        fflush(stdin);
        scanf("%i",&n);

        switch(n){
        case(1):{
        printf("\nUnesite novo ime: \n");
        fflush(stdin);
        gets(pom.ime);
        break;
        }
        case(2):{
        printf("\nUnesite novo prezime: \n");
        fflush(stdin);
        gets(pom.prezime);
        break;
        }
        case(3):{
            imejl:
        printf("\nUnesite novi email: \n");
        fflush(stdin);
        gets(pom.email);
        if (email(pom.email)){
        printf("\nUneliste pogresan ili isti email! Pokusajte ponovo!\n\n");
        goto imejl;
    }
        break;
        }
        case(4):{
            user:
        printf("\nUnesite novi username: \n");

        fflush(stdin);
        gets(pom.nickname);
        if(username(pom.nickname)){
        goto user;
    }
        break;
        }
        case(5):{
            ponovo:
        printf("\nUnesite novu sifru: \n");
        fflush(stdin);
        gets(sifra);
        printf("Potvrdite novu sifru: \n");
        fflush(stdin);
        gets(pom.password);
        if(strcmp(sifra,pom.password)){
            printf("\nUneli ste dve razlicite sifre!!! Pokusajte ponovo\n\n");
            goto ponovo;
        }
        if (strcmp(pom.password,str[broj].password)==0){
            printf("\nNova sifra je ista kao i stara. Unesite drugu sifru!\n\n");
            goto ponovo;
        }
        break;
        }
        case(7):{
            printf("\n\npromene nisu sacuvane!!!\n\n");
            fclose(dat);
            return;
        break;
        }


        }

    }while(n!=6);
    FILE* dat1 = fopen("dok.txt","w+");
    if (dat1 == NULL ){
    printf("Memory failed!\n");
    fclose(dat1);
    return;
}
    int j;
    for(j=0;j<i;j++){
        if (j==broj){
        fprintf(dat1,"%s",pom.ime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",pom.prezime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",pom.email);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",pom.nickname);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",pom.password);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].status);
        fprintf(dat1,"\n");
        }else{
        fprintf(dat1,"%s",str[j].ime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].prezime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].email);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].nickname);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].password);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].status);
        fprintf(dat1,"\n");

        }

    }
    printf("promene su sacuvane!\n\n");
    fclose(dat);
    fclose(dat1);
    remove("dokumenti.txt");
    rename("dok.txt","dokumenti.txt");
    return;
}
    void brisanje()
    {
    FILE* dat = fopen("dokumenti.txt","r+");
    if (dat == NULL ){
    printf("Memory failed!\n");
    fclose(dat);
    return;
}
if (dat == NULL){
    printf("Memery failed!");
    fclose(dat);
    return;
}
nalog str[100];
int broj = -1;
int i,j;
char niz[10] = "Online";
for(i =0;; i++)
    {
        fscanf(dat,"%[^\n]s",str[i].ime);

        if (feof(dat))
        {
        break;
        }


        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].prezime);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].email);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].nickname);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].password);

        fgetc(dat);
        fscanf(dat,"%[^\n]s",str[i].status);
        fgetc(dat);
        if (!strcmp(str[i].status,niz)){
            broj = i;
        }
    }
    if (broj == -1){
        printf("Doslo je do neocekivane greske!\n\n");
        fclose(dat);
        return;
    }
    FILE* dat1 = fopen("dok.txt","w+");
    if (dat1 == NULL ){
    printf("Memory failed!\n");
    fclose(dat1);
    return;
}
    if (dat1 == NULL){
        printf("Memory failed");
        fclose(dat);
        fclose(dat1);
        return;
    }
    for(j=0;j<i;j++){
        if (j==broj){
        continue;
        }else{
        fprintf(dat1,"%s",str[j].ime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].prezime);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].email);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].nickname);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].password);
        fprintf(dat1,"\n");
        fprintf(dat1,"%s",str[j].status);
        fprintf(dat1,"\n");

        }
        }
    fclose(dat);
    fclose(dat1);
    remove("dokumenti.txt");
    rename("dok.txt","dokumenti.txt");

    }
    void kreiranje_grupe()
    {

    }
    void izmena_grupe()
    {

    }
    void brisanje_grupe()
    {

    }
    void ulazak()
    {

    }
    void prijateljli()
    {

    }
    void akcije_grupe()
    {

    }





