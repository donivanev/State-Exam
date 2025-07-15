// В текущия каталог се намира текстов файл fileB.txt със следното съдържание
//  12345$$6789
//  $$abcdefg
// Да се напише вдясно на програмния код какво ще бъде изведено на стандартния изход (терминала) като резултат от изпълнението на файла,
// получен при успешна компилация на зададения по-долу програмен код на езика С, в който са използвани системни примитиви на ОС UNIX и LINUX:

#include <stdio.h>
#include <fcntl.h>

main() {
    int fdr, fdw, n_byt, i = 0, status;
    char buff [40], c;

    if (fork()) {
        wait (&status);
        
        if (open("file_new", 0) != -1)
            execlp("grep", "grep", "$", "file_new",0);
    }
    else {
        if ((fdr = open("fileB.txt",0))== -1) { 
            printf("\n Cannot open \n");
            exit(1);
        }
        
        if (( fdw = creat ("file_new",0666))== -1) {
            printf ("\n Cannot creat \n");
            exit (1);
        }
        
        n_byt = read (fdi, buff, 40);
        c = buff[i++];
        
        if (c <= '1' || c >= '9') {
            while ( buff [i ++] != '\n' && i < n_byt)
            write( fdw, "$", 1 );
            write(fdw, "\n", 1);
            write(1, "\n", 1);
        }
        else {
            write(1, buff, n_byt);
            write ( 1, "\n", 1 );
        }
        
        write (fdw, "$", 1);
        close (fdr);
        close (fdw);
    }
}