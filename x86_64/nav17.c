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
 
#define nrn_init _nrn_init__nav17
#define _nrn_initial _nrn_initial__nav17
#define nrn_cur _nrn_cur__nav17
#define _nrn_current _nrn_current__nav17
#define nrn_jacob _nrn_jacob__nav17
#define nrn_state _nrn_state__nav17
#define _net_receive _net_receive__nav17 
#define rates rates__nav17 
#define states states__nav17 
 
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
#define g _p[1]
#define ina _p[2]
#define c1 _p[3]
#define c2 _p[4]
#define c3 _p[5]
#define o _p[6]
#define I1 _p[7]
#define I2 _p[8]
#define ena _p[9]
#define k12 _p[10]
#define k21 _p[11]
#define k23 _p[12]
#define k32 _p[13]
#define k34 _p[14]
#define k43 _p[15]
#define k45 _p[16]
#define k54 _p[17]
#define k56 _p[18]
#define k65 _p[19]
#define k35 _p[20]
#define k53 _p[21]
#define k36 _p[22]
#define k63 _p[23]
#define k26 _p[24]
#define k62 _p[25]
#define qt _p[26]
#define Dc1 _p[27]
#define Dc2 _p[28]
#define Dc3 _p[29]
#define Do _p[30]
#define DI1 _p[31]
#define DI2 _p[32]
#define v _p[33]
#define _g _p[34]
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
 "setdata_nav17", _hoc_setdata,
 "rates_nav17", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define a62 a62_nav17
 double a62 = 0.29;
#define a26 a26_nav17
 double a26 = 0.26;
#define a63 a63_nav17
 double a63 = 0.02;
#define a36 a36_nav17
 double a36 = 0.01;
#define a53 a53_nav17
 double a53 = 6.3e-08;
#define a35 a35_nav17
 double a35 = 0.22;
#define a65 a65_nav17
 double a65 = 3.8e+08;
#define a56 a56_nav17
 double a56 = 51;
#define a54 a54_nav17
 double a54 = 3e-05;
#define a45 a45_nav17
 double a45 = 1.6;
#define a43 a43_nav17
 double a43 = 1;
#define a34 a34_nav17
 double a34 = 65;
#define a32 a32_nav17
 double a32 = 14;
#define a23 a23_nav17
 double a23 = 27;
#define a21 a21_nav17
 double a21 = 1.1;
#define a12 a12_nav17
 double a12 = 18;
#define z62 z62_nav17
 double z62 = 0.0044;
#define z26 z26_nav17
 double z26 = 0.0014;
#define z63 z63_nav17
 double z63 = 0.184;
#define z36 z36_nav17
 double z36 = 0.095;
#define z53 z53_nav17
 double z53 = 0.039;
#define z35 z35_nav17
 double z35 = 0.057;
#define z65 z65_nav17
 double z65 = 0.22;
#define z56 z56_nav17
 double z56 = 0.035;
#define z54 z54_nav17
 double z54 = 2e-05;
#define z45 z45_nav17
 double z45 = 0.012;
#define z43 z43_nav17
 double z43 = 0.02;
#define z34 z34_nav17
 double z34 = 0.064;
#define z32 z32_nav17
 double z32 = 0.054;
#define z23 z23_nav17
 double z23 = 0.041;
#define z21 z21_nav17
 double z21 = 0.034;
