
set terminal pngcairo enhanced
set output output_file

set title "Tiempo de ejecucion"
set xlabel "Tamaño de permutacion"
set ylabel "Tiempo de ordenacion(s)"

set grid
set key left top

# Escala vertical común para ambos algoritmos.
stats input_file using 3 nooutput
max_input = STATS_max

stats comparison_file using 3 nooutput
max_comparison = STATS_max

max_time = (max_input > max_comparison) ? max_input : max_comparison
set yrange [0:max_time * 1.05]

plot input_file using 1:3 \
    with linespoints \
    title sprintf("AvTime(%s)", algorithm)

set output
