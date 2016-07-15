/***********************************************************
********************WARFARE VERSION 1.00.0******************
********************by Kai S. and Laura K.******************
***********THIS GAME WAS BUILT FOR A SCIENCE PROJECT********
**************AT Duale Hochschule Baden Würtemberg**********
********************ALL RIGHTS RESERVED (C)*****************
***********************************************************/

#include "stdafx.h"
#include "conio.h"
#include "windows.h"
#include "time.h"
#include "string.h"
///Fehler 4996: fprintf_s Funktion soll nicht genutzt werden, da ein evtl. Fehler mit NULL in einer
///if Abfrage abgefangen wird. 
///Außerdem erfordert _s die Definition der Zeichenlänge. Diese ist dem Programm jedoch nicht bekannt
///wenn es neu gestartet wird und aus der txt-Datei ausliest.
#pragma warning(disable:4996)

//Init Grafik-Array "WARFARE"
int gfx[300] = {
	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	1,	1,	0,	0,	0,	1,	0,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,
	0,	0,	0,	0,	1,	0,	0,	0,	1,	0,	1,	0,	1,	0,	1,	0,	0,	0,	1,	0,
	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	1,	1,	1,	0,	1,	0,	0,	1,	1,	0,
	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	1,	0,	1,	0,	1,	0,	1,	0,	0,	0,
	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	1,	0,	1,	0,	1,	0,	0,	1,	1,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	1,	1,	1,	1,	0,	1,	1,	1,	0,	1,	1,	1,	1,	1,	0,	1,	1,	1,
	0,	0,	1,	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	0,	0,	1,	0,	1,	0,	0,
	0,	0,	1,	1,	1,	0,	0,	1,	1,	1,	0,	1,	0,	0,	1,	1,	0,	1,	1,	0,
	0,	0,	1,	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	1,	0,	0,	0,	1,	0,	0,
	0,	0,	1,	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	0,	1,	1,	0,	1,	1,	1,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1
};

//Init Grafik-Array Top 10 Ranking
int gfx_top[288] = {
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	1,	1,	1,	0,	1,	1,	1,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	1,	0,	1,	1,	1,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	1,	1,	0,	1,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0
};

//Init Spielfeld
unsigned char feld[21][31];
int y, x = 0;
int mov_down = 3; ///Welcome Nachricht startet bei y=3 und wird hochgezählt um abwärts zu laufen
int lauf = 0;
char name[10];
int level = 1;
int gegner_speed;

//Init Punktezahl-System
int ps_score[10];
char ps_puffer_name[100] = { 0 };
int ps_index = 0;
int ps_i = 0;
int ps_compare;
int ps_compare_b;
int ps_j, ps_k;
int set_score = 0;
int name_idx;
//Init Steuerung Player
int p_cursor_x; ///Start Position X-Achse

//Game Modus :: 0=Wake up and type your name :: 1=main menu :: 2=initialisiere Spielfeld :: 3=Game Modus starten
//			 :: 4=Gewonnen Modus			 :: 5=Verloren Modus :: 6=Top 10
int game_mode = 0;
int score; ///Script für score schreiben
int quit = 0;

//Init Gegner
int random_zahlen[10];
int scroll_down = 2; ///Start Position Y-Achse
int cycles = 0;
int gegner_anzahl;

//Init Shot
int shot = 0;
int mov_shot = 18;
int anzahl_shot;

//Init Funktionen
void read_keyboard(int taste);
void game(void);
void won(void);
void lose(void);
void wake_up(void);
void init_game(void);
void main_menu(void);
void stats(void);
void write_data(void);
void read_data(void);
void handle_stats(void);
void change_name(void);

int main()
{
	//Lese Top 10 aus externer Datei sofern vorhanden
	//Ansonsten wird Datei vorkonfiguriert erstellt.
	read_data();

	while (quit == 0) {
		switch (game_mode) {
		case 0: wake_up();
			break;
		case 1: main_menu();
			break;
		case 2: init_game();
			break;
		case 3: game();
			break;
		case 4: won();
			break;
		case 5: lose();
			break;
		case 6: stats();
			break;
		}

		//Einlesen von Taste, falls Tasteneingabe nicht erfolgt -> Leerzeichen übergeben
		if (_kbhit()) {
			read_keyboard(_getch());
			fflush(stdin);
		}
		else {
			read_keyboard(' ');
		}


		//Warte 5ms, damit Bild nicht so oft neu geladen wird.
		Sleep(5);
	}
	return 0;
}

