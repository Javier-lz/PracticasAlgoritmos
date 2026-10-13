set terminal pngcairo size 1000,600
set output "graficas/histogram.png"

set title "Frequency Distribution of Random Numbers"
set xlabel "Generated number"
set ylabel "Frequency"

set style fill solid 0.7 border
set boxwidth 0.8
set grid ytics

set xrange [0:*]
set yrange [0:*]

plot "< make exercise1_test | tail -n +4 | sort -n | uniq -c" using 2:1 \
    with boxes title "Frequency"