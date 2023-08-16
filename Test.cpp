// git push - 23072708
// git push - 23072802
// git push - 23073104
// git test - 23080307

#include <iostream>
#include <iostream>
#include <mil.h>

using namespace std;



int main()
{ 
	//1 -카메라가 몇 대 연결되어 있는지 확인하는 코드
	MIL.MappAlloc(MIL.M_NULL, MIL.M_DEFAULT, ref MilApplication);

	string s_default = "M_DEFAULT";

	MIL.MsysAlloc(MIL.M_DEFAULT, s_default, MIL.M_DEFAULT, MIL.M_DEFAULT, ref MilSystem);

	MIL.MsysControl(MIL.M_DEFAULT, MIL.M_DISCOVER_DEVICE, MIL.M_DEFAULT);

	MIL_INT DiscoverDeviceCount = 0;

	MIL.MsysInquire(MIL.M_DEFAULT, MIL.M_DISCOVER_DEVICE_COUNT, ref DiscoverDeviceCount);

	Console.WriteLine("Discovered Device is {0}", DiscoverDeviceCount);



	//2 -카메라 Device Information(SN, 이름) 확인하는 코드
	StringBuilder CameraModel = new StringBuilder();

	// Inquires the name of the camera model.

	MIL.MdigInquire(MilDigitizer, MIL.M_CAMERA_MODEL, CameraModel);

	Console.WriteLine("PN is {0}", CameraModel);

	StringBuilder GcSerialNumber = new StringBuilder();

	// Inquires the serial number for the camera.

	MIL.MdigInquire(MilDigitizer, MIL.M_GC_SERIAL_NUMBER, GcSerialNumber);

	Console.WriteLine("SN is {0}", GcSerialNumber);



	//3 Matrox Board 개수를 가지고 오는 예제는 아래와 같습니다.
	MIL_INT SysNum = 0;

	MIL.MappInquire(MilApplication, MIL.M_INSTALLED_SYSTEM_DEVICE_COUNT, ref SysNum);

	Console.WriteLine("Discovered System is {0}", SysNum);

	return 0;
}