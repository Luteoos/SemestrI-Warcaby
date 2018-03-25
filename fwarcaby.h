
void color(int , int );
int killmovepossible(int , int , int , int );//sprawdza czy po zbiciu mozliwy ruch
int killmove(int ,int );//zwraca 1 jesli mozna dalej zbijac!, 0 dla braku mozliwosci
void kill(int , int ,int , int );//zabija pionek, daje dzwiek!
int moveoptions(int ,int );//sprawdza czy pionek nie jest blokowany przez swoje pionki dalej DZIAlA?
void nextturn();//poteierdz zmiane int killmovepossible(int x, int y, int xr, int yr)//sprawdza czy po zbiciu mozliwy ruch
void movechange(int, int , int , int );//przestawia pionek
int owned(int ,int );//sprawdzenie czy pionek jest twoj, lpionka ustawiona na indeks struktury pionka danego gracza, sprawdza damke, zwraca 2 dla damy
int movepossible(int ,int ,int ,int );//sprawdza czy wspolrzedne ruchu maja sens, zwraca 0 gdy nie zbijamy pionka mozliwego do zbicia

int move();//sterowanie ruchami na planszy, ogarnia wszystkie funkcje
void win();//wyswietla zwyciestwo, sprawdza czy jest
void remis();//yswietla jesli tury bez zbicia sa rowne 40!
void create();//tworzy tabice do gry i uzupelnia struct pionkow
void show();//wyswietla "ekran gry" plansza pionki, czyja tura
void menu();//wyswietla menu i uruchaima gre(zapetlone w case1)
void protip();// wyswietla podpowiedzi na temat gry
