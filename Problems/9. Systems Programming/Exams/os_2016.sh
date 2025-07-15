# Текстов файл с име comproc1съдържа зададената по­долу последователност от команди на bash за Linux.
# Да се подчертаят операторите, които извеждат текст на стандартния изход и за всеки от тях да се напише вдясно какво ще бъде изведено
# след стартиране на файла със следния команден ред: bashcomproc1 1 3 5 ако на стандартния вход бъде подадена последователността от символи c d

br=1
br=`expr$br \* $2`
a=$3
set ab bc cd de
shift
while true
do echo$*
    for j
    do if test$# -lt $br
        then br=`expr$br / 2`
            echo$br $j >> file
        else br=`expr$br+$a`
            echo $br $j >> file
       fi
    done
break
done
read a1a2
while cat file | grep $a1
do echo $a $a2
    wc -l file
    tail -5c file
    exit
    echo FIN
done
echo $a $a1
wc -c file
tail -2l file

# ---------------------------------------------------------------

# Текстов файл с име procA съдържа зададената по-долу последователност от команди на bash за Linux.
# Да се напише вдясно какво ще бъде изведено на стандартния изход и какво ще бъде съдържанието на файловете f1 и f2 след стартиране на командната
# процедура със следния команден ред: bash procA ab bc cd ако на стандартния вход бъде подадена последователността от символи b c

count=1
for i in 6 1 4 2
do
    for each
    do if test $i -gt $#
        then count=` expr $count \* $i`
            echo $count $each >> f1
        else until false
            do echo $*
            break 3
            done
       fi
    done
done
read k1 k2
while cat f1 | grep $k1
do set $k1 $k2 $count
    shift
    echo $1 $2
    grep $2 f1 > f2
    wc -c f2
    exit
    echo END
done
wc -l f1
tail -2l f1
echo FIN