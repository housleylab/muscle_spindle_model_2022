TITLE CA1 KM channel from Mala Shah
: M. Migliore June 2006
COMMENT
 default parameters modified by RKP 2019 to match data in Figure 5 
 of Battefileld et al. for axonal Km  (J Neurosci 34(10):3719-3732,2014).
 also changed inf and tau to range variables
ENDCOMMENT

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)

}

PARAMETER {
	v 		(mV)
	ek
	celsius 	(degC)
	gbar=.0001 	(mho/cm2)
        vhalfl=-37  	(mV)	:originally -40
	kl=-10
        vhalft=-37   	(mV)	:originally -42
        a0t=0.016      	(/ms)	:originally 0.009
        zetat=2.8    	(1)	:originally 7
        gmt=0.6   	(1)	:originally .4
	q10=5
	b0=12			:originally 60
	st=1
	temp=35		(degC)  
}


NEURON {
	SUFFIX km
	USEION k READ ek WRITE ik
        RANGE  gbar,ik, inf, tau
}

STATE {
        m
}

ASSIGNED {
	ik (mA/cm2)
        inf
	tau
        taua
	taub
}

INITIAL {
	rate(v)
	m=inf
}


BREAKPOINT {
	SOLVE state METHOD cnexp
	ik = gbar*m^st*(v-ek)
}


FUNCTION alpt(v(mV)) {
  alpt = exp(0.0378*zetat*(v-vhalft)) 
}

FUNCTION bett(v(mV)) {
  bett = exp(0.0378*zetat*gmt*(v-vhalft)) 
}

DERIVATIVE state {
        rate(v)
:        if (m<inf) {tau=taua} else {tau=taub}
	m' = (inf - m)/tau
}

PROCEDURE rate(v (mV)) { :callable from hoc
        LOCAL a,qt
        qt=q10^((celsius-temp)/10)
        inf = (1/(1 + exp((v-vhalfl)/kl)))
        a = alpt(v)
        tau = b0 + bett(v)/(a0t*(1+a))
	tau=tau/qt	: orignal version calculated qt but didn't use it!
:        taua = 50
:        taub = 300
}