#define z12 z12_nav17
 double z12 = 0.023;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "a12_nav17", "/ms",
 "a21_nav17", "/ms",
 "a23_nav17", "/ms",
 "a32_nav17", "/ms",
 "a34_nav17", "/ms",
 "a43_nav17", "/ms",
 "a45_nav17", "/ms",
 "a54_nav17", "/ms",
 "a56_nav17", "/ms",
 "a65_nav17", "/ms",
 "a35_nav17", "/ms",
 "a53_nav17", "/ms",
 "a36_nav17", "/ms",
 "a63_nav17", "/ms",
 "a26_nav17", "/ms",
 "a62_nav17", "/ms",
 "z12_nav17", "/mV",
 "z21_nav17", "/mV",
 "z23_nav17", "/mV",
 "z32_nav17", "/mV",
 "z34_nav17", "/mV",
 "z43_nav17", "/mV",
 "z45_nav17", "/mV",
 "z54_nav17", "/mV",
 "z56_nav17", "/mV",
 "z65_nav17", "/mV",
 "z35_nav17", "/mV",
 "z53_nav17", "/mV",
 "z36_nav17", "/mV",
 "z63_nav17", "/mV",
 "z26_nav17", "/mV",
 "z62_nav17", "/mV",
 "gbar_nav17", "pS/um2",
 "g_nav17", "pS/um2",
 "ina_nav17", "mA/cm2",
 0,0
};
 static double I20 = 0;
 static double I10 = 0;
 static double c30 = 0;
 static double c20 = 0;
 static double c10 = 0;
 static double delta_t = 0.01;
 static double o0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "a12_nav17", &a12_nav17,
 "a21_nav17", &a21_nav17,
 "a23_nav17", &a23_nav17,
 "a32_nav17", &a32_nav17,
 "a34_nav17", &a34_nav17,
 "a43_nav17", &a43_nav17,
 "a45_nav17", &a45_nav17,
 "a54_nav17", &a54_nav17,
 "a56_nav17", &a56_nav17,
 "a65_nav17", &a65_nav17,
 "a35_nav17", &a35_nav17,
 "a53_nav17", &a53_nav17,
 "a36_nav17", &a36_nav17,
 "a63_nav17", &a63_nav17,
 "a26_nav17", &a26_nav17,
 "a62_nav17", &a62_nav17,
 "z12_nav17", &z12_nav17,
 "z21_nav17", &z21_nav17,
 "z23_nav17", &z23_nav17,
 "z32_nav17", &z32_nav17,
 "z34_nav17", &z34_nav17,
 "z43_nav17", &z43_nav17,
 "z45_nav17", &z45_nav17,
 "z54_nav17", &z54_nav17,
 "z56_nav17", &z56_nav17,
 "z65_nav17", &z65_nav17,
 "z35_nav17", &z35_nav17,
 "z53_nav17", &z53_nav17,
 "z36_nav17", &z36_nav17,
 "z63_nav17", &z63_nav17,
 "z26_nav17", &z26_nav17,
 "z62_nav17", &z62_nav17,
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
"nav17",
 "gbar_nav17",
 0,
 "g_nav17",
 "ina_nav17",
 0,
 "c1_nav17",
 "c2_nav17",
 "c3_nav17",
 "o_nav17",
 "I1_nav17",
 "I2_nav17",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 35, _prop);
 	/*initialize range parameters*/
 	gbar = 0;
 	_prop->param = _p;
 	_prop->param_size = 35;
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

 void _nav17_reg() {
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
  hoc_register_prop_size(_mechtype, 35, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 nav17 /Users/nickhousley/Downloads/Spindle_for_Nick/x86_64/nav17.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double q10 = 3;
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
 static int _slist1[6], _dlist1[6]; static double *_temp1;
 static int states();
 
static int states (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<6;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
   /* ~ c1 <-> c2 ( k12 , k21 )*/
 f_flux =  k12 * c1 ;
 b_flux =  k21 * c2 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  k12 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  k21 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( k23 , k32 )*/
 f_flux =  k23 * c2 ;
 b_flux =  k32 * c3 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  k23 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  k32 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c3 <-> o ( k34 , k43 )*/
 f_flux =  k34 * c3 ;
 b_flux =  k43 * o ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  k34 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 5 ,2)  -= _term;
 _term =  k43 ;
 _MATELM1( 2 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ o <-> I1 ( k45 , k54 )*/
 f_flux =  k45 * o ;
 b_flux =  k54 * I1 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  k45 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 1 ,5)  -= _term;
 _term =  k54 ;
 _MATELM1( 5 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( k56 , k65 )*/
 f_flux =  k56 * I1 ;
 b_flux =  k65 * I2 ;
 _RHS1( 1) -= (f_flux - b_flux);
 
 _term =  k56 ;
 _MATELM1( 1 ,1)  += _term;
 _term =  k65 ;
 _MATELM1( 1 ,0)  -= _term;
 /*REACTION*/
  /* ~ c3 <-> I1 ( k35 , k53 )*/
 f_flux =  k35 * c3 ;
 b_flux =  k53 * I1 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  k35 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  k53 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c3 <-> I2 ( k36 , k63 )*/
 f_flux =  k36 * c3 ;
 b_flux =  k63 * I2 ;
 _RHS1( 2) -= (f_flux - b_flux);
 
 _term =  k36 ;
 _MATELM1( 2 ,2)  += _term;
 _term =  k63 ;
 _MATELM1( 2 ,0)  -= _term;
 /*REACTION*/
  /* ~ c2 <-> I2 ( k26 , k62 )*/
 f_flux =  k26 * c2 ;
 b_flux =  k62 * I2 ;
 _RHS1( 3) -= (f_flux - b_flux);
 
 _term =  k26 ;
 _MATELM1( 3 ,3)  += _term;
 _term =  k62 ;
 _MATELM1( 3 ,0)  -= _term;
 /*REACTION*/
   /* c1 + c2 + c3 + o + I1 + I2 = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= I2 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= I1 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= o ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= c3 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= c2 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= c1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
   k12 = a12 * exp ( z12 * _lv ) * qt ;
   k21 = a21 * exp ( - z21 * _lv ) * qt ;
   k23 = a23 * exp ( z23 * _lv ) * qt ;
   k32 = a32 * exp ( - z32 * _lv ) * qt ;
   k34 = a34 * exp ( z34 * _lv ) * qt ;
   k43 = a43 * exp ( - z43 * _lv ) * qt ;
   k45 = a45 * exp ( z45 * _lv ) * qt ;
   k54 = a54 * exp ( - z54 * _lv ) * qt ;
   k56 = a56 * exp ( z56 * _lv ) * qt ;
   k65 = a65 * exp ( z65 * _lv ) * qt ;
   k35 = a35 * exp ( z35 * _lv ) * qt ;
   k53 = a53 * exp ( - z53 * _lv ) * qt ;
   k36 = a36 * exp ( z36 * _lv ) * qt ;
   k63 = a63 * exp ( z63 * _lv ) * qt ;
   k26 = a26 * exp ( z26 * _lv ) * qt ;
   k62 = a62 * exp ( - z62 * _lv ) * qt ;
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
 {int _i; for(_i=0;_i<6;_i++) _p[_dlist1[_i]] = 0.0;}
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( k12 , k21 )*/
 f_flux =  k12 * c1 ;
 b_flux =  k21 * c2 ;
 Dc1 -= (f_flux - b_flux);
 Dc2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c2 <-> c3 ( k23 , k32 )*/
 f_flux =  k23 * c2 ;
 b_flux =  k32 * c3 ;
 Dc2 -= (f_flux - b_flux);
 Dc3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> o ( k34 , k43 )*/
 f_flux =  k34 * c3 ;
 b_flux =  k43 * o ;
 Dc3 -= (f_flux - b_flux);
 Do += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ o <-> I1 ( k45 , k54 )*/
 f_flux =  k45 * o ;
 b_flux =  k54 * I1 ;
 Do -= (f_flux - b_flux);
 DI1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I1 <-> I2 ( k56 , k65 )*/
 f_flux =  k56 * I1 ;
 b_flux =  k65 * I2 ;
 DI1 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> I1 ( k35 , k53 )*/
 f_flux =  k35 * c3 ;
 b_flux =  k53 * I1 ;
 Dc3 -= (f_flux - b_flux);
 DI1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c3 <-> I2 ( k36 , k63 )*/
 f_flux =  k36 * c3 ;
 b_flux =  k63 * I2 ;
 Dc3 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ c2 <-> I2 ( k26 , k62 )*/
 f_flux =  k26 * c2 ;
 b_flux =  k62 * I2 ;
 Dc2 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
   /* c1 + c2 + c3 + o + I1 + I2 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<6;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
 /* ~ c1 <-> c2 ( k12 , k21 )*/
 _term =  k12 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  k21 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ c2 <-> c3 ( k23 , k32 )*/
 _term =  k23 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  k32 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ c3 <-> o ( k34 , k43 )*/
 _term =  k34 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 5 ,2)  -= _term;
 _term =  k43 ;
 _MATELM1( 2 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ o <-> I1 ( k45 , k54 )*/
 _term =  k45 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 1 ,5)  -= _term;
 _term =  k54 ;
 _MATELM1( 5 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( k56 , k65 )*/
 _term =  k56 ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 0 ,1)  -= _term;
 _term =  k65 ;
 _MATELM1( 1 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ c3 <-> I1 ( k35 , k53 )*/
 _term =  k35 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  k53 ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ c3 <-> I2 ( k36 , k63 )*/
 _term =  k36 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 0 ,2)  -= _term;
 _term =  k63 ;
 _MATELM1( 2 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ c2 <-> I2 ( k26 , k62 )*/
 _term =  k26 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 0 ,3)  -= _term;
 _term =  k62 ;
 _MATELM1( 3 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
   /* c1 + c2 + c3 + o + I1 + I2 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 6;}
 
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
	for (_i=0; _i < 6; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 6, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
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
  I2 = I20;
  I1 = I10;
  c3 = c30;
  c2 = c20;
  c1 = c10;
  o = o0;
 {
    _ss_sparse_thread(&_thread[_spth1]._pvoid, 6, _slist1, _dlist1, _p, &t, dt, states, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 6; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 qt = pow( q10 , ( ( celsius - 21.0 ) / 10.0 ) ) ;
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
   g = gbar * o ;
   ina = ( 1e-4 ) * g * ( v - ena ) ;
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
 {  sparse_thread(&_thread[_spth1]._pvoid, 6, _slist1, _dlist1, _p, &t, dt, states, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 6; ++_i) {
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
 _slist1[0] = &(I2) - _p;  _dlist1[0] = &(DI2) - _p;
 _slist1[1] = &(I1) - _p;  _dlist1[1] = &(DI1) - _p;
 _slist1[2] = &(c3) - _p;  _dlist1[2] = &(Dc3) - _p;
 _slist1[3] = &(c2) - _p;  _dlist1[3] = &(Dc2) - _p;
 _slist1[4] = &(c1) - _p;  _dlist1[4] = &(Dc1) - _p;
 _slist1[5] = &(o) - _p;  _dlist1[5] = &(Do) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/nickhousley/Downloads/Spindle_for_Nick/nav17.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "Six state HMM kinetic scheme for the WT Voltage-Gated Sodium Channel Nav1.7\n"
  "From the paper Kinetic Modeling of Nav1.7 Provides Insight Into Erythromelalgia-associated F1449V Mutation\n"
  "Gurkiewicz et al., J.Neurophysiol. (2011).\n"
  "RKP changed suffix and name to nav17 (formerly wtnag3e and WTNaG3e) and added temperature dependence\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX nav17\n"
  "	USEION na READ ena WRITE ina\n"
  "	RANGE g, gbar,ina\n"
  "}\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "	(pS) = (picosiemens)\n"
  "	(um) = (micron)\n"
  "}\n"
  "\n"
  "CONSTANT {\n"
  "	q10 = 3\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	celsius	(degC)\n"
  "	gbar = 0			(pS/um2)\n"
  "	a12 = 18			(/ms)\n"
  "	a21 = 1.1			(/ms)\n"
  "	a23 = 27			(/ms)\n"
  "	a32 = 14			(/ms)\n"
  "	a34 = 65			(/ms)\n"
  "	a43 = 1				(/ms)\n"
  "	a45 = 1.6			(/ms)\n"
  "	a54 = 3e-5			(/ms)\n"
  "	a56 = 51			(/ms)\n"
  "	a65 = 3.8e8			(/ms)\n"
  "	a35 = 0.22			(/ms)\n"
  "	a53 = 6.3e-8		(/ms)\n"
  "	a36 = 0.01			(/ms)\n"
  "	a63 = 0.02			(/ms)\n"
  "	a26 = 0.26			(/ms)\n"
  "	a62 = 0.29			(/ms)\n"
  "	z12 = 0.023			(/mV)\n"
  "	z21 = 0.034			(/mV)\n"
  "	z23 = 0.041			(/mV)\n"
  "	z32 = 0.054			(/mV)\n"
  "	z34 = 0.064			(/mV)\n"
  "	z43 = 0.02			(/mV)\n"
  "	z45 = 0.012			(/mV)\n"
  "	z54 = 2e-5			(/mV)\n"
  "	z56 = 0.035			(/mV)\n"
  "	z65 = 0.22			(/mV)\n"
  "	z35 = 0.057			(/mV)\n"
  "	z53 = 0.039			(/mV)\n"
  "	z36 = 0.095			(/mV)\n"
  "	z63 = 0.184			(/mV)\n"
  "	z26 = 1.4e-3		(/mV)\n"
  "	z62 = 4.4e-3		(/mV)\n"
  "}\n"
  "ASSIGNED {\n"
  "	v       (mV)\n"
  "	ena     (mV)\n"
  "	g       (pS/um2)\n"
  "	ina     (mA/cm2)\n"
  "	k12     (/ms)\n"
  "	k21     (/ms)\n"
  "	k23     (/ms)\n"
  "	k32     (/ms)\n"
  "	k34     (/ms)\n"
  "	k43     (/ms)\n"
  "	k45     (/ms)\n"
  "	k54     (/ms)\n"
  "	k56     (/ms)\n"
  "	k65     (/ms)\n"
  "	k35     (/ms)\n"
  "	k53     (/ms)\n"
  "	k36     (/ms)\n"
  "	k63     (/ms)\n"
  "	k26     (/ms)\n"
  "	k62     (/ms)\n"
  "	qt\n"
  "}\n"
  "\n"
  "STATE { c1 c2 c3 o I1 I2 }\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD sparse\n"
  "		g = gbar*o\n"
  "		ina = (1e-4) * g*(v - ena)\n"
  "}\n"
  "\n"
  "INITIAL { \n"
  "	SOLVE states STEADYSTATE sparse\n"
  "	qt = q10^((celsius-21 (degC))/10 (degC))	:21 was stated temp in Gurkiewicz et al\n"
  "}\n"
  "\n"
  "KINETIC states {\n"
  "	rates(v)\n"
  "        ~c1 <-> c2      (k12,k21)\n"
  "        ~c2 <-> c3      (k23,k32)\n"
  "        ~c3 <-> o       (k34,k43)\n"
  "        ~o <-> I1       (k45,k54)\n"
  "        ~I1 <-> I2      (k56,k65)\n"
  "        ~c3 <-> I1      (k35,k53)\n"
  "        ~c3 <-> I2      (k36,k63)\n"
  "        ~c2 <-> I2      (k26,k62)\n"
  "	CONSERVE c1+c2+c3+o+I1+I2=1\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v(millivolt)) {\n"
  "\n"
  "	k12 = a12*exp(z12*v) * qt\n"
  "	k21 = a21*exp(-z21*v) * qt\n"
  "	k23 = a23*exp(z23*v) * qt\n"
  "	k32 = a32*exp(-z32*v) * qt\n"
  "	k34 = a34*exp(z34*v) * qt\n"
  "	k43 = a43*exp(-z43*v) * qt\n"
  "	k45 = a45*exp(z45*v) * qt\n"
  "	k54 = a54*exp(-z54*v) * qt\n"
  "	k56 = a56*exp(z56*v) * qt\n"
  "	k65 = a65*exp(z65*v) * qt\n"
  "	k35 = a35*exp(z35*v) * qt\n"
  "	k53 = a53*exp(-z53*v) * qt\n"
  "	k36 = a36*exp(z36*v) * qt\n"
  "	k63 = a63*exp(z63*v) * qt\n"
  "	k26 = a26*exp(z26*v) * qt\n"
  "	k62 = a62*exp(-z62*v) * qt\n"
  "}\n"
  ;
#endif
