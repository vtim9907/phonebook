reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.07]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'reduced struct', \
'' using 4:xtic(1) with histogram title 'hash table', \
'' using 5:xtic(1) with histogram title 'binary search tree', \
'' using 6:xtic(1) with histogram title 'BST with 6 value in a node', \
'' using ($0-0.2):($2+0.001):2 with labels title ' ', \
'' using ($0+0.0):($3+0.0015):3 with labels title ' ', \
'' using ($0+0.2):($4+0.0015):4 with labels title ' ', \
'' using ($0+0.4):($5+0.0015):5 with labels title ' ', \
'' using ($0+0.6):($6+0.0015):6 with labels title ' '
