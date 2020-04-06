set term png
set output "ms_complete_graph.png"
set datafile separator " "
set grid
show grid

set title "macierz sasiedztwa"
set xlabel "wierzcholki"
set ylabel "wierzcholki"

unset key

plot "data_complete_graph.dat" using 1:2 with points pt 5