# Текстов файл с име comproc1 съдържа зададената по­долу последователност от команди на bash за Linux.
# Напишете вдясно какво ще бъде изведено на стандартния изход след стартиране на файла с команден ред bash comproc1 3 4 5
# ако на стандартния вход бъде подадена последователността от символи 6 7

br=0
br=`expr $br + $2`
set 3 5 7
shift
for j
do for var
    do if test $br -lt $2
        then br=` expr $br \* $2`
            echo $br $var $j >> file
        else br=`expr $br - $2`
            echo $var $br $j >> file
       fi
    done
    echo $*
    break
done
read a1 a2
until cat file | grep $a1
do echo $#
    grep $1 file
    exit
    echo END
done
echo $3
wc -l < file
echo FINAL

# ---------------------------------------------------------------

# Текстов файл с име comproc1 съдържа зададената по­долу последователност от команди на bash за Linux.
# Напишете вдясно какво ще бъде изведено на стандартния изход след стартиране на файла с команден ред bash comproc1 12 34 56
# ако на стандартния вход бъде подадена последователността от символи 5 6

var=1
for i in 4 3 2 1
do for j
    do if test $i –gt $#
        then var=` expr $var \* $i`
            echo $var $j >> ff
        else continue
        fi
    done
done

while true
do echo $*
    break
done

read k1 k2

while cat ff | grep $k2

do set $k1 $var
    shift
    echo $2
    grep $i ff
    exit
    echo $1
done

wc -l < ff
echo END