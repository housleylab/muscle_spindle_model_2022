/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__kv1_gp
#define _nrn_initial _nrn_initial__kv1_gp
#define nrn_cur _nrn_cur__kv1_gp
#define _nrn_current _nrn_current__kv1_gp
#define nrn_jacob _nrn_jacob__kv1_gp
#define nrn_state _nrn_state__kv1_gp
#define _net_receive _net_receive__kv1_gp 
#define states states__kv1_gp 
#define values values__kv1_gp 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gbar _p[0]
#define minf _p[1]
#define hinf _p[2]
#define tm _p[3]
#define th _p[4]
#define ik _p[5]
#define g _p[6]
#define m _p[7]
#define h _p[8]
#define ek _p[9]
#define Dm _p[10]
#define Dh _p[11]
#define _g _p[12]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_values(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_kv1_gp", _hoc_setdata,
 "values_kv1_gp", _hoc_values,
 0, 0
};
 /* declare global and static user variables */
#define Cq10 Cq10_kv1_gp
 double Cq10 = 3;
#define Ctm Ctm_kv1_gp
 double Ctm = 89.2;
#define Cth Cth_kv1_gp
 double Cth = 548.67;
#define ath ath_kv1_gp
 double ath = 29.013;
#define bth bth_kv1_gp
 double bth = 100;
#define p p_kv1_gp
 double p = 0.004;
#define th90 th90_kv1_gp
 double th90 = 0;
#define tm0 tm0_kv1_gp
 double tm0 = 3.4;
#define th0 th0_kv1_gp
 double th0 = 779;
#define vctm vctm_kv1_gp
 double vctm = 30.1;
#define vhtm vhtm_kv1_gp
 double vhtm = -34.3;
#define vhth vhth_kv1_gp
 double vhth = -0.956;
#define vch vch_kv1_gp
 double vch = 21.5;
#define vhh vhh_kv1_gp
 double vhh = -33.477;
#define vcm vcm_kv1_gp
 double vcm = -16;
#define vhm vhm_kv1_gp
 double vhm = -27;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "vhm_kv1_gp", "mV",
 "vhh_kv1_gp", "mV",
 "vcm_kv1_gp", "mV",
 "vch_kv1_gp", "mV",
 "Cth_kv1_gp", "ms",
 "vhth_kv1_gp", "mV",
 "ath_kv1_gp", "mV",
 "bth_kv1_gp", "mV",
 "th0_kv1_gp", "ms",
 "tm0_kv1_gp", "ms",
 "Ctm_kv1_gp", "ms",
 "vhtm_kv1_gp", "mV",
 "vctm_kv1_gp", "mV",
 "th90_kv1_gp", "ms",
 "gbar_kv1_gp", "S/cm2",
 "tm_kv1_gp", "ms",
 "th_kv1_gp", "ms",
 "ik_kv1_gp", "mA/cm2",
 "g_kv1_gp", "S/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "vhm_kv1_gp", &vhm_kv1_gp,
 "vhh_kv1_gp", &vhh_kv1_gp,
 "vcm_kv1_gp", &vcm_kv1_gp,
 "vch_kv1_gp", &vch_kv1_gp,
 "Cth_kv1_gp", &Cth_kv1_gp,
 "vhth_kv1_gp", &vhth_kv1_gp,
 "ath_kv1_gp", &ath_kv1_gp,
 "bth_kv1_gp", &bth_kv1_gp,
 "th0_kv1_gp", &th0_kv1_gp,
 "tm0_kv1_gp", &tm0_kv1_gp,
 "Ctm_kv1_gp", &Ctm_kv1_gp,
 "vhtm_kv1_gp", &vhtm_kv1_gp,
 "vctm_kv1_gp", &vctm_kv1_gp,
 "p_kv1_gp", &p_kv1_gp,
 "Cq10_kv1_gp", &Cq10_kv1_gp,
 "th90_kv1_gp", &th90_kv1_gp,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"kv1_gp",
 "gbar_kv1_gp",
 0,
 "minf_kv1_gp",
 "hinf_kv1_gp",
 "tm_kv1_gp",
 "th_kv1_gp",
 "ik_kv1_gp",
 "g_kv1_gp",
 0,
 "m_kv1_gp",
 "h_kv1_gp",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 13, _prop);
 	/*initialize range parameters*/
 	gbar = 0.01;
 	_prop->param = _p;
 	_prop->param_size = 13;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _kv1_gp_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 13, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 kv1_gp /Users/nickhousley/Downloads/Spindle_for_Nick/x86_64/kv1_gp.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int values();
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   values ( _threadargs_ ) ;
   Dm = ( minf - m ) / tm ;
   Dh = ( hinf - h ) / th ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 values ( _threadargs_ ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tm )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / th )) ;
  return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   values ( _threadargs_ ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tm)))*(- ( ( ( minf ) ) / tm ) / ( ( ( ( - 1.0 ) ) ) / tm ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / th)))*(- ( ( ( hinf ) ) / th ) / ( ( ( ( - 1.0 ) ) ) / th ) - h) ;
   }
  return 0;
}
 
