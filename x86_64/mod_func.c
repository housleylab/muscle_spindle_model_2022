#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _km_reg(void);
extern void _Kv1_axonal_reg(void);
extern void _kv1_gp_reg(void);
extern void _Kv3_reg(void);
extern void _Kv11_reg(void);
extern void _mAHP_reg(void);
extern void _MRCHas_reg(void);
extern void _na8sts_reg(void);
extern void _nav1p8_reg(void);
extern void _nav17_reg(void);
extern void _nax8sts_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," km.mod");
    fprintf(stderr," Kv1_axonal.mod");
    fprintf(stderr," kv1_gp.mod");
    fprintf(stderr," Kv3.mod");
    fprintf(stderr," Kv11.mod");
    fprintf(stderr," mAHP.mod");
    fprintf(stderr," MRCHas.mod");
    fprintf(stderr," na8sts.mod");
    fprintf(stderr," nav1p8.mod");
    fprintf(stderr," nav17.mod");
    fprintf(stderr," nax8sts.mod");
    fprintf(stderr, "\n");
  }
  _km_reg();
  _Kv1_axonal_reg();
  _kv1_gp_reg();
  _Kv3_reg();
  _Kv11_reg();
  _mAHP_reg();
  _MRCHas_reg();
  _na8sts_reg();
  _nav1p8_reg();
  _nav17_reg();
  _nax8sts_reg();
}
