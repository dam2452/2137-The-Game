#include <iostream>
#include <windows.h>
#include<cstdlib>
#include<ctime>
#include <string>
#include <fstream>

#define NULL 7777777
#define NULLvalue 7777779


bool continueGame=true;
bool showGame=false;
bool gameIsOver=false;
bool bestScoreFlag=false;

int goodAnswer=1;
int bestScoreNumber=0;
int scoreM=0;
int timeLimit=60;
int gameTime=60;

int gameMainNumber=1069,gameFirstSign=1,gameFirstNumber=10,gameSecondSign=2 ,gameSecondNumber=20;

int Unit(int number)
{
    return number%10;
}
int Tens(int number)
{
    if(number<10) return NULL;
    return ((number-(number%10))%100)/10;
}
int Hundreds(int number)
{
    if(number<100) return NULL;
    return (((number-(number%100)))/100)%10;
}
int Thousands(int number)
{
    if(number<1000) return NULL;
    return (number-(number%1000))/1000;
}

int UnitForSign(int number)
{
    return number%10;
}
int TensForSign(int number)
{
    if(number<10) return NULLvalue;
    return ((number-(number%10))%100)/10;
}
int HundredsForSign(int number)
{
    if(number<100) return NULLvalue;
    return (((number-(number%100)))/100)%10;
}
int ThousandsForSign(int number)
{
    if(number<1000) return NULLvalue;
    return (number-(number%1000))/1000;
}

