#include "fwarcaby.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>

   struct pion
{
    int exist;
    int x;
    int y;
    int player;
    int damka;

}b[12],c[12];
int crate[8][8];
int tura=0,lpionka,nokillturns=0;

void protip()
{
    system("cls");
    color(0,14);
    printf(" X  1 2 3 4 5 6 7 8\nY  þออออออออออออออ>\n1  บ\n2  บ\n3  บ\n4  บ\n5  บ\n6  บ\n7  บ\n8  \\/");
    printf("\n\nNacisnij dowolny kawisz \naby przejsc do gry");Sleep(200);printf(".");Sleep(200);printf(".");Sleep(200);printf(".");
    getch();
   /* printf("\n\nNacisnij dowolny kawisz \naby przejsc dalej...");
    getch();
    system("cls");
    color(0,15);
    printf("\n1. Pionki moga sie poruszac \ntylko po przekatnej o 1 pole\n2. Jesli pionek sasiaduje z pionem \nprzeciwnika i pole za nim jest puste, \nto musi zbic przeciwnika!");
     Sleep(500);
     printf("\n\nNacisnij dowolny kawisz \naby przejsc dalej...");
    getch();
    system("cls");

    printf("\n3. Po zbiciu przeciwnika pionek \nkontynuuje ruch dopoki ma taka mozliwosc\n4. Pionki tego samego gracza nie moga przeskakiwac przez siebie!");
     Sleep(500);
     printf("\n\nNacisnij dowolny kawisz \naby przejsc dalej...");
    getch();
    system("cls");
    printf("\n5. Gra konczy sie wygrana po zbiciu pionkow przeciwnika \nlub remisem po 40 turach bez zbicia! ");
    printf("\n\nNacisnij dowolny kawisz \naby przejsc do gry");Sleep(100);printf(".");Sleep(100);printf(".");Sleep(100);printf(".");
    getch();*/
}

void color(int bgColor, int fgColor)//ustawia kolor
{
	HANDLE a;
	a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(a, bgColor * 16 | fgColor); // kolory (tlo,napis)
}


int killmovepossible(int x, int y, int xr, int yr)//sprawdza czy po zbiciu mozliwy ruch
{
     int enemy;
switch(tura%2)
{
case 0:
    enemy=3;
    break;
case 1:
    enemy=2;
    break;
}
if((yr-y==2)||(yr-y==-2))
    {
        if((xr-x==2)||(xr-x==-2))
        {
            if(crate[yr][xr]==1)
            {
                if((yr-y==2)&&(xr-x==2))
                    {
                        if(crate[yr-1][xr-1]==enemy){return 1;}
                    }
                if((yr-y==2)&&(xr-x==-2))
                {
                    if(crate[yr-1][xr+1]==enemy){return 1;}
                }
                if((yr-y==-2)&&(xr-x==2))
                {
                    if(crate[yr+1][xr-1]==enemy){return 1;}
                }
                if((yr-y==-2)&&(xr-x==-2))
                    {
                        if(crate[yr+1][xr+1]==enemy){return 1;}
                    }


            }
        }
    }
    return 0;
}


