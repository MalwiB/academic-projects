set term png
set output "posortowane.png"
set datafile separator " "

set title "Sortowanie X"
set xlabel "numer pozycji"
set ylabel "liczba na pozycji"

unset key

plot "dane_posortowane.dat" using 1:2 with points pt 5