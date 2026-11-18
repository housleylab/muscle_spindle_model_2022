COMMENT

Conductance model of conversion of muscle length to receptor muscle tension to current
at the Ia muscle spindle ending.  Model based on Hasan, Z A model of 
afferent response to muscle stretch J Neurophys 49: 989-1006, 1983  
Except that rate is not calculated directly. A stretch-evoked conductance depends on the 
length of the sensory region (srL)
ENDCOMMENT

NEURON {
  SUFFIX MRCHas
  USEION na READ ena WRITE ina
  RANGE minf,taum,gbar,m,srL
  RANGE a,b,c,ina
  GLOBAL Lslp, Lhalf,rmL,rmdL
}


UNITS {
  (mV) = (millivolt)
  (uM) = (micrometer)
}

PARAMETER {
  a = 0.0003 (mm/ms)
  b = 250
  c = -15 (mm)

  gbar=0.01 (mho/cm2) :conductance density
  Lslp = 0.05 (mm)   :Slope of Boltzman equation specifying srL to conductance
  Lhalf = 0.1 (mm): half srL (sensory region length) activation point
  taum = 5 (ms)

}


ASSIGNED {
  v (mV)
  i (nA)
  rmL
  rmdL
  minf
  ena
  ina
}

STATE {m srL}



INITIAL {
  srL= (rmL - c)/b
  m = 1.0 / (1.0 +exp(-(srL-Lhalf)/Lslp))
}


BREAKPOINT {
   minf = 1.0 / (1.0 +exp(-(srL-Lhalf)/Lslp))
   srL=srL + dt*(rmdL -a*(((b*srL - rmL +c)/(rmL - c - srL))^3))

  SOLVE rmt_to_cond METHOD cnexp
  ina  = gbar*m*(v-ena)
}

DERIVATIVE rmt_to_cond {
	m'=(minf-m)/taum
}
