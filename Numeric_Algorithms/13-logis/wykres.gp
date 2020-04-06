set term pdfcairo enhanced size 6,4
set output "Wykres.pdf"
set title "Wykres odwzorowania logistycznego"
set xlabel "k"
set ylabel "x"
plot "dane.dat" u 1:2