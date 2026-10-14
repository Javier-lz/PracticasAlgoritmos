
set title "Operaciones Medias "
set xlabel "Tamaño de permutacion"
set ylabel "Numero de operaciones"

set grid
set terminal pngcairo
set output output_file

plot input_file using 1:5 title sprintf("AvNumOp(%s)", algorithm) with lines