int killmove(int x,int y)//zwraca 1 jesli mozna dalej zbijac!, 0 dla braku mozliwosci
{
    int enemy;
switch(tura%2)
{
case 0:
    enemy=3;
    break;
case 1:
    enemy=2;
    break;
}
if((y==7)||(y==6))
{
    if((x==0)||(x==1))
    {
        if((crate[y-1][x+1]==enemy)&&(crate[y-2][x+2]==1)){return 1;}
        return 0;
    }
    if((x==7)||(x==6))
    {
        if((crate[y-1][x-1]==enemy)&&(crate[y-2][x-2]==1)){return 1;}
        return 0;
    }
    if((crate[y-1][x+1]==enemy)&&(crate[y-2][x+2]==1)){return 1;}
    if((crate[y-1][x-1]==enemy)&&(crate[y-2][x-2]==1)){return 1;}
    return 0;
}
if((y==0)||(y==1))
{
    if((x==0)||(x==1))
    {
        if((crate[y+1][x+1]==enemy)&&(crate[y+2][x+2]==1)){return 1;}
        return 0;
    }
    if((x==7)||(x==6))
    {
        if((crate[y+1][x-1]==enemy)&&(crate[y+2][x-2]==1)){return 1;}
        return 0;
    }
    if((crate[y+1][x+1]==enemy)&&(crate[y+2][x+2]==1)){return 1;}
    if((crate[y+1][x-1]==enemy)&&(crate[y+2][x-2]==1)){return 1;}
    return 0;
}

if((x==0)||(x==1))
    {
        if((crate[y+1][x+1]==enemy)&&(crate[y+2][x+2]==1)){return 1;}
        if((crate[y-1][x+1]==enemy)&&(crate[y-2][x+2]==1)){return 1;}
        return 0;
    }
if((x==7)||(x==6))
    {
        if((crate[y+1][x-1]==enemy)&&(crate[y+2][x-2]==1)){return 1;}
        if((crate[y-1][x-1]==enemy)&&(crate[y-2][x-2]==1)){return 1;}
        return 0;
    }

if((crate[y+1][x+1]==enemy)&&(crate[y+2][x+2]==1)){return 1;}
if((crate[y+1][x-1]==enemy)&&(crate[y+2][x-2]==1)){return 1;}
if((crate[y-1][x+1]==enemy)&&(crate[y-2][x+2]==1)){return 1;}
if((crate[y-1][x-1]==enemy)&&(crate[y-2][x-2]==1)){return 1;}
return 0;




}

void kill(int x, int y,int xr, int yr)//zabija pionek, daje dzwiek!
{
    printf("\a");
    int xb=0,yb=0,i;
    switch(tura%2)
    {
    case 0:
        crate[y][x]=1;
        crate[yr][xr]=2;
        b[lpionka].x=xr;
        b[lpionka].y=yr;
        switch(xr-x)
        {
        case -2:
            xb=x-1;
            break;
        case 2:
            xb=x+1;
             break;
        }
        switch(yr-y)
        {
            case -2:
                yb=yr+1;
                break;
            case 2:
                yb=yr-1;
                 break;
        }
    for(i=0;i<12;i++)
    {
        if((c[i].x==xb)&&(c[i].y==yb)){ break;}
    }

    c[i].exist=0;
    c[i].x=-1;
    c[i].y=-1;
    crate[yb][xb]=1;
    break;
            case 1:
                crate[y][x]=1;
                crate[yr][xr]=3;
                c[lpionka].x=xr;
                c[lpionka].y=yr;
    switch(xr-x)
        {
        case -2:
            xb=x-1;
            break;
        case 2:
            xb=x+1;
            break;
        }
        switch(yr-y)
        {
            case -2:yb=y-1;break;
            case 2:yb=y+1;break;
        }
        for(i=0;i<12;i++)
        {
            if((b[i].x==xb)&&(b[i].y==yb)&&(b[i].exist==1)){break;}
        }
        b[i].exist=0;
        crate[yb][xb]=1;
        break;

    }
}

void movechange(int x, int y, int xr, int yr)//przestawia pionek
{
    switch(tura%2)
    {
    case 0:
        b[lpionka].x=xr;
        b[lpionka].y=yr;
        crate[y][x]=1;
        crate[yr][xr]=2;
        break;
    case 1:
        c[lpionka].x=xr;
        c[lpionka].y=yr;
        crate[y][x]=1;
        crate[yr][xr]=3;
        break;
    }


}

