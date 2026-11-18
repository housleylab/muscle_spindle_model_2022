# muscle_spindle_model_2022
Housley et al. 2024, Biophysical model of muscle spindle encoding

NEURON==7.7
numpy==1.18.0



After compiling the mod files, type nrngui termHaskm_node_axon.hoc

This file establishes the basic structure of the model (also shown in the first slide of the enclosed Powerpoint):  a terminal segment that contains the mechanosensitive channels as well as various ion channels, attached to a preterminal segment, followed by a number of nodes and mylenated internodes.  The first ppt slide shows which ion channels are inserted where.

This first hoc file also opens two additional hoc files:  make_stretch.hoc and test_params_Haskm.hoc.

make_stretch.hoc makes the length input applied to the mechanosensitive channels when the procedure new_ramp() is called.
The parameters of this signal are specified by L0(starting length), DELAY (time to start of stretch), RDUR1 and RDUR2 (durations of the up and down ramp segments), SLOPE1 and SLOPE2 (rates of stretch) and TPLAT (duration of hold phase).

test_params_Haskm.hoc specifies the mix of ion channels and their properties that lead to a reasonable control response.  It also calls additional files: a session file (termHaskm_node_axon.ses) that pulls up a number of graphs and conductance panels and another hoc file (plot_rate.hoc") that allows you to plot and save instantaneous frequency vs time by typing plotrate("outputfilename")

If you want to add vibration to the ramp type xopen("make_sine_stretch.hoc") and then new_sine() and add_sine(). The default parameters are 100 Hz 0.08 mm stretch starting at 290 ms and lasting until 1190 ms.


I've included a few frequency output files:
cntrl.txt - response to standard stretch with control parameters
no_Kv3.txt - response to standard stretch after setting Kv3 conductance to zero everywhere (by typing: forall {if(ismembrane("Kv3")){gbar_Kv3=0}} )
cntrlwsine.txt - control response with ramp + vibration
noKv3wsine.txt - response of noKv3 model with sine




