# NumericalMethods
A few functions I'm building out for some applied mathematics stuff- ie, monte carlo integration. 

Current implementation should use Monte Carlo Integration to estimate "easy" integrals.  
"Easy" integrals, as defined now, have finite bounds on a continuous, positive function.  Think x^2, sin(x) + 1- things like that.  

Putting in the Weierstrass function (https://en.wikipedia.org/wiki/Weierstrass_function) will likly cause the program to crash, 
although I haven't tested it.  Please, be my guest.

Ideas for later improvements include support for integrals that are both positive and negative (a must), better optimization implementations (a likely), multidimensionalality (a hope), parallel support (a hope), and others TBD.