int moveoptions(int x,int y)//sprawdza czy pionek nie jest blokowany przez swoje pionki dalej DZIAlA?
{
    int xl=0,xr=0,a=0,enemy=0;
    xl=x;
    xr=x;
    xl--;
    xr++;
    switch(tura%2)
    {
    case 0:
        a=-1;
        enemy=3;
        break;

    case 1:
        a=1;
        enemy=2;
        break;
    }
        if((enemy==3)&&(y==1))
        {
            if(x==0){if(crate[y+a][xr]==1){return 1;}else{return 0;}}
            if(crate[y+a][xl]==1){return 1;}
            if(crate[y+a][xr]==1){return 1;}
            return 0;
        }
        if((enemy==2)&&(y==6))
        {
            if(x==7){if(crate[y+a][xl]==1){return 1;}}
            if(crate[y+a][xl]==1){return 1;}
            if(crate[y+a][xr]==1){return 1;}
            return 0;
        }
        if(x==0)
        {
            if(crate[y+a][xr]==1){return 1;}
            if((crate[y+a][xr]==enemy)&&(crate[y+(2*a)][xr+1]==1)){return 1;}
            return 0;
        }
        if(x==7)
        {
            if(crate[y+a][xl]==1){return 1;}
            if((crate[y+a][xl]==enemy)&&(crate[y+(2*a)][xl-1]==1)){return 1;}
            return 0;
        }
        if(x==1)
        {
            if(crate[y+a][xl]==1){return 1;}
            if(crate[y+a][xr]==1){return 1;}
            if((crate[y+a][xr]==enemy)&&(crate[y+(2*a)][xr+1]==1)){return 1;}
            return 0;
        }
        if(x==6)
        {
            if(crate[y+a][xr]==1){return 1;}
            if(crate[y+a][xl]==1){return 1;}
            if((crate[y+a][xl]==enemy)&&(crate[y+(2*a)][xl-1]==1)){return 1;}
            return 0;
        }
       /* if(x==7)
        {
            if(crate[y+a][xl]==1){return 1;}
            if((crate[y+a][xl]==enemy)&&(crate[y+(2*a)][xl-1]==1)){return 1;}
            return 0;
        }
        if(x==1)
        {
            if(crate[y+a][xl]==1){return 1;}
            if(crate[y+a][xr]==1){return 1;}
            if((crate[y+a][xr]==enemy)&&(crate[y+(2*a)][xr-1]==1)){return 1;}
            return 0;
        }
      */ /* { CO TO JEST?

            if(crate[y+a][xl]==1){return 1;}
            if(crate[y+a][xr]==1){return 1;}
            if((crate[y+a][xl]==enemy)&&(crate[y+(2*a)][xl-1]==1)){return 1;}
            return 0;
        }*/
            if(crate[y+a][xl]==1){return 1;}
            if(crate[y+a][xr]==1){return 1;}
            if((crate[y+a][xr]==enemy)&&(crate[y+(2*a)][xr-1]==1)){return 1;}
            if((crate[y+a][xl]==enemy)&&(crate[y+(2*a)][xl-1]==1)){return 1;}
            return 0;
}

void nextturn()//poteierdz zmiane tury, daje mozliwosc restartu i wyjscia
{
    system("cls");
    show();
    color(0,14);
    printf("\n   [ENTER]-zacznij ture\n   m-powrot do menu\n   q-wyjscie");
    switch(getch())
    {
    case '\n':
       // tura++;
        //system("cls");
        //show();
        break;
    case 'm':
        tura=0;
        menu();
        break;
    case 'q':
        exit(0);
        break;

    }
}

int owned(int x,int y)//sprawdzenie czy pionek jest twoj, lpionka ustawiona na indeks struktury pionka danego gracza, sprawdza damke, zwraca 2 dla damy
{
    int i;
    switch(tura%2)
    {
    case 0:
        for(i=0;i<12;i++)
        {
            if((b[i].x==x)&&(b[i].y==y)&&(b[i].exist==1)){lpionka=i;
            if(b[i].damka==1){return 2;}
            return 1;}
        }return 0;
    case 1:
        for(i=0;i<12;i++)
        {
            if((c[i].x==x)&&(c[i].y==y)&&(c[i].exist==1)){lpionka=i;
            if(c[i].damka==1){return 2;}
            return 1;}
        }return 0;
    }
}

