#!/bin/bash

gnuplot <<'GP'
set terminal pngcairo size 1000,650
set grid
set xlabel "Tamaño del vector (N)"
set ylabel "Tiempo medio de CPU"
set title "Comparación del tiempo medio de CPU de QuickSort"
set key left top
set output "quicksort_tiempos.png"
plot "quicksort.log.min" using 1:3 with lines title "QuickSort_min", \
     "quicksort.log.mean" using 1:3 with lines title "QuickSort_mean", \
     "quicksort.log.median" using 1:3 with lines title "QuickSort_median"

set ylabel "Número medio de comparaciones"
set title "Comparación del número medio de comparaciones de QuickSort"
set output "quicksort_comparaciones.png"
plot "quicksort.log.min" using 1:4 with lines title "QuickSort_min", \
     "quicksort.log.mean" using 1:4 with lines title "QuickSort_mean", \
     "quicksort.log.median" using 1:4 with lines title "QuickSort_median"
GP
