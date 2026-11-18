/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
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
 
#define nrn_init _nrn_init__nas
#define _nrn_initial _nrn_initial__nas
#define nrn_cur _nrn_cur__nas
#define _nrn_current _nrn_current__nas
#define nrn_jacob _nrn_jacob__nas
#define nrn_state _nrn_state__nas
#define _net_receive _net_receive__nas 
#define kin kin__nas 
#define rates rates__nas 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gbar _p[0]
#define vShift_inact_local _p[1]
#define gna _p[2]
#define ina_ina _p[3]
#define c1 _p[4]
#define c2 _p[5]
#define c3 _p[6]
#define i1 _p[7]
#define i2 _p[8]
#define i3 _p[9]
#define i4 _p[10]
#define o _p[11]
#define ift _p[12]
#define ist _p[13]
#define is1 _p[14]
#define is2 _p[15]
#define it _p[16]
#define ena _p[17]
#define ina _p[18]
#define a1 _p[19]
#define b1 _p[20]
#define a2 _p[21]
#define b2 _p[22]
#define a3 _p[23]
#define b3 _p[24]
#define ah _p[25]
#define bh _p[26]
#define tadj _p[27]
#define tadjh _p[28]
#define Dc1 _p[29]
#define Dc2 _p[30]
#define Dc3 _p[31]
#define Di1 _p[32]
#define Di2 _p[33]
#define Di3 _p[34]
#define Di4 _p[35]
#define Do _p[36]
#define Dift _p[37]
#define Dist _p[38]
#define Dis1 _p[39]
#define Dis2 _p[40]
#define Dit _p[41]
#define v _p[42]
#define _g _p[43]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
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
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
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
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_nas", _hoc_setdata,
 "rates_nas", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define aS2 aS2_nas
 double aS2 = 1e-05;
#define aS1 aS1_nas
 double aS1 = 1e-05;
#define ah_2 ah_2_nas
 double ah_2 = 0.0268011;
#define ah_1 ah_1_nas
 double ah_1 = 162.841;
#define ah_0 ah_0_nas
 double ah_0 = 0.575782;
#define a3_1 a3_1_nas
 double a3_1 = 0.0659379;
#define a3_0 a3_0_nas
 double a3_0 = 71.8119;
#define a2_1 a2_1_nas
 double a2_1 = 0.0221771;
#define a2_0 a2_0_nas
 double a2_0 = 19.8084;
#define a1_1 a1_1_nas
 double a1_1 = 0.0239354;
#define a1_0 a1_0_nas
 double a1_0 = 45.8498;
#define bS2 bS2_nas
 double bS2 = 0.05;
#define bS1 bS1_nas
 double bS1 = 0.05;
#define bh_2 bh_2_nas
 double bh_2 = 0.069603;
#define bh_1 bh_1_nas
 double bh_1 = 0.289005;
#define bh_0 bh_0_nas
 double bh_0 = 2.83015;
#define b3_1 b3_1_nas
 double b3_1 = 0.0364798;
#define b3_0 b3_0_nas
 double b3_0 = 0.753118;
#define b2_1 b2_1_nas
 double b2_1 = 0.061084;
#define b2_0 b2_0_nas
 double b2_0 = 0.565017;
#define b1_1 b1_1_nas
 double b1_1 = 0.0884761;
#define b1_0 b1_0_nas
 double b1_0 = 0.0144095;
#define maxrate maxrate_nas
 double maxrate = 8000;
#define q10h q10h_nas
 double q10h = 2.3;
#define q10 q10_nas
 double q10 = 2.3;
#define temp temp_nas
 double temp = 23;
#define vShift_inact vShift_inact_nas
 double vShift_inact = 10;
