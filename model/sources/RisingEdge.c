#include "RisingEdge_macros.h"
#include "RisingEdge.h"
#include "RisingEdge_private.h"

DW_RisingEdge_T RisingEdge_DW;
ExtU_RisingEdge_T RisingEdge_U;
ExtY_RisingEdge_T RisingEdge_Y;
static RT_MODEL_RisingEdge_T RisingEdge_M_;
RT_MODEL_RisingEdge_T *const RisingEdge_M = &RisingEdge_M_;
void RisingEdge_step(void)
{
  RisingEdge_Y.T = (RisingEdge_U.u && (!RisingEdge_DW.UnitDelay_DSTATE));
  RisingEdge_DW.UnitDelay_DSTATE = RisingEdge_U.u;
  fmu_LogOutput();
}

void RisingEdge_initialize(void)
{
  (void) memset((void *)RisingEdge_M, 0,
                sizeof(RT_MODEL_RisingEdge_T));
  (void) memset((void *)&RisingEdge_DW, 0,
                sizeof(DW_RisingEdge_T));
  RisingEdge_U.u = false;
  RisingEdge_Y.T = false;
  RisingEdge_DW.UnitDelay_DSTATE = RisingEdge_P.UnitDelay_InitialCondition;
}

void RisingEdge_terminate(void)
{
}
