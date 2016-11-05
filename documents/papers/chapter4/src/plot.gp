set logscale y
set grid
set arrow 1 from 500.0, 200.0 to 315.0, 200.0
set label "315 years ago..."  at first  500, first  200
 #set term postscript eps enhanced
 #set output "plot.eps"
plot [0:800] "tt" t "finite difference method" w l, "ttt" t "strict" w l

pause -1
