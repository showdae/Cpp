#include <iostream>
#include <mil.h>
// ������Ʈ �Ӽ� (ConsoleApplication1)
// ������� ����:	�Ӽ� -> C/C++ -> �Ϲ� -> �߰� ���� ���͸� -> C:\Program Files\Matrox Imaging\MIL\Include
// ���̺귯�� �߰�:	�Ӽ� -> ��Ŀ -> �Ϲ� -> �߰� ���̺귯�� ���͸� -> C:\Program Files\Matrox Imaging\MIL\LIB
// �߰��� ���̺귯�� ��ġ���� ����� ���̺귯�� �Է�: �Ӽ� -> ��Ŀ -> �Է� -> �߰� ���Ӽ� -> mil.lib �ٹٲ� �� milmod.lib

/*
1. Mil �Լ��� Help ���� �˻�
mil control center->   mil help->   mil reference(�Լ� ����)
�Ҵ�� ���õ� �Լ��� MxxxAlloc()�� ���� ����(ex: MappAlloc(), MsysAlloc())
�Լ��̸�: MappControl (M + ��� + �Լ���)
�Ķ��Ÿ: M_ERROR (M���� �����ϰ� ��� �빮��)

2. �⺻ ��� ����
Application(�ֻ���)->	System(�׷�������)->		Display(ȭ�� ���)
												Digitizer(ī�޶� ����)
												Buffer(�̹��� �Ǵ� mil���� ����ϴ� �޸�)
												Graphics context(�̹��� ���� ���ڳ� �׸��� ǥ��)

3. ��� �Ҵ�� ����
Alloc() : ��� �ֻ������� ���������� ����
Free() : ��� �������� �ݴ� �������� ����
*/

void main()
{
	// MIL_ID: Mil���� ����ϴ� ���� Ÿ�� (long �ڷ��� ������), �ʿ��� ����� Mil_ID������ ����
	MIL_ID MilApplication;

	MIL_ID MilSystem;

	MIL_ID MilDigitizer;
	MIL_ID MilImage;
	MIL_ID MilDisplay;

	//	Allocate
	MappAlloc(M_DEFAULT, &MilApplication); // �ֻ��� ��
	MsysAlloc(M_SYSTEM_SOLIOS, M_DEV0, M_DEFAULT, &MilSystem);
	//	MsysAlloc():	�׷������带 �ý��ۿ� �Ҵ�
	//	1st:			Solios ���带 �ý��ۿ� �Ҵ�
	//	2nd:			���尡 �������� ��� M_DEV0, M_DEV1, ...
	//					�Ϲ������δ� VGAī�忡�� ����� ���尡 M_DEV0

	MdigAlloc(MilSystem, M_DEV0, "svs11002mucp.dcf", M_DEFAULT, &MilDigitizer);
	//	MdigAlloc():	ī�޶� ���� �Ҵ�
	//	1st:			Solios ���带 �Ҵ�
	//	2nd:			M_DEV0:			ù��° ī�޶�
	//	3rd:			Dcf ī�޶� ������ ��� ����
	//					�׷�������� � ī�޶� ������� �𸣱� ������ ī�޶� ������ �˷���� �Ѵ�
	//					Intelicam���� ���� Ȯ�� ��, �� ������ �ҽ��󿡼� ���
	//	5rd:			Solios ���忡 ����� ī�޶�
		
	MbufAlloc2d(MilSystem, 4008, 2672, 8 + M_UNSIGNED, M_IMAGE + M_GRAB + M_DISP, &MilImage);
	//	MbufAlloc2d():	������ �Ҵ�
	//	1st:			MilSystem�� ����
	//	2nd/3rd:		ī�޶� �ػ�
	//	4rd:			data depth(bit)
	//	5rd:			����ڰ� �� ���۸� �̹���+�������+����������� ���

	MdispAlloc(MilSystem, M_DEFAULT, "M_DEFAULT", M_WINDOWED, &MilDisplay);
	// MdispAlloc():	���÷��̿� ���� �Ҵ�

	// Free
	// �Ҵ��� ��� ������ �ݴ�� �� ��⺰ Free()�Լ��� �̿��Ͽ� ����
	MdispFree(MilDisplay);
	MbufFree(MilImage);
	MdigFree(MilDigitizer);
	MsysFree(MilSystem);
	MappFree(MilApplication);
}