#define vShift vShift_nas
 double vShift = 12;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "a1_0_nas", "/ms",
 "a1_1_nas", "/mV",
 "b1_0_nas", "/ms",
 "b1_1_nas", "/mV",
 "a2_0_nas", "/ms",
 "a2_1_nas", "/mV",
 "b2_0_nas", "/ms",
 "b2_1_nas", "/mV",
 "a3_0_nas", "/ms",
 "a3_1_nas", "/mV",
 "b3_0_nas", "/ms",
 "b3_1_nas", "/mV",
 "bh_0_nas", "/ms",
 "bh_2_nas", "/mV",
 "ah_0_nas", "/ms",
 "ah_2_nas", "/mV",
 "aS1_nas", "1/ms",
 "bS1_nas", "1/ms",
 "aS2_nas", "1/ms",
 "bS2_nas", "1/ms",
 "vShift_nas", "mV",
 "vShift_inact_nas", "mV",
 "maxrate_nas", "/ms",
 "temp_nas", "degC",
 "gbar_nas", "pS/um2",
 "vShift_inact_local_nas", "mV",
 "gna_nas", "millimho/cm2",
 "ina_ina_nas", "milliamp/cm2",
 0,0
};
 static double c30 = 0;
 static double c20 = 0;
 static double c10 = 0;
 static double delta_t = 0.01;
 static double it0 = 0;
 static double is20 = 0;
 static double is10 = 0;
 static double ist0 = 0;
 static double ift0 = 0;
 static double i40 = 0;
 static double i30 = 0;
 static double i20 = 0;
 static double i10 = 0;
 static double o0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "a1_0_nas", &a1_0_nas,
 "a1_1_nas", &a1_1_nas,
 "b1_0_nas", &b1_0_nas,
 "b1_1_nas", &b1_1_nas,
 "a2_0_nas", &a2_0_nas,
 "a2_1_nas", &a2_1_nas,
 "b2_0_nas", &b2_0_nas,
 "b2_1_nas", &b2_1_nas,
 "a3_0_nas", &a3_0_nas,
 "a3_1_nas", &a3_1_nas,
 "b3_0_nas", &b3_0_nas,
 "b3_1_nas", &b3_1_nas,
 "bh_0_nas", &bh_0_nas,
 "bh_1_nas", &bh_1_nas,
 "bh_2_nas", &bh_2_nas,
 "ah_0_nas", &ah_0_nas,
 "ah_1_nas", &ah_1_nas,
 "ah_2_nas", &ah_2_nas,
 "aS1_nas", &aS1_nas,
 "bS1_nas", &bS1_nas,
 "aS2_nas", &aS2_nas,
 "bS2_nas", &bS2_nas,
 "vShift_nas", &vShift_nas,
 "vShift_inact_nas", &vShift_inact_nas,
 "maxrate_nas", &maxrate_nas,
 "temp_nas", &temp_nas,
 "q10_nas", &q10_nas,
 "q10h_nas", &q10h_nas,
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
"nas",
 "gbar_nas",
 "vShift_inact_local_nas",
 0,
 "gna_nas",
 "ina_ina_nas",
 0,
 "c1_nas",
 "c2_nas",
 "c3_nas",
 "i1_nas",
 "i2_nas",
 "i3_nas",
 "i4_nas",
 "o_nas",
 "ift_nas",
 "ist_nas",
 "is1_nas",
 "is2_nas",
 "it_nas",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 44, _prop);
 	/*initialize range parameters*/
 	gbar = 1000;
 	vShift_inact_local = 0;
 	_prop->param = _p;
 	_prop->param_size = 44;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _na8sts_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 3);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 44, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 nas /Users/nickhousley/Downloads/Spindle_for_Nick/x86_64/na8sts.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsprotocomma_ double);
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  1
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[10], _dlist1[10]; static double *_temp1;
 static int kin();
 
