#ifndef RTW_HEADER_RisingEdge_h_
#define RTW_HEADER_RisingEdge_h_
#include <string.h>
#ifndef RisingEdge_COMMON_INCLUDES_
#define RisingEdge_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif

#include "RisingEdge_types.h"

#include "multiword_types.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
  boolean_T UnitDelay_DSTATE;
} DW_RisingEdge_T;

typedef struct {
  boolean_T u;
} ExtU_RisingEdge_T;

typedef struct {
  boolean_T T;
} ExtY_RisingEdge_T;

struct P_RisingEdge_T_ {
  boolean_T UnitDelay_InitialCondition;
};

struct tag_RTM_RisingEdge_T {
  const char_T *errorStatus;
};

extern P_RisingEdge_T RisingEdge_P;
extern DW_RisingEdge_T RisingEdge_DW;
extern ExtU_RisingEdge_T RisingEdge_U;
extern ExtY_RisingEdge_T RisingEdge_Y;
extern void RisingEdge_initialize(void);
extern void RisingEdge_step(void);
extern void RisingEdge_terminate(void);
extern RT_MODEL_RisingEdge_T *const RisingEdge_M;
extern void fmu_LogOutput();

#endif
