/*
	Base Plugin
	Downloaded from http://jass.ucoz.net/
	This file is base for new plugins
*/

#include "version.h" //Constants with info about autor
//Usual headers:
#include </usr/include/jka/game/q_shared.h>
#include </usr/include/jka/game/g_local.h>
#include "jassapi.h" //JAZZ APIs

pluginres_t* g_result = NULL;
//Plugin info
plugininfo_t g_plugininfo = {
	"netstatus",					//Plugin name
	Plugin_Base_version,			//version
	"Checks network settings",				//description
	Plugin_Base_Builder,			//author --- devon
	"esljka.com",	//site
	1,								//can plugin be paused?
	1,								//can plugin be loaded via cmd?
	1,								//can plugin be unloaded via cmd?
	JASS_PIFV_MAJOR,				//interface version (inside the jassapi.h)
	JASS_PIFV_MINOR				
};
eng_syscall_t g_syscall = NULL;
mod_vmMain_t g_vmMain = NULL;
pluginfuncs_t* g_pluginfuncs = NULL;


//First function called by JAZZ. Don't change it
C_DLLEXPORT void JASS_Query(plugininfo_t** pinfo) {
	JASS_GIVE_PINFO();
}

//Second function called by JAZZ
//All the code, that must be executed on start, must be written here.
// engfunc - pointer to engine's syscall
// modfunc - pointer to mod's vmMain
// presult - pointer to plugin result
// iscmd - method of loading: 0 = loaded via jass.ini, 1 = loaded via "jass load" cmd
C_DLLEXPORT int JASS_Attach(eng_syscall_t engfunc, mod_vmMain_t modfunc, pluginres_t* presult, pluginfuncs_t* pluginfuncs, int iscmd) {
	JASS_SAVE_VARS();
	iscmd = 0;

	return 1;
	//return 0; is failure
}

//Last function called by JAZZ
//All the code, that must be executed on exit, must be written here.
// iscmd - method of unloading: 0 = loaded on server shutdown, 1 = loaded via "jass unload" cmd
C_DLLEXPORT void JASS_Detach(int iscmd) {
	iscmd = 0;
}

//This function calls before mod's vmMain (Engine - mod)
C_DLLEXPORT int JASS_vmMain(int cmd, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11) {
	
	/*if (cmd == GAME_CLIENT_COMMAND) { //Checking the client cmd
		//Use g_syscall to send commands to Engine
		//ex.: g_syscall(G_PRINT, "Hi!\n");
		//Use g_vmMain to send commands to Mod
		//List of possible cmd values is inside g_public.h
	} //else if (cmd == GAME_SERVER_COMMAND){
		//JASS_RET_SUPERCEDE(1); //command will be blocked
	}
	*/
//g_syscall(G_PRINT, JASS_VARARGS("vmMain(%s)\n", JASS_MODMSGNAME(cmd)));
	 if (cmd == GAME_CLIENT_COMMAND) {
#define strcasecmp stricmp
		int argc = g_syscall(G_ARGC);
		g_syscall(G_ARGV, 0, GAME_CLIENT_COMMAND);
		if (GAME_CLIENT_COMMAND , "netstatus") {
			char tmparg[1024];
			g_syscall(G_PRINT, "score ping rate   fps packets timeNudge snaps R id name \n");
			JASS_RET_IGNORED(1);
			//G_PRINT("Netstatus");
			//args
		}
	}
	
	if (cmd == GAME_CONSOLE_COMMAND) {
#define strcasecmp stricmp
		int argc = g_syscall(G_ARGC);
		g_syscall(G_ARGV, 0, ConsoleCommand);
		if (ConsoleCommand, "netstatus") {
			char tmparg[1024];

			g_syscall(G_PRINT, "score ping rate   fps packets timeNudge snaps R id name \n");
			JASS_RET_IGNORED(1);
			//G_PRINT("Netstatus");
			//args
		}
	}
	
		if (cmd == GAME_CLIENT_COMMAND) {
#define strcasecmp stricmp
		int argc = g_syscall(G_ARGC);
		char command[16];

		g_syscall(G_ARGV, 0, command, sizeof(command));
		if (!strcasecmp(command, "netstatus")) {

			g_syscall(G_PRINT, "score ping rate   fps packets timeNudge snaps R id name \n");
			JASS_RET_IGNORED(1); //command will be passed
		}
		
		
	}

		if (cmd == GAME_CONSOLE_COMMAND) {
		#define strcasecmp stricmp
		int argc = g_syscall(G_ARGC);
		char command[16];
		g_syscall(G_ARGV, 0, command, sizeof(command));
		if (!strcasecmp(command, "netstatus"))

		g_syscall(G_PRINT, "score ping rate   fps packets timeNudge snaps R id name \n");
		JASS_RET_IGNORED(1); //command will be passed
						}
					
				}
				
				
			
		
	

			

//This function calls before engine's suscall (mod - engine)
C_DLLEXPORT int JASS_syscall(int cmd, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12) {
/*	
	if (cmd == G_PRINT) {
		JASS_RET_SUPERCEDE(1);
	}

	//g_syscall(G_PRINT, JASS_VARARGS("syscall(%s)\n", JASS_ENGMSGNAME(cmd)));
	if (cmd == GAME_CLIENT_COMMAND) {
#define strcasecmp stricmp
		int argc = g_syscall(G_ARGC);
		char command[16];

		g_syscall(G_ARGV, 0, command, sizeof(command));
		if (!strcasecmp(command, "netstatus")) {

			g_syscall(G_PRINT, "score ping rate   fps packets timeNudge snaps R id name \n"); */
			JASS_RET_IGNORED(1); //command will be passed
		
}


//This function calls after mod's vmMain (Engine - mod)
C_DLLEXPORT int JASS_vmMain_Post(int cmd, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11) {
	//g_syscall(G_PRINT, JASS_VARARGS("vmMain_Post(%s)\n", JASS_MODMSGNAME(cmd)));
	JASS_RET_IGNORED(1);
}

//This function calls after engine's suscall (mod - engine)
C_DLLEXPORT int JASS_syscall_Post(int cmd, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12) {
	//g_syscall(G_PRINT, JASS_VARARGS("syscall_Post(%s)\n", JASS_ENGMSGNAME(cmd)));
	JASS_RET_IGNORED(1);
}

//This function calls when other plugin or JASS by itself onvokes it
//Place there code that will be shared to other plugins
C_DLLEXPORT int JASS_pluginCall(int cmd, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11, int arg12) {
	return 0;
	
}
