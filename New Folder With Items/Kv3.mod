TITLE Voltage-gated potassium channel from Kv3 subunits

COMMENT
Voltage-gated potassium channel with high threshold and fast activation/deactivation kinetics

KINETIC SCHEME: Hodgkin-Huxley single gate
n'= alpha * (1-n) - betha * n
g(v) = gbar * n* ( v-ek )

alpha = ra*(v-vhlfa)/(1-exp(-(v-vhlfa)/slpa))
beta = rb*exp(-v/vslpb)

From Lien and Jonas  Kv3 potassium conductance is necessary and kinetically optimized
for high-frequency action potential generation in hippocampal interneurons J Neurosci: 23:2058-68,2003.

Implemented by Randy Powers February 2019

ENDCOMMENT

NEURON {
	SUFFIX Kv3
	USEION k READ ek WRITE ik
	RANGE gbar, g, ik
	RANGE ninf, taun,n
}

UNITS {
	(mV) = (millivolt)
	(mA) = (milliamp)
	(nA) = (nanoamp)
	(S)  = (siemens)
}

PARAMETER {
	gbar=0.005 (S/cm2)
	ra=0.019 (1/ms)
	vhlfa=4.184 (mV)
	vslpa=6.426 (mV)
	rb=0.0159	(1/ms)
	vslpb= 25.483 (mV)
	q10= 2.7
}

ASSIGNED {
	celsius (degC)
	v (mV)
	ik (mA/cm2)
        ek (mV)
	g (S/cm2)
	qt (1)

	ninf (1)
	taun (ms)
	alpha (1/ms)
	beta (1/ms)
}

STATE {n}

INITIAL {
	qt = q10^((celsius-22 (degC))/10 (degC))
	rates(v)
	n = ninf
}

BREAKPOINT {
	SOLVE state METHOD cnexp
      g = gbar * n
	ik = g * (v - ek)
}

DERIVATIVE state {
	rates(v)
	n' = alpha * (1-n) - beta * n
}

PROCEDURE rates(v (mV)) {
	alpha = qt * trap0(v,vhlfa,ra,vslpa)
	beta = qt * rb*exp(-v/vslpb)
	ninf = alpha / (alpha + beta) 
	taun = 1 / (alpha + beta)
}
	
FUNCTION trap0(v,th,a,q) {
	if (fabs(v-th) > 1e-6) {
	        trap0 = a * (v - th) / (1 - exp(-(v - th)/q))
	} else {
	        trap0 = a * q
 	}
}	
