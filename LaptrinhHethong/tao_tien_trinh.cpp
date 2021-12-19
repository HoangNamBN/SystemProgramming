//#include <iostream.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{
  STARTUPINFO stgStartupInfo;         // für CreateProcess()
  PROCESS_INFORMATION stgProcessInfo;

  DWORD ExitCode;                       // für den ExitCode

  ZeroMemory(&stgStartupInfo,sizeof(STARTUPINFO));
  stgStartupInfo.cb = sizeof(STARTUPINFO);
  
  char sz[256]="c:\\windows\\notepad.exe c:\\abc.bat";

  // Notepad starten:
  //if(CreateProcess(NULL,"c:\\windows\\notepad.exe c:\\abc.bat",
  if(CreateProcess(NULL,sz,
                NULL,NULL,false,
                CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS,
                NULL,NULL,&stgStartupInfo,&stgProcessInfo)==TRUE)
  {
    CloseHandle(stgProcessInfo.hThread);  // wird nicht mehr gebraucht..

    // Auf das Ende der Initialisierung der soeben gestarteten
    // Anwendung warten (Initialisierung ist beendet wenn das Programm
    // bereit ist, die Benutzereingaben entgegenzunehmen)
    WaitForInputIdle(stgProcessInfo.hProcess, INFINITE);
    
    // nun ist die Initialisierung des Notepads abgeschlossen !


    // Auf das Programmende warten (es würde auch ohne Schleife
    // mit WaitForSingleObject(stgProcessInfo.hProcess, INFINITE)
    // funktionieren, allerdings würden die Systembotschaften
    // von der Anwendung nicht verarbeitet, das Fenster nicht
    // aktualisiert etc. Daher warten wir "in Scheibchen" a 0,1s und
    // rufen immer wieder ProcessMessages auf. Gleiche Vorgehensweise
    // wäre bei grösseren Anwendungen auch bei WaitForInputIdle()
    // angebracht, beim Notepad lohnt es sich aufgrund der kurzen
    // Initialisierungsdauer allerdings nicht. :)
    while(WaitForSingleObject(stgProcessInfo.hProcess, 100) == WAIT_TIMEOUT)
    {
    }

    // Das Programm wurde beendet...

    // Rückgabewert auslesen:
    GetExitCodeProcess(stgProcessInfo.hProcess, &ExitCode);

    // die Variable ExitCode ist nun mit dem Rückgabewert unserer Anwendung 
    // (Notepad) initialisiert

    CloseHandle(stgProcessInfo.hProcess); // Ressourcen freigeben
  }
  
  STARTUPINFO stgStartupInfo2;         // für CreateProcess()
  PROCESS_INFORMATION stgProcessInfo2;

  DWORD ExitCode2;                       // für den ExitCode

  ZeroMemory(&stgStartupInfo2,sizeof(STARTUPINFO));
  stgStartupInfo2.cb = sizeof(STARTUPINFO);
  
  

  // Notepad starten:
  //if(CreateProcess(NULL,"c:\\windows\\notepad.exe c:\\abc.bat",
  if(CreateProcess(NULL,sz,
                NULL,NULL,false,
                CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS,
                NULL,NULL,&stgStartupInfo2,&stgProcessInfo2)==TRUE)
  {
    CloseHandle(stgProcessInfo2.hThread);  // wird nicht mehr gebraucht..

    // Auf das Ende der Initialisierung der soeben gestarteten
    // Anwendung warten (Initialisierung ist beendet wenn das Programm
    // bereit ist, die Benutzereingaben entgegenzunehmen)
    WaitForInputIdle(stgProcessInfo.hProcess, INFINITE);
    
    // nun ist die Initialisierung des Notepads abgeschlossen !


    // Auf das Programmende warten (es würde auch ohne Schleife
    // mit WaitForSingleObject(stgProcessInfo.hProcess, INFINITE)
    // funktionieren, allerdings würden die Systembotschaften
    // von der Anwendung nicht verarbeitet, das Fenster nicht
    // aktualisiert etc. Daher warten wir "in Scheibchen" a 0,1s und
    // rufen immer wieder ProcessMessages auf. Gleiche Vorgehensweise
    // wäre bei grösseren Anwendungen auch bei WaitForInputIdle()
    // angebracht, beim Notepad lohnt es sich aufgrund der kurzen
    // Initialisierungsdauer allerdings nicht. :)
    while(WaitForSingleObject(stgProcessInfo2.hProcess, 100) == WAIT_TIMEOUT)
    {
    }

    // Das Programm wurde beendet...

    // Rückgabewert auslesen:
    GetExitCodeProcess(stgProcessInfo2.hProcess, &ExitCode2);

    // die Variable ExitCode ist nun mit dem Rückgabewert unserer Anwendung 
    // (Notepad) initialisiert

    CloseHandle(stgProcessInfo2.hProcess); // Ressourcen freigeben
  }
  
  return 0;
}