int movepossible(int x,int y,int xr,int yr)//sprawdza czy wspolrzedne ruchu maja sens, zwraca 0 gdy nie zbijamy pionka mozliwego do zbicia
{

    switch(tura%2)//
    {
    case 0:
        if(((crate[y-1][x-1]==3)&&(crate[y-2][x-2]==1)&&((yr-y)==-2)&&((xr-x)==-2))||((crate[y-1][x+1]==3)&&(crate[y-2][x+2]==1)&&((yr-y)==-2)&&((xr-x)==2)))//sprawdzam czy po lewej albo prawej jest pionek przeciwnika odsloniety
        {
            return 2;
        }else if(((crate[y-1][x-1]==3)&&(crate[y-2][x-2]==1)&&(((yr-y)!=-2)||((xr-x)!=-2)))||((crate[y-1][x+1]==3)&&(crate[y-2][x+2]==1)&&(((yr-y)!=-2)||((xr-x)!=2))))//zwraca 0 jesli gracz nie zbija pionka mimo takiej opcji
        {
            return 0;
        }

        if((yr-y)!=-1){return 0;}//normalny ruch
        if(((xr-x)==1)||((xr-x)==-1)){}else{return 0;}
        if(crate[yr][xr]!=1){return 0;}
        return 1;
        break;
    case 1:
        if(((crate[y+1][x-1]==2)&&(crate[y+2][x-2]==1)&&((yr-y)==2)&&((xr-x)==-2))||((crate[y+1][x+1]==2)&&(crate[y+2][x+2]==1)&&((yr-y)==2)&&((xr-x)==2)))//sprawdzam czy po lewej albo prawej jest pionek przeciwnika odsloniety
        {
            return 2;
        }else if(((crate[y+1][x-1]==2)&&(crate[y+2][x-2]==1)&&(((yr-y)!=2)||((xr-x)!=-2)))||((crate[y+1][x+1]==2)&&(crate[y+2][x+2]==1)&&(((yr-y)!=2)||((xr-x)!=2))))//zwraca 0 jesli gracz nie zbija pionka mimo takiej opcji
        {
            return 0;
        }

        if((yr-y)!=1){return 0;}//normalny ruch
        if(((xr-x)==1)||((xr-x)==-1)){}else{return 0;}
        if(crate[yr][xr]!=1){return 0;}
        return 1;
        break;
    }

}
int move()//sterowanie ruchami na planszy, ogarnia wszystkie funkcje
{
    color(0,15);
    int x,y,xr,yr,i;
    printf("\nKtory ruszyc? X:");//PODANIE CO RUSZYC
    scanf("%d",&x);
    if((x<=8)&&(x>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);return 0;}
    printf("\nKtory ruszyc? Y:");
    scanf("%d",&y);
    if((y<=8)&&(y>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);return 0;}
    x=x--;
    y=y--;
    if(owned(x,y)==0)
    {
        printf("Tu nie ma twojego pionka!");Sleep(1000);system("cls");return 0;
    }
    if(owned(x,y)==2)
    {
      if(moveoptions(x,y)==0){printf("Pionek zablokowany!");Sleep(1000);return 0;}
       system("cls");
    show();
    color(0,15);
    printf("\n[DAMKA]Gdzie ruszyc? X:");//PODANIE DOKAD RUSZYC
    scanf("%d",&xr);
    if((xr<=8)&&(xr>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);return 0;}
    printf("\n[DAMKA]Gdzie ruszyc? Y:");
    scanf("%d",&yr);
    if((yr<=8)&&(yr>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);return 0;}
    xr=xr--;
    yr=yr--;
      //TU MOVE POSSIBLE DLA DAMKI!
      //EFUNKCJE ZABICIA DLA DAMKI MUSZA BYC INNE!
      //JAK NIE ZBIJA TO MOGE UZYC MOVECHANGE

      return 1;//musi sie tak konczyc zeby nie wybuchlo
    }
    if(moveoptions(x,y)==0){printf("Pionek zablokowany!");Sleep(1000);return 0;}
    system("cls");
    show();
    color(0,15);
    printf("\nGdzie ruszyc? X:");//PODANIE DOKAD RUSZYC
    scanf("%d",&xr);
    if((xr<=8)&&(xr>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);return 0;}
    printf("\nGdzie ruszyc? Y:");
    scanf("%d",&yr);
    if((yr<=8)&&(yr>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);return 0;}
    xr=xr--;
    yr=yr--;
    if(movepossible(x,y,xr,yr)==0){printf("Ruch zabroniony!");Sleep(1000);return 0;}
    else if(movepossible(x,y,xr,yr)==2){//potrzebuje petli, funkcji zracajacej 0 dla mozliwosci ruchu po zbiciu i gdzies tu show()
            kill(x,y,xr,yr);
            nokillturns=0;
            for(;;){
            show();
            switch(tura%2)
            {
            case 0:
                x=b[lpionka].x;
                y=b[lpionka].y;
                break;
            case 1:
                x=c[lpionka].x;
                y=c[lpionka].y;
            }
            if(killmove(x,y)==0){return 1;}
           color(0,14);
            printf("\n\tPionek [%d,%d]",x+1,y+1);
            color(0,15);
            printf("\nGdzie ruszyc? X:");//PODANIE DOKAD RUSZYC
            scanf("%d",&xr);
            if((xr<=8)&&(xr>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);continue;}
            printf("\nGdzie ruszyc? Y:");
            scanf("%d",&yr);
            if((yr<=8)&&(yr>=1)){}else{printf("\nZla wspolrzedna!");Sleep(1000);continue;}
            xr=xr--;
            yr=yr--;
            if(killmovepossible(x,y,xr,yr)==0){printf("\nRuch zabroniony!");Sleep(1000);continue;}
            kill(x,y,xr,yr);
    }}
    movechange(x,y,xr,yr);
    nokillturns++;
    return 1;

}

