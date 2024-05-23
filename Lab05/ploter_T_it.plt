set terminal epslatex color size 6.0in,5.0in standalone font "" 14
set output 'FigureT_it.tex'

set border linewidth 6 

set ylabel '\textbf{Tiempo de operacion}'
set xlabel '\textbf{Tamano de } $i$'

set ytics scale 2
set xtics scale 2
set logscale x 10
set logscale y 10

f(x) = x

plot 'datosT_it.dat' u 1:2 w p pt 7 ps 2.5 lc rgb "blue" t 'Escalabilidad \texttt{matmultmkl.cpp}',\
          f(x) w l lw 3 lc rgb "blue" t 'Escalabilidad Lineal'



set output
system('latex FigureT_it.tex')
system('dvips FigureT_it.dvi')
system('ps2pdf FigureT_it.ps')
system('rm FigureT_it.tex FigureT_it.log FigureT_it.aux FigureT_it-inc.eps FigureT_it.dvi FigureT_it.ps')
