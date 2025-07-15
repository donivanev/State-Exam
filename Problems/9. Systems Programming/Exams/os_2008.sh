# Какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения фрагмент на bash:

for var in a1 a2 a3
do
    set $var
done

shift
listpar=` echo $* `

if [ -n "$listpar" ]
then
    true
else
    false
fi
echo $?
echo $listpar