std::string drawSpace(int line)
{
    switch(line)
    {
        case 1:
        {
            return "       ";
            break;
        }
        case 2:
        {
            return "       ";
            break;
        }
        case 3:
        {
            return "       ";
            break;
        }
        case 4:
        {
            return "       ";
            break;
        }
        case 5:
        {
            return "       ";
            break;
        }
        case 6:
        {
            return "       ";
            break;
        }
        case 7:
        {
            return "       ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}

std::string drawScoreAndTime(int line, int time)
{
    switch(line)
    {
        case 1:
        {
            return "Time: "+ std::to_string(time);
            break;
        }
        case 2:
        {
            return "Score: "+ std::to_string(scoreM);
            break;
        }
        case 3:
        {
            return "Best Score: "+std::to_string(bestScoreNumber);
            break;
        }
        case 4:
        {

            return "       ";
            break;
        }
        case 5:
        {
            return "       ";
            break;
        }
        case 6:
        {
            return "       ";
            break;
        }
        case 7:
        {
            return "       ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}


//Symbol1
std::string drawAdd(int line)
{
    switch(line)
    {
        case 1:
        {
            return "       ";
            break;
        }
        case 2:
        {
            return "  ##   ";
            break;
        }
        case 3:
        {
            return "  ##   ";
            break;
        }
        case 4:
        {
            return "###### ";
            break;
        }
        case 5:
        {
            return "  ##   ";
            break;
        }
        case 6:
        {
            return "  ##   ";
            break;
        }
        case 7:
        {
            return "       ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
//Symbol2
std::string drawMinus(int line)
{
    switch(line)
    {
        case 1:
        {
            return "        ";
            break;
        }
        case 2:
        {
            return "        ";
            break;
        }
        case 3:
        {
            return "        ";
            break;
        }
        case 4:
        {
            return "####### ";
            break;
        }
        case 5:
        {
            return "        ";
            break;
        }
        case 6:
        {
            return "        ";
            break;
        }
        case 7:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
//Symbol3
std::string drawMultiply(int line)
{
    switch(line)
    {
        case 1:
        {
            return "##     ## ";
            break;
        }
        case 2:
        {
            return " ##   ##  ";
            break;
        }
        case 3:
        {
            return "  ## ##   ";
            break;
        }
        case 4:
        {
            return "   ###    ";
            break;
        }
        case 5:
        {
            return "  ## ##   ";
            break;
        }
        case 6:
        {
            return " ##   ##  ";
            break;
        }
        case 7:
        {
            return "##     ## ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
//Symbol4
std::string drawDivide(int line)
{
    switch(line)
    {
        case 1:
        {
            return "    ##    ";
            break;
        }
        case 2:
        {
            return "    ##    ";
            break;
        }
        case 3:
        {
            return "          ";
            break;
        }
        case 4:
        {
            return " ######## ";
            break;
        }
        case 5:
        {
            return "          ";
            break;
        }
        case 6:
        {
            return "    ##    ";
            break;
        }
        case 7:
        {
            return "    ##    ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}

//Numbers
std::string drawOne(int line)
{
    switch(line)
    {
        case 1:
        {
            return "   ##   ";
            break;
        }
        case 2:
        {
            return " ####   ";
            break;
        }
        case 3:
        {
            return "   ##   ";
            break;
        }
        case 4:
        {
            return "   ##   ";
            break;
        }
        case 5:
        {
            return "   ##   ";
            break;
        }
        case 6:
        {
            return "   ##   ";
            break;
        }
        case 7:
        {
            return " ###### ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }

    }
}
std::string drawTwo(int line)
{
    switch(line)
    {
        case 1:
        {
            return " #######  ";
            break;
        }
        case 2:
        {
            return "##     ## ";
            break;
        }
        case 3:
        {
            return "       ## ";
            break;
        }
        case 4:
        {
            return " #######  ";
            break;
        }
        case 5:
        {
            return "##        ";
            break;
        }
        case 6:
        {
            return "##        ";
            break;
        }
        case 7:
        {
            return "######### ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawThree(int line)
{
    switch(line)
    {
        case 1:
        {
            return " #######  ";
            break;
        }
        case 2:
        {
            return "##     ## ";
            break;
        }
        case 3:
        {
            return "       ## ";
            break;
        }
        case 4:
        {
            return " #######  ";
            break;
        }
        case 5:
        {
            return "       ## ";
            break;
        }
        case 6:
        {
            return "##     ## ";
            break;
        }
        case 7:
        {
            return " #######  ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawFour(int line)
{
    switch(line)
    {
        case 1:
        {
            return "##        ";
            break;
        }
        case 2:
        {
            return "##    ##  ";
            break;
        }
        case 3:
        {
            return "##    ##  ";
            break;
        }
        case 4:
        {
            return "##    ##  ";
            break;
        }
        case 5:
        {
            return "######### ";
            break;
        }
        case 6:
        {
            return "      ##  ";
            break;
        }
        case 7:
        {
            return "      ##  ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawFive(int line)
{
    switch(line)
    {
        case 1:
        {
            return "######## ";
            break;
        }
        case 2:
        {
            return "##       ";
            break;
        }
        case 3:
        {
            return "##       ";
            break;
        }
        case 4:
        {
            return "#######  ";
            break;
        }
        case 5:
        {
            return "      ## ";
            break;
        }
        case 6:
        {
            return "##    ## ";
            break;
        }
        case 7:
        {
            return " ######  ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawSix(int line)
{
    switch(line)
    {
        case 1:
        {
            return " #######  ";
            break;
        }
        case 2:
        {
            return "##     ## ";
            break;
        }
        case 3:
        {
            return "##        ";
            break;
        }
        case 4:
        {
            return "########  ";
            break;
        }
        case 5:
        {
            return "##     ## ";
            break;
        }
        case 6:
        {
            return "##     ## ";
            break;
        }
        case 7:
        {
            return " #######  ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawSeven(int line)
{
    switch(line)
    {
        case 1:
        {
            return "######## ";
            break;
        }
        case 2:
        {
            return "##    ## ";
            break;
        }
        case 3:
        {
            return "    ##   ";
            break;
        }
        case 4:
        {
            return "   ##    ";
            break;
        }
        case 5:
        {
            return "  ##     ";
            break;
        }
        case 6:
        {
            return "  ##     ";
            break;
        }
        case 7:
        {
            return "  ##     ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawEight(int line)
{
    switch(line)
    {
        case 1:
        {
            return " #######  ";
            break;
        }
        case 2:
        {
            return "##     ## ";
            break;
        }
        case 3:
        {
            return "##     ## ";
            break;
        }
        case 4:
        {
            return " #######  ";
            break;
        }
        case 5:
        {
            return "##     ## ";
            break;
        }
        case 6:
        {
            return "##     ## ";
            break;
        }
        case 7:
        {
            return " #######  ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawNine(int line)
{
    switch(line)
    {
        case 1:
        {
            return " #######  ";
            break;
        }
        case 2:
        {
            return "##     ## ";
            break;
        }
        case 3:
        {
            return "##     ## ";
            break;
        }
        case 4:
        {
            return " ######## ";
            break;
        }
        case 5:
        {
            return "       ## ";
            break;
        }
        case 6:
        {
            return "##     ## ";
            break;
        }
        case 7:
        {
            return " #######  ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}
std::string drawZero(int line)
{
    switch(line)
    {
        case 1:
        {
            return "  #####   ";
            break;
        }
        case 2:
        {
            return " ##   ##  ";
            break;
        }
        case 3:
        {
            return "##     ## ";
            break;
        }
        case 4:
        {
            return "##     ## ";
            break;
        }
        case 5:
        {
            return "##     ## ";
            break;
        }
        case 6:
        {
            return " ##   ##  ";
            break;
        }
        case 7:
        {
            return "  #####   ";
            break;
        }
        case NULL:
        {
            return "          ";
            break;
        }

        case NULLvalue:
        {
            return "";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}

std::string switchNumber(int number,int line)
{
    switch(number)
    {
        case 1:
        {
            return drawOne(line);
            break;
        }
        case 2:
        {
            return drawTwo(line);
            break;
        }
        case 3:
        {
            return drawThree(line);
            break;
        }
        case 4:
        {
            return drawFour(line);
            break;
        }
        case 5:
        {
            return drawFive(line);
            break;
        }
        case 6:
        {
            return drawSix(line);
            break;
        }
        case 7:
        {
            return drawSeven(line);
            break;
        }
        case 8:
        {
            return drawEight(line);
            break;
        }
        case 9:
        {
            return drawNine(line);
            break;
        }
        case 0:
        {
            return drawZero(line);
            break;
        }
        case NULL:
        {
            return drawZero(NULL);
            break;
        }
        case NULLvalue:
        {
            return drawZero(NULLvalue);
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}

std::string switchSign(int signNumber, int line)
{
    switch(signNumber)
    {
        case 1:
        {
            return drawAdd(line);
            break;
        }
        case 2:
        {
            return drawMinus(line);
            break;
        }
        case 3:
        {
            return drawMultiply(line);
            break;
        }
        case 4:
        {
            return drawDivide(line);
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}

int randomNumber(int range)
{
if(range == 0)
    range++;
    return (1 + (rand() % range)) ;
}
int randomNumber(int from, int to )
{
from++;
    return (from + (rand() % to)) ;
}

void drawNumberAndTime(int number)
{
int unit=Unit(number),tens=Tens(number),hundreds=Hundreds(number),thousands=Thousands(number);
if(number<10000 && number>-1) {
    for (int i = 1; i < 8; ++i) {
        std::cout << drawSpace(i) + drawSpace(i) + drawSpace(i) + switchNumber(thousands, i) +
                     switchNumber(hundreds, i) + switchNumber(tens, i) +
                     switchNumber(unit, i) + drawSpace(i) + drawScoreAndTime(i, gameTime) << std::endl;

    }
}
}

void drawOnlyNumber(int number)
{
    int unit=Unit(number),tens=Tens(number),hundreds=Hundreds(number),thousands=Thousands(number);
    if(number<10000 && number>-1) {
        for (int i = 1; i < 8; ++i) {
            std::cout << drawSpace(i)+drawSpace(i)+drawSpace(i)+switchNumber(thousands, i) +
                         switchNumber(hundreds, i) + switchNumber(tens, i) +
                         switchNumber(unit, i)<< std::endl;

        }
    }
}

void drawNumberAndSign(int firstSign, int firstNumber, int secondSign, int secondNumber)
{
    int unit1= UnitForSign(firstNumber),tens1= TensForSign(firstNumber),hundreds1= HundredsForSign(firstNumber),thousands1= ThousandsForSign(
            firstNumber);
    int unit2= UnitForSign(secondNumber),tens2= TensForSign(secondNumber),hundreds2= HundredsForSign(secondNumber),thousands2= ThousandsForSign(
            secondNumber);

    if(firstNumber<10000 && firstNumber>-1 && secondNumber<10000 &&secondNumber>-1) {
        for (int i = 1; i < 8; ++i) {
            std::cout << switchSign(firstSign, i) + switchNumber(thousands1, i) + switchNumber(hundreds1, i) + switchNumber(tens1, i) +
                         switchNumber(unit1, i) + drawSpace(i) + switchSign(secondSign, i) + switchNumber(thousands2, i) + switchNumber(hundreds2, i) + switchNumber(tens2, i) +
                         switchNumber(unit2, i) << std::endl;

        }
    }
}

std::string switchBestScore(int line)
{
    switch(line)
    {
        case 1:
        {
            return "########  ########  ######  ########     ######   ######   #######  ########  ######## ";
            break;
        }
        case 2:
        {
            return "##     ## ##       ##    ##    ##       ##    ## ##    ## ##     ## ##     ## ##       ";
            break;
        }
        case 3:
        {
            return "##     ## ##       ##          ##       ##       ##       ##     ## ##     ## ##       ";
            break;
        }
        case 4:
        {
            return "########  ######    ######     ##        ######  ##       ##     ## ########  ######   ";
            break;
        }
        case 5:
        {
            return "##     ## ##             ##    ##             ## ##       ##     ## ##   ##   ##       ";
            break;
        }
        case 6:
        {
            return "##     ## ##       ##    ##    ##       ##    ## ##    ## ##     ## ##    ##  ##       ";
            break;
        }
        case 7:
        {
            return "########  ########  ######     ##        ######   ######   #######  ##     ## ######## ";
            break;
        }
        case NULL:
        {
            return "        ";
            break;
        }

        default: {
            return "#Error#";
            break;
        }
    }
}

void drawBestScore(int score)
{
     for (int i = 1; i < 8; ++i) {
            std::cout << drawSpace(i)+drawSpace(i)+switchBestScore(i)<< std::endl;

        }
    std::cout << std::endl;
    std::cout << std::endl;
    drawOnlyNumber(bestScoreNumber);
}
void drawIntro()
{
    system("cls");
    std::cout << "                        _______   _____  ________   ________                            \n"
                 "                       /  ___  \\ / __  \\|\\_____  \\ |\\_____  \\                           \n"
                 "                      /__/|_/  /|\\/_|\\  \\|____|\\ /_ \\|___/  /|                          \n"
                 "                      |__|//  / ||/ \\ \\  \\    \\|\\  \\    /  / /                          \n"
                 "                          /  /_/__   \\ \\  \\  __\\_\\  \\  /  / /                           \n"
                 "                         |\\________\\  \\ \\__\\|\\_______\\/__/ /                            \n"
                 "                          \\|_______|   \\|__|\\|_______||__|/                             \n"
                 "                                                                                        \n"
                 "                                                                                        \n"
                 "                                                                                        \n"
                 " _________  ___  ___  _______           ________  ________  _____ ______   _______      \n"
                 "|\\___   ___\\\\  \\|\\  \\|\\  ___ \\         |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\     \n"
                 "\\|___ \\  \\_\\ \\  \\\\\\  \\ \\   __/|        \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|    \n"
                 "     \\ \\  \\ \\ \\   __  \\ \\  \\_|/__       \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__  \n"
                 "      \\ \\  \\ \\ \\  \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \n"
                 "       \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\       \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\\n"
                 "        \\|__|  \\|__|\\|__|\\|_______|        \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|\n"
                 "                                                                                        " << std::endl;
Sleep(3000);
    system("cls");
}
void saveProgress()
{
    std::fstream save;
    save.open("save2137",std::ios::out);
    save << bestScoreNumber << " ";
    save.close();
}
void loadProgress()
{
    std::fstream save;
    save.open("save2137",std::ios::in);
    save >> bestScoreNumber;
    save.close();
}

void drawGameOver()
{
    std::cout<<" ________  ________  _____ ______   _______      \n"
               "|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\     \n"
               "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|    \n"
               " \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__  \n"
               "  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \n"
               "   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\\n"
               "    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|\n"
               "                                                 \n"
               "                                                 \n"
               "                                                 \n"
               " ________  ___      ___ _______   ________       \n"
               "|\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\      \n"
               "\\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\     \n"
               " \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\    \n"
               "  \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\|   \n"
               "   \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\   \n"
               "    \\|_______|\\|__|/       \\|_______|\\|__|\\|__|  \n"
               "                                                 \n"
               "                                                 "<<std::endl;

}
void initializeStart()
{
    gameMainNumber= randomNumber(999, 1000);
    gameFirstSign=1;
    gameSecondSign=2;
    gameFirstNumber=1;
    gameSecondNumber=1;
    scoreM=0;
    gameTime=60;
    timeLimit=60;
}
void bestScore()
{
    system("cls");
    drawBestScore(bestScoreNumber);
    Sleep(3000);
}
void Error()
{
    std::cout<<"#Error#"<<std::endl;
}

void gameOver()
{
    system("cls");
    showGame=false;
    gameIsOver=true;
    if(scoreM > bestScoreNumber)
    {
        bestScoreNumber=scoreM;
        saveProgress();
       bestScoreFlag=true;
    }
    drawGameOver();
    Sleep(3000);

if(bestScoreFlag)
        {
       system("cls");
        bestScore();
        Sleep(3000);
         bestScoreFlag=false;
        }

    system("cls");
    initializeStart();

    showGame=true;
}
void timerCountDown()
{
    if(gameTime > 0)
    {
        gameTime--;
    }
    else if(gameTime <= 0)
    {
        gameOver();
    }

}
void setLessTime()
{
    if(timeLimit > 4)
    {
        timeLimit-=2;
    }

}

void drawGame()
{
    system("cls");
    drawNumberAndTime(gameMainNumber);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    drawNumberAndSign(gameFirstSign, gameFirstNumber, gameSecondSign, gameSecondNumber);
    Sleep(1000);
    timerCountDown();
}

void RandomizeNumber()
{
    gameFirstSign= randomNumber(4);
    gameSecondSign= randomNumber(4);
    goodAnswer= randomNumber(2);
        switch(gameFirstSign)
        {
            case 1: {
                 if(goodAnswer == 1){
                     gameFirstNumber = randomNumber((2137 - gameMainNumber));
                 }
                 else if(goodAnswer == 2) {
                     gameFirstNumber = randomNumber(gameMainNumber);
                 }
                break;
            }
            case 2: {

                if(goodAnswer == 1){
                    gameFirstNumber= randomNumber(gameMainNumber / 2);
                }
                else if(goodAnswer == 2) {
                    gameFirstNumber= randomNumber(gameMainNumber);
                }
                break;
            }
            case 3: {
                if(goodAnswer == 1){
                    gameFirstNumber= randomNumber((2137 / gameMainNumber));
                }
                else if(goodAnswer == 2) {
                   gameFirstNumber= randomNumber(gameMainNumber);
                }

                break;
            }
            case 4: {
                if(goodAnswer == 1){
                    if(gameMainNumber > 5)
                        gameFirstNumber= randomNumber(1, 4);
                    else gameFirstNumber=1;
                }
                else if(goodAnswer == 2) {
                    gameFirstNumber= randomNumber(gameMainNumber);
                }
                break;
            }
            default:
                break;
                Error();
        }

    switch(gameSecondSign)
        {
            case 1: {
                if(goodAnswer == 2){
                    gameSecondNumber = randomNumber((2137 - gameMainNumber));
                }
                else if(goodAnswer == 1) {
                    gameSecondNumber = randomNumber(gameMainNumber);
                }
                break;
            }
            case 2: {
                if(goodAnswer == 2){
                    gameSecondNumber= randomNumber(gameMainNumber / 2);
                }
                else if(goodAnswer == 1) {
                    gameSecondNumber= randomNumber(gameMainNumber);
                }
                break;
            }
            case 3: {
                if(goodAnswer == 2){
                    gameSecondNumber= randomNumber((2137 / gameMainNumber));
                }
                else if(goodAnswer == 1) {
                    gameSecondNumber= randomNumber(gameMainNumber);
                }
                break;
            }
            case 4: {
                if(goodAnswer == 2){
                     if(gameMainNumber > 5)
                         gameSecondNumber= randomNumber(1, 4);
                     else
                         gameSecondNumber=1;
                }
                else if(goodAnswer == 1) {
                    gameSecondNumber= randomNumber(gameMainNumber);
                }
                break;
            }
            default:
                break;
                Error();
        }
}
void nextRound()
{
    Sleep(10);
    RandomizeNumber();
    scoreM++;
    gameTime=timeLimit;
    setLessTime();
}
void gameKeyDetection()
{
    if(GetKeyState(VK_ESCAPE) & 0x8000)
    {
        saveProgress();
        Sleep(1000);
        exit(0);
    }
    if(GetKeyState('1') & 0x8000)
    {
        switch(gameFirstSign)
        {
            case 1: {
                if(gameMainNumber + gameFirstNumber <= 2137)
                {
                    gameMainNumber+=gameFirstNumber;
                    nextRound();
                }
                else
                {
                    gameOver();
                }
                break;
            }
            case 2: {
                if(gameMainNumber - gameFirstNumber > 0)
                {
                    gameMainNumber-=gameFirstNumber;
                    nextRound();
                }
                else
                {
                    gameOver();
                }
                break;
            }
            case 3: {

                if(gameMainNumber * gameFirstNumber <= 2137)
                {
                    gameMainNumber*=gameFirstNumber;
                    nextRound();
                }
                else
                {
                    gameOver();
                }
                break;
            }
            case 4: {

                if(gameMainNumber >= gameFirstNumber)
                {
                    gameMainNumber= gameMainNumber / gameFirstNumber;
                    nextRound();
                }
                else
                {
                    gameOver();
                }
                break;
            }
            default:
                break;
                Error();
        }
        Sleep(150);
    }
    if(GetKeyState('2') & 0x8000)
    {
        switch(gameSecondSign)
        {
            case 1: {
                if(gameMainNumber + gameSecondNumber <= 2137)
                {
                    gameMainNumber+=gameSecondNumber;
                    nextRound();
                }
                else
                {
                    gameOver();
                }
                break;
            }
            case 2: {
                if(gameMainNumber - gameSecondNumber > 0)
                {
                    gameMainNumber-=gameSecondNumber;
                    nextRound();
                }
                else
                {
                    gameOver();
                }
                break;
            }
            case 3: {

                if(gameMainNumber * gameSecondNumber <= 2137)
                {
                    gameMainNumber*=gameSecondNumber;
                    nextRound();
                }
                else
                {
                    gameOver();

                }
                break;
            }
            case 4: {

                if(gameMainNumber >= gameSecondNumber)
                {
                    gameMainNumber= gameMainNumber / gameSecondNumber;
                    nextRound();
                }
                else
                {
                    gameOver();
                }
                break;
            }
            default:
                break;
                Error();
        }
        Sleep(150);
    }
}

int main() {
    srand(time(0));

    drawIntro();
    initializeStart();
    loadProgress();
    showGame=true;

    while(continueGame)
    {
        if(showGame)
        {
            gameKeyDetection();
            drawGame();
        }

    }
    std::cin.get();
    return 0;
}
