/* gitc: git-curses
 * A TUI frontend for the Git VCS
 * License:TBD
 * Author:Aditya Visvanathan
 * Version : 1.0.0
 */
#define EXIT_KEY_PRESS 113
#define CLEAN_EXIT_MAIN 0

#include "gitc.h"
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#define EXIT_MAIN 1
int main(int argc,char **argv)
{
    setlocale(LC_ALL,"C");
    if ( ! check_if_repo() )
    {
        printf("Fatal! Not a Git Repository!\n");
        return EXIT_MAIN;
    }

    initscr();
    curs_set(0);
    cbreak();
    keypad(stdscr,TRUE);
    noecho();

    int key = 0;
    static int prev_window;
    if( ! check_if_repo())
        prev_window = print_git_repo_error(stdscr);
    else
        prev_window = print_welc_scr(stdscr);
    
    while( (key = getch() ) != EXIT_KEY_PRESS)
    {
        if ( key == KEY_RESIZE )
        {
            clear();
            
                if ( prev_window == CLEAN_EXIT_WELC_SCR )
                    prev_window = print_welc_scr(stdscr);
                else if ( prev_window == CLEAN_EXIT_OPEN_ERR )
                    prev_window = print_git_repo_error(stdscr);
                else if ( prev_window == CLEAN_EXIT_REPO_DET_SCR )
                    prev_window = repo_commit_menu(stdscr);
            
        }
        else if ( prev_window == CLEAN_EXIT_WELC_SCR )
            prev_window = repo_commit_menu(stdscr);

        
    }  
    curs_set(1); 
    endwin();

    return CLEAN_EXIT_MAIN;
}