void wake_up(void) {
	system("cls");
	int i = 0;

	for (y = 1; y <= 15; y++) {
		for (x = 1; x <= 20; x++) {
			i++;
			system("color 0F");
			if (gfx[i] == 1) {

				feld[y][x] = 219;
			}
			else {
				feld[y][x] = ' ';
			}

			printf("%c", feld[y][x]);
		}
		printf("\n");
	}
	system("color 0C");
	printf("\nLET THE FIGHT BEGIN \n    ver. 1.00.0 \n  by KAI n' LAURA\n");
	printf("\n\nType your name\n\n >> ");
	scanf_s("%s", &name, 10);
	game_mode = 1;
}

void main_menu(void) {
	
	int i = 0;
	char tmp_print[700];
	int tmp_count = 0;
	system("color 0C");
	for (y = 1; y <= 15; y++) {
		for (x = 1; x <= 20; x++) {
			i++;
			if (gfx[i] == 1) {
				feld[y][x] = 219;
			}
			else {
				feld[y][x] = ' ';
			}

			tmp_print[tmp_count] = feld[y][x];
			tmp_count++;
		}
		tmp_print[tmp_count] = '\n';
		tmp_count++;
		if (tmp_count == 620) tmp_count = 0;
	}
	system("cls");
	printf("%s", tmp_print);
	printf("> %s choose your task\n", name);
	printf("(1) for fight\n");
	printf("(2) for stats\n");
	printf("(3) for quit");
	printf("\n\n--------------------\n<-  Move left\n->  Move right\nm   Shot");
	Sleep(100);
}

void init_game(void) {
	//Bereite Spielbrett vor

	switch (level) {

		//LEVEL 1
	case 1:
		score = 0;
		p_cursor_x = 15;
		anzahl_shot = 0;
		gegner_anzahl = 0;
		cycles = 0;

		for (y = 1; y < 21; y++) {
			for (x = 1; x < 31; x++) {
				if (x == 1 || x == 30 || y == 1 || y == 20) {
					feld[y][x] = 219;
				}
				else if (x > 4 && x < 27 && y > 2 && y < 15 && (x % 2) == 0 && (y % 2) == 0) {
					//Gegner einfügen
					feld[y][x] = 2;
					gegner_anzahl++;
				}
				else if (x == p_cursor_x && y == 19) {
					//Player einfügen
					feld[y][x] = 30;
				}
				else {
					feld[y][x] = ' ';
				}
			}
		}
		game_mode = 3;
		gegner_speed = 8;
		break;
		//LEVEL 2
	case 2:
		p_cursor_x = 15;
		anzahl_shot = 0;
		gegner_anzahl = 0;
		cycles = 0;

		for (y = 1; y < 21; y++) {
			for (x = 1; x < 31; x++) {
				if (x == 1 || x == 30 || y == 1 || y == 20) {
					feld[y][x] = 219;
				}
				else if (x > 4 && x < 27 && y > 2 && y < 18 && (x % 2) == 0 && (y % 2) == 0) {
					//Gegner einfügen
					feld[y][x] = 2;
					gegner_anzahl++;
				}
				else if (x == p_cursor_x && y == 19) {
					//Player einfügen
					feld[y][x] = 30;
				}
				else {
					feld[y][x] = ' ';
				}
			}
		}
		game_mode = 3;
		gegner_speed = 3;
		break;
	}


}

