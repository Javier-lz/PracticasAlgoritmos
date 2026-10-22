
# Ajuste del numero medio de operaciones basicas
f_ob(x) = a*x*log(x)/log(2) + b*x + c
a = 1
b = 1
c = 0

fit [10000:20000] f_ob(x) "exercise5.log.merge" using 1:4 via a,b,c

# Ajuste independiente del tiempo medio de CPU
f_cpu(x) = d*x*log(x)/log(2) + e*x + g
d = 1e-7
e = 0
g = 0

fit [10000:20000] f_cpu(x) "exercise5.log.merge" using 1:3 via d,e,g

# Representacion de operaciones basicas y su ajuste
set xlabel "Tamano de entrada N"
set ylabel "Operaciones basicas"
plot "exercise5.log.merge" using 1:4 with points title "OB medidas", \
     f_ob(x) with lines title "Ajuste OB"

# Representacion del tiempo de CPU y su ajuste
set xlabel "Tamano de entrada N"
set ylabel "Tiempo de CPU (s)"
plot "exercise5.log.merge" using 1:3 with points title "Tiempo medido", \
     f_cpu(x) with lines title "Ajuste CPU"
