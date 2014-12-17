// Win32ConsoleApplication.cpp : Defines the entry point for the console application.
//

#define _WIN32_DCOM

#include <stdio.h>
#include <string>

#import "<path to Decoder.tlb>" 


int __cdecl main(int /*argc*/, char* /*argv[]*/)
{
	CoInitializeEx(0, COINIT_APARTMENTTHREADED);

	using Decoder::IDecoderPtr;
	using Decoder::StringDecoder;

	IDecoderPtr ptr;
	auto hr = ptr.CreateInstance(__uuidof(StringDecoder));
	if (SUCCEEDED(hr)) {
		auto output = ptr->encode("hello");
		printf(output);
		printf("\n");
		printf(ptr->decode(output));
		printf("\n");
	}
	else {
		printf("failed");
		printf("\n");
	}

	CoUninitialize();
}

