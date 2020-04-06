set term png
set output "przed_scaleniem.png"
set datafile separator " "

set title "Sortowanie X"
set xlabel "numer pozycji"
set ylabel "liczba na pozycji"

unset key

plot "dane_przed_scaleniem.dat" using 1:2 with points pt 5