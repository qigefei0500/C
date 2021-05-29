#include <stdio.h>
#include <windows.h>
#include <time.h>
time_t time( time_t *time );

class mlog
{
    char fn[250];
    FILE *fp;
public:
    mlog()
    {
        strcpy(fn,"log.txt");
        fp=fopen(fn,"w");
    }
    ~mlog()
    {
        fclose(fp);
    }

    void pr(  char* szString, ... )
    {
        va_list va;
        time_t ttime;
        tm* pCurTime;

        char szParsedString[1024];
        char szLogTime[32];

        //??????
        time( &ttime );
        pCurTime= localtime( &ttime );
        strftime( szLogTime, 32, " %H:%M:%S    ", pCurTime );

        //?????????
        va_start( va, szString );
        vsprintf( szParsedString, szString, va );
        va_end( va );

        if ( !fp )
            return;

        fprintf( fp, "%s    %s\n",  szLogTime, szParsedString );
        fflush(fp);
    }
};
