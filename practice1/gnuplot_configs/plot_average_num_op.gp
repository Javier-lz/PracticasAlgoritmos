
set terminal pngcairo enhanced
set output output_file

set title sprintf("Operaciones básicas - %s", algorithm)
set xlabel "Tamaño de entrada"
set ylabel "Número de comparaciones"

set grid
set key left top

# Escala vertical común para ambos algoritmos.
stats input_file using 6 nooutput
max_insert = STATS_max

stats comparison_file using 6 nooutput
max_bubble = STATS_max

max_ops = (max_insert > max_bubble) ? max_insert : max_bubble
set yrange [0:max_ops * 1.05]

plot input_file using 1:4 with linespoints title "InsertSort - Media", \
     input_file using 1:5 with linespoints title "InsertSort - Mínimo", \
     input_file using 1:6 with linespoints title "InsertSort - Máximo", \
     comparison_file using 1:4 with linespoints title "BubbleSort - Media", \
     comparison_file using 1:5 with linespoints title "BubbleSort - Mínimo", \
     comparison_file using 1:6 with linespoints title "BubbleSort - Máximo"