void game(void) {
	char tmp_print[700];
	int tmp_count = 0;
	int enemy_sht;
	system("cls");
	enemy_sht = 0;
	for (y = 1; y < 21; y++) {
		for (x = 1; x < 31; x++) {
			//Spielfeld als String übergeben
			tmp_print[tmp_count] = feld[y][x];
			tmp_count++;
			//Dann Spielfeld manipulieren...
			//Player bewegen
			if (feld[y][x] == 30 && p_cursor_x != x) {
				feld[19][p_cursor_x] = 30;
				feld[y][x] = ' ';
			}
			else if (feld[y][x] == 178 && enemy_sht == 1) {
				feld[y+1][x] = 254;
				enemy_sht = 0;
			}
			else if (feld[y][x] == 254) {
				feld[y+1][x] = 254;
				feld[y][x] = ' ';
			}
			//Schuss abfeuern
			else if (x == p_cursor_x && y == 18 && shot == 1) {
				feld[y][x] = '^';
				anzahl_shot++;
				shot = 0;
			}
			//Schuss nach oben bewegen
			else if (feld[y][x] == '^' && feld[y - 1][x] == ' ') {
				feld[y][x] = ' ';
				feld[y - 1][x] = '^';
			}
			//Wenn Gegner getroffen, mache ihn zu + -> Wegen Simulation einer Explosion
			else if (feld[y][x] == '^' && feld[y - 1][x] == 2 || feld[y][x] == '^' && feld[y - 1][x] == '+') {
				feld[y - 1][x] = '+';
				feld[y][x] = ' ';
				--gegner_anzahl;
			}
			//+ klebt fest, also lösche es weg
			else if (feld[y][x] == '+') {
				feld[y][x] = ' ';
				score = (score + (10 * (100 / gegner_anzahl)) * (100 / anzahl_shot));

			}
			//^ klebt am oberen Rand, also lösche es weg
			else if (feld[y][x] == '^') {
				feld[y][x] = ' ';
			}
			//Bewege Gegner eine Zeile tiefer alle n Zyklen -> n wird durch Gegner_speed definiert
			else if (feld[y][x] == 2 && feld[y + 1][x] == ' ' && cycles == gegner_speed) {
				feld[y + 1][x] = 2;
				feld[y][x] = ' ';
				cycles = 0;
				//Wenn Gegner Zeile 19 erreicht ist das Spiel verloren
				if (feld[19][x] == 2) {
					game_mode = 5;
					level = 1;
				}
			}

		}
		//printf("\n");		
		tmp_print[tmp_count] = '\n';
		tmp_count++;
		if (tmp_count == 620) tmp_count = 0;
	}

	printf("%s", tmp_print);
	printf("\n>> PLAYER: %s \n>> SCORE: %d \n>> SHOTS: %4.d   >> LEVEL: %d", name, score, anzahl_shot, level);
	cycles++;

	//Wenn Gegner alle getötet in Level 1, sprung in Level 2
	if (gegner_anzahl == 0 && level == 1) {
		game_mode = 2;
		level = 2;
		if (score < 8500) {
			score = score + 1000;
		}
		else {
			score = score + 3000;
		}
	}
	//Wenn Level 2 und alle Gegner getötet, wechsele in Win Modus
	else if (gegner_anzahl == 1 && level == 2) {
		game_mode = 4;
		level = 1;
		if (score < 19000) {
			score = score + 1000;
		}
		else {
			score = score + 6000;
		}
	}
	Sleep(10);

}

void won(void) {
	system("cls");
	for (y = 1; y <= 5; y++) {
		for (x = 1; x <= 30; x++) {
			feld[y][x] = '*';
			printf("%c", feld[y][x]);
		}
		printf("\n");
	}

	printf("       GOOD JOB SOLDIER\n\n");
	printf("       YOUR SCORE %d", score);
	Sleep(4000);
	game_mode = 6;
	//Set_score sorgt dafür, dass errungener Score nur 
	//angezeigt wird wenn man aus dem Game Modus in stats kommt
	set_score = 1;
	handle_stats();
}

void lose(void) {
	system("cls");
	for (y = 1; y <= 5; y++) {
		for (x = 1; x <= 30; x++) {
			feld[y][x] = '*';
			printf("%c", feld[y][x]);
		}
		printf("\n");
	}

	printf("       THE WAR IS LOST\n\n");
	printf("    DO IT NEXT TIME BETTER\n\n");
	printf("       YOUR SCORE %d", score);
	Sleep(4000);
	game_mode = 6;
	//Set_score sorgt dafür, dass errungener Score nur 
	//angezeigt wird wenn man aus dem Game Modus in stats kommt
	set_score = 1;
	handle_stats();
}

