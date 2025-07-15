# Текстовите файлове x1 и f1 се намират в текущата директория и имат следното съдържание:

# x1                            f1
# ———————————————————————       ———————————————————————
# 5 line five                   line
# 8 line eight
# More text
# 0123456789
# test check trial
# 9 line nine 10 line ten
# abcdef

# В текущата директория се намира също и празният файл f4. Текстов файл с име comproc съдържа зададената по-долу последователност
# от команди на bash за Linux. Да се напише какво ще бъде изведено на стандартния изход след еднократно стартиране на comproc със следния
# команден ред bash comproc ab cd ef gh и при подаване на последователността от символи 3 1 на стандартния вход.

grep `head -1 f1` `tail -1 f1` | wc -l > f2
a=`cat f2`
echo $a $3
set 9 7 5 3
shift 2
for j in 1 2 3 4 5
do for i
    do if test $a -lt $i
        then cat f1 f2 > f3
            wc -l f3
            echo $i $j $a >> f4
        else tee f2 f3 < f1
            wc -w f2
            echo $i $j $a >> f4
       fi
    done
    echo $# >> f4
    break
done
read key1 key2
while cat f4 | grep $key2
do sort f4
    a=`wc -c < f4`
    echo -n "Character count: $a"
    exit
done
grep $key1 f4
b=`wc -l < f4`
echo -n "Lines count: $b"