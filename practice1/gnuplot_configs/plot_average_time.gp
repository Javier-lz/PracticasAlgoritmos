
set title "Tiempo de ejecucion "
set xlabel "Tamaño de permutacion"
set ylabel "Tiempo de ordenacion(s)"

set grid
set terminal pngcairo
set output output_file

plot input_file using 1:3 title sprintf("AvTime(%s)", algorithm) with lines
