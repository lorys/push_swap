ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`;
./$3 $ARG
