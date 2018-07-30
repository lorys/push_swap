ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
if [ "$3" = "1" ]; then
./push_swap $ARG | ./checker $ARG
elif [ "$3" = "2" ]; then
./push_swap $ARG | ./checker -v $ARG
elif [ "$3" = "3" ]; then
./push_swap $ARG
elif [ "$3" = "4" ]; then
./checker $ARG
elif [ "$3" = "5" ]; then
./checker -v $ARG
elif [ "$3" = "6" ]; then
./push_swap $ARG | wc -l
fi
./push_swap $ARG | ./checker $ARG
