set term png
set output "macierz_sasiedztwa.png"
set datafile separator " "
set grid
show grid

set title "macierz sasiedztwa"
set xlabel "wierzcholki"
set ylabel "wierzcholki"

unset key

plot "data_edges.dat" using 1:2 with points pt 5