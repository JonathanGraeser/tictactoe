#include <stdio.h>

// Feld erstellen
char field[3][3] = {
        {' ', ' ',' '},
        {' ', ' ',' '},
        {' ', ' ',' '}
};

//Feld auf die Konsole ausgeben
void printField() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void playerTurn(char player) {
    int x, y;

    //Eingabe wo man PLatzieren möchte
    printf("Player %c enter coordinats: ", player);
    scanf("%d %d", &x, &y);

    x--; y--;

    //Checken ob Koordinaten existieren oder schon belegt ist oder nicht
    if (x < 0 || x > 2 || y > 2 || y < 0) {
        printf("Nicht zulässige Koordinaten!\n");
        playerTurn(player);
    } else if(field[x][y] != ' ') {
        printf("PLatz schon belegt!\n");
        playerTurn(player);
    } else {
        field[x][y] = player;
    }
}

//Nach Win checken
char checkWin() {
    for (int i = 0; i < 3; ++i) {
        //Horizontal check
        if(field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != ' '){
            return field[i][0];
        }
        //Vertikal Check
        if(field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != ' '){
            return field[0][i];
        }
    }
    //Parallel check 1
    if(field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != ' '){
        return field[0][0];
    }
    //Parallel check 2
    if(field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] != ' '){
        return field[0][2];
    }
    return ' ';
}



int main() {
     //Spiel Start
    int turn = 0;
    int run = 1;
    printField();


    //Spiel loop startet hier
    while(run = 1) {

        //Player1 darf setzen
        playerTurn('X');
        printField();
        turn++;

        //Check Player1 gewinnt
        if (checkWin() == 'X') {
            printf("Player X gewinnt!\n");
            run = 0;
            break;
        }

        //Schauen ob ein Unentschieden ist
        if(turn == 9) {
            printf("Unentschieden!\n");
            break;
        }

        //Player2 darf setzen
        playerTurn('O');
        printField();
        turn++;

        //Check Player2 gewinnt
        if (checkWin() == 'O') {
            printf("Player O gewinnt!\n");
            run = 0;
            break;
        }

        //Schauen ob ein Unterschied ist
        if(turn == 9) {
            printf("Unentschieden!\n");
            break;
        }

    }

    return 0;
}

//Noch zu machen:
//check nach niemand hat gewonnen