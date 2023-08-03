#include <iostream>
#include <mil.h>
// 프로젝트 속성 (ConsoleApplication1)
// 헤더파일 포함:	속성 -> C/C++ -> 일반 -> 추가 포함 디렉터리 -> C:\Program Files\Matrox Imaging\MIL\Include
// 라이브러리 추가:	속성 -> 링커 -> 일반 -> 추가 라이브러리 디렉터리 -> C:\Program Files\Matrox Imaging\MIL\LIB
// 추가한 라이브러리 위치에서 사용할 라이브러리 입력: 속성 -> 링커 -> 입력 -> 추가 종속성 -> mil.lib 줄바꿈 후 milmod.lib

/*
1. Mil 함수와 Help 파일 검색
mil control center->   mil help->   mil reference(함수 설명)
할당과 관련된 함수는 MxxxAlloc()과 같은 형태(ex: MappAlloc(), MsysAlloc())
함수이름: MappControl (M + 모듈 + 함수명)
파라메타: M_ERROR (M으로 시작하고 모두 대문자)

2. 기본 모듈 구조
Application(최상위)->	System(그래버관리)->		Display(화면 출력)
												Digitizer(카메라 제어)
												Buffer(이미지 또는 mil에서 사용하는 메모리)
												Graphics context(이미지 위에 문자나 그림을 표시)

3. 모듈 할당과 해제
Alloc() : 모듈 최상위부터 순차적으로 진행
Free() : 모듈 하위부터 반대 방향으로 진행
*/

void main()
{
	// MIL_ID: Mil에서 사용하는 변수 타입 (long 자료형 포인터), 필요한 모듈을 Mil_ID형으로 선언
	MIL_ID MilApplication;

	MIL_ID MilSystem;

	MIL_ID MilDigitizer;
	MIL_ID MilImage;
	MIL_ID MilDisplay;

	//	Allocate
	MappAlloc(M_DEFAULT, &MilApplication); // 최상위 모델
	MsysAlloc(M_SYSTEM_SOLIOS, M_DEV0, M_DEFAULT, &MilSystem);
	//	MsysAlloc():	그래버보드를 시스템에 할당
	//	1st:			Solios 보드를 시스템에 할당
	//	2nd:			보드가 여러장인 경우 M_DEV0, M_DEV1, ...
	//					일반적으로는 VGA카드에서 가까운 보드가 M_DEV0

	MdigAlloc(MilSystem, M_DEV0, "svs11002mucp.dcf", M_DEFAULT, &MilDigitizer);
	//	MdigAlloc():	카메라에 대한 할당
	//	1st:			Solios 보드를 할당
	//	2nd:			M_DEV0:			첫번째 카메라
	//	3rd:			Dcf 카메라 정보가 담긴 파일
	//					그래버보드는 어떤 카메라가 연결될지 모르기 떄문에 카메라 정보를 알려줘야 한다
	//					Intelicam에서 영상 확인 후, 그 파일을 소스상에서 사용
	//	5rd:			Solios 보드에 연결된 카메라
		
	MbufAlloc2d(MilSystem, 4008, 2672, 8 + M_UNSIGNED, M_IMAGE + M_GRAB + M_DISP, &MilImage);
	//	MbufAlloc2d():	버퍼의 할당
	//	1st:			MilSystem에 종속
	//	2nd/3rd:		카메라 해상도
	//	4rd:			data depth(bit)
	//	5rd:			사용자가 이 버퍼를 이미지+영상취득+영상출력으로 사용

	MdispAlloc(MilSystem, M_DEFAULT, "M_DEFAULT", M_WINDOWED, &MilDisplay);
	// MdispAlloc():	디스플레이에 대한 할당

	// Free
	// 할당한 모듈 순서의 반대로 각 모듈별 Free()함수를 이용하여 해제
	MdispFree(MilDisplay);
	MbufFree(MilImage);
	MdigFree(MilDigitizer);
	MsysFree(MilSystem);
	MappFree(MilApplication);
}