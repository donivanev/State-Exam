// В текущия каталог се намира текстов файл f1.txt със следното съдържаниe:
//  xyzabcd
//  0123456789
//  ABCD
// Изпълнимият файл, получен след компилация на зададения по-долу програмен фрагмент, се стартира със следния команден ред:
// ./a.out f1.txt f2.txt
// Напишете какво ще бъде изведено на стандартния изход и какво ще бъде съдържанието на файловете f1.txt и f2.txt след приключване на успешното изпълнение.

#include <stdio.h>
#include <fcntl.h>

main(int argc, char* argv[]) {
    int des1, des2, k, broi, i = 0, status;
    char buff[40], c;
 
    if ((des1 = open(argv[1], O_RDWR)) == -1) {
        printf("\n Cannot open \n");
        exit(1);
    }
    if ((des2 = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) {
        printf("\n Cannot open \n");
        exit(1);
    }
    if (fork() == 0) {
        broi = read(des1, buff, 22);
        write(1, buff, 10);
        k = dup(1);
        close(1);
        dup(des1);
        c = buff[i++];
        
        if (c <= '0' || c >= '9') {
            while (buff[i++] != '\n' && i < broi)
                write(1, "x", 1);
            
            write(1, "\n", 1);
            close(1);
            dup(k);
            write(1, buff, 4);
            write(des2, buff, 12);
        } 
        else {
            write(1, buff, broi);
            close(1);
            dup(k);
            write(1, "x\n", 2);
        }
 
        lseek(des2, 0, 0);
        write(des2, "x\n", 2);
        close(des1);
        close(des2);
    } 
    else {
        wait( &status );
        close(1);
        dup(des1);
        execlp("head", "head", "-2",argv[2], 0);
        execlp("wc", "wc", "-l", argv[1], 0);
    }

    execlp("grep", "grep", "x", "f1.txt", 0);
}

// ----------------------------------------------------

// Дадена е следната програма за ОС Linux, написана на езика C:

#include <unistd.h>
#include <string.h>

int main(void) {
    char* buff = "Hello, world!\n";
    int p;
 
    if (fork() == 0)
        write(1, buff, strlen(buff));
    p = fork();
    write(1, buff, strlen(buff));
}

// а) Колко пъти ще се изведе на стандартния изход текстът "Hello, world!" при изпълнението на програмата? Обосновете отговора си.
// б) Нарисувайте кореновото дърво с върхове процесите, които ще се стартират в резултат от изпълнението на програмата и ребра двойките родител-наследник.