void handle_stats(void) {
	//Sortiere Array erneut, falls ein neuer Score vor Neustart vom Spiel dazu kam
	for (ps_j = 0; ps_j <= 10; ps_j++) {
		ps_compare = ps_score[ps_j];
		for (ps_k = 0; ps_k <= 10; ps_k++) {
			if (ps_compare > ps_score[ps_k]) {
				ps_score[ps_j] = ps_score[ps_k];
				ps_score[ps_k] = ps_compare;
				ps_compare = ps_score[ps_j];
			}
		}
	}
	//Überprüfe ob neuer Score größer ist als bisher vorhandene im Array. Wenn ja, dann schreibe ihn ins Array
	//und verschiebe andere weiter nach unten
	for (ps_j = 0; ps_j <= 10; ps_j++) {
		if (score > ps_score[ps_j]) {
			name_idx = ps_j;
			ps_compare = ps_score[ps_j];
			ps_score[ps_j] = score;
			for (ps_k = ps_j + 1; ps_k <= 10; ps_k++) {
				ps_compare_b = ps_score[ps_k];
				ps_score[ps_k] = ps_compare;
				ps_compare = ps_compare_b;
			}
			ps_j = 11; //Beende äußere For Schleife wenn if Bedingung abgearbeitet
		}
	}
	change_name();
	write_data();
}

void change_name(void) {
	//name_idx übergibt den index an der Stelle im Array ps_puffer_name wo der Player Name
	//eingefügt werden muss. Die anderen Namen werden eine Zeile tiefer bewegt.

	int a, b, c = 0;
	int search_idx = 0;
	char tmp_string[100] = { 0 };
	char tmp_string_b[100] = { 0 };
	char tmp_string_c[100] = { 0 };
	//Puffer String in temporären String übergeben
	strcpy(tmp_string, ps_puffer_name);
	//Falls der erste Platz erzielt wurde tritt der Fall ein wo name_idx = 0 ist
	//daher wird nachfolgend einfach der Name und der temporäre String in
	//den Puffer String geschrieben
	if (name_idx == 0) {
		strcpy(ps_puffer_name, name);
		strcat(ps_puffer_name, " ");
		strcat(ps_puffer_name, tmp_string);
	}
	//Tritt der Fall ein, dass ein Platz unter 1 erzielt wurde,
	//werden durch suchen der leerzeichen im String der Index
	//verglichen und wenn dieser übereinstimmt wird der
	//bis zum Leerezeichen durchsuchte String in Tmp_string_b geschriben
	//und der nachfolgende in tmp_string_c. Danach werden alle drei Teile wieder
	//miteinander verklebt...
	else {
		for (a = 0; a <= 100; a++) {
			tmp_string_b[a] = ps_puffer_name[a];
			if (ps_puffer_name[a] == ' ') {
				search_idx++;
				if (search_idx == name_idx) {
					for (b = a + 1; b <= 100; b++) {
						tmp_string_c[c] = ps_puffer_name[b];
						c++;
					}
					c = 0;
					a = 101;
				}
				
			}
		}
		strcat(tmp_string_b, name);
		strcat(tmp_string_b, " ");
		strcat(tmp_string_b, tmp_string_c);
		strcpy(ps_puffer_name, tmp_string_b);
	}

}

void stats(void) {
	//liste Top 10 auf
	system("cls");
	int i = 0;

	for (y = 1; y <= 12; y++) {
		for (x = 1; x <= 24; x++) {
			i++;
			if (gfx_top[i] == 1) {

				feld[y][x] = 219;
			}
			else {
				feld[y][x] = ' ';
			}

			printf("%c", feld[y][x]);
		}
		printf("\n");
	}


	ps_index = 0;
	//Bilde Array mit Score Werten ab
	if (ps_i > 10) ps_i = 0;
	for (ps_i = 0; ps_i <= 9; ps_i++) {
		printf("  >> %2.d :: %11.d  ", ps_i + 1, ps_score[ps_i]);
		for (i = ps_index; i <= 100; i++) {

			if (ps_puffer_name[i] == ' ') {
				ps_index = i + 1;
				i = 110;

			}
			else {
				printf("%c", ps_puffer_name[i]);
			}
		}
		printf("\n");
	}
	if (set_score == 1) {
		printf("\n\n >> YOUR SCORE %.9d <<", score);
		set_score = 0;
	}

	Sleep(4000);
	game_mode = 1;

}

