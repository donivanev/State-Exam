// Даден е следния фрагмент от програма:

#define LST "ls"
main() {
    int pid, k = 5, status;
    printf( "Stoinostta na k = %d;", k - 2 );
    ++k;
    printf( "Stoinostta na k = %d;", k );
    execlp(LST, LST, 0);
    if ( (pid = fork() ) == 0 ) k++;
    else { wait( &status); --k ; }
    printf( "Stoinostta na k = %d;", k );
}

// Като резултат от изпълнението на последователността от зададените оператори на стандартния изход ще се изведе:

// ------------------------------------------------------

// Даден е следния фрагмент от програма:

int filed, i;
filed = creat ( "exam_txt", 0777 );
close ( 1 );
i = dup (filed);
write ( i, "TEST \n", sizeof("TEST \n" ) );
write ( 1, "TEST \n", sizeof("TEST \n" ) );

// Като резултат от изпълнението на последователността от зададените оператори:
// а) на терминала ще се изведе два пъти низът "TEST"
// б) на терминала ще се изведе низът "TEST" и във файла "exam_txt" ще се запише низът "TEST"
// в)във файла "exam_txt" ще се запише два пъти низът "TEST"