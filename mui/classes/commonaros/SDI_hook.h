#ifndef SDI_HOOK_H
#define SDI_HOOK_H

/* Includeheader

        Name:           SDI_hook.h
        Versionstring:  $VER: SDI_hook.h 1.7 (04.07.2004)
        Author:         SDI
        Distribution:   PD
        Description:    defines to hide compiler specific hook stuff

 1.0   21.06.02 : based on the work made for freeciv and YAM with
                  additional texts partly taken from YAM_hook.h changes made
                  by Jens Langner, largely reworked the mechanism
 1.1   07.10.02 : added HOOKPROTONP and HOOKPROTONONP requested by Jens
 1.2   18.10.02 : reverted to old MorphOS-method for GCC
 1.3   08.02.04 : modified to get it compatible to AmigaOS4
 1.4   17.02.04 : modified to get compatible to latest SDI_compiler.h changes
 1.5   02.03.04 : added UNUSED define to OS4 hook specification so that the
                  compiler can ignore some warnings.
 1.6   02.03.04 : added (APTR) casts to MorphOS prototype definition to
                  reduce compiler warnings.
 1.7   04.07.04 : removed static from all DISPATCHERPROTO definitions as there
                  may dispatcher that are of course non static.
*/

/*
** This is PD (Public Domain). This means you can do with it whatever you want
** without any restrictions. I only ask you to tell me improvements, so I may
** fix the main line of this files as well.
**
** To keep confusion level low: When changing this file, please note it in
** above history list and indicate that the change was not made by myself
** (e.g.�add your name or nick name).
**
** Dirk St�cker <stoecker@epost.de>
*/

#include "SDI_compiler.h"

#include <aros/asmcall.h>

/*
** Hook macros to handle the creation of Hooks/Dispatchers for different
** Operating System versions.
** Currently AmigaOS and MorphOS is supported.
**
** For more information about hooks see include file <utility/hooks.h> or
** the relevant descriptions in utility.library autodocs.
**
** Example:
**
** Creates a hook with the name "TestHook" that calls a corresponding
** function "TestFunc" that will be called with a pointer "text"
** (in register A1) and returns a long.
**
** HOOKPROTONHNO(TestFunc, LONG, STRPTR text)
** {
**   Printf(text);
**   return 0;
** }
** MakeHook(TestHook, TestFunc);
**
** Every function that is created with HOOKPROTO* must have a MakeHook() or
** MakeStaticHook() to create the corresponding hook. Best is to call this
** directly after the hook function. This is required by the GCC macros.
**
** The naming convention for the Hook Prototype macros is as followed:
**
** HOOKPROTO[NH][NO][NP]
**           ^^  ^^  ^^
**      NoHook   |    NoParameter
**            NoObject
**
** So a plain HOOKPROTO() creates you a Hook function that requires
** 4 parameters, the "name" of the hookfunction, the "obj" in REG_A2,
** the "param" in REG_A1 and a "hook" in REG_A0. Usually you will always
** use NH, as the hook structure itself is nearly never required.
**
** The DISPATCHERPROTO macro is for MUI dispatcher functions. It gets the
** functionname as argument. To supply this function for use by MUI, use
** The ENTRY macro, which also gets the function name as argument.
*/

#define AROS_HOOKPROTO(name, ret, objtype, obj, paramtype, param) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, hook, A0), \
	AROS_UFHA(objtype, obj, A2), \
	AROS_UFHA(paramtype, param, A1))
#define AROS_HOOKPROTONO(name, ret, paramtype, param) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, hook, A0), \
	AROS_UFHA(APTR, unused_obj, A2), \
	AROS_UFHA(paramtype, param, A1))
#define AROS_HOOKPROTONP(name, ret, objtype, obj) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, hook, A0), \
	AROS_UFHA(objtype, obj, A2), \
	AROS_UFHA(APTR, unused_param, A1))
#define AROS_HOOKPROTONONP(name, ret) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, hook, A0), \
	AROS_UFHA(APTR, unused_obj, A2), \
	AROS_UFHA(APTR, unused_param, A1))
#define AROS_HOOKPROTONH(name, ret, objtype, obj, paramtype, param) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, unused_hook, A0), \
	AROS_UFHA(objtype, obj, A2), \
	AROS_UFHA(paramtype, param, A1))
#define AROS_HOOKPROTONHNO(name, ret, paramtype, param) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, unused_hook, A0), \
	AROS_UFHA(APTR, unused_obj, A2), \
	AROS_UFHA(paramtype, param, A1))
#define AROS_HOOKPROTONHNP(name, ret, objtype, obj) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, hook, A0), \
	AROS_UFHA(objtype, obj, A2), \
	AROS_UFHA(APTR, unused_param, A1))
#define AROS_HOOKPROTONHNONP(name, ret) \
    AROS_UFH3S(ret, name, \
    	AROS_UFHA(struct Hook *, unused_hook, A0), \
	AROS_UFHA(APTR, unused_obj, A2), \
	AROS_UFHA(APTR, unused_param, A1))
	
#define HOOK_INIT AROS_USERFUNC_INIT
#define HOOK_EXIT AROS_USERFUNC_EXIT
	
#define DISPATCHERPROTO(name) \
    AROS_UFH3(IPTR, name, \
    	AROS_UFHA(struct IClass *, cl, A0), \
	AROS_UFHA(Object *, obj, A2), \
	AROS_UFHA(Msg, msg, A1))

#define DISPATCHER_INIT AROS_USERFUNC_INIT
#define DISPATCHER_EXIT AROS_USERFUNC_EXIT

#define ENTRY(func) (APTR)func

#define MakeHook(hookname, funcname) struct Hook hookname = {{NULL, NULL}, \
    (HOOKFUNC)funcname, NULL, NULL}

#define MakeHookWithData(hookname, funcname, data) struct Hook hookname =  \
    {{NULL, NULL}, (HOOKFUNC)funcname, NULL, (APTR)data}
    
#define MakeStaticHook(hookname, funcname) static struct Hook hookname =   \
    {{NULL, NULL}, (HOOKFUNC)funcname, NULL, NULL}

#define InitHook(hook, orighook, data) ((hook)->h_Entry = (orighook).h_Entry,\
  (hook)->h_SubEntry = (orighook).h_SubEntry,(hook)->h_Data = (APTR)(data))

#endif /* SDI_HOOK_H */