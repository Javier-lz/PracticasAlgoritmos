#!/bin/bash
make exercise5
make exercise5_test 
mkdir -p graficas 

gnuplot -e "input_file='exercise5.log.insert';comparison_file='exercise5.log.bubble';
 algorithm='Insert'; output_file='./graficas/average_time_insert.png'" ./gnuplot_configs/plot_average_time.gp 
 
gnuplot -e "input_file='exercise5.log.bubble'; comparison_file='exercise5.log.insert';algorithm='Bubble';
 output_file='./graficas/average_time_bubble.png'" ./gnuplot_configs/plot_average_time.gp 

gnuplot -e "input_file='exercise5.log.insert';comparison_file='exercise5.log.bubble'; algorithm='Insert';
 output_file='./graficas/average_num_op_insert.png'" ./gnuplot_configs/plot_average_num_op.gp 
