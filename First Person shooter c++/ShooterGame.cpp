#include<bits/stdc++.h>
#ifndef UNICODE
#define UNICODE
#define UNICODE_WAS_UNDEFINED
#endif

#include <Windows.h>

#ifdef UNICODE_WAS_UNDEFINED
#undef UNICODE
#endif
#include<tchar.h>

using namespace std;

int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWidth = 16;

float fFOV = 3.14159 / 4.0;
float fDepth = 16.0f;

int main()
{
	// Create Screen Buffer

	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

    wstring map;

	map += L"#########.......";
	map += L"#...............";
	map += L"#.......########";
	map += L"#..............#";
	map += L"#......##......#";
	map += L"#......##......#";
	map += L"#..............#";
	map += L"###............#";
	map += L"##.............#";
	map += L"#......####..###";
	map += L"#......#.......#";
	map += L"#......#.......#";
	map += L"#..............#";
	map += L"#......#########";
	map += L"#..............#";
	map += L"################";

	while(1)
    {
        if(GetAsyncKeyState((unsigned short)'A') & 0x8000)
        {
            fPlayerA -= (1.0f);
        }

        if(GetAsyncKeyState((unsigned short)'D') & 0x8000)
        {
            fPlayerA += (1.0f);
        }

        for(int x = 0; x < nScreenWidth; x++)
        {
            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

            float fDistanceToWall = 0;

            bool bHitWall = false;

            float fEyeX = sinf(fRayAngle);
            float fEyeY = cosf(fRayAngle);

            while(!bHitWall && fDistanceToWall < fDepth)
            {
                fDistanceToWall += 0.1f;

                int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
                int nTestY = (int)(fPlayerX + fEyeY * fDistanceToWall);

                if(nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
                {
                    bHitWall = true;
                    fDistanceToWall = fDepth;
                }
                else
                {
                    if(map[nTestY * nMapWidth + nTestX] == '#')
                    {
                        bHitWall == true;
                    }
                }
            }

            //distance to ceiling and floor
            int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float) fDistanceToWall);
            int nFloor = nScreenHeight - nCeiling;

			short nShade = ' ';
			if (fDistanceToWall <= fDepth / 4.0f)	nShade = 0x2588;	// Very close
			else if (fDistanceToWall < fDepth / 3.0f)	nShade = 0x2593;
			else if (fDistanceToWall < fDepth / 2.0f)	nShade = 0x2592;
			else if (fDistanceToWall < fDepth)	nShade = 0x2591;
			else nShade = ' ';


            for(int y=0; y<nScreenHeight;y++)
            {
                if(y<=nCeiling)
                    screen[y*nScreenWidth + x] = ' ';
                else if (y>nCeiling && y<=nFloor)
                    screen[y*nScreenWidth + x] = nShade;
                else
                    screen[y*nScreenWidth + x] = ' ';

            }
        }

        // Display Frame
        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }

return 0;
}
