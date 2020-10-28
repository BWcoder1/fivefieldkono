#include <iostream>
#include "kwadracik.h"
//#include "Player.h"
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>


    kwadracik plansza[5][5];

    bool makeMove(int x, int y, int dir, int player) {
        if (plansza[x][y].isTaken() == player) {
            switch (dir)
            {

                //w dol i w lewo
            case 0:
                if (x - 1 < 0 || y + 1 > 4) {
                    return false;
                }
                if (plansza[x - 1][y + 1].isTaken() == 0) {
                    plansza[x][y].setTaken(0);
                    plansza[x - 1][y + 1].setTaken(player);
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            case 1:

                if (x + 1 > 4 || y + 1 > 4) {
                    return false;
                }
                if (plansza[x + 1][y + 1].isTaken() == 0) {
                    plansza[x][y].setTaken(0);
                    plansza[x + 1][y + 1].setTaken(player);
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            case 2:
                if (x - 1 < 0 || y - 1 < 0) {
                    return false;
                }
                if (plansza[x - 1][y - 1].isTaken() == 0) {
                    plansza[x][y].setTaken(0);
                    plansza[x - 1][y - 1].setTaken(player);
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            case 3:

                if (x + 1 > 4 || y - 1 < 0) {
                    return false;
                }
                if (plansza[x + 1][y - 1].isTaken() == 0) {
                    plansza[x][y].setTaken(0);
                    plansza[x + 1][y - 1].setTaken(player);
                    return true;
                }
                else
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }
        else
        {
            return false;
        }

    }

    void ruch(int player,std::vector<int> &possMoves) {
        bool moznadalje = true;
        bool okej = false;
        bool temporary;
        bool czydasiecokolwiek = true;
        int index = 0;
        int asd = 0;
        int x, y, dir;
        int zakazane[4];
        std::vector<std::string> tablica;
        std::string temp;
        char liczba;
        // szukamy wszyskich pionkow gracza i zapisujemy ich pozycje
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (plansza[i][j].isTaken() == player) {
                    temp = std::to_string(i) + std::to_string(j);
                    tablica.push_back(temp);

                }
            }
        }

        if (player == 2) {
            int ruchy = 0;
            int suma = 0;
            int srednia = 0;
            for (int d = 0; d < tablica.size(); d++) {
                temp = tablica[d];
                liczba = temp[0];
                int a = (int)liczba - 48;
                liczba = temp[1];
                int b = (int)liczba - 48;
                if (!(a - 1 < 0 || b + 1 > 4)) {
                    if (plansza[a - 1][b + 1].isTaken() == 0) {
                        ruchy++;
                    }
                }
                if (!(a + 1 > 4 || b + 1 > 4)) {
                    if (plansza[a + 1][b + 1].isTaken() == 0) {
                        ruchy++;
                    }
                }
                if (!(a - 1 < 0 || b - 1 < 0)) {
                    if (plansza[a - 1][b - 1].isTaken() == 0) {
                        ruchy++;
                    }
                }
                if (!(a + 1 > 4 || b - 1 < 0)) {
                    if (plansza[a + 1][b - 1].isTaken() == 0) {
                        ruchy++;
                    }
                }
                // std::cout << "Mozliwe ruchy pionka nr " << d << ": " << ruchy << std::endl;


            }
            //std::cout << "Mozliwe ruchy gracza 2 w tej rundzie: " << ruchy << std::endl;
            possMoves.push_back(ruchy);
            ruchy = 0;
        }



        if (player == 1) {
            for (int i = 0; i < tablica.size(); i++) {
                if (tablica[i] == "00") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "01") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "02") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "03") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "04") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "10") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "14") {
                    tablica[i] = "block";
                }
            }
        }
        if (player == 2) {
            for (int i = 0; i < tablica.size(); i++) {
                if (tablica[i] == "40") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "41") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "42") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "43") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "44") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "30") {
                    tablica[i] = "block";
                }
                else if (tablica[i] == "34") {
                    tablica[i] = "block";
                }
            }
        }

        for (int i = 0; i < tablica.size(); i++) {
            if (tablica[i] == "block") {
                tablica.erase(tablica.begin() + i);
            }
        }
        for (int i = 0; i < tablica.size(); i++) {
            if (tablica[i] == "block") {
                tablica.erase(tablica.begin() + i);
            }
        }
        for (int i = 0; i < tablica.size(); i++) {
            if (tablica[i] == "block") {
                tablica.erase(tablica.begin() + i);
            }
        }
        for (int i = 0; i < tablica.size(); i++) {
            if (tablica[i] == "block") {
                tablica.erase(tablica.begin() + i);
            }
        }
        for (int i = 0; i < tablica.size(); i++) {
            if (tablica[i] == "block") {
                tablica.erase(tablica.begin() + i);
            }
        }
        for (int i = 0; i < tablica.size(); i++) {
            if (tablica[i] == "block") {
                tablica.erase(tablica.begin() + i);
            }
        }

        int ruch = 0;
        // wybieramy losowy z znalezionych pionkow
        while (czydasiecokolwiek) {
            
            index = rand() % (tablica.size());
            temp = tablica[index];
            liczba = temp[0];
            x = (int)liczba - 48;
            liczba = temp[1];
            y = (int)liczba - 48;

            if (asd == 4 && ruch == tablica.size()) {
                //std::cout << "nie ma ruchow" << std::endl;
                break;
            }

            asd = 0;
            temporary = false;

            for (int i = 0; i < 4; i++)
            {
                zakazane[i] = 5;

            }

            //losujemy kierunek w ktorym sie ruszymy
            while (true) {

                moznadalje = false;
                while (!moznadalje) {
                    dir = rand() % 4;
                    okej = false;
                    for (int i = 0; i < 4; i++)
                    {
                        if (dir == zakazane[i]) {
                            okej = true;
                        }
                    }
                    if (!okej) {
                        break;
                    } 
                    //moznadalje = std::find(std::begin(zakazane), std::end(zakazane), dir);
                }
                if (makeMove(x, y, dir, player))
                {
                    czydasiecokolwiek = false;
                    break;
                }
                else
                {
                    zakazane[asd] = dir;
                    asd++;
                    if (asd == 4) {
                        ruch++;
                        break;
                    }

                }

            }
        }
        // jeslesmy tu jesli udalo sie zrobic jakis ruch
    }

    void randomGenerate() {
        int x, y;
        for (int i = 0; i < 7; i++) {
            while (true) {
                x = rand() % 5;
                y = rand() % 5;
                if (plansza[x][y].isTaken() == 0) {
                    plansza[x][y].setTaken(1);
                    break;
                }

            }
            while (true) {
                x = rand() % 5;
                y = rand() % 5;
                if (plansza[x][y].isTaken() == 0) {
                    plansza[x][y].setTaken(2);
                    break;
                }

            }
        }
    }

    void showBoard() {

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                std::cout << plansza[i][j].isTaken();
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void resetBoard() {
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                plansza[a][b].setTaken(0);
            }
        }
    }

    void setBoard() {
        for (int x = 0; x < 5; x++){
            plansza[4][x].setTaken(1);
        }
        plansza[3][0].setTaken(1);
        plansza[3][4].setTaken(1);

        for (int x = 0; x < 5; x++){
            plansza[0][x].setTaken(2);
        }
        plansza[1][0].setTaken(2);
        plansza[1][4].setTaken(2);
            
    }

    bool checkBoard() {
        
        int white1 = 0;
        int white2 = 0;
        int black1 = 0;
        int black2 = 0;

        // na gorze zaczyna player 2
        for (int i = 0; i < 5; i++) {
            if (i == 0 || i == 2 || i == 4) {
                for (int j = 0; j < 5; j++) {
                    if (j == 0 || j == 2 || j == 4) {
                        if (plansza[i][j].isTaken() == 2) {
                            white2++;
                        }
                        else if (plansza[i][j].isTaken() == 1) {
                            white1++;
                        }
                    }
                }
            }
            else if (i == 1 || i == 3) {
                for (int j = 0; j < 5; j++) {
                    if (j == 1 || j == 3) {
                        if (plansza[i][j].isTaken() == 2) {
                            white2++;
                        }
                        else if (plansza[i][j].isTaken() == 1) {
                            white1++;
                        }
                    }
                }
            }
         
            if (i == 0 || i == 2 || i == 4) {
                for (int j = 0; j < 5; j++) {
                    if (j == 1 || j == 3 ) {
                        if (plansza[i][j].isTaken() == 2) {
                            black2++;
                        }
                        else if (plansza[i][j].isTaken() == 1) {
                            black1++;
                        }
                    }
                }
            }
            else if (i == 1 || i == 3) {
                for (int j = 0; j < 5; j++) {
                    if (j == 0 || j == 2 || j == 4) {
                        if (plansza[i][j].isTaken() == 2) {
                            black2++;
                        }
                        else if (plansza[i][j].isTaken() == 1) {
                            black1++;
                        }
                    }
                }
            }
        }
        /*std::cout << "Pionki gracza 2 na bialych: " << white2 << std::endl;
        std::cout << "Pionki gracza 2 na czarnych: " << black2 << std::endl;

        std::cout << "Pionki gracza 1 na bialych: " << white1 << std::endl;
        std::cout << "Pionki gracza 1 na czarnych: " << black1 << std::endl;*/

        if (!(black1 == 4)) {
            return false;
        }
        if (!(black2 == 4)) {
            return false;
        }

        return true;
    }

    bool checkwin(int player) {
        bool finish;
        if (player == 2) {
            for (int u = 0; u < 5; u++) {
                if (plansza[4][u].isTaken() == player) {
                    finish = true;
                }
                else
                {
                    finish = false;
                    break;
                }
            }

            if (finish) {
                if (plansza[3][0].isTaken() == player) {
                    if (plansza[3][4].isTaken() == player) {
                        return true;

                    }
                }
            }
        }
        else if (player == 1) {
            for (int u = 0; u < 5; u++) {
                if (plansza[0][u].isTaken() == player) {
                    finish = true;
                }
                else
                {
                    finish = false;
                    break;
                }
            }

            if (finish) {
                if (plansza[1][0].isTaken() == player) {
                    if (plansza[1][4].isTaken() == player) {
                        return true;

                    }
                }
            }
        }

        

        return false;
    }

    int task2(int ilosc) {
        
        int properBoard = 0; 

        srand(time(NULL));

        for (int i = 0; i < ilosc; i++) {
            resetBoard();
            randomGenerate();
            //showBoard();
            if (checkBoard()) {
                properBoard++;
            }
            
        }
        std::cout << "Ilosc poprawnych plansz na " << ilosc << " losowan: " << properBoard << std::endl;
        return properBoard;
    }

    void task1(int ilosc)
    {
        int glebokosc = 0;
        int suma = 0;
        int counter = 1;
        bool loop = false;
        std::vector <int> possMoves;
        while (!loop) {
            //std::cout << "SYMULACJA NR: " << counter << std::endl;
            bool gamefinished = false;
            int tura = 0;
            int x, y, dir;
            bool finish, canMakemove;
            int depth = 0;

            resetBoard();
            setBoard();
            while (!gamefinished) {

                depth++;

                ruch(1,possMoves);
                gamefinished = checkwin(1);
                if (gamefinished) {
                    break;
                }


                ruch(2,possMoves);
                gamefinished = checkwin(2);
                if (gamefinished) {
                    break;
                }

            }


            int buff = 0;
            for (int i = 0; i < possMoves.size(); i++) {
                buff += possMoves[i];
            }

            int srednia = buff / possMoves.size();
            possMoves.clear();
            counter++;
            glebokosc += depth;
            suma += srednia;

        if (counter == ilosc+1) {
            break;
        }
    }

     suma = suma / ilosc;
     glebokosc = glebokosc / ilosc;
     std::cout << "=====================================" << std::endl;
     std::cout << "=====================================" << std::endl;
     std::cout << "ZAKONCZONO " << ilosc << " SYMULACJI"<<std::endl;
     std::cout << "ZADANIE 1" << std::endl;
     std::cout << "Sredni branching factor: " << suma << std::endl;
     std::cout << "Srednia depth: " << glebokosc << std::endl;
     std::cout << "Zlozonosc gry: " << pow(suma, glebokosc) << std::endl;
     std::cout << "=====================================" << std::endl;
     


    }

    int main() {

        srand(time(NULL));

        int gen = 1;
        int collector = 0;
        task1(1000);
        std::cout << "ZADANIE 2" << std::endl;
        std::cout << "Kombinacje mozliwych stanow planszy: 25^3" << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "GENERACJA NR " << gen << std::endl;
            gen++;
            collector += task2(1000);
        }
        int buff = collector / 10;
        std::cout << "Srednia ilosc poprawnych plansz: " << buff << std::endl;
        std::cout << "Zlozonosc gry: " << pow(25, 3) * buff << std::endl;
        std::cout << "=====================================" << std::endl;
        std::cout << "=====================================" << std::endl;
    }