static int kin (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<10;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
   /* ~ c1 <-> c2 ( a1 , b1 )*/
 f_flux =  a1 * c1 ;
 b_flux =  b1 * c2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  a1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  b1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( a2 , b2 )*/
 f_flux =  a2 * c2 ;
 b_flux =  b2 * c3 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  a2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  b2 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c3 <-> o ( a3 , b3 )*/
 f_flux =  a3 * c3 ;
 b_flux =  b3 * o ;
 _RHS1( 1) -= (f_flux - b_flux);
 
 _term =  a3 ;
 _MATELM1( 1 ,1)  += _term;
 _term =  b3 ;
 _MATELM1( 1 ,0)  -= _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( a1 , b1 )*/
 f_flux =  a1 * i1 ;
 b_flux =  b1 * i2 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  a1 ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  b1 ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( a2 , b2 )*/
 f_flux =  a2 * i2 ;
 b_flux =  b2 * i3 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  a2 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  b2 ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ i3 <-> i4 ( a3 , b3 )*/
 f_flux =  a3 * i3 ;
 b_flux =  b3 * i4 ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  a3 ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  b3 ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ i1 <-> c1 ( ah , bh )*/
 f_flux =  ah * i1 ;
 b_flux =  bh * c1 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  ah ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 3 ,9)  -= _term;
 _term =  bh ;
 _MATELM1( 9 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ i2 <-> c2 ( ah , bh )*/
 f_flux =  ah * i2 ;
 b_flux =  bh * c2 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  ah ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 2 ,8)  -= _term;
 _term =  bh ;
 _MATELM1( 8 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ i3 <-> c3 ( ah , bh )*/
 f_flux =  ah * i3 ;
 b_flux =  bh * c3 ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  ah ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 1 ,7)  -= _term;
 _term =  bh ;
 _MATELM1( 7 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ i4 <-> o ( ah , bh )*/
 f_flux =  ah * i4 ;
 b_flux =  bh * o ;
 _RHS1( 6) -= (f_flux - b_flux);
 
 _term =  ah ;
 _MATELM1( 6 ,6)  += _term;
 _term =  bh ;
 _MATELM1( 6 ,0)  -= _term;
 /*REACTION*/
  /* ~ o <-> is1 ( tadj * aS1 , tadj * bS1 )*/
 f_flux =  tadj * aS1 * o ;
 b_flux =  tadj * bS1 * is1 ;
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  tadj * aS1 ;
 _MATELM1( 5 ,0)  -= _term;
 _term =  tadj * bS1 ;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ i4 <-> is2 ( tadj * aS2 , tadj * bS2 )*/
 f_flux =  tadj * aS2 * i4 ;
 b_flux =  tadj * bS2 * is2 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  tadj * aS2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 4 ,6)  -= _term;
 _term =  tadj * bS2 ;
 _MATELM1( 6 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + i1 + i2 + i3 + i4 + is1 + is2 + o = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= o ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= is2 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= is1 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= i4 ;
 _MATELM1(0, 7) = 1;
 _RHS1(0) -= i3 ;
 _MATELM1(0, 8) = 1;
 _RHS1(0) -= i2 ;
 _MATELM1(0, 9) = 1;
 _RHS1(0) -= i1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= c3 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= c2 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= c1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
   double _lvS ;
 _lvS = _lv - vShift ;
   tadj = pow( q10 , ( ( celsius - temp ) / 10.0 ) ) ;
   tadjh = pow( q10h , ( ( celsius - temp ) / 10.0 ) ) ;
   a1 = tadj * a1_0 * exp ( a1_1 * _lvS ) ;
   a1 = a1 * maxrate / ( a1 + maxrate ) ;
   b1 = tadj * b1_0 * exp ( - b1_1 * _lvS ) ;
   b1 = b1 * maxrate / ( b1 + maxrate ) ;
   a2 = tadj * a2_0 * exp ( a2_1 * _lvS ) ;
   a2 = a2 * maxrate / ( a2 + maxrate ) ;
   b2 = tadj * b2_0 * exp ( - b2_1 * _lvS ) ;
   b2 = b2 * maxrate / ( b2 + maxrate ) ;
   a3 = tadj * a3_0 * exp ( a3_1 * _lvS ) ;
   a3 = a3 * maxrate / ( a3 + maxrate ) ;
   b3 = tadj * b3_0 * exp ( - b3_1 * _lvS ) ;
   b3 = b3 * maxrate / ( b3 + maxrate ) ;
   bh = tadjh * bh_0 / ( 1.0 + bh_1 * exp ( - bh_2 * ( _lvS - vShift_inact - vShift_inact_local ) ) ) ;
   bh = bh * maxrate / ( bh + maxrate ) ;
   ah = tadjh * ah_0 / ( 1.0 + ah_1 * exp ( ah_2 * ( _lvS - vShift_inact - vShift_inact_local ) ) ) ;
   ah = ah * maxrate / ( ah + maxrate ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<10;_i++) _p[_dlist1[_i]] = 0.0;}
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( a1 , b1 )*/
 f_flux =  a1 * c1 ;
 b_flux =  b1 * c2 ;
 Dc1 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c2 <-> c3 ( a2 , b2 )*/
 f_flux =  a2 * c2 ;
 b_flux =  b2 * c3 ;
 Dc2 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> o ( a3 , b3 )*/
 f_flux =  a3 * c3 ;
 b_flux =  b3 * o ;
 Dc3 -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i1 <-> i2 ( a1 , b1 )*/
 f_flux =  a1 * i1 ;
 b_flux =  b1 * i2 ;
 Di1 -= (f_flux - b_flux);
 Di2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i2 <-> i3 ( a2 , b2 )*/
 f_flux =  a2 * i2 ;
 b_flux =  b2 * i3 ;
 Di2 -= (f_flux - b_flux);
 Di3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i3 <-> i4 ( a3 , b3 )*/
 f_flux =  a3 * i3 ;
 b_flux =  b3 * i4 ;
 Di3 -= (f_flux - b_flux);
 Di4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i1 <-> c1 ( ah , bh )*/
 f_flux =  ah * i1 ;
 b_flux =  bh * c1 ;
 Di1 -= (f_flux - b_flux);
 Dc1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i2 <-> c2 ( ah , bh )*/
 f_flux =  ah * i2 ;
 b_flux =  bh * c2 ;
 Di2 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i3 <-> c3 ( ah , bh )*/
 f_flux =  ah * i3 ;
 b_flux =  bh * c3 ;
 Di3 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i4 <-> o ( ah , bh )*/
 f_flux =  ah * i4 ;
 b_flux =  bh * o ;
 Di4 -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ o <-> is1 ( tadj * aS1 , tadj * bS1 )*/
 f_flux =  tadj * aS1 * o ;
 b_flux =  tadj * bS1 * is1 ;
 Do -= (f_flux - b_flux);
 Dis1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ i4 <-> is2 ( tadj * aS2 , tadj * bS2 )*/
 f_flux =  tadj * aS2 * i4 ;
 b_flux =  tadj * bS2 * is2 ;
 Di4 -= (f_flux - b_flux);
 Dis2 += (f_flux - b_flux);
 
 /*REACTION*/
   /* c1 + c2 + c3 + i1 + i2 + i3 + i4 + is1 + is2 + o = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<10;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( a1 , b1 )*/
 _term =  a1 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  b1 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( a2 , b2 )*/
 _term =  a2 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  b2 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c3 <-> o ( a3 , b3 )*/
 _term =  a3 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  b3 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ i1 <-> i2 ( a1 , b1 )*/
 _term =  a1 ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  b1 ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ i2 <-> i3 ( a2 , b2 )*/
 _term =  a2 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  b2 ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ i3 <-> i4 ( a3 , b3 )*/
 _term =  a3 ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  b3 ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ i1 <-> c1 ( ah , bh )*/
 _term =  ah ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 3 ,9)  -= _term;
 _term =  bh ;
 _MATELM1( 9 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ i2 <-> c2 ( ah , bh )*/
 _term =  ah ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 2 ,8)  -= _term;
 _term =  bh ;
 _MATELM1( 8 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ i3 <-> c3 ( ah , bh )*/
 _term =  ah ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 1 ,7)  -= _term;
 _term =  bh ;
 _MATELM1( 7 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ i4 <-> o ( ah , bh )*/
 _term =  ah ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 0 ,6)  -= _term;
 _term =  bh ;
 _MATELM1( 6 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ o <-> is1 ( tadj * aS1 , tadj * bS1 )*/
 _term =  tadj * aS1 ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 5 ,0)  -= _term;
 _term =  tadj * bS1 ;
 _MATELM1( 0 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ i4 <-> is2 ( tadj * aS2 , tadj * bS2 )*/
 _term =  tadj * aS2 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 4 ,6)  -= _term;
 _term =  tadj * bS2 ;
 _MATELM1( 6 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + i1 + i2 + i3 + i4 + is1 + is2 + o = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 10;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 10; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 10, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  c3 = c30;
  c2 = c20;
  c1 = c10;
  it = it0;
  is2 = is20;
  is1 = is10;
  ist = ist0;
  ift = ift0;
  i4 = i40;
  i3 = i30;
  i2 = i20;
  i1 = i10;
  o = o0;
 {
    _ss_sparse_thread(&_thread[_spth1]._pvoid, 10, _slist1, _dlist1, _p, &t, dt, kin, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 10; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gna = gbar * o ;
   ina = gna * ( v - ena ) * ( 1e-4 ) ;
   ina_ina = gna * ( v - ena ) * ( 1e-4 ) ;
   ift = i1 + i2 + i3 + i4 ;
   ist = is1 + is2 ;
   it = ift + ist ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 {  sparse_thread(&_thread[_spth1]._pvoid, 10, _slist1, _dlist1, _p, &t, dt, kin, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 10; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(o) - _p;  _dlist1[0] = &(Do) - _p;
 _slist1[1] = &(c3) - _p;  _dlist1[1] = &(Dc3) - _p;
 _slist1[2] = &(c2) - _p;  _dlist1[2] = &(Dc2) - _p;
 _slist1[3] = &(c1) - _p;  _dlist1[3] = &(Dc1) - _p;
 _slist1[4] = &(is2) - _p;  _dlist1[4] = &(Dis2) - _p;
 _slist1[5] = &(is1) - _p;  _dlist1[5] = &(Dis1) - _p;
 _slist1[6] = &(i4) - _p;  _dlist1[6] = &(Di4) - _p;
 _slist1[7] = &(i3) - _p;  _dlist1[7] = &(Di3) - _p;
 _slist1[8] = &(i2) - _p;  _dlist1[8] = &(Di2) - _p;
 _slist1[9] = &(i1) - _p;  _dlist1[9] = &(Di1) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/nickhousley/Downloads/Spindle_for_Nick/na8sts.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "\n"
  " Originally eight state kinetic sodium channel gating scheme, two slow inactivation\n"
  " states is1 and is2 added by RKP\n"
  "\n"
  "Modified from k3st.mod, chapter 9.9 (example 9.7) of the NEURON book\n"
  "12 August 2008, Christoph Schmidt-Hieber\n"
  "accompanies the publication:\n"
  "Schmidt-Hieber C, Bischofberger J. (2010)\n"
  "Fast sodium channel gating supports localized and efficient \n"
  "axonal action potential initiation.\n"
  "J Neurosci 30:10233-42\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "\n"
  "NEURON {\n"
  "\n"
  "    SUFFIX nas\n"
  "\n"
  "    USEION na READ ena WRITE ina\n"
  "\n"
  "    GLOBAL vShift, vShift_inact, maxrate\n"
  "\n"
  "    RANGE vShift_inact_local\n"
  "\n"
  "    RANGE gna, gbar, ina_ina\n"
  "\n"
  ":    RANGE a1_0, a1_1, b1_0, b1_1, a2_0, a2_1  commented out by RKP\n"
  ":    RANGE b2_0, b2_1, a3_0, a3_1, b3_0, b3_1  commented out by RKP\n"
  ":    RANGE bh_0, bh_1, bh_2, ah_0, ah_1, ah_2  commented out by RKP\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "UNITS { (mV) = (millivolt) }\n"
  "\n"
  "\n"
  "\n"
  ": initialize parameters\n"
  "\n"
  "\n"
  "\n"
  "PARAMETER {\n"
  "\n"
  ":   gbar = 33     (millimho/cm2)\n"
  "    gbar = 1000     (pS/um2)\n"
  "\n"
  "\n"
  "\n"
  "    a1_0 = 4.584982656184167e+01 (/ms)\n"
  "\n"
  "    a1_1 = 2.393541665657613e-02 (/mV) \n"
  "\n"
  "    \n"
  "\n"
  "    b1_0 = 1.440952344322651e-02 (/ms)\n"
  "\n"
  "    b1_1 = 8.847609128769419e-02 (/mV)\n"
  "\n"
  "\n"
  "\n"
  "    a2_0 = 1.980838207143563e+01 (/ms)\n"
  "\n"
  "    a2_1 = 2.217709530008501e-02 (/mV) \n"
  "\n"
  "    \n"
  "\n"
  "    b2_0 = 5.650174488683913e-01 (/ms)\n"
  "\n"
  "    b2_1 = 6.108403283302217e-02 (/mV)\n"
  "\n"
  "\n"
  "\n"
  "    a3_0 = 7.181189201089192e+01 (/ms)\n"
  "\n"
  "    a3_1 = 6.593790601261940e-02 (/mV) \n"
  "\n"
  "    \n"
  "\n"
  "    b3_0 = 7.531178253431512e-01 (/ms)\n"
  "\n"
  "    b3_1 = 3.647978133116471e-02 (/mV)\n"
  "\n"
  "\n"
  "\n"
  "    bh_0 = 2.830146966213825e+00 (/ms)\n"
  "\n"
  "    bh_1 = 2.890045633775495e-01\n"
  "\n"
  "    bh_2 = 6.960300544163878e-02 (/mV)\n"
  "\n"
  "\n"
  "\n"
  "    ah_0 = 5.757824421450554e-01 (/ms)\n"
  "\n"
  "    ah_1 = 1.628407420157048e+02\n"
  "\n"
  "    ah_2 = 2.680107016756367e-02 (/mV)\n"
  "\n"
  "    aS1 = 0.00001	(1/ms)  :default is low so there is little slow inact\n"
  "    bS1 = 0.05	(1/ms)\n"
  "    aS2 = 0.00001	(1/ms)  :default is low so there is little slow inact\n"
  "    bS2 = 0.05	(1/ms)\n"
  "\n"
  "\n"
  "    vShift = 12            (mV)  : shift to the right to account for Donnan potentials\n"
  "\n"
  "                                 : 12 mV for cclamp, 0 for oo-patch vclamp simulations\n"
  "\n"
  "    vShift_inact = 10      (mV)  : global additional shift to the right for inactivation\n"
  "\n"
  "                                 : 10 mV for cclamp, 0 for oo-patch vclamp simulations\n"
  "\n"
  "    vShift_inact_local = 0 (mV)  : additional shift to the right for inactivation, used as local range variable\n"
  "\n"
  "    maxrate = 8.00e+03     (/ms) : limiting value for reaction rates\n"
  "\n"
  "                                 : See Patlak, 1991\n"
  "\n"
  "	temp = 23	(degC)		: original temp \n"
  "	q10  = 2.3			: temperature sensitivity\n"
  "	q10h  = 2.3			: temperature sensitivity for inactivatoin\n"
  "	celsius		(degC)\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "ASSIGNED {\n"
  "\n"
  "    v    (mV)\n"
  "\n"
  "    ena  (mV)\n"
  "\n"
  "    gna    (millimho/cm2)\n"
  "\n"
  "    ina  (milliamp/cm2)\n"
  "\n"
  "   ina_ina  (milliamp/cm2)	:to monitor\n"
  "\n"
  "    a1   (/ms)\n"
  "\n"
  "    b1   (/ms)\n"
  "\n"
  "    a2   (/ms)\n"
  "\n"
  "    b2   (/ms)\n"
  "\n"
  "    a3   (/ms)\n"
  "\n"
  "    b3   (/ms)\n"
  "\n"
  "    ah   (/ms)\n"
  "\n"
  "    bh   (/ms)\n"
  "\n"
  "    tadj\n"
  "	\n"
  "    tadjh\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "STATE { c1 c2 c3 i1 i2 i3 i4 o ift ist is1 is2 it}\n"
  "\n"
  "\n"
  "\n"
  "BREAKPOINT {\n"
  "\n"
  "    SOLVE kin METHOD sparse\n"
  "\n"
  "    gna = gbar*o\n"
  "\n"
  ":   ina = g*(v - ena)*(1e-3)\n"
  "    ina = gna*(v - ena)*(1e-4) 	: define  gbar as pS/um2 instead of mllimho/cm2\n"
  "    ina_ina = gna*(v - ena)*(1e-4) 	: define  gbar as pS/um2 instead of mllimho/cm2		:to monitor\n"
  "    ift = i1 + i2 + i3 + i4  : total fast inactivation\n"
  "    ist=is1+is2     : total slow inactivation\n"
  "    it = ift + ist    : total inactivation\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "INITIAL { SOLVE kin STEADYSTATE sparse }\n"
  "\n"
  "\n"
  "\n"
  "KINETIC kin {\n"
  "\n"
  "    rates(v)\n"
  "\n"
  "    ~ c1 <-> c2 (a1, b1)\n"
  "\n"
  "    ~ c2 <-> c3 (a2, b2)\n"
  "\n"
  "    ~ c3 <-> o (a3, b3)\n"
  "\n"
  "    ~ i1 <-> i2 (a1, b1)\n"
  "\n"
  "    ~ i2 <-> i3 (a2, b2)\n"
  "\n"
  "    ~ i3 <-> i4 (a3, b3)\n"
  "\n"
  "    ~ i1 <-> c1 (ah, bh)\n"
  "\n"
  "    ~ i2 <-> c2 (ah, bh)\n"
  "\n"
  "    ~ i3 <-> c3 (ah, bh)\n"
  "\n"
  "    ~ i4 <-> o  (ah, bh)\n"
  " \n"
  "    ~ o <-> is1 (tadj*aS1, tadj*bS1)\n"
  "\n"
  "    ~ i4 <-> is2 (tadj*aS2, tadj*bS2)\n"
  "\n"
  "    CONSERVE c1 + c2 + c3 + i1 + i2 + i3 + i4 + is1 + is2 + o = 1\n"
  "\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  ": FUNCTION_TABLE tau1(v(mV)) (ms)\n"
  "\n"
  ": FUNCTION_TABLE tau2(v(mV)) (ms)\n"
  "\n"
  "\n"
  "\n"
  "PROCEDURE rates(v(millivolt)) {\n"
  "\n"
  "    LOCAL vS\n"
  "\n"
  "    vS = v-vShift\n"
  "\n"
  "    tadj = q10^((celsius - temp)/10)\n"
  "\n"
  "    tadjh = q10h^((celsius - temp)/10)\n"
  "\n"
  "\n"
  ":   maxrate = tadj*maxrate\n"
  "\n"
  "\n"
  "    a1 = tadj*a1_0*exp( a1_1*vS)\n"
  "\n"
  "    a1 = a1*maxrate / (a1+maxrate)\n"
  "\n"
  "    b1 = tadj*b1_0*exp(-b1_1*vS)\n"
  "\n"
  "    b1 = b1*maxrate / (b1+maxrate)\n"
  "\n"
  "    \n"
  "\n"
  "    a2 = tadj*a2_0*exp( a2_1*vS)\n"
  "\n"
  "    a2 = a2*maxrate / (a2+maxrate)\n"
  "\n"
  "    b2 = tadj*b2_0*exp(-b2_1*vS)\n"
  "\n"
  "    b2 = b2*maxrate / (b2+maxrate)\n"
  "\n"
  "    \n"
  "\n"
  "    a3 = tadj*a3_0*exp( a3_1*vS)\n"
  "\n"
  "    a3 = a3*maxrate / (a3+maxrate)\n"
  "\n"
  "    b3 = tadj*b3_0*exp(-b3_1*vS)\n"
  "\n"
  "    b3 = b3*maxrate / (b3+maxrate)\n"
  "\n"
  "    \n"
  "\n"
  "    bh = tadjh*bh_0/(1+bh_1*exp(-bh_2*(vS-vShift_inact-vShift_inact_local)))\n"
  "\n"
  "    bh = bh*maxrate / (bh+maxrate)\n"
  "\n"
  "    ah = tadjh*ah_0/(1+ah_1*exp( ah_2*(vS-vShift_inact-vShift_inact_local)))\n"
  "\n"
  "    ah = ah*maxrate / (ah+maxrate)\n"
  "\n"
  "}\n"
  "\n"
  ;
#endif