static int  values (  ) {
   double _lq10 ;
 _lq10 = pow( Cq10 , ( ( celsius - 22.0 ) / 10.0 ) ) ;
   minf = 1.0 / ( 1.0 + exp ( ( v - vhm ) / vcm ) ) ;
   tm = ( 1.0 / _lq10 ) * ( tm0 + Ctm * exp ( - pow( ( ( v - vhtm ) / vctm ) , 2.0 ) ) ) ;
   hinf = ( 1.0 - p ) / ( 1.0 + exp ( ( v - vhh ) / vch ) ) + p ;
   th = ( 1.0 / _lq10 ) * ( ( Cth / ( exp ( ( v - vhth ) / ath ) + exp ( - ( v - vhth ) / bth ) ) ) + th0 ) ;
   th90 = ( 1.0 / _lq10 ) * ( ( Cth / ( exp ( ( - 90.0 - vhth ) / ath ) + exp ( - ( - 90.0 - vhth ) / bth ) ) ) + th0 ) ;
    return 0; }
 
static void _hoc_values(void) {
  double _r;
   _r = 1.;
 values (  );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 ();
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  h = h0;
  m = m0;
 {
   values ( _threadargs_ ) ;
   m = minf ;
   h = hinf ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   g = gbar * ( pow( m , 2.0 ) ) * h ;
   ik = g * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
 { error =  states();
 if(error){fprintf(stderr,"at line 69 in file kv1_gp.mod:\n	SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/nickhousley/Downloads/Spindle_for_Nick/kv1_gp.mod";
static const char* nmodl_file_text = 
  ":   KV1_GP.MOD\n"
  ":\n"
  ":   Kv1.2 channel model using HH-type activation/inactivation\n"
  ":\n"
  ":   3/2003\n"
  ":   Josh Held\n"
  ":   from Mercer JN, Chan CS, Tkatch T, Held J, Surmeier DJ. Nav1.6 sodium channels\n"
  ":   are critical to pacemaking and fast spiking in globus pallidus neurons.,\n"
  ":   J Neurosci. 2007 Dec 5;27(49):13552-66. Model DB 105385\n"
  "\n"
  "	 \n"
  "NEURON {\n"
  "	SUFFIX kv1_gp\n"
  "	USEION k READ ek WRITE ik\n"
  "	RANGE th, tm, ik, hinf, minf, g, gbar\n"
  "	GLOBAL p\n"
  "	GLOBAL vhm, vcm\n"
  "	GLOBAL vhh, vch\n"
  "	GLOBAL Cth, vhth, ath, bth, th0\n"
  "	GLOBAL tm0, Ctm, vhtm, vctm\n"
  "	GLOBAL th90\n"
  "	GLOBAL Cq10\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(S) = (siemens)\n"
  "	(mV) = (millivolt)\n"
  "	(mA) = (milliamp)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gbar = 0.01	(S/cm2)  : changed from 1\n"
  "	ek		(mV)\n"
  "	vhm = -27	(mV)\n"
  "	vhh = -33.477	(mV)\n"
  "	vcm = -16	(mV)\n"
  "	vch = 21.5	(mV)\n"
  "	Cth = 548.67	(ms)\n"
  "	vhth = -0.956	(mV)\n"
  "	ath = 29.013	(mV)\n"
  "	bth= 100	(mV)\n"
  "	th0 = 779	(ms)\n"
  "	tm0 = 3.4	(ms)\n"
  "	Ctm = 89.2	(ms)\n"
  "	vhtm = -34.3	(mV)\n"
  "	vctm = 30.1	(mV)\n"
  "	p = 0.004\n"
  "	celsius		(degC)\n"
  "	Cq10 = 3\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v	(mV)\n"
  "	minf\n"
  "	hinf\n"
  "	tm	(ms)\n"
  "	th	(ms)\n"
  "	th90	(ms)\n"
  "	ik	(mA/cm2)\n"
  "	g	(S/cm2)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	m\n"
  "	h\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "	g = gbar * (m^2) * h \n"
  "	ik = g * (v - ek) \n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "	values()\n"
  "	m' = (minf - m)/tm\n"
  "	h' = (hinf - h)/th\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	values()\n"
  "	m = minf\n"
  "	h = hinf\n"
  "}\n"
  "\n"
  "PROCEDURE values() {LOCAL q10\n"
  "	q10 = Cq10^((celsius-22 (degC))/10 (degC))\n"
  "	minf = 1/(1 + exp((v - vhm)/vcm))\n"
  "	tm = (1/q10)*(tm0 + Ctm*exp(-((v-vhtm)/vctm)^2))\n"
  "\n"
  "	hinf = (1-p)/(1 + exp((v - vhh)/vch)) + p\n"
  "	th = (1/q10)*((Cth/(exp((v-vhth)/ath) + exp(-(v-vhth)/bth))) + th0)\n"
  "	th90 = (1/q10)*((Cth/(exp((-90-vhth)/ath) + exp(-(-90-vhth)/bth))) + th0)\n"
  "}\n"
  ;
#endif
