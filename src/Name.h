#pragma once
#include "NameFunctions.h"

namespace ProjectNovigrad
{
	namespace TW3
	{
		class __declspec(dllexport) CName
		{
		public:
			uint32_t pool_index;
			CName() : pool_index(0) {}

			void Set(const wchar_t* str)
			{
				Functions::CName_Set(this, str);
			}

			const wchar_t* AsChar()
			{	
				return Functions::CName_AsChar(this);
			}

		};
	}
}