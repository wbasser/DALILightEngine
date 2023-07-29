/******************************************************************************
 * @file TaskManager_cfg.c
 *
 * @brief task manager configuration implementation
 *
 * This file contains the task definitions structures
 *
 * @copyright Copyright (c) 2012 CyberIntegration
 * This document contains proprietary data and information of CyberIntegration 
 * LLC. It is the exclusive property of CyberIntegration, LLC and will not be 
 * disclosed in any form to any party without prior written permission of 
 * CyberIntegration, LLC. This document may not be reproduced or further used 
 * without the prior written permission of CyberIntegration, LLC.
 *
 * Version History
 * ======
 * $Rev: $
 * 
 *
 * \addtogroup TaskManager
 * @{
 *****************************************************************************/

// system includes ------------------------------------------------------------

// local includes -------------------------------------------------------------
#include "TaskManager/TaskManager_cfg.h"

// library includes -----------------------------------------------------------
#include "DALIMessageHandler/DALIMessageHandler.h"
#include "DbgAscCommandHandler/DbgAscCommandHandler.h"
#include "ManchesterCodec/ManchesterCodec.h"
#include "StatusManager/StatusManager.h"
#include "SystemControlManager/SystemControlManager.h"

// Macros and Defines ---------------------------------------------------------

// enumerations ---------------------------------------------------------------

// structures -----------------------------------------------------------------

// global parameter declarations ----------------------------------------------
/// declare event buffers here
// TASKEVENTSTORAGE( bufname, size )
TASKEVENTSTORAGE( SysCtrl,  SYSCTRLMNGR_TASK_NUM_EVENTS     );
TASKEVENTSTORAGE( DbgChar,  DBGASCCOMMANDHANDLER_NUM_EVENTS );
TASKEVENTSTORAGE( StsCtrl,  STATUSMANAGER_NUM_EVENTS        );
TASKEVENTSTORAGE( ManRecv,  MANCHESTERCODEC_RECV_NUM_EVENTS );
TASKEVENTSTORAGE( DaliEvnt, DALIMESSAGE_EVENT_NUM_EVENTS    );
TASKEVENTSTORAGE( DaliTimr, DALIMESSAGE_TIMER_NUM_EVENTS    );
TASKEVENTSTORAGE( DaliOutp, DALIMESSAGE_OUTPUT_NUM_EVENTS   );
TASKEVENTSTORAGE( DaliBusf, DALIMESSAGE_BUSFAIL_NUM_EVENTS  );
 
/// scheduled task table declaration
const CODE TASKSCHDDEF  g_atTaskSchdDefs[ TASK_SCHD_MAX ] =
{
  // TASKSCHD( type, taskhandler, numevents, bufname, executionrate, enabled, runoninit )
  TASKSCHD( TASK_TYPE_EVENT,            SystemControlManager_ProcessEvent,   SYSCTRLMNGR_TASK_NUM_EVENTS,     SysCtrl,                               0,  TRUE,  FALSE ),
  TASKSCHD( TASK_TYPE_EVENT,            DbgAscCommandHandler_ProcessChar,    DBGASCCOMMANDHANDLER_NUM_EVENTS, DbgChar,                               0,  TRUE,  FALSE ),
  TASKSCHD( TASK_TYPE_TIMED_CONTINUOUS, StatusManager_ProcessEvent,          STATUSMANAGER_NUM_EVENTS,        StsCtrl,  STATUSMANAGER_EXEC_RATE_COUNTS,  TRUE,  FALSE ),
  TASKSCHD( TASK_TYPE_EVENT,            ManchesterCodec_ProcessCaptureValue, MANCHESTERCODEC_RECV_NUM_EVENTS, ManRecv,                               0,  FALSE, FALSE ),
  TASKSCHD( TASK_TYPE_EVENT,            DALIMessageHandler_ProcessEvent,     DALIMESSAGE_EVENT_NUM_EVENTS,    DaliEvnt,                              0,  FALSE, FALSE ),
  TASKSCHD( TASK_TYPE_TIMED_ONESHOT,    DALIMessageHandler_ProcessTimer,     DALIMESSAGE_TIMER_NUM_EVENTS,    DaliTimr,   DALIMESSAGE_TIMER_EXEC_RAT1E,  FALSE, FALSE ),
  TASKSCHD( TASK_TYPE_TIMED_CONTINUOUS, DALIMessageHandler_ProcessOutput,    DALIMESSAGE_OUTPUT_NUM_EVENTS,   DaliOutp,   DALIMESSAGE_OUTPUT_EXEC_RATE,  FALSE, FALSE ),
  TASKSCHD( TASK_TYPE_TIMED_CONTINUOUS, DALIMessageHandler_ProcessBusFail,   DALIMESSAGE_BUSFAIL_NUM_EVENTS,  DaliBusf,  DALIMESSAGE_BUSFAIL_EXEC_RATE,  FALSE, FALSE ),
};

#if ( TASK_TICK_ENABLE == 1 )
/// tick task table declaration
const CODE TASKTICKDEF  g_atTaskTickDefs[ TASK_TICK_MAX ] = 
{
  // TASKTICK( taskhandler, executionrate, enabled ),
};
#endif  // TASK_TICK_ENABLE


/**@} EOF TaskManager_cfg.c */
