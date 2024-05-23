set terminal epslatex color size 6.0in,5.0in standalone font "" 14
set output 'FigureI.tex'

set border linewidth 6 

set ylabel '\textbf{Velocidad de operacion}'
set xlabel '\textbf{Número de threads} $i$'

set ytics scale 2
set xtics scale 2

f(x) = x

plot 'datosI.dat' u 1:2 w p pt 7 ps 2.5 lc rgb "red" t 'Escalabilidad \texttt{matmult.cpp}',\
     f(x) w l lw 3 lc rgb "red" t 'Escalabilidad Lineal'     



set output
system('latex FigureI.tex')
system('dvips FigureI.dvi')
system('ps2pdf FigureI.ps')
system('rm FigureI.tex FigureI.log FigureI.aux FigureI-inc.eps FigureI.dvi FigureI.ps')
