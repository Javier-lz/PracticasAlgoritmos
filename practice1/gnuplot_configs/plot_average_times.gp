
set title "Operaciones Medias "
set xlabel "Tamaño de permutacion"
set ylabel "Numero de operaciones"

set grid
set terminal pngcairo
set output "./graficas/average_time.png"

plot "./exercise5.log" using 1:5 title "NumOp" with lines