void read_data(void) {
	//Lese Spielergebnisse aus Datei "stats.txt" und übertrage sie ins ps_score und ps_puffer_name Array
	FILE *datei;

	datei = fopen("stats.txt", "r");

	if (datei == NULL) {
		//Wenn Datei nicht vorhanden, wird das Format der Datei vorab schon mal geschrieben
		//und das Score Array bzw. Name Array mit Werten gefüllt.
		datei = fopen("stats.txt", "w");
		ps_index = 0;
		for (ps_i = 0; ps_i <= 9; ps_i++) {
			fprintf(datei, "Score: %9.d  ", 1);
			ps_score[ps_i] = 1;
			fprintf(datei, "%c", '*');
			for (int i = ps_index; i <= 20; i++) {
				ps_puffer_name[i] = '*';
				ps_puffer_name[i + 1] = ' ';
				ps_index = i + 2;
				i = 22;
			}
			fprintf(datei, " ");
			fprintf(datei, "\n");
		}
		fclose(datei);
	}
	else {
		//Lese Werte
		ps_index = 0;
		for (ps_i = 0; ps_i <= 9; ps_i++) {
			fscanf(datei, "Score: %d  ", &ps_score[ps_i]);
			for (int i = ps_index; i <= 100; i++) {
				fscanf(datei, "%c", &ps_puffer_name[i]);
				if (ps_puffer_name[i] == ' ') {
					ps_puffer_name[i] = ' ';
					ps_index = i + 1;
					i = 110;
				}
			}
			fprintf(datei, "\n");
		}

		fclose(datei);
	}


	//Sortiere Array der Größe nach Absteigend
	for (ps_j = 0; ps_j <= 10; ps_j++) {
		ps_compare = ps_score[ps_j];
		for (ps_k = 0; ps_k <= 10; ps_k++) {
			if (ps_compare > ps_score[ps_k]) {
				ps_score[ps_j] = ps_score[ps_k];
				ps_score[ps_k] = ps_compare;
				ps_compare = ps_score[ps_j];
			}
		}
	}
}

void write_data(void) {
	//Schreibe Spielergebnisse aus ps_score array in Datei "stats.txt"
	FILE *datei;

	datei = fopen("stats.txt", "w");

	if (datei == NULL) {
		//Wird Datei während Spiel gelöscht, 
		//wird einfach eine Neue erstellt, da die Daten temporär im Array vorliegen
	}
	else {
		//Schreibe Werte
		ps_index = 0;
		for (ps_i = 0; ps_i <= 9; ps_i++) {
			fprintf(datei, "Score: %9.d  ", ps_score[ps_i]);
			for (int i = ps_index; i <= 100; i++) {
				if (ps_puffer_name[i] == ' ') {
					ps_index = i + 1;
					i = 110;
				}
				else {
					fprintf(datei, "%c", ps_puffer_name[i]);
				}
			}
			fprintf(datei, " ");
			fprintf(datei, "\n");
		}


		fclose(datei);
	}
}

void read_keyboard(int taste) {
	switch (taste) {
	case 49: game_mode = 2;		//Erkenne Taste: "1" und gehe zu Init_game()
		break;
	case 50: game_mode = 6;		//Erkenne Taste: "2" und gehe zu stats()
		break;
	case 51: quit = 1;			//Erkenne Taste: "3" und beende Programm
		break;
	case 77: p_cursor_x++;		//Erkenne Taste: "Pfeil rechts" und bewege Cursor Rechts
		if (p_cursor_x > 29) p_cursor_x = 2;
		break;
	case 75: p_cursor_x--;		//Erkenne Taste: "Pfeil links" und bewege Cursor Links
		if (p_cursor_x < 2) p_cursor_x = 29;
		break;
	case 109: shot = 1;			//Erkenne Taste: "M" und aktiviere Schuss
		break;
	default:
		break;
	}

}
//PROGRAMM ENDEEEE :-)