void win()//wyswietla zwyciestwo, sprawdza czy jest
{
    int cz=12,n=12,i;
    for(i=0;i<12;i++) //tu petla ktora liczy pozostale pionki
    {
        if(b[i].exist==0){n--;}
    }
    for(i=0;i<12;i++)
    {
        if(c[i].exist==0){cz--;}
    }
    if(cz==0||n==0){

    system("cls");
    switch(tura %2)
    {
    case 0:
        color(0,1);
       printf("\n\n\tษอออออออออออป\n\tบ  Wygrywa  บ\n\tบ NIEBIESKI บ\n\tศอออออออออออผ");//Tu zwycietwo niebieskich!
        break;
    case 1:
        color(0,4);
        printf("\n\n\tษอออออออออออป\n\tบ  Wygrywa  บ\n\tบ CZERWONY  บ\n\tศอออออออออออผ");//zwyciestwo czerwonych!
        break;
    }
    Sleep(1000);
    color(0,14);
    printf("\n\nNacisnij dowolny klawisz\naby powrocic do menu!");
    getch();
    menu();
    }



}

void remis()//yswietla jesli tury bez zbicia sa rowne 40!
{
    system("cls");
    color(0,14);
    printf("\n\n\tษอออออออป\n\tบ REMIS บ\n\tศอออออออผ");//tu namalowanie slowa remis!
    Sleep(1000);
    color(0,15);
    printf("\n\n\nNacisnij dowolny klawisz\naby powrocic do menu!");
    getch();
    menu();

}

