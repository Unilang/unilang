#include <curses.h>
#include <iostream>

int main()
{
    int ch;

    /* Curses Initialisations */
    initscr();
    //cbreak();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printw("Welcome - Press # to Exit\n");

    while((ch = getch()) != '#')
    {
    switch(ch)
    {
    case KEY_UP: printw("\nUp Arrow");
    break;
    case KEY_DOWN: printw("\nDown Arrow");
    break;
    case KEY_LEFT: printw("\nLeft Arrow");
    break;
    case KEY_RIGHT: printw("\nRight Arrow");
    break;
    default:
    {
    printw("\nThe pressed key is ");
    attron(A_BOLD);
    printw("%c", ch);
    attroff(A_BOLD);
    }
    }
    }

    printw("\n\nBye Now!\n");

    refresh();
    getch();
    endwin();

    return 0;
}