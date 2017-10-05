#include "Include_and_constants.h"
#include <windef.h>



int Game( int Number ) ;
int SetAmountOfTries() ;
int StartGame() ;

int Game( int Number ) //сама игра
{
    int Idea = 0 ; //предположение пользователя
    printf( "Print your ideas_ " ) ;
    Idea = In() ; //получаем предположение
    if( Idea == Number ) //если совподает то выходим из обеих функций
    {
        printf( "You are win! My congratulations to you!\n" ) ;
        printf( "Press any button to restart the game\n" ) ;
        getch() ;
        return -1 ;
    }else if ( Idea < Number )//если не угадали возвращаемся в цикл
    {
        printf( "Try bigger one\n" ) ;
        return 0 ;
    }
    else
    {
        printf( "Try smaller one\n" ) ;
        return 0;
    }
}


int SetAmountOfTries() //получаем количество попыток в подходящем количестве
{
    system( "cls" ) ;
    printf( "Choose Amount of tries_\n" ) ;
    int Amount = In() ;
    while( Amount < 1 || Amount > 50 )
    {
        if( Amount > 50 ) printf( "It's too easy, set less amount of tries_ \n" ) ;
        else printf( "It's impossible, set more tries_ \n" ) ;
        Amount = In() ;
    }
    system( "cls" ) ;
    return Amount ;
}

int StartGame()//начинаем игру
{
    int Amount = SetAmountOfTries() , Number = rand() % 99 + 1 ; //получаем количество попаыток и определяем число
    for( int i = 0 ; i < Amount ; i ++ )
    {
        switch( Game( Number ) )
        {
            case -1 :
                return 0 ;
            default:
                break ;
        }
        printf( "You have %d more tries\n" , Amount - i - 1 ) ;
    }
    return 0 ;
}






int main()
{
    while(TRUE)
    {
        system("cls") ;
        printf( "1.New game\n2.Exit\n" ) ;
        char Choose = getch() ;
        switch( Choose )
        {
            case '1' :
                StartGame() ;
                break ;
            case '2' :
                return 0 ;
        }


    }

}