void create()//tworzy tabice do gry i uzupelnia struct pionkow
{
    int i,j,k,l;
     for(i=0;i<=11;i++)//twworzy pionki
    {
    b[i].player=0;b[i].exist=1;b[i].damka=0;
    c[i].player=1;c[i].exist=1;c[i].damka=0;
    }
    for (i=0; i<8; i++)//wypelnia tablice 8x8 0dla bialych pol, 1dla czarnych,
	{
		if (i%2==0)
		{
			for (j = 0; j<8; j++)
			{
				if (j%2 == 0)
				{
					crate[i][j]=0;
				}
				else
				{
					crate[i][j]=1;
				}
			}
		}
		else
		{
			for (j=0;j<8; j++)
			{
				if (j%2==1)
				{
					crate[i][j]=0;
				}
				else
				{
					crate[i][j]=1;
				}
			}
		}

	}
	k=0;
	l=0;
	for(i=0;i<8;i++)//2dla bialych pionow, 3 dla czarnych pionow, ustala wspolrzedne kazdego piona.[y][x]
    {
       for(j=0;j<8;j++)
       {
           if(crate[i][j]==1)
           {
               if(i<=2)
               {
                   c[k].x=j;c[k].y=i;
                   k++;
                   crate[i][j]=3;
               }else if(i>=5)
               {
                   b[l].x=j;b[l].y=i;
                   l++;
                   crate[i][j]=2;

               }
           }
       }
    }
}
void show()//wyswietla "ekran gry" plansza pionki, czyja tura
{
    system("cls");
    int i,j,k,d;
color(0,15);
printf ("  1 2 3 4 5 6 7 8\n  บ บ บ บ บ บ บ บ\n");
for(i=0;i<8;i++)
{
    color(0,15);
    printf("%dอ",i+1);
    for(j=0;j<8;j++)
    {
        switch(crate[i][j])
        {
        case 0:
            color(15,0);
            printf("  ");
            break;
        case 1:
            color(8,0);
            printf("  ");
            break;
        case 2:
            color(1,15);
            d=0;
            for(k=0;k<12;k++){
            if((b[k].x==j)&&(b[k].y==i)&&(b[k].damka==1)){printf("#D");d++;}
            }
            if(d==1){break;};
            printf("  ");
            break;
        case 3:
            color(12,15);
            d=0;
            for(k=0;k<12;k++){
            if((c[k].x==j)&&(c[k].y==i)&&(c[k].damka==1)){printf("#D");d++;}
            }
            if(d==1){break;};
            printf("  ");
            break;
        }
    }printf("\n");
}
color(0,15);
printf("\n\tPosiadane pionki:\n");
for(i=0;i<12;i++)
{
    if(b[i].exist==1)
    {
        color(15,1);
        printf("o");
    }
}
color(0,15);
printf(" | ");
for(i=0;i<12;i++)
{
    if(c[i].exist==1)
    {
        color(15,4);
        printf("o");
    }
}
color(0,15);
switch(tura%2)
{
case 0:
    color(0,9);
    printf("\n\tTura niebieskich");
    break;
case 1:
    color(0,12);
    printf("\n\tTura czerwonych");
    break;
}

}
void menu()//wyswietla menu i uruchaima gre(zapetlone w case1)
{
    create();


    for(;;)
{
    system("cls");
char respond;
color(0,14);
printf("\n\n\t***********\n\t* WARCABY *\n\t***********\n");
color(0,3);
printf("\t1-Nowa gra\n\t2-Autor\n\tq-Wyjscie");
respond=getch();
switch(respond)
{
case '1':
    protip();
    for(;;){
    show();
    if(move()==1)//jak tura sie uda to sprawdzaj zmiane na damke
        {
            if(nokillturns==40)
            {
                remis();
            }
            win();
            tura++;
            nextturn();
    }

    }
    break;
case '2':
    system("cls");
    color(0,15);
    printf("\n\n   Mateusz Lutecki\n   Politechnika Slaska\n   Gliwice\n   2017");
    Sleep(2500);
    menu();
case 'q':
    exit(0);
    break;
default:
    color(0,14);
    printf("\n\tNie ma takiej opcji!");
    Sleep(1500);
    system("cls");

}
}
}


