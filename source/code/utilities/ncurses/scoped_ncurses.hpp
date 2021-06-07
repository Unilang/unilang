#pragma once
#include <curses.h>
#include <stdio.h>
#include <term.h>

class ScopedNcurses
{
public:
  ScopedNcurses()
  {
    //filter();
    //initscr();
    //newterm();
    
    FILE *fp = fopen("x", "w");
    SCREEN *s = newterm(NULL, stdin, stdout);
    
    
    //newterm(NULL, stdin, stdout);
    keypad(stdscr, TRUE);
    noecho(); 
  }

  ~ScopedNcurses()
  {
    //delscreen();
    endwin();
  }

};
