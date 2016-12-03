#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	if (argc < 2) {
		cout << "Number argument is missing";
		return 0;
	}		
	char*  y = argv[1];
	int   lenas = strlen(y);
	int  ats;

	__asm {
		push eax
		push ebx
		push ecx 
		push edx

		mov eax, y
		mov ebx, [lenas] 
		add eax, ebx
		mov [lenas],ebx
		xor edx,edx
		xor ecx,ecx
		inc edx
		jz endas

		loopas:
		dec eax
		xor ebx, ebx
		mov bl, byte ptr [eax]
		sub bl, 48
		imul ebx, edx
		add ecx, ebx
		imul edx, 10
		mov ebx, [lenas]
		dec ebx
		mov [lenas],ebx
		cmp ebx, 0
		jz endas
		jmp loopas

		endas:
		mov [ats],ecx
		pop edx	
		pop ecx
		pop ebx
		pop eax

	}

	cout << ats << endl;
	
	cin >> y;
	return 0;
}
