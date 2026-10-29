
# Datos: columna 1 = tamaño n, columna 4 = tiempo
datafile = "exercise5.log.merge"

# Funcion de ajuste: n log n
f(x) = a * x * log(x) / log(2) + b

# Valores iniciales de los parametros
a = 1e-9
b = 0

# Ajuste por minimos cuadrados
fit f(x) datafile using 1:3 via a,b

# Mostrar los parametros calculados
print "a = ", a
print "b = ", b

# Representar los datos y la curva ajustada
set title "Ajuste temporal de Merge Sort: O(n log n)"
set xlabel "Tamano de entrada (n)"
set ylabel "Tiempo (segundos)"
set grid
set key top left

plot datafile using 1:3 with points title "Datos experimentales", \
     f(x) with lines lw 2 title sprintf("Ajuste: a*n*log2(n) + b,a=%f b= %f",a,b)

pause -1
