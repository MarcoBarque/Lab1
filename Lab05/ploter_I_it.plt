set terminal epslatex color size 6.0in,5.0in standalone font "" 14
set output 'FigureI_it.tex'

set border linewidth 6 

set ylabel '\textbf{Tiempo de operacion}'
set xlabel '\textbf{Tamano de } $m$'

set ytics scale 2
set xtics scale 2
set logscale x 10
set logscale y 10

f(x) = x

plot 'datosI_it.dat' u 1:2 w p pt 7 ps 2.5 lc rgb "red" t 'Escalabilidad \texttt{matmult.cpp}',\
     f(x) w l lw 3 lc rgb "red" t 'Escalabilidad Lineal'



set output
system('latex FigureI_it.tex')
system('dvips FigureI_it.dvi')
system('ps2pdf FigureI_it.ps')
system('rm FigureI_it.tex FigureI_it.log FigureI_it.aux FigureI_it-inc.eps FigureI_it.dvi FigureI_it.ps')
