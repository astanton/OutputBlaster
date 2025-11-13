/*This file is part of Output Blaster.

Output Blaster is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Output Blaster is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Output Blaster.If not, see < https://www.gnu.org/licenses/>.*/

#include "ProjectR.h"
#include <bitset>

static int WindowsLoop()
{

	INT64 bits = helpers->ReadInt64(0x8E1940, true);
	std::bitset<64> bitmap(bits);

	bool view1 = helpers->IsBitSet(bitmap, 5);
	bool view2 = helpers->IsBitSet(bitmap, 6);
	bool view3 = helpers->IsBitSet(bitmap, 7);
	bool abort = helpers->IsBitSet(bitmap, 8);
	bool music = helpers->IsBitSet(bitmap, 9);
	bool leader = helpers->IsBitSet(bitmap, 32);

	Outputs->SetValue(OutputLampStart, abort);
	Outputs->SetValue(OutputLampRed, view1);
	Outputs->SetValue(OutputLampBlue, view2);
	Outputs->SetValue(OutputLampWhite, view3);
	Outputs->SetValue(OutputLampGreen, music);
	Outputs->SetValue(OutputLampLeader, leader);

	// adding these so we can clean up properly or if they are wanted to be used elsewehre
	Outputs->SetValue(OutputLampView1, view1);
	Outputs->SetValue(OutputLampView2, view2);
	Outputs->SetValue(OutputLampView3, view3);
	Outputs->SetValue(OutputLampView4, music);

	return 0;
}

static DWORD WINAPI OutputsAreGo(LPVOID lpParam)
{
	while (true)
	{
		WindowsLoop();
		Sleep(SleepA);
	}
}

void ProjectR::OutputsGameLoop()
{
	if (!init)
	{
		helpers->log("in the init: ");

		Outputs = CreateOutputsFromConfig();
		m_game.name = "Project R";
		Outputs->SetGame(m_game);
		Outputs->Initialize();
		Outputs->Attached();
		CreateThread(NULL, 0, OutputsAreGo, NULL, 0, NULL);
		while (GetMessage(&Msg1, NULL, NULL, 0))
		{
			TranslateMessage(&Msg1);
			DispatchMessage(&Msg1);
		}
		init = true;
	}
}