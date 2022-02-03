((i = 1))
while [[ $i -le 10 ]]
do
    sleep 0.01
    ./edmonds --size $i --printFlow --glpk "Edmonds$iModel"
    ((i = i + 1))
done