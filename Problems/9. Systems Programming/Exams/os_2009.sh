# Опишете с думи действията, които ще се реализират при изпълнението на зададената командна процедура на bash

if test -d /home/compiled
then :
else
    mkdir /home/compiled
fi

l_files=` ls $HOME/*.c `
proc=` ps | wc -l `

while [ $proc -lt 5 ]
do
    for i in $l_files
    do
        name=$i.exe
        cc -o $name $i &
        break
    done
    mv $i /home/compiled
    proc=` ps | wc -l `
    l_files=` ls $HOME/*.c `
done

# Текство файл с име procA съдържа следната последователност от команди на bash

br=0
for x in a b c
do for y
    do if test $y -lt $#
        then br=` expr $br + 1`
            echo $br
        else continue
            echo $y
        fi
    done
    break
done

# Какъв резултат ще бъде изведен на стандартния изход при стартиране на изпълнение чрез командния ред: sh procA 1 2 3

# а) 1 2 3
# б) 1 2 1 2 1 2
# в) 1 2
# г) 1 2 3 3
# д) нито един от посочените

# ----------------------------------------------------------

# Даденият по-долу фрагмент от команди на командния интерпретатор bash за LINUX се изпълнява успешно.
# Да се напише отдясно на командите какво и в кои оператори се извежда на стандартния изход

count = 0
for var in a1 a2 a3
do
    echo $var > fxxx
done
cat fxxx
listpar=` grep a3 fxxx `
echo $listpar > fyyy
until cat fyyy | grep a2 > /dev/null
do
    count = ` expr $count + 1 `
    echo a2 >> fyyy
done
echo $count
echo $listpar