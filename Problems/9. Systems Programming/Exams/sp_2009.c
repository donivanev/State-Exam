// В текущия каталог има текстов файл fileA.txt със следното съдържание
//  xxxxxxxxxx
//  abcdefgh
//  012345678
// При успешно изпълнение на файла, получен при успешна компилация на зададения по-долу програмен код на С,
// в който са използвани системни примитиви на ОС UNIX и LINUX:

// A) Означете със стрелка края на всяка линия, в която се извежда на стандартния изход (терминала).
// Всяка стрелка да е свързана с пореден номер, съответстващ на реда на извеждането.

#include <stdio.h>
#include <fcntl.h>

main() {
    int fd, n_byt, i = 0, status;
    char sline [40], c;

    if ( fork() ) {
        wait (&status);
        execlp ("echo", "echo", "End_of_program", 0);
    }
    else {
        if ( ( fd = open ("fileA.txt",O_RDONLY ) ) == -1 ) {
            printf ("\n Cannot open \n" );
            exit (1);
        }
        
        n_byt = read (fd, sline, 20);
        c = sline[i++];
        
        if ( c >= 'a' && c <= 'z' ) {
            while ( sline [ i ++] != '\n' && i < n_byt )
                write ( 1, "$", 1 );
                write ( 1, "\n", 1 );
        }
        
        while ( i < n_byt )
            write (1, &sline[i++], 1);

        close ( fd );
        execlp ("wc", "wc", "-l", "fileA.txt",0 );
    }
}

// Б) Какво се извежда на стандартния изход (терминала) ?

// -------------------------------------------------------

// Да се напише отдясно на програмния код какво ще бъде изведено на стандартния изход като резултат
// от успешното изпълнение на дадения по-долу фрагмент от програма на С

main() {
    // .............

    int i, pid, flag = 2, status;
    pid = fork();
    
    if ( pid ) { 
        --flag;
        wait(&status);
    }
    else for ( i = 1; i <= 2; i++ ) ++flag;
    ++flag;

    if ( flag == 3 )
        exit ( --i );
    printf ( "flag = %d\n",flag);

    // ..............
}