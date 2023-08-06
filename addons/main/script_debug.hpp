/**
Fast Recompiling via function
**/
// #define DISABLE_COMPILE_CACHE
// To Use: [] call KEKO_PREP_RECOMPILE;

#ifdef DISABLE_COMPILE_CACHE
    #define LINKFUNC(x) {_this call FUNC(x)}
    #define PREP_RECOMPILE_START    if (isNil "RAT_PREP_RECOMPILE") then {RAT_RECOMPILES = []; RAT_PREP_RECOMPILE = {{call _x} forEach RAT_RECOMPILES;}}; private _recomp = {
    #define PREP_RECOMPILE_END      }; call _recomp; RAT_RECOMPILES pushBack _recomp;
#else
    #define LINKFUNC(x) FUNC(x)
    #define PREP_RECOMPILE_START; /* disabled */
    #define PREP_RECOMPILE_END; /* disabled */
#endif


/**
STACK TRACING
**/
//#define ENABLE_CALLSTACK
//#define ENABLE_PERFORMANCE_COUNTERS
//#define DEBUG_EVENTS

#ifdef ENABLE_CALLSTACK
    #define CALLSTACK(function) {if(RAT_IS_ERRORED) then { ['AUTO','AUTO'] call RAT_DUMPSTACK_FNC; RAT_IS_ERRORED = false; }; RAT_IS_ERRORED = true; RAT_STACK_TRACE set [RAT_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, RAT_CURRENT_FUNCTION, 'ANON', _this]]; RAT_STACK_DEPTH = RAT_STACK_DEPTH + 1; RAT_CURRENT_FUNCTION = 'ANON'; private _ret = _this call ##function; RAT_STACK_DEPTH = RAT_STACK_DEPTH - 1; RAT_IS_ERRORED = false; _ret;}
    #define CALLSTACK_NAMED(function, functionName) {if(RAT_IS_ERRORED) then { ['AUTO','AUTO'] call RAT_DUMPSTACK_FNC; RAT_IS_ERRORED = false; }; RAT_IS_ERRORED = true; RAT_STACK_TRACE set [RAT_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, RAT_CURRENT_FUNCTION, functionName, _this]]; RAT_STACK_DEPTH = RAT_STACK_DEPTH + 1; RAT_CURRENT_FUNCTION = functionName; private _ret = _this call ##function; RAT_STACK_DEPTH = RAT_STACK_DEPTH - 1; RAT_IS_ERRORED = false; _ret;}
    #define DUMPSTACK ([__FILE__, __LINE__] call RAT_DUMPSTACK_FNC)

    #define FUNC(var1) {if(RAT_IS_ERRORED) then { ['AUTO','AUTO'] call RAT_DUMPSTACK_FNC; RAT_IS_ERRORED = false; }; RAT_IS_ERRORED = true; RAT_STACK_TRACE set [RAT_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, RAT_CURRENT_FUNCTION, 'TRIPLES(ADDON,fnc,var1)', _this]]; RAT_STACK_DEPTH = RAT_STACK_DEPTH + 1; RAT_CURRENT_FUNCTION = 'TRIPLES(ADDON,fnc,var1)'; private _ret = _this call TRIPLES(ADDON,fnc,var1); RAT_STACK_DEPTH = RAT_STACK_DEPTH - 1; RAT_IS_ERRORED = false; _ret;}
    #define EFUNC(var1,var2) {if(RAT_IS_ERRORED) then { ['AUTO','AUTO'] call RAT_DUMPSTACK_FNC; RAT_IS_ERRORED = false; }; RAT_IS_ERRORED = true; RAT_STACK_TRACE set [RAT_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, RAT_CURRENT_FUNCTION, 'TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)', _this]]; RAT_STACK_DEPTH = RAT_STACK_DEPTH + 1; RAT_CURRENT_FUNCTION = 'TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)'; private _ret = _this call TRIPLES(DOUBLES(PREFIX,var1),fnc,var2); RAT_STACK_DEPTH = RAT_STACK_DEPTH - 1; RAT_IS_ERRORED = false; _ret;}
#else
    #define CALLSTACK(function) function
    #define CALLSTACK_NAMED(function, functionName) function
    #define DUMPSTACK
#endif


/**
PERFORMANCE COUNTERS SECTION
**/
//#define ENABLE_PERFORMANCE_COUNTERS
// To Use: [] call keko_common_fnc_dumpPerformanceCounters;

#ifdef ENABLE_PERFORMANCE_COUNTERS
    #define CBA_fnc_addPerFrameHandler { _ret = [(_this select 0), (_this select 1), (_this select 2), #function] call CBA_fnc_addPerFrameHandler; if(isNil "RAT_PFH_COUNTER" ) then { RAT_PFH_COUNTER=[]; }; RAT_PFH_COUNTER pushBack [[_ret, __FILE__, __LINE__], [(_this select 0), (_this select 1), (_this select 2)]];  _ret }

    #define CREATE_COUNTER(x) if(isNil "RAT_COUNTERS" ) then { RAT_COUNTERS=[]; }; GVAR(DOUBLES(x,counter))=[]; GVAR(DOUBLES(x,counter)) set[0, QUOTE(GVAR(DOUBLES(x,counter)))];  GVAR(DOUBLES(x,counter)) set[1, diag_tickTime]; RAT_COUNTERS pushBack GVAR(DOUBLES(x,counter));
    #define BEGIN_COUNTER(x) if(isNil QUOTE(GVAR(DOUBLES(x,counter)))) then { CREATE_COUNTER(x) }; GVAR(DOUBLES(x,counter)) set[2, diag_tickTime];
    #define END_COUNTER(x) GVAR(DOUBLES(x,counter)) pushBack [(GVAR(DOUBLES(x,counter)) select 2), diag_tickTime];

    #define DUMP_COUNTERS ([__FILE__, __LINE__] call RAT_DUMPCOUNTERS_FNC)
#else
    #define CREATE_COUNTER(x) /* disabled */
    #define BEGIN_COUNTER(x) /* disabled */
    #define END_COUNTER(x) /* disabled */
    #define DUMP_COUNTERS  /* disabled */
#endif
