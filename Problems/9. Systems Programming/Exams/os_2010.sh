# Текстов файл с име comprocB съдържа зададената по-долу последователност от команди на bash за Linux.
# Напишете вдясно какво ще бъде изведено на стандартния изход след стартиране на файла с команден ред: bash comprocB b1 b2 b3,
# ако на стандартния вход бъде подадена следната последователност от символи: b2

if test -z $5
then echo $1
    for var
    do echo $var >> fniz
    done
else echo $2
    while true
    do echo LOOP
    break
    done
fi
cat fniz
read string
until cat fniz | grep $string
do
    set $2 b1
    echo `grep $2 fniz `
    echo END
    exit
done
set $3 $1 1
echo OK $3
echo ` grep $1 fniz `
exit
echo OK